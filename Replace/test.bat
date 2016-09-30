set PROGRAM="%~1"

rem ����⪠ �������� �ணࠬ�� � �ᯮ�짮������ ������������ �᫠ ��ࠬ��஢
%PROGRAM%
if %ERRORLEVEL% EQU 0 goto err

rem �஢���� ������ ��ப� � ���������饬 䠩��
%PROGRAM% null.txt %TEMP%\null.txt "some string" "some another string"
if %ERRORLEVEL% EQU 0 goto err

rem �஢���� ������ ��ப� � ���⮬ 䠩��
%PROGRAM% empty.txt %TEMP%\empty.txt "some string" "some another string"
if %ERRORLEVEL% EQU 0 goto err

rem �஢���� ������ ��ப� � 䠩��, ����饬 ���� ��ப�
%PROGRAM% one-line.txt %TEMP%\one-line.txt hardly hard
if %ERRORLEVEL% EQU 1 goto err
fc.exe %TEMP%\one-line.txt one-line.txt
if %ERRORLEVEL% EQU 0 goto err

rem �஢���� ������ ��ப� � 䠩��, ����饬 ��᪮�쪮 ��ப
%PROGRAM% multiline.txt %TEMP%\multiline.txt factories flowers
if %ERRORLEVEL% EQU 1 goto err
fc.exe %TEMP%\multiline.txt multiline.txt
if %ERRORLEVEL% EQU 0 goto err

rem �஢���� ������ ��ப� � 䠩��, ����饬 ���� ��ப�, �� �⮬ ������� ��᪮�쪮 ���������� ᫮�
%PROGRAM% one-line-multiword.txt %TEMP%\one-line-multiword.txt six five
if %ERRORLEVEL% EQU 1 goto err
fc.exe %TEMP%\one-line-multiword.txt one-line-multiword.txt
if %ERRORLEVEL% EQU 0 goto err

rem �஢���� ������ ��ப� � 䠩��, ����饬 ��᪮�쪮 ��ப, �� �⮬ ������� ��᪮�쪮 ���������� ᫮�
%PROGRAM% multiline-multiword.txt %TEMP%\multiline-multiword.txt that it
if %ERRORLEVEL% EQU 1 goto err                               
fc.exe %TEMP%\multiline-multiword.txt multiline-multiword.txt
if %ERRORLEVEL% EQU 0 goto err

rem mama test
%PROGRAM% mama.txt %TEMP%/mama.txt ma mama
if %ERRORLEVEL% EQU 1 goto err
fc.exe %TEMP%\mama.txt mama.txt
if %ERRORLEVEL% EQU 0 goto err


echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1