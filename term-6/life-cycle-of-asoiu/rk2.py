import simpy
import random

# Параметры модели
N = 5  # количество компьютеров типа А
K = 10  # количество компьютеров типа В
MASTER_A_COUNT = 1  # мастера для типа А
MASTER_B_COUNT = 3 - MASTER_A_COUNT  # мастера для типа В
SIM_TIME = 6 * 30 * 24  # 6 месяцев в часах

# График работы мастеров
WORK_START = 8
WORK_END = 17


# Класс для хранения статистики каждого мастера
class Master:
    def __init__(self):
        self.busy_time = 0
        self.repairs_count = 0


# Функция ожидания до начала рабочего дня
def wait_until_work_hours(env):
    now = env.now
    hour = now % 24

    if hour < WORK_START:
        return WORK_START - hour
    elif hour >= WORK_END:
        return (24 - hour) + WORK_START
    return 0


# Процесс для компьютеров типа А
def computer_a_process(env, masters, master_stats):
    while True:
        # Время работы до поломки
        yield env.timeout(random.uniform(300, 360))

        # Ожидание начала рабочего дня
        delay = wait_until_work_hours(env)
        if delay > 0:
            yield env.timeout(delay)

        # Запрашиваем мастера
        with masters.request() as req:
            yield req

            # Определяем индекс мастера (грубая эвристика)
            idx = min(MASTER_A_COUNT - 1, len(masters.users) - 1)

            # Время ремонта
            repair_time = random.uniform(1, 10)
            master_stats[idx].busy_time += repair_time
            master_stats[idx].repairs_count += 1

            # Выполняем ремонт (может выйти за рабочее время)
            yield env.timeout(repair_time)


# Процесс для компьютеров типа В
def computer_b_process(env, masters, master_stats):
    while True:
        # Время работы до поломки
        yield env.timeout(random.uniform(350, 400))

        # Ожидание начала рабочего дня
        delay = wait_until_work_hours(env)
        if delay > 0:
            yield env.timeout(delay)

        # Запрашиваем мастера
        with masters.request() as req:
            yield req

            # Определяем индекс мастера
            idx = min(MASTER_B_COUNT - 1, len(masters.users) - 1)

            # Время ремонта
            repair_time = random.uniform(3, 9)
            master_stats[idx].busy_time += repair_time
            master_stats[idx].repairs_count += 1

            # Выполняем ремонт
            yield env.timeout(repair_time)


# Основная функция моделирования
def run_model():
    # Инициализация мастеров
    env = simpy.Environment()
    master_a = simpy.Resource(env, capacity=MASTER_A_COUNT)
    master_b = simpy.Resource(env, capacity=MASTER_B_COUNT)

    # Статистика по мастерам
    master_a_stats = [Master() for _ in range(MASTER_A_COUNT)]
    master_b_stats = [Master() for _ in range(MASTER_B_COUNT)]

    # Добавляем процессы для компьютеров
    for _ in range(N):
        env.process(computer_a_process(env, master_a, master_a_stats))

    for _ in range(K):
        env.process(computer_b_process(env, master_b, master_b_stats))

    # Запуск моделирования
    env.run(until=SIM_TIME)

    # Расчет доступного времени (с учетом овертаймов)
    total_days = 180
    work_hours_per_day = 9
    overtime_per_day = 2  # гипотетические сверхурочные часы

    available_time_a = (
        MASTER_A_COUNT * (work_hours_per_day + overtime_per_day) * total_days
    )
    available_time_b = (
        MASTER_B_COUNT * (work_hours_per_day + overtime_per_day) * total_days
    )

    # Вывод статистики
    print("\n=== Статистика мастеров типа А ===")
    for i, stat in enumerate(master_a_stats):
        load = 100 * stat.busy_time / available_time_a if available_time_a > 0 else 0
        print(f"Мастер А-{i}: ремонтов={stat.repairs_count}, загрузка={load:.2f}%")

    print("\n=== Статистика мастеров типа В ===")
    for i, stat in enumerate(master_b_stats):
        load = 100 * stat.busy_time / available_time_b if available_time_b > 0 else 0
        print(f"Мастер В-{i}: ремонтов={stat.repairs_count}, загрузка={load:.2f}%")


# Тесты
def test_random_ranges():
    assert 300 <= random.uniform(300, 360) <= 360
    assert 1 <= random.uniform(1, 10) <= 10
    assert 350 <= random.uniform(350, 400) <= 400
    assert 3 <= random.uniform(3, 9) <= 9


def test_repair_delay():
    assert wait_until_work_hours(simpy.Environment(initial_time=7)) == 1
    assert wait_until_work_hours(simpy.Environment(initial_time=8)) == 0
    assert wait_until_work_hours(simpy.Environment(initial_time=17)) == 15
    assert wait_until_work_hours(simpy.Environment(initial_time=23)) == 9


if __name__ == "__main__":
    test_random_ranges()
    test_repair_delay()
    run_model()
