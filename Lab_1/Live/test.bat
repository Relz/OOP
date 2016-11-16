set PROGRAM="%~1"

rem Проверка недостаточности параметров
%PROGRAM%
if %ERRORLEVEL% EQU 0 goto err

rem Проверка пустых параметров
%PROGRAM% "" ""
if %ERRORLEVEL% EQU 0 goto err

rem Проверка пустого параметра входного файла
%PROGRAM% "" out.txt
if %ERRORLEVEL% EQU 0 goto err

rem Проверка пустого параметра выходного файла
%PROGRAM% in0.txt ""
if %ERRORLEVEL% EQU 0 goto err

rem Тест неправильного игрового поля №1
%PROGRAM% in1.txt
if %ERRORLEVEL% EQU 0 goto err

rem Тест неправильного игрового поля №2
%PROGRAM% in2.txt
if %ERRORLEVEL% EQU 0 goto err

rem Тест неправильного игрового поля №3
%PROGRAM% in3.txt
if %ERRORLEVEL% EQU 0 goto err

rem Тест неправильного игрового поля №4
%PROGRAM% in4.txt
if %ERRORLEVEL% EQU 0 goto err

rem Проверка успешного вывода в стандартный поток
%PROGRAM% in0.txt
if %ERRORLEVEL% EQU 1 goto err

rem Проверка успешного вывода в выходной файл
%PROGRAM% in0.txt out.txt
if %ERRORLEVEL% EQU 1 goto err

rem Проверка движения клеток по диагонали вверх-направо
%PROGRAM% in5.txt out1.txt
if %ERRORLEVEL% EQU 1 goto err
%PROGRAM% out1.txt out2.txt
if %ERRORLEVEL% EQU 1 goto err
%PROGRAM% out2.txt out3.txt
if %ERRORLEVEL% EQU 1 goto err
%PROGRAM% out3.txt out4.txt
if %ERRORLEVEL% EQU 1 goto err
%PROGRAM% out4.txt out5.txt
if %ERRORLEVEL% EQU 1 goto err
%PROGRAM% out5.txt out6.txt
if %ERRORLEVEL% EQU 1 goto err
%PROGRAM% out6.txt out7.txt
if %ERRORLEVEL% EQU 1 goto err
%PROGRAM% out7.txt out8.txt
if %ERRORLEVEL% EQU 1 goto err
%PROGRAM% out8.txt out9.txt
if %ERRORLEVEL% EQU 1 goto err
%PROGRAM% out9.txt out10.txt
if %ERRORLEVEL% EQU 1 goto err
%PROGRAM% out10.txt out11.txt
if %ERRORLEVEL% EQU 1 goto err
%PROGRAM% out11.txt out12.txt
if %ERRORLEVEL% EQU 1 goto err
%PROGRAM% out12.txt out13.txt
if %ERRORLEVEL% EQU 1 goto err
%PROGRAM% out13.txt out14.txt
if %ERRORLEVEL% EQU 1 goto err
%PROGRAM% out14.txt out15.txt
if %ERRORLEVEL% EQU 1 goto err
%PROGRAM% out15.txt out16.txt
if %ERRORLEVEL% EQU 1 goto err
%PROGRAM% out16.txt out17.txt
if %ERRORLEVEL% EQU 1 goto err
%PROGRAM% out17.txt out18.txt
if %ERRORLEVEL% EQU 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1