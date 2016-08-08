CXXFLAGS=-g3
SRCS=scc.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: scc

scc: $(OBJS)
	$(CXX) $(LDFLAGS) -o scc $(OBJS) $(LDLIBS)

scc.o: scc.cpp

clean:
	$(RM) $(OBJS) scc
