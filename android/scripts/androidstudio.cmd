SET CURDIR=%~dp0
call %CURDIR%\env.cmd

%HOMEDRIVE%
pushd "%ProgramFiles%\Android\Android Studio\bin\"
start studio64.exe
popd


