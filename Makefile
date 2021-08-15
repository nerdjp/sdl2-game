CXX = g++
LIBS = -I/usr/include/SDL2 -lSDL2 -lSDL2main -lSDL2_image
CFLAGS = -g -Wall
NAME = main
SRCDIR = src
BINDIR = bin
OBJDIR = obj
INCDIR = include
SRCSUBDIR = $(wildcard $(SRCDIR)/*/)
OBJSUBDIR = $(patsubst $(SRCDIR)/%/, $(OBJDIR)/%/, $(SRCSUBDIR))
INCSUBDIR = $(wildcard $(INCDIR)/*/)
SRC = $(wildcard $(SRCDIR)/*.cpp $(foreach fd, $(SRCSUBDIR), $(fd)*.cpp))
BIN = $(BINDIR)/$(NAME)
OBJ = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRC))
INC = $(wildcard $(INCDIR)/*.hpp $(foreach fd, $(INCSUBDIR), $(fd)/*.hpp))
INCFLAGS = $(addprefix -I, $(INCDIR)) $(addprefix -I, $(INCSUBDIR))

all: $(BINDIR) $(BIN)

release: CFLAGS=-Wall -O3 -s
release: clean
release: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $^ $(CFLAGS) $(LIBS) -o $@

#$(INC) $(OBJDIR) $(OBJSUBDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CFLAGS) $(INCFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $@

$(OBJSUBDIR):
	mkdir -p $@

$(BINDIR):
	mkdir -p $@

clean:
	$(RM) -r $(OBJDIR)
	$(RM) -r $(BINDIR)
