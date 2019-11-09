@echo off
setlocal enabledelayedexpansion

date /T > %1
echo Test Data Total Col:%2 >> %1


for /L %%i in ( 1,1, %3 ) do ( 
	set /a i10 = %%i * %4
	echo %%i, %date% %time% , !i10! >> %1 
)
