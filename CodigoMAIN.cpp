#include <iostream>
#include <algorithm>
#include <functional>
#include <random>
#include <vector>
#include <time.h>
#include <Windows.h> 
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//dices
void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

void dibujar_marco(int x)
{
	int offset_x = 10 * x;
	for (int i = 1 + offset_x; i <= 9 + offset_x; i++)
	{
		gotoxy(i, 0); putchar(220); //lado arriba
		gotoxy(i, 4); putchar(223); //lado abajo
	}
	for (int i = 1; i < 4; i++)
	{
		gotoxy(1 + offset_x, i); putchar(219); //lado izquierdo

		gotoxy(9 + offset_x, i); putchar(219); //lado derecho
	}
}

void dibujar_marco_interfaz() {
	for (int i = 2; i < 100; i++) {
		gotoxy(i, 1); printf("%c", 205);
		gotoxy(i, 30); printf("%c", 205);
	};
	for (int i = 2; i < 30; i++) {
		gotoxy(1, i); printf("%c", 186);
		gotoxy(100, i); printf("%c", 186);
	};
	
	gotoxy(1, 1); printf("%c", 201);
	gotoxy(1, 30); printf("%c", 200);
	gotoxy(100, 1); printf("%c", 187);
	gotoxy(100, 30); printf("%c", 188);
	gotoxy(2, 2);
}

void dibujar_dado(int x, int y)
{
	int offset_x = 10 * x;
	dibujar_marco(x);
	switch (y)
	{
	case 1:
		gotoxy(5 + offset_x, 2); putchar(254); //medio
		gotoxy(7 + offset_x, 3); printf(" "); //espacio
		break;
	case 2:
		gotoxy(3 + offset_x, 1); putchar(254); //punto izquierdo alto
		gotoxy(7 + offset_x, 3); putchar(254); //punto derecho bajo
		break;

	case 3:
		gotoxy(3 + offset_x, 1); putchar(254); //punto izquierdo alto
		gotoxy(5 + offset_x, 2); putchar(254); //medio
		gotoxy(7 + offset_x, 3); putchar(254); //punto derecho bajo
		break;

	case 4:
		gotoxy(3 + offset_x, 1); putchar(254); //punto izquierdo alto
		gotoxy(3 + offset_x, 3); putchar(254); //punto izquierdo bajo
		gotoxy(7 + offset_x, 1); putchar(254); //punto derecho alto
		gotoxy(7 + offset_x, 3); putchar(254); //punto derecho bajo
		break;
	case 5:
		gotoxy(3 + offset_x, 1); putchar(254); //punto izquierdo alto
		gotoxy(3 + offset_x, 3); putchar(254); //punto izquierdo bajo
		gotoxy(5 + offset_x, 2); putchar(254); //medio
		gotoxy(7 + offset_x, 1); putchar(254); //punto derecho alto
		gotoxy(7 + offset_x, 3); putchar(254); //punto derecho bajo
		break;
	case 6:
		gotoxy(3 + offset_x, 1); putchar(254); //punto izquierdo alto
		gotoxy(3 + offset_x, 2); putchar(254); //punto izquierdo medio
		gotoxy(3 + offset_x, 3); putchar(254); //punto izquierdo bajo
		gotoxy(7 + offset_x, 1); putchar(254); //punto derecho alto
		gotoxy(7 + offset_x, 2); putchar(254); //punto derecho medio
		gotoxy(7 + offset_x, 3); putchar(254); //punto derecho bajo
		break;
	default:
		break;
	}
}

