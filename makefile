CPPFLAGS=-std=c++17
IPATH=-Iinc/
SRC=src/
OBJ=obj/

all: app

app: main.gch  Graph.gch
	g++ $(OBJ)main.gch $(OBJ)Graph.gch -o app

main.gch: $(SRC)main.cpp
	$(CHAIN)-gcc $(CPPFLAGS) $(IPATH) -c $(SRC)main.cpp -o $(OBJ)main.gch
                                        
	
Graph.gch: $(SRC)Graph.cpp 
	g++ $(CPPFLAGS) $(IPATH) -c $(SRC)Graph.cpp -o $(OBJ)Graph.gch
	
clean:
	rm -rf $(OBJ)*.gch

