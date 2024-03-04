from data import files, filedirs, filefiledirs
from bindings import get_many_to_many_bindings, get_one_to_many_bindings


def get_files_that_ends_with(ending: str, one_to_many_bindings):
    return list(filter(lambda x: x[0].endswith(ending), one_to_many_bindings))


def get_filedirs_avg_file_size(one_to_many_bindings):
    res = []
    counted_fds = set()
    for filename, file_size, fd_path in one_to_many_bindings:
        if fd_path not in counted_fds:
            counted_fds.add(fd_path)
        else:
            continue

        file_sizes = [i[1] for i in one_to_many_bindings if i[2] == fd_path]
        res.append((fd_path, sum(file_sizes) / len(file_sizes)))
    return res


def get_filedirs_starts_with(beginning, many_to_many_bindings):
    filedirs = list(set(filedir_path for _, filedir_path in many_to_many_bindings))
    dict_ = {i: [] for i in filedirs}
    for filename, filedir_path in many_to_many_bindings:
        dict_[filedir_path].append(filename)

    res_3 = [(i, dict_[i]) for i in dict_]
    return list(filter(lambda x: x[0].startswith(beginning), res_3))


def taskD1(one_to_many_bindings):
    print("Task #D1")
    for i in get_files_that_ends_with('.py', one_to_many_bindings):
        print(i[0], i[2])


def taskD2(one_to_many_bindings):
    print("\nTask #D2")
    res = get_filedirs_avg_file_size(one_to_many_bindings)
    for i in sorted(res, key=lambda x: x[1]):
        print(i)


def taskD3(many_to_many_bindings):
    print("\nTask #D3")
    for i in get_filedirs_starts_with('/root/PyCharm Projects/', many_to_many_bindings):
        print(i)


def main():
    one_to_many = get_one_to_many_bindings(files, filedirs)
    many_to_many = get_many_to_many_bindings(files, filedirs, filefiledirs)

    taskD1(one_to_many)
    taskD2(one_to_many)
    taskD3(many_to_many)


if __name__ == '__main__':
    main()
