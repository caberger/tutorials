SET CURDIR=%~dp0
call %CURDIR%\env.cmd
SET PATH=%CMAKE_HOME%\bin;%PATH%
%HOMEDRIVE%
pushd %CURDIR%
rem start powershell.exe
start cmd
popd


