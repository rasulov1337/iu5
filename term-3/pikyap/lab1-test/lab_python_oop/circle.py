from .figure import Figure
from .color import Color
import math


class Circle(Figure):
    type = "Круг"

    def __init__(self, radius, color):
        self.radius = radius
        self.color = Color(color)

    def area(self):
        return math.pi * (self.radius ** 2)

    def __repr__(self):
        return '{} {} цвета радиусом {} площадью {}.'.format(
            self.type,
            self.color.val,
            self.radius,
            self.area()
        )
