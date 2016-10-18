set PROGRAM="%~1"

rem Попытка запустить программу с использованием неожидаемого числа параметров
%PROGRAM%
if %ERRORLEVEL% EQU 0 goto err

rem Прочитаем матрицу из несуществующего файле
%PROGRAM% null.txt
if %ERRORLEVEL% EQU 0 goto err

rem Прочитаем матрицу из пустого файла
%PROGRAM% empty.txt
if %ERRORLEVEL% EQU 0 goto err

rem Прочитаем матрицу из файла, в котором недостаточно элементов для её заполнения
%PROGRAM% in0.txt
if %ERRORLEVEL% EQU 0 goto err

rem Прочитаем матрицу из файла, в котором слишком много элементов для её заполнения
%PROGRAM% in1.txt
if %ERRORLEVEL% EQU 0 goto err

rem Прочитаем матрицу букв из файла
%PROGRAM% in2.txt
if %ERRORLEVEL% EQU 0 goto err

rem Прочитаем правильную матрицу положительных целых чисел из файла
%PROGRAM% in3.txt
if %ERRORLEVEL% EQU 1 goto err

rem Прочитаем правильную матрицу отрицательных целых чисел из файла
%PROGRAM% in4.txt
if %ERRORLEVEL% EQU 1 goto err

rem Прочитаем правильную матрицу любых целых чисел из файла
%PROGRAM% in5.txt
if %ERRORLEVEL% EQU 1 goto err

rem Прочитаем матрицу переполняющих тип double чисел из файла
%PROGRAM% in6.txt
if %ERRORLEVEL% EQU 0 goto err

rem Прочитаем правильную матрицу любых чисел из файла
%PROGRAM% in7.txt
if %ERRORLEVEL% EQU 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1