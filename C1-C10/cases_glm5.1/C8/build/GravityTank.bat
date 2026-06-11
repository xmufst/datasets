@echo off
SET PATH=;D:/software/OpenModelica1.25.5-64bit/bin/;%PATH%;
SET ERRORLEVEL=
CALL "%CD%/GravityTank.exe" %*
SET RESULT=%ERRORLEVEL%

EXIT /b %RESULT%
