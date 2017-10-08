"C:\Program Files\Git\bin\git.exe" describe --always > tmpgithash
SET /p ghvar= <tmpgithash
DEL tmpgithash
ECHO #define GITHASH %ghvar% > GITHASH.h