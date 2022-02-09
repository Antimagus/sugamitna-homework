@echo off
for %%i in (*.cpp) do (
    g++ -c %%i -o Build/%%~ni.o
)