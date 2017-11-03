##
# Linux Makefile for ReHash
#
# Dependencies:
#	none
# Notes:
#	none
##

OUTPUT = ../bin_lx/rehash
SOURCES = $(wildcard ../rehash/*.cpp) $(wildcard ../src_algo/*.cpp)
OBJECTS = $(patsubst %.cpp,%.o,$(SOURCES))
CC = gcc
LINK = g++
CFLAGS = -g -O2 -frtti -fexceptions -I./ -I./../ -I./../rehash/ -I./../src_algo/
LFLAGS = -L/usr/lib -L/usr/local/lib/

.PHONEY: all clean

all: $(OUTPUT)

clean:
	-rm $(OBJECTS)

$(OUTPUT): $(OBJECTS)
	$(LINK) $(LFLAGS) -o $@ $+

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<
