BUILD = release

CXX = g++
BIN = prog.exe
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -DBUILD_DLL
LDFLAGS = -luser32 -s

ifeq ($(BUILD), release)
	CXXFLAGS += -O2 -s
else
	CXXFLAGS += -g -Og
endif

all: $(BIN) test1 test2 test3
	@echo Program built, running...
	@echo.
	$(BIN)

prog.exe: main.o
	$(CXX) $^ -o $@ $(LDFLAGS)
main.o: main.cpp main.hpp
	$(CXX) -c main.cpp -o main.o -std=c++11 -Wall -Wextra -pedantic -O2 -s

test1: test1.o
	if not exist .\plugins ( mkdir .\plugins )
	$(CXX) -shared -Wl,--dll $^ -o .\plugins\test1.dll $(LDFLAGS)
test2: test2.o
	if not exist .\plugins ( mkdir .\plugins )
	$(CXX) -shared -Wl,--dll $^ -o .\plugins\test2.dll $(LDFLAGS)
test3: test3.o
	if not exist .\plugins ( mkdir .\plugins )
	$(CXX) -shared -Wl,--dll $^ -o .\plugins\test3.dll $(LDFLAGS)

clean:
	del *.o
	del $(BIN)
	rd /Q /S .\plugins

.PHONY: clean