@echo off
set dev=COM3
mode %dev%:data=8 to=off xon=off odsr=off octs=off dtr=off rts=off idsr=off > NUL
if exist %1 copy /b %1 %dev%
