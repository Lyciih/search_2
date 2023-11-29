CFLAG = -Wall -g -I include -MD

COMPUTE_SERVER_SRCS = $(wildcard src/compute_server/*.cpp)
COMPUTE_SERVER_OBJS = $(patsubst src/compute_server/%.cpp, obj/compute_server/%.o, ${COMPUTE_SERVER_SRCS})
COMPUTE_SERVER_DEPS = $(COMPUTE_SERVER_OBJS:.o=.d)

all:flow_compute_server

-include $(COMPUTE_SERVER_DEPS)

flow_compute_server: $(COMPUTE_SERVER_OBJS)
	g++ $(CFLAG) -o $@ $^

obj/%.o: src/%.cpp
	g++ $(CFLAG) -c $< -o $@

.PHONY: clean run re

clean:
	rm -f flow_compute_server obj/compute_server/*.o obj/compute_server/*.d

run:
	./flow_compute_server

re: clean all run
	
