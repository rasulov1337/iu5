import math
from typing import Dict
from tabulate import tabulate

# Таблица для перевода синдромов в векторы ошибок
syndrome_to_error_vec: Dict[int, int] = {
    1: 0b1,
    2: 0b10,
    4: 0b100,
    8: 0b1000,
    3: 0b10000,
    6: 0b100000,
    12: 0b1000000,
    11: 0b10000000,
    5: 0b100000000,
    10: 0b1000000000,
    7: 0b10000000000,
    14: 0b100000000000,
    15: 0b1000000000000,
    13: 0b10000000000000,
    9: 0b100000000000000,
}


# Преобразование бинарной строки в десятичное число
def bin_to_dec(string: str) -> int:
    return int(string, 2)


# Деление числа на порождающий полином с нахождением остатка
def divide(divisible: int) -> int:
    divider = bin_to_dec("10011")  # Порождающий полином g(x) = x^4 + x + 1
    while divisible.bit_length() >= divider.bit_length():
        difference = divisible.bit_length() - divider.bit_length()
        divisible ^= divider << difference
    return divisible


# Генерация векторов ошибок заданной кратности
def generate_error_vector(errors_count: int, error: int) -> int:
    error += 1
    while bin(error).count("1") != errors_count:
        error += 1
    return error


# Основная функция
if __name__ == "__main__":
    # Входной вектор для варианта 13
    a = "00001010011"
    b = bin_to_dec(a) << 4  # Сдвиг на n-k = 4 разряда
    rest = divide(b)
    b |= rest  # Формирование кодового слова

    table = []

    for i in range(1, 16):  # Для кратности ошибок от 1 до 15
        error = 0b0
        count_isprav = 0
        count_naiden = 0
        combinations = math.comb(15, i)  # Число комбинаций ошибок

        for _ in range(combinations):
            vectorbuff = b
            error = generate_error_vector(i, error)
            vectorbuff ^= error  # Внесение ошибки

            vectorsyndroma = divide(vectorbuff)  # Вычисление синдрома
            if vectorsyndroma != 0:
                count_naiden += 1
                if vectorsyndroma in syndrome_to_error_vec:
                    errorbytable = syndrome_to_error_vec[vectorsyndroma]
                    vectorbuff ^= errorbytable
                    if vectorbuff == b:
                        count_isprav += 1

        Ck = count_isprav / combinations
        Co = count_naiden / combinations
        result = (
            "Все ошибки исправлены"
            if Ck == 1
            else ("Ошибки не исправлены" if Ck == 0 else "Часть ошибок исправлена")
        )
        table.append(
            [
                i,
                combinations,
                count_naiden,
                f"{Co:.1%}",
                count_isprav,
                f"{Ck:.1%}",
                result,
            ]
        )

    headers = [
        "Кратность ошибки",
        "Количество комбинаций",
        "Количество найденных",
        "Обнаруживающая способность",
        "Количество исправленных",
        "Корректирующая способность",
        "Результат",
    ]
    print(
        tabulate(
            table, headers, tablefmt="fancy_grid", stralign="center", numalign="center"
        )
    )
