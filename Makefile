CXX = g++
CXXFLAGS = -std=c++11 -Iinclude
LIBS = -lcurl -ljsoncpp
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# List of source files
SRCS = $(wildcard $(SRCDIR)/*.cpp)

# List of object files
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

# Final executable
TARGET = $(BINDIR)/my_program

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all clean
