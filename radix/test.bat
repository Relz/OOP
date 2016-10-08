set PROGRAM="%~1"

rem Проверка недостаточности параметров
%PROGRAM%
if %ERRORLEVEL% EQU 0 goto err

rem Проверка пустых параметров
%PROGRAM% "" "" ""
if %ERRORLEVEL% EQU 0 goto err

rem Проверка пустого параметра исходной системы счисления
%PROGRAM% "" 2 543
if %ERRORLEVEL% EQU 0 goto err

rem Проверка пустого параметра выходной системы счисления
%PROGRAM% 2 "" 010100
if %ERRORLEVEL% EQU 0 goto err

rem Проверка пустого параметра исходного числа
%PROGRAM% 2 10 ""
if %ERRORLEVEL% EQU 0 goto err

rem Перевод числа 12 из 3679-ой системы счисления в 2-ую
%PROGRAM% 3679 2 12
if %ERRORLEVEL% EQU 0 goto err

rem Перевод числа 11 из 2-ой системы счисления в 200-ую
%PROGRAM% 2 200 11
if %ERRORLEVEL% EQU 0 goto err

rem Перевод числа 12 из 999999999999999999-ой системы счисления в 2-ую
%PROGRAM% 999999999999999999 2 12
if %ERRORLEVEL% EQU 0 goto err

rem Перевод числа 11 из 2-ой системы счисления в 999999999999999999-ую
%PROGRAM% 2 999999999999999999 11
if %ERRORLEVEL% EQU 0 goto err

rem Перевод числа 10102 из 2-ой системы счисления в 34-ую
%PROGRAM% 2 34 10102
if %ERRORLEVEL% EQU 0 goto err

rem Перевод числа -12 из 3-ой системы счисления в 2-ую
%PROGRAM% 3 2 -12
if %ERRORLEVEL% EQU 1 goto err

rem Перевод числа -10010101011 из 2-ой системы счисления в 36-ую
%PROGRAM% 2 36 -10010101011
if %ERRORLEVEL% EQU 1 goto err

rem Перевод числа OSIZ из 36-ой системы счисления в 8-ую
%PROGRAM% 36 8 OSIZ
if %ERRORLEVEL% EQU 1 goto err

rem Перевод числа FHJDOSIZ из 36-ой системы счисления в 8-ую
%PROGRAM% 36 10 ZZZZZZZZFHJDOSIZZZZZZ
if %ERRORLEVEL% EQU 0 goto err


echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1