set PROGRAM="%~1"

rem �஢�ઠ �������筮�� ��ࠬ��஢
%PROGRAM%
if %ERRORLEVEL% EQU 0 goto err

rem ��ॢ�� �᫠ 12 �� 3679-�� ��⥬� ��᫥��� � 2-��
%PROGRAM% 3679 2 12
if %ERRORLEVEL% EQU 0 goto err

rem ��ॢ�� �᫠ 10102 �� 2-�� ��⥬� ��᫥��� � 34-��
%PROGRAM% 2 34 10102
if %ERRORLEVEL% EQU 0 goto err

rem ��ॢ�� �᫠ -12 �� 3-�� ��⥬� ��᫥��� � 2-��
%PROGRAM% 3 2 -12
if %ERRORLEVEL% EQU 1 goto err

rem ��ॢ�� �᫠ -10010101011 �� 2-�� ��⥬� ��᫥��� � 36-��
%PROGRAM% 2 36 -10010101011
if %ERRORLEVEL% EQU 1 goto err

rem ��ॢ�� �᫠ OSIZ �� 36-�� ��⥬� ��᫥��� � 8-��
%PROGRAM% 36 8 OSIZ
if %ERRORLEVEL% EQU 1 goto err

rem ��ॢ�� �᫠ FHJDOSIZ �� 36-�� ��⥬� ��᫥��� � 8-��
%PROGRAM% 36 8 FHJDOSIZ
if %ERRORLEVEL% EQU 0 goto err


echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1