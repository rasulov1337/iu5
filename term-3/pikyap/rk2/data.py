from entities import File, FileDirectory, FileFileDirectory
from datetime import date


filedirs = [FileDirectory(1, '/root/PyCharm Projects/lab1'),
            FileDirectory(2, '/root/PyCharm Projects/lab2'),
            FileDirectory(3, '/root/PyCharm Projects/lab3'),
            FileDirectory(4, '/root/Desktop/')]

files = [File(1, 'lab2.py', date(2023, 9, 23), date(2023, 9, 23), 'rasulov1337', 1024, 2),
         File(2, 'lab1.py', date(2023, 10, 19), date(2023, 10, 19), 'rasulov1337', 10, 1),
         File(3, 'readme.txt', date(2023, 10, 1), date(2023, 10, 15), 'root', 10, 3),
         File(4, '.gitignore', date(2023, 10, 24), date(2023, 10, 24), 'adam', 1, 1),
         File(5, 'main.py', date(2023, 10, 19), date(2023, 10, 19), 'rasulov1337', 1, 2),
         File(6, 'wallpaper.png', date(2023, 10, 20), date(2023, 10, 20), 'root', 1024 * 7, 4)]

filefiledirs = [FileFileDirectory(2, 1),
                FileFileDirectory(1, 2),
                FileFileDirectory(3, 3),
                FileFileDirectory(4, 1),
                FileFileDirectory(4, 2),
                FileFileDirectory(4, 3),
                FileFileDirectory(5, 1),
                FileFileDirectory(6, 4)]