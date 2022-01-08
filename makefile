default: Mesh.o Charge.o ElectricField.o Arrow.o Scene.o main.o
	g++ Mesh.o Charge.o ElectricField.o Arrow.o Scene.o  main.o -o Visualiser -lsfml-graphics -lsfml-window -lsfml-system -I./
	./Visualiser 

main.o: main.cpp Scene.cpp Arrow.cpp ElectricField.cpp Charge.cpp Mesh.cpp
	g++ -c main.cpp -o $@ -g -std=c++17

Scene.o: Scene.cpp Arrow.cpp ElectricField.cpp Charge.cpp Mesh.cpp
	g++ -c Scene.cpp -o $@ -g -std=c++17

Charge.o: Arrow.cpp ElectricField.cpp Charge.cpp
	g++ -c Charge.cpp -o $@ -g -std=c++17

ElectricField.o: ElectricField.cpp
	g++ -c ElectricField.cpp -o $@ -g -std=c++17

Arrow.o: Arrow.cpp
	g++ -c Arrow.cpp -o $@ -g -std=c++17

Mesh.o: Mesh.cpp
	g++ -c Mesh.cpp -o $@ -g -std=c++17

clean:
	rm -f ./*.o Visualiser