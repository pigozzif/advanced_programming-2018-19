CXX=c++
SRC=source/hello.cc
OBJ=$(SRC:.cc=.o)
DEST=/home/usr/local

all: libexercise.so

libexercise.so: $(OBJ)
	$(CXX) -shared -o $@ $^

%.o:%.cc
	$(CXX) -fpic -o $@ -c $^ -I include

source/hello.cc: include/hello.h

install: libexercise.so
	mv -t $(DEST) $<
