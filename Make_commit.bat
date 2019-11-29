@echo off
set /p Message="Message for commit: "
for /D %%f in (Tour*) do for %%i in (%%f\*.c) do if %%~zi == 0 del /f %%i
git add .
git commit -m %Message%
