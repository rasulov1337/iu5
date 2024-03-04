from .rectangle import Rectangle


class Square(Rectangle):
    type = "Квадрат"

    def __init__(self, side, color):
        self.side = side
        super().__init__(self.side, self.side, color)

    def __repr__(self):
        return '{} {} цвета с длиной стороны {}, площадью {}.'.format(
            self.type,
            self.color.val,
            self.side,
            self.area()
        )

