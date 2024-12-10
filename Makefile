#Madison Bennett
#id: 824800113

##Alyssa Rivera
##id: 825469587

##Linh Tran
##id: 828187432

# CXX Make variable for compiler
CXX=g++
# -std=c++17  C/C++ variant to use, e.g. C++ 2017
# -Wall       show the necessary warning files
# -g3         include information for symbolic debugger e.g. gdb 
CXXFLAGS=-std=c++17 -Wall -g3 -c -g

# object files
OBJS = TemperatureReader.o TeaTimer.o main.o

# Program name
PROGRAM = steeperAgent

$(PROGRAM) : $(OBJS)
	$(CXX) -o $(PROGRAM) $^

TemperatureReader.o : TemperatureReader.h TemperatureReader.cpp
	$(CXX) $(CXXFLAGS) TemperatureReader.cpp

TeaTimer.o : TemperatureReader.h TeaTimer.h TeaTimer.cpp
	$(CXX) $(CXXFLAGS) TeaTimer.cpp

main.o : TemperatureReader.h TeaTimer.h main.cpp
	$(CXX) $(CXXFLAGS) main.cpp
	
clean :
	rm -f *.o $(PROGRAM)
