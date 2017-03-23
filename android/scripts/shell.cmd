SET CURDIR=%~dp0
call %CURDIR%\env.cmd
SET PATH=%CMAKE_HOME%\bin;%PATH%
%HOMEDRIVE%
rem pushd %CURDIR%
start powershell.exe
start cmd
popd