void test_game_1_game_5(bool game_1, bool game_5) {

	if (game_1) {
		cout << "Tambien conseguiste un juego de unos! Pero estos puntos no se cuentan." << "\n";
	}
	if (game_5) {
		cout << "Tambien conseguiste un juego de cincos! Pero estos puntos no se cuentan." << "\n";
	}
}
void tirar_dados()
{
	//srand(time(NULL));  // Init randomizer
	//// Setup ONCE
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 6);

	//std::default_random_engine generator;
	//std::uniform_int_distribution<int> distribution(1,6);
	//auto dice = std::bind ( distribution, generator );
	//int wisdom = dice()+dice()+dice();
	//std::cout << wisdom;

	vector<int> dices;  // Tiro de dices
	vector<int> times;  // Contador de repeticiones

	// Carga el tiro de dices (vector)
	// con números al azar entre 1 y 6
	for (int i = 0; i < 6; i++)
		dices.push_back(dis(gen));

	// Cuenta repeticiones del número 'x' en el tiro
	for (int x = 1; x <= 6; x++)
		times.push_back(count(dices.begin(), dices.end(), x));

	for (int i = 0; i < 6; i++)
	{
		dibujar_dado(i, dices[i]);
	}
	cout << endl << endl;

	// Combinaciones ganadoras
	bool game_1 = false;        // Uno o dos 1 (100 por cada uno)
	bool game_5 = false;        // uno o dos 5 (50 por cada uno)
	bool trio = false;          // Tres 1 (1000)
	bool trio_x = false;        // Tres iguales (X*100)
	bool trio_xplus = false;    // Cuatro o cinco iguales (X*200)
	bool trio_ext = false;      // Cuatro o cinco unos (2000)
	bool triple_par = false;    // Tres pares (1000)
	int long_ladder = 0;        // Escalera de 6 dices (1500)
	bool sextet = false;        // Seis unos (gana)

	// Puntajes
	int total_score = 0;
	bool sextet_win = false;
	int total_score_round = 0; // Variable que se agrego para acumular los puntos en caso de que no se continue lanzando

	// Aux
	int number;

	// Chequea si el tiro es una escalera larga
	for (auto n : times) {
		if (n == 1)
			long_ladder++;
		else
			break;
	}

	// Chequea por trio, trio ampliado o un sexteto (si es que no hay una escalera)
	if (long_ladder != 6) {
		if (times[0] > 2) {
			if ((times[0] == 4) || (times[0] == 5))
				trio_ext = true;
			else if (times[0] == 3)
				trio = true;
			else
				sextet = true;
		}

		if (!trio && !trio_ext && !sextet) {
			triple_par = true;

			// Chequea si hay triple par (si no hay ninguno de los trios o sextetos)
			for (auto n : times) {
				if (n % 2 != 0) {
					triple_par = false;
					break;
				}
			}

			// Chequea si hay un trio o un trio++
			for (int i = 1; i < 6; i++) {
				if (times[i] == 3) {
					trio_x = true;
					number = i + 1;
				}

				else if ((times[i] == 4) || (times[i] == 5)) {
					trio_xplus = true;
					number = i + 1;
				}
			}
		}

		// Chequea si hay juego de unos o cincos
		if (!triple_par && !sextet) {
			if ((times[0] == 1) || (times[0] == 2))
				game_1 = true;
			if ((times[4] == 1) || (times[4] == 2))
				game_5 = true;
		}
	}

	// Puntajes
	if (sextet)
		sextet_win = true;

	else {
		vector<int> partial_scores; // Para chequear cual es el puntaje mas grande
		if (game_1) partial_scores.push_back(100 * times[0]);
		if (game_5) partial_scores.push_back(50 * times[4]);

		if (trio_ext) {
			partial_scores.push_back(2000);
			cout << "Conseguiste un trío ampliado! +2000\n";
		}

		else if (long_ladder == 6) {
			partial_scores.push_back(1500);
			cout << "Conseguiste una escalera larga! +1500\n";
		}

		else if (triple_par) {
			partial_scores.push_back(1000);
			cout << "Conseguiste un triple par! +1000\n";
		}

		else if (trio_xplus) {
			partial_scores.push_back(number * 200);
			cout << "Conseguiste un trio ampliado de " << number << "! +" << number * 200 << "\n";
			test_game_1_game_5(game_1, game_5);
		}

		else if (trio) {
			partial_scores.push_back(1000);
			cout << "Conseguiste un trio! +1000\n";
			test_game_1_game_5(game_1, game_5);
		}

		else if (trio_x) {
			partial_scores.push_back(number * 100);
			cout << "Conseguiste un trio de " << number << "! +" << number * 100 << "\n";
			test_game_1_game_5(game_1, game_5);
		}

		else if (game_1) {
			cout << "Conseguiste un juego de unos! +" << times[0] * 100 << "\n";
		}

		else if (game_5) {
			cout << "Conseguiste un juego de cincos! +" << times[4] * 50 << "\n";
		}

		else {
			cout << "No conseguiste ninguna combinacion. Perdiste tus puntos.\n";
			for (auto x : dices)
				cout << x;
			total_score_round = 0;

			return;
		}

		if (sextet_win) {
			cout << "TE SALIÓ UN SEXTETO!!!" << endl;
			cout << "██╗    ██╗██╗███╗   ██╗███╗   ██╗███████╗██████╗" << endl;
			cout << "██║    ██║██║████╗  ██║████╗  ██║██╔════╝██╔══██╗" << endl;
			cout << "██║ █╗ ██║██║██╔██╗ ██║██╔██╗ ██║█████╗  ██████╔╝" << endl;
			cout << "██║███╗██║██║██║╚██╗██║██║╚██╗██║██╔══╝  ██╔══██╗" << endl;
			cout << "╚███╔███╔╝██║██║ ╚████║██║ ╚████║███████╗██║  ██║" << endl;
			cout << "╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝" << endl;
			return;
		}

		else {
			sort(partial_scores.begin(), partial_scores.end());
			total_score += partial_scores[(partial_scores.size() - 1)];
			
			for (auto x : dices)
				cout << x;

			cout << endl;
			cout << total_score;
		}
	}
	total_score_round += total_score;
	gotoxy(25, 12);
	cout << "| Puntaje Acumulado al momento: " << total_score_round << endl;
}

