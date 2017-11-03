DEL ..\dist_lx\rehash
DEL ..\dist_lx\*.htm
DEL ..\dist_lx\*.html
DEL ..\dist_lx\*.txt
DEL ..\dist_lx\*.css
DEL ..\dist_lx\*.jpg

COPY /B ..\bin_lx\rehash /B ..\dist_lx\rehash
COPY /B ..\docs\license.txt /B ..\dist_lx\license.txt
COPY /B ..\docs\rehash.html /B ..\dist_lx\rehash.html
COPY /B ..\docs\rehash.jpg /B ..\dist_lx\rehash.jpg
COPY /B ..\docs\rehash.css /B ..\dist_lx\rehash.css
