class File:
    def __init__(self, id, name, creation_date, modification_date, author, size, filedir_id):
        self.id = id
        self.name = name
        self.creation_date = creation_date
        self.modification_date = modification_date
        self.author = author
        self.size = size
        self.filedir_id = filedir_id

    def __repr__(self):
        return self.name


class FileDirectory:
    def __init__(self, id, path):
        self.id = id
        self.path = path

    def __repr__(self):
        return self.path


class FileFileDirectory:
    def __init__(self, file_id, file_directory_id):
        self.file_id = file_id
        self.file_directory_id = file_directory_id
