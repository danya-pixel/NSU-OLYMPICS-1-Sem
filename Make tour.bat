@echo off
set /p Tour="Tour: "

md Tour%Tour%

for /l %%i in (1,1,10) do if not exist Tour%Tour%/%%i.c nul > Tour%Tour%/%%i.c
        
