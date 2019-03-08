CXX = g++
CXXFLAGS = `Magick++-config --cxxflags --cppflags` -O2 -Wall
LIBS=`Magick++-config --ldflags --libs`
SRC = readImage.cpp
OBJFILES = readImage.o
TARGET = readImage

all: $(TARGET)
	@echo $(TARGET) build finished.
$(TARGET): $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) $(LIBS) 
clean:
	rm -f $(OBJFILES) $(TARGET) *~