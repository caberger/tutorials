@echo off

set KEY="HKLM\SOFTWARE\JavaSoft\Java Development Kit"
set VALUE=CurrentVersion

setlocal
::- Get the Java Version
reg query %KEY% /v %VALUE% 2>nul || (
    echo Error: JDK not installed
    exit /b 1
)
set JDK_VERSION=
for /f "tokens=2,*" %%a in ('reg query %KEY% /v %VALUE% ^| findstr %VALUE%') do (
    set JDK_VERSION=%%b
)

::- Get JavaHome
set KEY="HKLM\SOFTWARE\JavaSoft\Java Development Kit\%JDK_VERSION%"
set VALUE=JavaHome
reg query %KEY% /v %VALUE% 2>nul || (
    echo JavaHome not installed
    exit /b 1
)

set JAVAHOME=
for /f "tokens=2,*" %%a in ('reg query %KEY% /v %VALUE% ^| findstr %VALUE%') do (
    set JAVAHOME=%%b
)

endlocal & set JAVA_HOME=%JAVAHOME%
"%JAVA_HOME%\bin\java" -version
