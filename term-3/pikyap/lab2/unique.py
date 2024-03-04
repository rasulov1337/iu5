class Unique(object):
    def __init__(self, items, **kwargs):
        ignore_case = bool(kwargs.get('ignore_case'))
        self.items = []
        used_items = set()
        for i in items:
            if ignore_case and i.lower() not in used_items:
                self.items.append(i)
                used_items.add(i.lower())
            elif not ignore_case and i not in used_items:
                self.items.append(i)
                used_items.add(i)
        self.index = 0

    def __next__(self):
        if self.index < len(self.items):
            res = self.items[self.index]
            self.index += 1
            return res
        raise StopIteration

    def __iter__(self):
        self.index = 0
        return self


if __name__ == '__main__':
    data = ['a', 'A', 'b', 'B', 'a', 'A', 'b', 'B']

    a = Unique(data, ignore_case=True)
    print(next(a))
    print(next(a))
