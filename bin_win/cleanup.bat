REM Delete Linux temporary build files

DEL ..\rehash\*.o
DEL ..\src_algo\*.o

REM Delete intermediate Linux binary output files

DEL ..\bin_lx\rehash

REM Delete Windows temporary build files

DEL debug\*.ilk
DEL debug\*.obj
DEL debug\*.pch
DEL debug\*.pdb
DEL debug\*.idb
DEL release\*.ilk
DEL release\*.obj
DEL release\*.pch
DEL release\*.pdb
DEL release\*.idb
