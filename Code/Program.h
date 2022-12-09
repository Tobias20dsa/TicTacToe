#ifndef PROGRAM_H
#define PROGRAM_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>

#define pos(x) poses[x][0], poses[x][1]

using namespace sf;
using namespace std;

bool comprobarQuienGana();

char tablero[][3] = {
	'-','-','-',
	'-','-','-',
	'-','-','-'
};

int poses[][2] = {
	
	{100, 185},//0
	//1,0,0
	//0,0,0
	//0,0,0
	{200, 185},//1
	//0,1,0
	//0,0,0
	//0,0,0
	{300, 185},//2
	//0,0,1
	//0,0,0
	//0,0,0
	{100, 285},//3
	//0,0,0
	//1,0,0
	//0,0,0
	{200, 285},//4
	//0,0,0
	//0,1,0
	//0,0,0
	{300, 285},//5
	//0,0,0
	//0,0,1
	//0,0,0
	{100, 385},//6
	//0,0,0
	//0,0,0
	//1,0,0
	{200, 385},//7
	//0,0,0
	//0,0,0
	//0,1,0
	{300, 385}//8
	//0,0,0
	//0,0,0
	//0,0,1
};

int pos__;

bool comprobarEmpate();

void empate(RenderWindow* Ventana) {
	Texture* TEXgameOver = new Texture;
	TEXgameOver->loadFromFile("Img/game_Over.png");
	Sprite* gameOver = new Sprite(*TEXgameOver);
	gameOver->setOrigin(gameOver->getTexture()->getSize().x / 2, gameOver->getTexture()->getSize().y / 2);
	gameOver->setPosition(200, 300);

	Event evento;
	while (Ventana->isOpen()) {
		while (Ventana->pollEvent(evento)) {
			if (evento.type == Event::Closed) {
				Ventana->close();
			}
		}
		Ventana->draw(*gameOver);
		Ventana->display();
	}
}

