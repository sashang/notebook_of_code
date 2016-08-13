CXXFLAGS=-g3
SRCS=dijkstra.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: dijkstra

dijkstra: $(OBJS)
	$(CXX) $(LDFLAGS) -o dijkstra $(OBJS) $(LDLIBS)

dijkstra.o: dijkstra.cpp

clean:
	$(RM) $(OBJS) dijkstra
