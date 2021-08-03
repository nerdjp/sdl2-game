CXX = g++
LIBS = -I/usr/include/SDL2 -lSDL2 -lSDL2main -lSDL2_image
SRCDIR = src
BINDIR = bin
OBJDIR = obj
_OBJ = main.o window.o
OBJ = $(patsubst %,$(OBJDIR)/%,$(_OBJ))

release: $(OBJ)
	$(CXX) $^ $(LIBS) -O3 -o $(BINDIR)/release/main-$@

debug: $(OBJ)
	$(CXX) $^ $(LIBS) -g -o $(BINDIR)/debug/main-$@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) -c $< -o $@
