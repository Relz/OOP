set PROGRAM="%~1"

rem �஢�ઠ �������筮�� ��ࠬ��஢
%PROGRAM%
if %ERRORLEVEL% EQU 0 goto err

rem �஢�ઠ ������ ��ࠬ��஢
%PROGRAM% "" ""
if %ERRORLEVEL% EQU 0 goto err

rem �஢�ઠ ���⮣� ��ࠬ��� �室���� 䠩��
%PROGRAM% "" out.txt
if %ERRORLEVEL% EQU 0 goto err

rem �஢�ઠ ���⮣� ��ࠬ��� ��室���� 䠩��
%PROGRAM% in0.txt ""
if %ERRORLEVEL% EQU 0 goto err

rem ���� ���ࠢ��쭮�� ��஢��� ���� �1
%PROGRAM% in1.txt
if %ERRORLEVEL% EQU 0 goto err

rem ���� ���ࠢ��쭮�� ��஢��� ���� �2
%PROGRAM% in2.txt
if %ERRORLEVEL% EQU 0 goto err

rem ���� ���ࠢ��쭮�� ��஢��� ���� �3
%PROGRAM% in3.txt
if %ERRORLEVEL% EQU 0 goto err

rem ���� ���ࠢ��쭮�� ��஢��� ���� �4
%PROGRAM% in4.txt
if %ERRORLEVEL% EQU 0 goto err

rem �஢�ઠ �ᯥ譮�� �뢮�� � �⠭����� ��⮪
%PROGRAM% in0.txt
if %ERRORLEVEL% EQU 1 goto err

rem �஢�ઠ �ᯥ譮�� �뢮�� � ��室��� 䠩�
%PROGRAM% in0.txt out.txt
if %ERRORLEVEL% EQU 1 goto err

rem �஢�ઠ �������� ���⮪ �� ��������� �����-���ࠢ�
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