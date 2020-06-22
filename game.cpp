#include <algorithm>
#include <functional>
#include <random>
#include <vector>
#include <time.h>
#include "draw.h"

#define PUNTAJE_MAXIMO 10000

void test_game_1_game_5(bool, bool);

//tiro de dados
int tirar_dados()
{
	dibujar_ui(15, 76);
	// Para obtener la semilla
	std::random_device rd;
	// Motor Mersenne Twister estándar, sembrado con rd()
	std::mt19937 gen(rd());
	// Transformar u_int aleatorio generado a int en [1, 6]
	std::uniform_int_distribution<> distrib(1, 6);

	vector<int> dices;  // Tiro de dices
	vector<int> times;  // Contador de repeticiones

	// Carga el tiro de dices (vector)
	// con números al azar entre 1 y 6
	for (int i = 0; i < 6; i++)
		dices.push_back(distrib(gen));

	// Cuenta repeticiones del número 'x' en el tiro
	for (int x = 1; x <= 6; x++)
		times.push_back(count(dices.begin(), dices.end(), x));

	for (int i = 0; i < 6; i++)
		dibujar_dado(i, dices[i]);

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

	vector<int> partial_scores; // Para chequear cual es el puntaje mas grande

	if (sextet) {
		cout << "TE SALIÓ UN SEXTETO!!!" << endl;
		cout << "██╗    ██╗██╗███╗   ██╗███╗   ██╗███████╗██████╗" << endl;
		cout << "██║    ██║██║████╗  ██║████╗  ██║██╔════╝██╔══██╗" << endl;
		cout << "██║ █╗ ██║██║██╔██╗ ██║██╔██╗ ██║█████╗  ██████╔╝" << endl;
		cout << "██║███╗██║██║██║╚██╗██║██║╚██╗██║██╔══╝  ██╔══██╗" << endl;
		cout << "╚███╔███╔╝██║██║ ╚████║██║ ╚████║███████╗██║  ██║" << endl;
		cout << "╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝" << endl;
		return PUNTAJE_MAXIMO;
	}

	if (game_1)
		partial_scores.push_back(100 * times[0]);
	if (game_5)
		partial_scores.push_back(50 * times[4]);
	if (trio_ext) {
			partial_scores.push_back(2000);
			gotoxy(3, 6);
			cout << "Conseguiste un trío ampliado! +2000\n";
	}
	else if (long_ladder == 6) {
		partial_scores.push_back(1500);
		gotoxy(3, 6);
		cout << "Conseguiste una escalera larga! +1500\n";
	}
	else if (triple_par) {
		partial_scores.push_back(1000);
		gotoxy(3, 6);
		cout << "Conseguiste un triple par! +1000\n";
	}
	else if (trio_xplus) {
		partial_scores.push_back(number * 200);
		gotoxy(3, 6);
		cout << "Conseguiste un trio ampliado de " << number << "! +" << number * 200 << "\n";
		test_game_1_game_5(game_1, game_5);
	}
	else if (trio) {
		partial_scores.push_back(1000);
		gotoxy(3, 6);
		cout << "Conseguiste un trio! +1000\n";
		test_game_1_game_5(game_1, game_5);
	}
	else if (trio_x) {
		partial_scores.push_back(number * 100);
		gotoxy(3, 6);
		cout << "Conseguiste un trio de " << number << "! +" << number * 100 << "\n";
		test_game_1_game_5(game_1, game_5);
	}
	else if (game_1) {
		gotoxy(3, 6);
		cout << "Conseguiste un juego de unos! +" << times[0] * 100 << "\n";
	}
	else if (game_5) {
		gotoxy(3, 6);
		cout << "Conseguiste un juego de cincos! +" << times[4] * 50 << "\n";
	}
	else {
		gotoxy(3, 6);
		cout << "No conseguiste ninguna combinacion.\n";
		return 0;
	}

	sort(partial_scores.begin(), partial_scores.end());
	total_score += partial_scores[(partial_scores.size() - 1)];
	cout << endl;
	return total_score;
}

//juego de 1 o juego de 5
void test_game_1_game_5(bool game_1, bool game_5) {

	if (game_1) {
		gotoxy(3, 7);
		cout << "Tambien conseguiste un juego de unos! Pero estos puntos no se cuentan." << "\n";
	}
	if (game_5) {
		if (game_1)
			gotoxy(3, 8);
		else gotoxy(3, 7);
		cout << "Tambien conseguiste un juego de cincos! Pero estos puntos no se cuentan." << "\n";
	}
}

