#include <SFML/Graphics.hpp>
#include "Program.h"

using namespace sf;


int main(int argc, char** args) {

	RenderWindow* Ventana = new RenderWindow(VideoMode(400, 600, 32), "Hola mundo");
	Program(Ventana);

	return 0;
}