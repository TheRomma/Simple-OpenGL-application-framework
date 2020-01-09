
FLAGS = -std=c++17
LIBRARIES = -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-network -lGL -lGLEW -lBox2D

executable: main.o application.o window.o test_layer.o mesh.o shader.o texArray.o box.o button.o animation.o
	g++ -o executable $^ $(LIBRARIES)

main.o: main.cpp
	g++ $(FLAGS) -c main.cpp

application.o: application.cpp application.h
	g++ $(FLAGS) -c application.cpp

window.o: window.cpp window.h
	g++ $(FLAGS) -c window.cpp

test_layer.o: test_layer.cpp test_layer.h layer.h
	g++ $(FLAGS) -c test_layer.cpp

mesh.o: mesh.cpp mesh.h
	g++ $(FLAGS) -c mesh.cpp

shader.o: shader.cpp shader.h
	g++ $(FLAGS) -c shader.cpp

texArray.o: texArray.cpp texArray.h
	g++ $(FLAGS) -c texArray.cpp

box.o: box.cpp box.h
	g++ $(FLAGS) -c box.cpp

button.o: button.cpp button.h
	g++ $(FLAGS) -c button.cpp

animation.o: animation.cpp animation.h
	g++ $(FLAGS) -c animation.cpp

clean:
	rm *.o

delete:
	rm executable

