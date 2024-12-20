@echo off
for /L %%i in ( 1,1, %1 ) do ( echo Name_%%i,%RANDOM%,NickName_%%i >> infile.csv )
