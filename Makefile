CXX = g++
LIBS = -I/usr/include/SDL2 -lSDL2 -lSDL2main -lSDL2_image
SRCDIR = src
BINDIR = bin
BLDDIR = build
OBJ = main.o

release: $(OBJ)
	$(CXX) $(BLDDIR)/*.o $(LIBS) -O3 -o $(BINDIR)/release/main

debug: $(OBJ)
	$(CXX) $(BLDDIR)/*.o $(LIBS) -g -o $(BINDIR)/debug/main

%.o: $(SRCDIR)/%.cpp
	$(CXX) -c $(SRCDIR)/*.cpp -o $(BLDDIR)/*.o
