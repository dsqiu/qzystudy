 ###########################################
#Makefile for simple programs
###########################################
TOP = ../..
SRCDIR = $(TOP)/seqlist/code
MAINDIR= ../simple
CPPUNITDIR=/usr/local
INC = -I$(SRCDIR) -I$(MAINDIR) -I$(CPPUNITDIR)/include
LIB = $(CPPUNITDIR)/lib/libcppunit.a -ldl -lm

CC = g++
LD = g++
CC_FLAG = -Wall

PRG = seqlist
OBJ = seqlist_test.o $(MAINDIR)/Main.o

$(PRG):$(OBJ)
	$(LD) -o $@ $(OBJ) $(LIB)

.SUFFIXES: .c .o .cpp
.cpp.o:
	$(CC) $(CC_FLAG) $(INC) -c $*.cpp -o $*.o

.PRONY:clean
clean:
	@echo "Removing linked and compiled files......"
	rm -f $(OBJ) $(PRG)
