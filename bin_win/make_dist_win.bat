DEL ..\dist_win\*.exe
DEL ..\dist_win\*.htm
DEL ..\dist_win\*.html
DEL ..\dist_win\*.txt
DEL ..\dist_win\*.jpg
DEL ..\dist_win\*.css

IF EXIST release\rehash.exe COPY /B release\rehash.exe /B ..\dist_win\rehash.exe
IF NOT EXIST release\rehash.exe COPY /B debug\rehash.exe /B ..\dist_win\rehash.exe

COPY /B ..\docs\license.txt /B ..\dist_win\license.txt
COPY /B ..\docs\rehash.html /B ..\dist_win\rehash.html
COPY /B ..\docs\rehash.css /B ..\dist_win\rehash.css
COPY /B ..\docs\rehash.jpg /B ..\dist_win\rehash.jpg
