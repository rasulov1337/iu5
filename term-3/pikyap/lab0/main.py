from math import sqrt
import sys


def get_coef(index, prompt):
    while True:
        try:
            return float(sys.argv[index])
        except:
            try:
                return float(input(prompt))
            except ValueError:
                print("Введите число")


def roots(A, B, C):
    if A == 0:
        if B == 0:
            if C == 0:
                print("Любое число")
                return
            else:
                print("Нет корней")
                return
        else:
            xx = (-1) * C / B
            if xx < 0:
                print("Нет корней")
                return
            else:
                roots = [sqrt(xx), (-1) * sqrt(xx)]
    else:
        D = B ** 2 - 4 * A * C
        if D < 0:
            print("Нет корней")
            return
        else:
            x1 = ((-1) * B - sqrt(D)) / (2 * A)
            x2 = ((-1) * B + sqrt(D)) / (2 * A)
            roots = []
            if x1 >= 0:
                roots.append(sqrt(x1))
                roots.append(-sqrt(x1))
            if x2 >= 0:
                roots.append(sqrt(x2))
                roots.append(-sqrt(x2))
    if not roots:
        print("Нет корней")
        return

    unique_roots = list(set(roots))
    for root in unique_roots:
        print(root)


if __name__ == "__main__":
    A = get_coef(1, 'Введите коэффициент A: ')
    B = get_coef(2, 'Введите коэффициент B: ')
    C = get_coef(3, 'Введите коэффициент C: ')
    roots(A, B, C)
