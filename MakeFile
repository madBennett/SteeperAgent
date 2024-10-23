#Madison Bennett
#id: 824800113

##ADD YOURS

# CXX Make variable for compiler
CXX=g++
# -std=c++11  C/C++ variant to use, e.g. C++ 2011
# -Wall       show the necessary warning files
# -g3         include information for symbolic debugger e.g. gdb 
CXXFLAGS=-std=c++11 -Wall -g3 -c -g

# object files
OBJS = TeaTimer.o main.o

# Program name
PROGRAM = steeperAgent

$(PROGRAM) : $(OBJS)
	$(CXX) -o $(PROGRAM) $^

TeaTimer.o : TeaTimer.h TeaTimer.cpp
	$(CXX) $(CXXFLAGS) TeaTimer.cpp

main.o : TeaTimer.h main.cpp
	$(CXX) $(CXXFLAGS) main.cpp
	
clean :
	rm -f *.o $(PROGRAM)
