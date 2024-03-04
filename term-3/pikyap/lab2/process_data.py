import json

import unique
import field
import gen_random
from print_result import print_result
from cm_timer import cm_timer_1

path = './data_light.json'

with open(path, encoding='utf-8') as f:
    data = json.load(f)


@print_result
def f1(arg):
    return sorted(unique.Unique(field.field(data, 'job-name'), ignore_case=True))


@print_result
def f2(arg):
    return list(filter(lambda x: x.lower().startswith("программист"), arg))


@print_result
def f3(arg):
    return list(map(lambda x: (x + " с опытом Python"), arg))


@print_result
def f4(arg):
    salaries = gen_random.gen_random(len(arg), 100_000, 200_000)
    result = []
    for job, salary in zip(arg, salaries):
        result.append(f"{job}, зарплата {salary} руб")
    return result


if __name__ == '__main__':
    with cm_timer_1():
        f4(f3(f2(f1(data))))
