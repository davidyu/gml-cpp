.PHONY: test

BIN=bin
SHELL=/bin/bash
CXX=g++
CFLAGS=-std=c++11 -I./src
TESTFLAGS=$(CFLAGS) -I./test
SRCCPP=$(shell find ./src -name "*.cpp")
TESTCPP=$(shell find ./test -name "*.cpp")

test:
	$(CXX) $(TESTFLAGS) -o $(BIN)/$@ $(SRCCPP) $(TESTCPP)
