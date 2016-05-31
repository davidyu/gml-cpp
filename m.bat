@setlocal EnableDelayedExpansion

@set SRC=src
@set DIST=bin
@set TEST=test

@echo updating vendor code...

@pushd %TEST%\lib
call update
@popd

@echo building test code...

@if not exist %DIST% mkdir %DIST%

g++ -std=c++11 -I./src -I./test -o %DIST%/test.exe ./src/mat.cpp ./test/test.cpp
