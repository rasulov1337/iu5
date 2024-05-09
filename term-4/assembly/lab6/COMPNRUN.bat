@echo off
REM COMPILE & RUN
REM Простой код тупо для компиляции и запуска программы
REM Имя файла должно быть без расширения
SET FILENAME=LAB6_ADD
..\tasm3\tasm /l /zi /c /z %FILENAME%
..\tasm3\tlink /v /l /m %FILENAME%

REM Очистка от промежуточных файлов
IF EXIST %FILENAME%.MAP DEL  %FILENAME%.MAP
IF EXIST %FILENAME%.OBJ DEL  %FILENAME%.OBJ
IF EXIST %FILENAME%.LST DEL  %FILENAME%.LST
%FILENAME%.exe %1