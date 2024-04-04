@echo off
setlocal EnableDelayedExpansion

:: Определение имен файлов
set testfile1=file1.txt
set testfile2=file2.txt
set testfile3=file3.txt
set testfile4=file4.txt
set testfile3=file5.txt
set testfile4=file6.txt
set exeName="cmake-build-debug/lab1.exe"

:: Создание исполняемого файла, если необходимо
:: g++ -o %exeName% compare_files/compare_files.cpp

:: Тест 1: Идентичные файлы
echo Test 1
echo Compare file1 and file2, files are similar 
%exeName% file1.txt file2.txt
echo.
echo.

:: Тест 2: Файлы различаются на второй строке
echo Test 2
echo Compare file3 and file4, files are different in 2 line
%exeName% file3.txt file4.txt
echo.

:: Тест 3: Подается один и тот же файл
echo Test 3
echo Compare file1 and file1, the same one
%exeName% file1.txt file1.txt
echo.
echo.

:: Тест 4: Подается два пустых файла
echo Test 4
echo Compare file5 and file6, both are empty
%exeName% file5.txt file6.txt
echo.
echo.

:: Тест 5: Подается файл формата не txt
echo Test 5
echo Get non txt files as arguments
%exeName% %exeName% %exeName%

endlocal
