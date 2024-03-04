def get_one_to_many_bindings(files, filedirs):
    return [(f.name, f.size, fd.path) for f in files for fd in filedirs if f.filedir_id == fd.id]


def get_many_to_many_bindings(files, filedirs, filefiledirs):
    many_to_many_temp = [(fd.path, ffd.file_directory_id, ffd.file_id)
                         for fd in filedirs
                         for ffd in filefiledirs
                         if fd.id == ffd.file_directory_id]

    many_to_many = [(f.name, fd_path)
                    for fd_path, fd_id, f_id in many_to_many_temp
                    for f in files if f.id == f_id]

    return many_to_many