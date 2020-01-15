
COMPILER = g++
FLAGS = -std=c++17
LIBRARIES = -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-network -lGL -lGLEW -lBox2D

executable: main.o application.o window.o test_layer.o mesh.o shader.o texArray.o box.o button.o animation.o
	$(COMPILER) -o executable $^ $(LIBRARIES)

main.o: main.cpp
	$(COMPILER) $(FLAGS) -c main.cpp

application.o: application.cpp application.h
	$(COMPILER) $(FLAGS) -c application.cpp

window.o: window.cpp window.h
	$(COMPILER) $(FLAGS) -c window.cpp

test_layer.o: test_layer.cpp test_layer.h layer.h
	$(COMPILER) $(FLAGS) -c test_layer.cpp

mesh.o: mesh.cpp mesh.h
	$(COMPILER) $(FLAGS) -c mesh.cpp

shader.o: shader.cpp shader.h
	$(COMPILER) $(FLAGS) -c shader.cpp

texArray.o: texArray.cpp texArray.h
	$(COMPILER) $(FLAGS) -c texArray.cpp

box.o: box.cpp box.h
	$(COMPILER) $(FLAGS) -c box.cpp

button.o: button.cpp button.h
	$(COMPILER) $(FLAGS) -c button.cpp

animation.o: animation.cpp animation.h
	$(COMPILER) $(FLAGS) -c animation.cpp

clean:
	rm *.o

delete:
	rm executable

