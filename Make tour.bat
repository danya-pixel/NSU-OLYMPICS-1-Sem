set /p Tour="Tour: "

md Tour%Tour%

for /l %%i in (1,1,10) do echo nul>>Tour%Tour%/%%i".c"
        
