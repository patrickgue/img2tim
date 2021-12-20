TARGET=img2tim
SRCS=main.cpp tim.cpp
OBJS=$(SRCS:.cpp=.o)

CXX=c++

LDFLAGS=-lfreeimage

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)


%.o:%.c
	$(CXX) -O2 $^ -c -o $@

clean:
	rm -f *.o $(TARGET)

install: $(TARGET)
	cp $(TARGET) /usr/local/bin
