from abc import ABC, abstractmethod


class Figure(ABC):
    @abstractmethod
    def area(self):
        pass

    @abstractmethod
    def __repr__(self):
        pass

    def __str__(self):
        return self.__repr__()
