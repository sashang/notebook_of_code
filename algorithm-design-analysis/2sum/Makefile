CXXFLAGS=-g3
SRCS=two-sum.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: two-sum

two-sum: $(OBJS)
	$(CXX) $(LDFLAGS) -o two-sum $(OBJS) $(LDLIBS)

two-sum.o: two-sum.cpp

clean:
	$(RM) $(OBJS) two-sum
