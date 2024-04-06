@echo off
SETLOCAL enableextensions enabledelayedexpansion
:: Определение имен файлов
set exeName="compare.exe"



:: Тест 1: Идентичные файлы
echo ----------------------------------------
echo Test 1
echo Compare file1 and file2, files are similar 
call :Test file1.txt file2.txt
echo.

:: Тест 2: Файлы различаются на второй строке
echo ----------------------------------------
echo Test 2
echo Compare file3 and file4, files are different in 2 line
call :Test file3.txt file4.txt
echo.

:: Тест 3: Подается один и тот же файл
echo ----------------------------------------
echo Test 3
echo Compare file1 and file1, the same one
call :Test file1.txt file1.txt
echo.

:: Тест 4: Подается два пустых файла
echo ----------------------------------------
echo Test 4
echo Compare file5 and file6, both are empty
call :Test file5.txt file6.txt
echo.

:: Тест 5: Подается файл формата не txt
echo ----------------------------------------
echo Test 5
echo Get non txt files as arguments
call :Test compare.exe file6.txt
echo.

:: Тест 6: Подается просто строка а не имя файла с его расширением
echo ----------------------------------------
echo Test 6
echo Get string, not file_name(file_path)
call :Test file5 file6


:Test <file1> <file2>

%exeName% %1 %2
echo %ErrorLevel% >> output.txt
fc %1 %2 >nul
echo %ErrorLevel% >> outputfc.txt

set /p resp=<output.txt
set /p respfc=<outputfc.txt

if !resp! == !respfc! (echo SUCCESS) else (echo FAIL)
echo ----------------------------------------

break>output.txt
break>outputfc.txt
goto :eof

endlocal

