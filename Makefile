# the compiler to use.
COMPILER=clang++

# include path
INCLUDE=-I./

# program souce files
SOURCES=

# build source
BUILD_SOUCES=$(SOURCES)

# test source files
TEST_SOURCES=$(SOURCES) tests/*.cpp

# depencences
LIBS=-lgtest

# flags for compiling
FLAGS=-std=c++11

# executable name
TEST_EXEC=test.out

all: test

test: $(TEST_SOURCES)
	$(COMPILER) -o $(TEST_EXEC) $(TEST_SOURCES) $(INCLUDE) $(LIBS) $(FLAGS)
	./$(TEST_EXEC)

clean:
	rm -rf *.o $(EXECUTABLE) $(TEST_EXEC)