void Program(RenderWindow* Ventana) {

	//TABLERO
	Texture* TEXtablero = new Texture;
	TEXtablero->loadFromFile("Img/Tablero.png");
	Sprite* stablero = new Sprite(*TEXtablero);
	stablero->setOrigin(stablero->getTexture()->getSize().x / 2, stablero->getTexture()->getSize().y / 2);
	stablero->setPosition(200, 300);
	stablero->setScale(1.f, 1.f);
	
	//JUGADOR X
	Texture* TEXplayerX = new Texture;
	TEXplayerX->loadFromFile("Img/player_X.png");
	Sprite* splayerX = new Sprite(*TEXplayerX);
	splayerX->setOrigin(splayerX->getTexture()->getSize().x / 2, splayerX->getTexture()->getSize().y / 2);
	splayerX->setPosition(pos(2));
	splayerX->setScale(0.5, 0.4);
	
	//JUGADOR O
	Texture* TEXplayerO = new Texture;
	TEXplayerO->loadFromFile("Img/player_O.png");
	Sprite* splayerO = new Sprite(*TEXplayerO);
	splayerO->setOrigin(splayerO->getTexture()->getSize().x / 2, splayerO->getTexture()->getSize().y / 2);
	splayerO->setPosition(200, 140);
	splayerO->setScale(0.4, 0.4);

	char playerTurn = 'O';
	int turnSet = 1;

	Event eventos;
	while (Ventana->isOpen()) {

		while (Ventana->pollEvent(eventos)) {
			if (eventos.type == Event::Closed) {
				Ventana->close();
			}
		}

		if ((Keyboard::isKeyPressed(Keyboard::Q)) && (tablero[0][0] == '-')) {
			pos__ = 0;
			if (turnSet % 2 == 0) playerTurn = 'O';
			if (turnSet % 2 != 0) playerTurn = 'P';
			turnSet++;

			if (playerTurn == 'P')
				tablero[0][0] = 'x';

			else if (playerTurn == 'O')
				tablero[0][0] = 'o';
		}
		else if ((Keyboard::isKeyPressed(Keyboard::W)) && (tablero[0][1] == '-')) {
			pos__ = 1;
			if (turnSet % 2 == 0) playerTurn = 'O';
			if (turnSet % 2 != 0) playerTurn = 'P';
			turnSet++;

			if (playerTurn == 'P')
				tablero[0][1] = 'x';

			else if (playerTurn == 'O')
				tablero[0][1] = 'o';
		}
		else if ((Keyboard::isKeyPressed(Keyboard::E)) && (tablero[0][2] == '-')) {
			pos__ = 2;
			if (turnSet % 2 == 0) playerTurn = 'O';
			if (turnSet % 2 != 0) playerTurn = 'P';
			turnSet++;

			if (playerTurn == 'P')
				tablero[0][2] = 'x';

			else if (playerTurn == 'O')
				tablero[0][2] = 'o';
		}
		else if ((Keyboard::isKeyPressed(Keyboard::A)) && (tablero[1][0] == '-')) {
			pos__ = 3;
			if (turnSet % 2 == 0) playerTurn = 'O';
			if (turnSet % 2 != 0) playerTurn = 'P';
			turnSet++;

			if (playerTurn == 'P')
				tablero[1][0] = 'x';

			else if (playerTurn == 'O')
				tablero[1][0] = 'o';
		}
		else if ((Keyboard::isKeyPressed(Keyboard::S)) && (tablero[1][1] == '-')) {
			pos__ = 4;
			if (turnSet % 2 == 0) playerTurn = 'O';
			if (turnSet % 2 != 0) playerTurn = 'P';
			turnSet++;

			if (playerTurn == 'P')
				tablero[1][1] = 'x';

			else if (playerTurn == 'O')
				tablero[1][1] = 'o';
		}
		else if ((Keyboard::isKeyPressed(Keyboard::D)) && (tablero[1][2] == '-')) {
			pos__ = 5;
			if (turnSet % 2 == 0) playerTurn = 'O';
			if (turnSet % 2 != 0) playerTurn = 'P';
			turnSet++;

			if (playerTurn == 'P')
				tablero[1][2] = 'x';

			else if (playerTurn == 'O')
				tablero[1][2] = 'o';
		}
		else if ((Keyboard::isKeyPressed(Keyboard::Z)) && (tablero[2][0] == '-')) {
			pos__ = 6;
			if (turnSet % 2 == 0) playerTurn = 'O';
			if (turnSet % 2 != 0) playerTurn = 'P';
			turnSet++;

			if (playerTurn == 'P')
				tablero[2][0] = 'x';

			else if (playerTurn == 'O')
				tablero[2][0] = 'o';
		}
		else if ((Keyboard::isKeyPressed(Keyboard::X)) && (tablero[2][1] == '-')) {
			pos__ = 7;
			if (turnSet % 2 == 0) playerTurn = 'O';
			if (turnSet % 2 != 0) playerTurn = 'P';
			turnSet++;

			if (playerTurn == 'P')
				tablero[2][1] = 'x';

			else if (playerTurn == 'O')
				tablero[2][1] = 'o';
		}
		else if ((Keyboard::isKeyPressed(Keyboard::C)) && (tablero[2][2] == '-')) {
			pos__ = 8;
			if (turnSet % 2 == 0) playerTurn = 'O';
			if (turnSet % 2 != 0) playerTurn = 'P';
			turnSet++;

			if (playerTurn == 'P')
				tablero[2][2] = 'x';

			else if (playerTurn == 'O')
				tablero[2][2] = 'o';
		}

		if ((comprobarQuienGana()) && (!comprobarEmpate())) {
			Ventana->close();
			if (playerTurn == 'O') MessageBox(NULL, L"O a won :D", L"O WIN", MB_OK);
			else if (playerTurn == 'P') MessageBox(NULL, L"X a won :D", L"X WIN", MB_OK);
		}
		else if (comprobarEmpate()) {

			empate(Ventana);
		}

		Ventana->clear(Color::White);
		Ventana->draw(*stablero);

		int aux = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (tablero[i][j] == 'x') {
					splayerX->setPosition(pos(aux));
					Ventana->draw(*splayerX);
				}
				else if (tablero[i][j] == 'o') {
					splayerO->setPosition(pos(aux));
					Ventana->draw(*splayerO);
				}
				aux++;
			}
		}

		
		Ventana->display();
	}
}

