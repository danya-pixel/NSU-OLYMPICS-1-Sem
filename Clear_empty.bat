@echo off
for /D %%f in (Tour*) do for %%i in (%%f\*.c) do if %%~zi == 0 del /f %%i