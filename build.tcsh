#!/usr/bin/tcsh

set ExecName=cooper

setenv PATH /faculty/andrews/Qt-4.6.0/bin:$PATH
setenv LD_LIBRARY_PATH /faculty/andrews/Qt-4.6.0/lib:$LD_LIBRARY_PATH

alias TEH_FAILZ0RZ "echo Build of $ExecName FAILED. ; exit 1"

if ($# != 0) then
  echo Usage: $0
  exit 1
endif

echo "Removing intermediate files..."
rm -f *.o $ExecName Makefile *.pro moc_*

if (-r QmakeSwitches.txt) then
  echo "Running qmake -project"
  echo "with switches" `cat QmakeSwitches.txt`
  qmake -project `cat QmakeSwitches.txt`
else
  echo "Running qmake -project ..."
  qmake -project
endif

echo "Running qmake ..."
qmake

echo "Running gmake ..."
gmake

if (-r $ExecName) then
  echo "Build of $ExecName SUCCEEDED."
else
  echo "ERROR: no file '$ExecName' built."
  TEH_FAILZ0RZ
endif

exit 0

