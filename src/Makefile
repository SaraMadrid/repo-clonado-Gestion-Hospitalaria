CXX = g++
CXXFLAGS = -std=c++17 -Wall
TARGET = hospital_manager
SRC = src/main.cpp src/InterfazHospital.cpp src/Servicios.cpp src/Modelos.cpp
OBJ = $(SRC:.cpp=.o)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

clean:
	rm -f $(OBJ) $(TARGET)
