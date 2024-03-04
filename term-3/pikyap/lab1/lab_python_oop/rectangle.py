from .figure import  Figure
from .color import Color


class Rectangle(Figure):
    type = "Прямоугольник"

    def __init__(self, width, height, color):
        self.width = width
        self.height = height
        self.color = Color(color)

    def area(self):
        return self.width * self.height

    def __repr__(self):
        return '{} {} цвета с длиной стороны {}, шириной стороны {}, площадью {}.'.format(
            self.type,
            self.color.val,
            self.width,
            self.height,
            self.area()
        )
