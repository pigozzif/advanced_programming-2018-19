EXE = exe

LFLAGS = -lnecessary -L .
CXX = g++
CXXFLAGS = -std=c++11 -I include

SRC = src/src1.o src/src2.o main.o
OBJ = $(SRC:.cc=.o)

all: $(EXE) libnecessary.so

libnecessary.so: $(OBJ)
	$(CXX) -shared -o $@ $^

%.o: %.cc
	$(CXX) -fpic -c $< -o $@ $(CXXFLAGS)


$(EXE): $(SRC)
	$(CXX) $^ -o $(EXE) $(LFLAGS)

main.o: src/src1.o src/src2.o include/foo.h include/utility.h

#src/src1.o: include/utility.h
#src/src2.o: include/utility.h

clean:
	rm -rf src/*.o main.o $(EXE) */*~ *~

.PHONY: clean all


