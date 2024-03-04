def field(dicts, *args):
    assert len(args) > 0

    if len(args) == 1:
        key = args[0]
        for i in dicts:
            if i.get(key):
                yield i[key]
    else:
        for dict_ in dicts:
            if all(not dict_.get(i) for i in args):
                continue
            res = {}
            for i in args:
                if dict_.get(i):
                    res[i] = dict_.get(i)
            yield res


if __name__ == '__main__':
    goods = [
        {'title': 'Ковер', 'price': 2000, 'color': 'green'},
        {'title': 'Диван для отдыха', 'color': 'black'}
    ]
    a = field(goods, 'title', 'price')  # должен выдавать {'title': 'Ковер', 'price': 2000}, {'title': 'Диван для отдыха', 'price': 5300}
    print(next(a))
    print(next(a))
