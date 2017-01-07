GXX = g++
CFLAGS = -g -Wall -std=c++11
TARGET = test
INC = -I./

OBJECTS = $(patsubst %.cpp, %.o, $(notdir $(wildcard *.cpp)))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo -e "\033[1;33m\n$(OBJECTS) ==> $@ \033[0m..."
	$(GXX) -o $@ $^ $(CFLAGS) $(LIBS)
	@echo

%.o: %.cpp
	@echo -e "\033[1;33m\nCompiling $< ==> $@ \033[0m..."
	$(GXX) $(INC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	rm -f $(TARGET)

.PHONY: clean