bool comprobarEmpate() {

	return

		(
			((tablero[0][0] == 'x') || (tablero[0][0] == 'o')) &&
			((tablero[0][1] == 'x') || (tablero[0][1] == 'o')) &&
			((tablero[0][2] == 'x') || (tablero[0][2] == 'o')) &&

			((tablero[1][0] == 'x') || (tablero[1][0] == 'o')) &&
			((tablero[1][1] == 'x') || (tablero[1][1] == 'o')) &&
			((tablero[1][2] == 'x') || (tablero[1][2] == 'o')) &&

			((tablero[2][0] == 'x') || (tablero[2][0] == 'o')) &&
			((tablero[2][1] == 'x') || (tablero[2][1] == 'o')) &&
			((tablero[2][2] == 'x') || (tablero[2][2] == 'o'))
			) &&
		(!comprobarQuienGana())
		;
}

bool comprobarQuienGana() {
	/*  0-1-2
	 *0|0-0-0
	 *1|0-0-0    [filas][columnas]
	 *2|0-0-0
	 *
	*/


	return
		(((tablero[0][0] == 'x') && (tablero[1][0] == 'x') && (tablero[2][0] == 'x')) ||
			//1-0-0
			//1-0-0
			//1-0-0
			((tablero[0][1] == 'x') && (tablero[1][1] == 'x') && (tablero[2][1] == 'x')) ||
			//0-1-0
			//0-1-0
			//0-1-0
			((tablero[0][2] == 'x') && (tablero[1][2] == 'x') && (tablero[2][2] == 'x')) ||
			//0-0-1
			//0-0-1
			//0-0-1
			((tablero[0][0] == 'x') && (tablero[0][1] == 'x') && (tablero[0][2] == 'x')) ||
			//1-1-1
			//0-0-0
			//0-0-0
			((tablero[1][0] == 'x') && (tablero[1][1] == 'x') && (tablero[1][2] == 'x')) ||
			//0-0-0
			//1-1-1
			//0-0-0
			((tablero[2][0] == 'x') && (tablero[2][1] == 'x') && (tablero[2][2] == 'x')) ||
			//0-0-0
			//0-0-0
			//1-1-1
			((tablero[0][0] == 'x') && (tablero[1][1] == 'x') && (tablero[2][2] == 'x')) ||
			//1-0-0
			//0-1-0
			//0-0-1
			((tablero[2][0] == 'x') && (tablero[1][1] == 'x') && (tablero[0][2] == 'x'))) ||
			//0-0-1
			//0-1-0
			//1-0-0
			(((tablero[0][0] == 'o') && (tablero[1][0] == 'o') && (tablero[2][0] == 'o')) ||
			//1-0-0
			//1-0-0
			//1-0-0
			((tablero[0][1] == 'o') && (tablero[1][1] == 'o') && (tablero[2][1] == 'o')) ||
			//0-1-0
			//0-1-0
			//0-1-0
			((tablero[0][2] == 'o') && (tablero[1][2] == 'o') && (tablero[2][2] == 'o')) ||
			//0-0-1
			//0-0-1
			//0-0-1
			((tablero[0][0] == 'o') && (tablero[0][1] == 'o') && (tablero[0][2] == 'o')) ||
			//1-1-1
			//0-0-0
			//0-0-0
			((tablero[1][0] == 'o') && (tablero[1][1] == 'o') && (tablero[1][2] == 'o')) ||
			//0-0-0
			//1-1-1
			//0-0-0
			((tablero[2][0] == 'o') && (tablero[2][1] == 'o') && (tablero[2][2] == 'o')) ||
			//0-0-0
			//0-0-0
			//1-1-1
			((tablero[0][0] == 'o') && (tablero[1][1] == 'o') && (tablero[2][2] == 'o')) ||
			//1-0-0
			//0-1-0
			//0-0-1
			((tablero[2][0] == 'o') && (tablero[1][1] == 'o') && (tablero[0][2] == 'o')))
			//0-0-1
			//0-1-0
			//1-0-0
		;
}

#endif