CPP=icc
CPPFLAGS=-Qoption,cpp,--extended_float_type -O2
QUADLIB=libquad_x86_64.a
LIBS= -lifcore ../lib/$(QUADLIB)

all: quad_example

quad_example: quad_example.cpp ../lib/$(QUADLIB)
	$(CPP) quad_example.cpp -o quad_example $(CPPFLAGS) $(LIBS)