//JUEGO
int main()
{
	system("CLS"); dibujar_marco_interfaz();
	int gamemode; char res; char name[20]; char name2[20];
	/*
	std::cout << "\n██████╗ ██╗███████╗███████╗    ███╗   ███╗██╗██╗";
	std::cout << "\n██╔══██╗██║██╔════╝╚══███╔╝    ████╗ ████║██║██║";
	std::cout << "\n██║  ██║██║█████╗    ███╔╝     ██╔████╔██║██║██║";
	std::cout << "\n██║  ██║██║██╔══╝   ███╔╝      ██║╚██╔╝██║██║██║";
	std::cout << "\n██████╔╝██║███████╗███████╗    ██║ ╚═╝ ██║██║███████╗";
	std::cout << "\n╚═════╝ ╚═╝╚══════╝╚══════╝    ╚═╝     ╚═╝╚═╝╚══════╝";
	*/
	gotoxy(2, 2);
	std::cout << "\n1 - Juego nuevo para un jugador";
	gotoxy(2, 3);
	std::cout << "\n2 - Juego nuevo para dos jugadores";
	gotoxy(2, 4);
	std::cout << "\n3 - Mostrar puntuación más alta";
	gotoxy(2, 5);
	std::cout << "\n\nModo de juego ? ";
	std::cin >> gamemode;
	std::cin.clear();
	std::cin.ignore(256, '\n');
	
	switch (gamemode) {
	case 1:
		//--Interfaz --
		system("CLS"); dibujar_marco_interfaz();
		gotoxy(2, 2);
		cout << "Nombre? " << endl;
		gotoxy(2, 3);
		cin >> name;
		system("CLS");
		do {
			system("CLS");
			tirar_dados();
			gotoxy(0, 12);
			cout << "Nombre de Jugador: " << name << endl;
			cout << "\nJugar de vuelta? S/N\n";
			cin >> res; res = tolower(res);
		} while (res == 's');
		break;
	case 2:
		system("CLS"); dibujar_marco_interfaz();
		gotoxy(2, 2);
		cout << "Nombre del primer jugador? " << endl;
		gotoxy(2, 3);
		cin >> name;
		system("CLS"); dibujar_marco_interfaz();
		gotoxy(2, 2);
		cout << "Nombre del segundo jugador? " << endl;
		gotoxy(2, 3);
		cin >> name2;
		system("CLS");
		// Funcion de juego de 2 jugadores
		// Condicion de un ciclo para repetir el juego
		break;
	case 3: // Puntajes totales de las partidas hasta el momento
		system("CLS"); dibujar_marco_interfaz();
		gotoxy(2, 2);
		cout << "Lista de puntajes: " << endl;
		gotoxy(2, 3);
		cout << " 1- ";
		gotoxy(2, 4);
		cout << " 2- ";
		gotoxy(2, 5);
		cout << " 3- ";
		gotoxy(2, 6);
		cout << " 4- ";
		gotoxy(2, 7);
		cout << " 5- ";
		gotoxy(2, 8);
		break;
	default:
		system("CLS"); dibujar_marco_interfaz();
		gotoxy(2, 2);
		std::cout << "El modo ingresado no es válido. : ) Adios";

	}
	gotoxy(2, 10);
	system("Pause");	
}
