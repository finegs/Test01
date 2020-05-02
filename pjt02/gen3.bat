
@echo off
setlocal enabledelayedexpansion

echo %2 > %1


for /L %%i in ( 1, 1, %2 ) do ( 
	echo !random! >> %1 
)
