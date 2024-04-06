@echo off

rem Тесты
call :test "110010000"
call :test "11001002"
call :test "110010000 111"

:test
    echo Testing: "%~1"
    for /f "delims=" %%i in ('bin2dec.exe "%~1"') do set "output=%%i"

    for /f %%i in ('powershell -command "[Convert]::ToInt32('%~1', 2)"') do set expectedResult=%%i

    echo %expectedResult% | findstr /R /C:"^[0-9]*$" > expected_clean.txt
    set /p expectedResult=<expected_clean.txt

    if "%output%" equ "%expectedResult%" (
            echo Results match.
            echo Received: %output%.
            echo Expected: %expectedResult%.
        ) else (
            echo Results do not match.
            echo Received: %output%.
            echo Expected: %expectedResult%.
        )

        echo.
    goto :eof
