CC = g++
CFLAGS = -std=c++11 -Wall

SRCDIR = .
OBJDIR = obj
BINDIR = bin

SRC_ARBOL_AVL = arbol_avl/ArbolAVL.cpp
SRC_CAMPO = campo/Campo.cpp
SRC_GRUPO = grupo/Grupo.cpp
SRC_NODO = nodo/Nodo.cpp
SRC_TABLA = tabla/TablaHash.cpp
SRC_TABLA_CAMPOS = tabla_campos/TablaHashCampos.cpp
SRC_GENERADORDOT = GeneradorDot.cpp
SRC_MAIN = main.cpp

OBJ_ARBOL_AVL = $(OBJDIR)/ArbolAVL.o
OBJ_CAMPO = $(OBJDIR)/Campo.o
OBJ_GRUPO = $(OBJDIR)/Grupo.o
OBJ_NODO = $(OBJDIR)/Nodo.o
OBJ_TABLA = $(OBJDIR)/TablaHash.o
OBJ_TABLA_CAMPOS = $(OBJDIR)/TablaHashCampos.o
OBJ_GENERADORDOT = $(OBJDIR)/GeneradorDot.o
OBJ_MAIN = $(OBJDIR)/main.o

TARGET = $(BINDIR)/main

all: directories $(TARGET)

directories:
	mkdir -p $(OBJDIR)
	mkdir -p $(BINDIR)

$(TARGET): $(OBJ_ARBOL_AVL) $(OBJ_CAMPO) $(OBJ_GRUPO) $(OBJ_NODO) $(OBJ_TABLA) $(OBJ_TABLA_CAMPOS) $(OBJ_GENERADORDOT) $(OBJ_MAIN)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/ArbolAVL.o: $(SRCDIR)/$(SRC_ARBOL_AVL)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/Campo.o: $(SRCDIR)/$(SRC_CAMPO)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/Grupo.o: $(SRCDIR)/$(SRC_GRUPO)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/Nodo.o: $(SRCDIR)/$(SRC_NODO)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/TablaHash.o: $(SRCDIR)/$(SRC_TABLA)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/TablaHashCampos.o: $(SRCDIR)/$(SRC_TABLA_CAMPOS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/GeneradorDot.o: $(SRCDIR)/$(SRC_GENERADORDOT)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/main.o: $(SRCDIR)/$(SRC_MAIN)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJDIR) $(BINDIR)
