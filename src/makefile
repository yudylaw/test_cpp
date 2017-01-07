CXX = g++
CFLAGS = -g -Wall -std=c++11
TARGET = test
INC = -I./
LIBS = -L../lib -lopen_platform -lcrypto -pthread

OBJECTS = $(patsubst %.cpp, %.o, $(notdir $(wildcard *.cpp)))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo -e "\033[1;33m\n$(OBJECTS) ==> $@ \033[0m..."
	$(CXX) -o $@ $^ $(CFLAGS) $(LIBS)
	@echo

%.o: %.cpp
	@echo -e "\033[1;33m\nCompiling $< ==> $@ \033[0m..."
	$(CXX) $(INC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	rm -f $(TARGET)

.PHONY: clean
