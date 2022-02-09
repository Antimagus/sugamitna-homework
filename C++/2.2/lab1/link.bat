@echo off
set obj = ""
for %%i in (Build/*.o) do (
    call :concat %%i
)

cd Build
g++ %obj% -o main.exe

goto :eof

:concat
set obj=%obj% %1
goto :eof