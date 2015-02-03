
CXXFLAGS=-O3 -m64

COLORMAPS=grayscaleLinear grayscaleLogarithmic yahooColorMap
FRACTALS=mandlebrot

# Command to print a variable
#Test=$(COLORMAPS:%=./obj/ColorMap/%.o)
#$(info $$Test is [${Test}])

./bin/FractalVisualizer: ./obj/visualizer.o ./obj/colorMap.o ./obj/plot.o $(COLORMAPS:%=./obj/ColorMaps/%.o) $(FRACTALS:%=./obj/Fractals/%.o)
	g++ $(CXXFLAGS) -o ./bin/FractalVisualizer ./obj/visualizer.o ./obj/plot.o ./obj/colorMap.o $(COLORMAPS:%=./obj/ColorMaps/%.o) $(FRACTALS:%=./obj/Fractals/%.o) -I/usr/local/include/ -L/usr/local/lib/ -lopencv_highgui -lopencv_core

./obj/visualizer.o: ./src/visualizer.cpp ./include/fractal.hpp ./include/colorMap.hpp ./include/definitions.hpp ./include/plot.hpp $(COLORMAPS:%=./include/ColorMaps/%.hpp)  $(FRACTALS:%=./obj/Fractals/%.o)
	g++ $(CXXFLAGS) -c -o ./obj/visualizer.o ./src/visualizer.cpp

./obj/colorMap.o: ./src/colorMap.cpp ./include/colorMap.hpp
	g++ $(CXXFLAGS) -c -o ./obj/colorMap.o ./src/colorMap.cpp

$(COLORMAPS:%=./obj/ColorMaps/%.o): $(subst obj,src,${@:.o=.cpp}) $(subst obj,include,${@:.o=.hpp}) ./include/colorMap.hpp
	g++ $(CXXFLAGS) -c -o $@ $(subst obj,src,${@:.o=.cpp})

$(FRACTALS:%=./obj/Fractals/%.o): $(subst obj,src,${@:.o=.cpp}) $(subst obj,include,${@:.o=.hpp}) ./include/fractal.hpp
	g++ $(CXXFLAGS) -c -o $@ $(subst obj,src,${@:.o=.cpp})



./obj/plot.o: ./src/plot.cpp ./include/plot.hpp
	g++ $(CXXFLAGS) -c -o ./obj/plot.o ./src/plot.cpp




clean:
	rm ./obj/*.o
	rm ./obj/Fractals/*.o
	rm ./obj/ColorMaps/*.o
	rm ./bin/FractalVisualizer