//chequeo de puntos (modo 2 jugadores)
void chequeo_puntos(string name, int& puntaje, int& high_score, bool& win, bool& sex_win)
{
	int tiros = 0;
	int actual_score;

	char res;

	do {
		tiros++;
		system("CLS");
		actual_score = tirar_dados();
		if (actual_score == 0) {//Si no hubo combinacion ganadora, los puntajes son borrados.
			gotoxy(3, 9);
			cout << "TURNO DEL JUGADOR " << name;
			gotoxy(3, 8);
			cout << name << ", no has conseguido una combinacion, se resetean tus puntos.";
			puntaje = 0;
			gotoxy(3, 11);
			cout << "Puntaje total de la ronda: " << puntaje;
			while (!_kbhit());
			_getch();
			break;
		}
		else if (actual_score == PUNTAJE_MAXIMO) { //Si se consigue un sexteto, el programa termina.
			sex_win = true;
			break;
		}
		else puntaje += actual_score;

		if (puntaje == PUNTAJE_MAXIMO) {
			win = true;
			break;
		}
		else if (puntaje > PUNTAJE_MAXIMO) { //chequea si el puntaje se pasó de 10000
			puntaje -= actual_score;
			gotoxy(3, 9);
			cout << "TURNO DEL JUGADOR " << name;
			gotoxy(3, 10);
			cout << name << ", te pasaste del puntaje maximo, los puntos en este tiro no cuentan.";
			gotoxy(3, 11);
			cout << "Puntaje total de la ronda: " << puntaje;
			while (!_kbhit());
			_getch();
			break;
		}
		else {
			gotoxy(3, 10);
			cout << "Puntaje total del tiro " << tiros << ": " << actual_score;
		}
		if (actual_score > high_score)
			high_score = actual_score; //chequea el highscore

		gotoxy(3, 9);
		cout << "TURNO DEL JUGADOR " << name;
		gotoxy(3, 12);
		cout << "Tirar de vuelta? Presione N para cancelar.\n";
		gotoxy(3, 11);
		cout << "Puntaje total de la ronda: " << puntaje;
		gotoxy(3, 13);
		while (!_kbhit());
		res = tolower(_getch());

	} while (res != 'n' && puntaje < PUNTAJE_MAXIMO);
}

