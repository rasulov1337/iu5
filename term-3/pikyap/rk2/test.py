import unittest
import data
from bindings import get_one_to_many_bindings, get_many_to_many_bindings
from main import get_filedirs_starts_with, get_filedirs_avg_file_size, get_files_that_ends_with


class Test(unittest.TestCase):
    def setUp(self):
        self.data = data

    def test_one_to_many(self):
        desired = [('lab2.py', 1024, '/root/PyCharm Projects/lab2'),
                   ('lab1.py', 10, '/root/PyCharm Projects/lab1'),
                   ('readme.txt', 10, '/root/PyCharm Projects/lab3'),
                   ('.gitignore', 1, '/root/PyCharm Projects/lab1'),
                   ('main.py', 1, '/root/PyCharm Projects/lab2'),
                   ('wallpaper.png', 7168, '/root/Desktop/')]
        actual = get_one_to_many_bindings(self.data.files, self.data.filedirs)
        self.assertCountEqual(desired, actual)

    def test_many_to_many(self):
        actual = get_many_to_many_bindings(self.data.files, self.data.filedirs, self.data.filefiledirs)
        desired = [('lab1.py', '/root/PyCharm Projects/lab1'),
                    ('.gitignore', '/root/PyCharm Projects/lab1'),
                    ('main.py', '/root/PyCharm Projects/lab1'),
                    ('lab2.py', '/root/PyCharm Projects/lab2'),
                    ('.gitignore', '/root/PyCharm Projects/lab2'),
                    ('readme.txt', '/root/PyCharm Projects/lab3'),
                    ('.gitignore', '/root/PyCharm Projects/lab3'),
                    ('wallpaper.png', '/root/Desktop/')]
        self.assertCountEqual(desired, actual)


    def test_get_files_that_ends_with(self):
        actual = get_files_that_ends_with('.py', get_one_to_many_bindings(self.data.files, self.data.filedirs))
        desired = [('lab2.py', 1024, '/root/PyCharm Projects/lab2'), ('lab1.py', 10, '/root/PyCharm Projects/lab1'), ('main.py', 1, '/root/PyCharm Projects/lab2')]
        self.assertCountEqual(actual, desired)

    def test_get_filedirs_avg_file_size(self):
        actual = get_filedirs_avg_file_size(get_one_to_many_bindings(self.data.files, self.data.filedirs))
        desired = [('/root/PyCharm Projects/lab2', 512.5), ('/root/PyCharm Projects/lab1', 5.5), ('/root/PyCharm Projects/lab3', 10.0), ('/root/Desktop/', 7168.0)]
        self.assertCountEqual(actual, desired)

    def test_get_filedirs_starts_with(self):
        actual = get_filedirs_starts_with('/root/PyCharm Projects/',
                                          get_many_to_many_bindings(self.data.files, self.data.filedirs, self.data.filefiledirs))
        desired = [('/root/PyCharm Projects/lab3', ['readme.txt', '.gitignore']), ('/root/PyCharm Projects/lab2', ['lab2.py', '.gitignore']), ('/root/PyCharm Projects/lab1', ['lab1.py', '.gitignore', 'main.py'])]
        self.assertCountEqual(actual, desired)
