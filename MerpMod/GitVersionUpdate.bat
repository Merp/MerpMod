"C:\Program Files\Git\bin\git.exe" describe --tags --long --always > tmpgithash
SET /p ghvar= <tmpgithash
DEL tmpgithash
ECHO #define GITVERSION %ghvar% > GitVersion.h