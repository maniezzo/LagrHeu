CXX = g++
CXXFLAGS = -g -Wall -O -Wreorder
LDADD =

OBJ = main.o json.o GAP.o Lagrangian.o LocalSearch.o

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

main: $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o LagrHeu 

clean:
	rm -rf $(OBJ) LagrHeu

.PHONY: clean