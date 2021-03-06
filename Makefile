CXX = g++
CXXFLAGS = -fopenmp
LFLAGS = -lX11 -lGL -lpthread -lpng -lstdc++fs -std=c++17 -O3 -mavx2 
WFLAGS = -luser32 -lgdi32 -lopengl32 -lgdiplus -lShlwapi -ldwmapi -lstdc++fs -static -std=c++17 -O3 -mavx2 
FILE = app

all: $(FILE).cpp
	$(CXX) $(CXXFLAGS) $(FILE).cpp $(LFLAGS) -o app && make run
	
gen: $(FILE).cpp
	$(CXX) $(CXXFLAGS) $(FILE).cpp $(LFLAGS) -o app

genw: $(FILE).cpp
	$(CXX) $(CXXFLAGS) $(FILE).cpp $(WFLAGS) -o app

run: app
	./app

install:
	sudo apt-get install build-essential libglu1-mesa-dev libpng-dev

clean:
	rm -rf *.o
