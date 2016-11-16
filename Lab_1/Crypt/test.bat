set PROGRAM="%~1"

rem ������� ��������� ��������� � �������������� ������������ ����� ����������
%PROGRAM%
if %ERRORLEVEL% EQU 0 goto err

rem ������� ��������� ��������� � �������������� ������ ����������
%PROGRAM% "" "" ""
if %ERRORLEVEL% EQU 0 goto err

rem ������� ��������� ��������� � �������������� ������� ��������� �������� �����
%PROGRAM% "" out.txt 242
if %ERRORLEVEL% EQU 0 goto err

rem ������� ��������� ��������� � �������������� ������� ��������� ��������� �����
%PROGRAM% in.txt "" 123
if %ERRORLEVEL% EQU 0 goto err

rem ������� ��������� ��������� � �������������� ������� ��������� ����� �����
%PROGRAM% in.txt out.txt ""
if %ERRORLEVEL% EQU 0 goto err

rem ��������� �������������� ����
%PROGRAM% null.txt out.txt 213
if %ERRORLEVEL% EQU 0 goto err

rem ��������� ������ ����
%PROGRAM% empty.txt out.txt 19
if %ERRORLEVEL% EQU 0 goto err

rem ���� ����������
%PROGRAM% in.txt in_encoded.txt 98
if %ERRORLEVEL% EQU 1 goto err
%PROGRAM% in_encoded.txt in_decoded.txt 98
if %ERRORLEVEL% EQU 1 goto err
fc.exe in.txt in_decoded.txt
if %ERRORLEVEL% NEQ 0 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1