//main
int main()
{
	bool sex_win_1 = false;
	bool sex_win_2 = false;
	bool win_1 = false;
	bool win_2 = false;

	char res;

	int gamemode;
	int turnos = 0;
	int tiros = 0;
	int total_score = 0;
	int actual_score = 0;
	int total_score_1 = 0;
	int total_score_2 = 0;
	int high_score = 0;

	string name1;
	string name2;
	string winner;

	menu_de_inicio();
	gotoxy(3, 6);
	cin >> gamemode;

	switch (gamemode) {
	case 1:
		system("CLS");
		dibujar_ui(5, 30);
		gotoxy(3, 2);
		cout << "Nombre del jugador: ";
		gotoxy(3, 3);
		cin >> name1;

		do {
			turnos++;
			system("CLS");
			actual_score = tirar_dados();

			if (actual_score == 0) { //Si no hubo combinacion ganadora, los puntajes son borrados.
				gotoxy(3, 8);
				cout << "No has conseguido una combinacion, se resetean tus puntos.";
				total_score = 0;
			}
			else if (actual_score == PUNTAJE_MAXIMO) { //Si se consigue un sexteto, el programa termina.
				sex_win_1 = true;
				break;
			}
			else total_score += actual_score;

			if (total_score > PUNTAJE_MAXIMO) { //chequea si el puntaje se pasó de 10000
				total_score -= actual_score;
				gotoxy(3, 9);
				cout << "Te pasaste del puntaje maximo, los puntos en este tiro no cuentan.";
			}
			else {
				gotoxy(3, 9);
				cout << "Puntaje total del tiro " << turnos << ": " << actual_score;
			}
			gotoxy(3, 11);
			cout << "Tirar de vuelta? Presione N para cancelar.\n";
			gotoxy(3, 10);
			cout << "Puntaje total de la ronda: " << total_score;
			gotoxy(3, 12);
			while (!_kbhit());
			res = tolower(_getch());

		} while (res != 'n' && total_score < PUNTAJE_MAXIMO);

		if (sex_win_1 == true) {
			system("CLS");
			dibujar_ui(15, 76);
			gotoxy(3, 10);
			cout << name1 << " ha conseguido un SEXTETO!";
			while (!_kbhit());
			break;
		}

		//muestra puntaje final
		system("CLS");
		dibujar_ui(13, 31);
		gotoxy(3, 4);
		cout << "---------------------------";
		gotoxy(3, 5);
		cout << "Jugador: " << name1;
		gotoxy(3, 6);
		cout << "---------------------------";
		gotoxy(3, 7);
		cout << "Puntos totales: " << total_score;
		gotoxy(3, 8);
		cout << "Rondas jugadas: " << turnos;
		gotoxy(3, 9);
		cout << "---------------------------";

		break;
	case 2:
		//pide nombre jugador 1
		system("CLS");
		dibujar_ui(5, 30);
		gotoxy(3, 2);
		cout << "Nombre del jugador 1: ";
		gotoxy(3, 3);
		cin >> name1;

		//pide nombre jugador 2
		system("CLS");
		dibujar_ui(5, 30);
		gotoxy(3, 2);
		cout << "Nombre del jugador 2: ";
		gotoxy(3, 3);
		cin >> name2;

		for (turnos = 1; turnos <= 10; turnos++) {
			//jugador 1
			chequeo_puntos(name1, total_score_1, high_score, win_1, sex_win_1);
			if (win_1 || sex_win_1) {
				break;
			}
			else {
				system("CLS");
				menu_intermedio(turnos, total_score_2, total_score_1, name2, name1);
				while (!_kbhit());
				_getch();
			}

			//jugador 2
			chequeo_puntos(name2, total_score_2, high_score, win_2, sex_win_2);

			if (win_2 || sex_win_2) {
				break;
			}
			else {
				system("CLS");
				menu_intermedio(turnos, total_score_1, total_score_2, name1, name2);
				while (!_kbhit());
				_getch();
			}
		}
		if (sex_win_1 == true) {
			dibujar_ui(15, 76);
			gotoxy(3, 10);
			cout << name1 << " ha conseguido un SEXTETO!";
			total_score_1 = 10000;
			while (!_kbhit());
			_getch();
		}
		else if (sex_win_2 == true) {
			dibujar_ui(15, 76);
			gotoxy(3, 10);
			cout << name2 << " ha conseguido un SEXTETO!";
			total_score_2 = 10000;
			while (!_kbhit());
			_getch();
		}

		else if (win_1 == true) {
			dibujar_ui(15, 76);
			gotoxy(3, 10);
			cout << name1 << " ha GANADO!";
			while (!_kbhit());
			_getch();
		}
		else if (win_2 == true) {
			dibujar_ui(15, 76);
			gotoxy(3, 10);
			cout << name2 << " ha GANADO!";
			while (!_kbhit());
			_getch();
		}

		system("CLS");
		dibujar_ui(15, 76);
		gotoxy(3, 7);
		cout << "Turnos terminados!";
		gotoxy(3, 8);
		cout << "Presione cualquier tecla para ver el puntaje final.";
		while (!_kbhit());
		_getch();

		if (total_score_1 > total_score_2)
			winner = name1;
		else winner = name2;

		system("CLS");
		dibujar_ui(18, 32);
		gotoxy(3, 3); cout << "---------------------------";
		gotoxy(3, 4); cout << "GANADOR " << winner;
		gotoxy(3, 5); cout << "---------------------------";
		gotoxy(3, 7); cout << "---------------------------";
		gotoxy(3, 8); cout << "JUGADOR 1 | " << name1;
		gotoxy(4, 9); cout << "Puntos totales: " << total_score_1;
		gotoxy(3, 10); cout << "---------------------------";
		gotoxy(3, 11); cout << "JUGADOR 2 | " << name2;
		gotoxy(4, 12); cout << "Puntos totales: " << total_score_2;
		gotoxy(3, 13); cout << "---------------------------";
		gotoxy(3, 14); cout << "Tiro mas alto: " << high_score;
		gotoxy(3, 15); cout << "Rondas transcurridas: " << turnos;
		gotoxy(3, 16); cout << "---------------------------";
		break;
	default:
		gotoxy(2, 16);
		cout << "Codigo de juego erroneo. Cerrando..." << endl;
	}
	gotoxy(0, 18);
}
