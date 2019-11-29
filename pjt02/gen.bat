@echo off
for /L %%i in ( 1,1, %1 ) do ( echo Name_%%i,%%i,NickName_%%i >> infile.csv )