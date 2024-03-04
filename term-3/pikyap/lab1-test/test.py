from lab_python_oop.square import Square
from lab_python_oop.circle import Circle
from lab_python_oop.rectangle import Rectangle

import unittest

blue = "Синего"
red = "Красного"
green = "Зеленого"


class MyTesting(unittest.TestCase):
    def setUp(self):
        self.a = Rectangle(3, 2, blue)
        self.b = Circle(5, green)
        self.c = Square(5, red)

    def test_area(self):
        from math import pi
        self.assertEqual(self.a.area(), 6)
        self.assertEqual(self.b.area(), pi * 5 * 5)
        self.assertEqual(self.c.area(), 25)

    def test_color(self):
        self.assertEqual(self.a.color.val, blue)
        self.assertEqual(self.b.color.val, green)
        self.assertEqual(self.c.color.val, red)

    def test_repr(self):
        self.assertEqual(str(self.a), 'Прямоугольник Синего цвета с длиной стороны 3, шириной стороны 2, площадью 6.')
        self.assertEqual(str(self.b), 'Круг Зеленого цвета радиусом 5 площадью 78.53981633974483.')
        self.assertEqual(str(self.c), 'Квадрат Красного цвета с длиной стороны 5, площадью 25.')


def main():
    print(Rectangle(3, 2, "Синего"))
    print(Circle(5, "Зеленого"))
    print(Square(5, "Красного"))


if __name__ == "__main__":
    main()
