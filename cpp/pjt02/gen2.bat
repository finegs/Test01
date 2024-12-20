@echo off
setlocal enabledelayedexpansion

date /T > %1
echo Test Data Total Col:%2 >> %1
set MAX = %4


for /L %%i in ( 1,1, %3 ) do ( 
rem	set /a i10 = %%i * %4
rem	echo %%i, %date% %time% , !i10! >> %1 
rem	set /a t = %RANDOM% %% %4 + 1
rem    call:rand 1 %4
	echo %%i, %date% %time% , !random! >> %1 
)
