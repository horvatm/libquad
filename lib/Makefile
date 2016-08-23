CPP=icc
F90=ifort
FFLAGS=-O2
CPPFLAGS=-O2 -Wall
RM=/bin/rm
AR=/usr/bin/ar
ARCH=$(shell uname -m)

SRCS=$(wildcard *.f90)
OBJS=$(SRCS:.f90=.o)
LIB=libquad_$(ARCH).a

all: $(LIB)

%.o: %.f90
	$(F90) $(FFLAGS) -c $< -o $@

%.a: $(OBJS)
	$(RM) -f $@
	$(AR) -r $@ $^

clean:
	rm -f libquad_*.a *.o
