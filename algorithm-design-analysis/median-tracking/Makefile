CXXFLAGS=-g3
SRCS=median.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: median

median: $(OBJS)
	$(CXX) $(LDFLAGS) -o median $(OBJS) $(LDLIBS)

median.o: median.cpp

clean:
	$(RM) $(OBJS) median
