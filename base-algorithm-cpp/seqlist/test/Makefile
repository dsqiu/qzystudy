 ###########################################
#Makefile for simple programs
###########################################
TOP = ..
SRCDIR = $(TOP)/code
INC = -I$(SRCDIR)
LIB =  -ldl -lm

CC = g++
LD = g++
CC_FLAG = -Wall

PRG = seqlisttest
OBJ = seqlisttest.o

$(PRG):$(OBJ)
	$(LD) -o $@ $(OBJ) $(LIB)

.SUFFIXES: .c .o .cpp
.cpp.o:
	$(CC) $(CC_FLAG) $(INC) -c $*.cpp -o $*.o

.PRONY:clean
clean:
	@echo "Removing linked and compiled files......"
	rm -f $(OBJ) $(PRG)
