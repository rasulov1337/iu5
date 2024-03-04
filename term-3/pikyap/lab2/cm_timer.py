import contextlib
import time
from datetime import timedelta


class cm_timer_1:
    def __enter__(self):
        self.start_time = time.time()

    def __exit__(self, exc_type, exc_val, exc_tb):
        end_time = time.time()
        print("Execution time in seconds:", timedelta(seconds=end_time - self.start_time).seconds)
        return False


@contextlib.contextmanager
def cm_timer_2():
    start_time = time.time()
    yield start_time
    end_time = time.time()
    print("Execution time in seconds: {}".format(timedelta(seconds=end_time - start_time).seconds))


if __name__ == '__main__':
    with cm_timer_1():
        time.sleep(5)

    with cm_timer_2() as start_time:
        time.sleep(5)
