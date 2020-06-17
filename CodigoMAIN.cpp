#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>

using namespace std;

void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}
void dibujoDadoGeneral() {
	//Valor
	gotoxy(3, 2); printf("%c", 2);
	gotoxy(3, 3); printf("%c", 2);
	gotoxy(3, 4); printf("%c", 2);
	gotoxy(5, 2); printf("%c", 2);
	gotoxy(5, 3); printf("%c", 2);
	gotoxy(5, 4); printf("%c", 2);
	gotoxy(7, 2); printf("%c", 2);
	gotoxy(7, 3); printf("%c", 2);
	gotoxy(7, 4); printf("%c", 2);
	//
	gotoxy(10, 5);
}
void dibujoDado1() {
	for (int i = 2; i < 9; i++) {
		gotoxy(i, 1); printf("%c", 220);
		gotoxy(i, 5); printf("%c", 220);
	};
	for (int i = 2; i < 5; i++) {
		gotoxy(1, i); printf("%c", 219);
		gotoxy(9, i); printf("%c", 219);
	};
	gotoxy(1, 1); printf("%c", 220);
	gotoxy(1, 5); printf("%c", 219);
	gotoxy(9, 1); printf("%c", 220);
	gotoxy(9, 5); printf("%c", 219);
	//Valor
	gotoxy(5, 3); printf("%c", 2);
	//
	gotoxy(10, 5);
}
void dibujoDado2() {
	for (int i = 11; i < 19; i++) {
		gotoxy(i, 1); printf("%c", 220);
		gotoxy(i, 5); printf("%c", 220);
	};
	for (int i = 2; i < 5; i++) {
		gotoxy(11, i); printf("%c", 219);
		gotoxy(19, i); printf("%c", 219);
	};
	gotoxy(11, 1); printf("%c", 220);
	gotoxy(11, 5); printf("%c", 219);
	gotoxy(19, 1); printf("%c", 220);
	gotoxy(19, 5); printf("%c", 219);
	// Valor
	gotoxy(13, 2); printf("%c", 2);
	gotoxy(17, 4); printf("%c", 2);
	//
	gotoxy(10, 5);
}
void dibujoDado3() {
	for (int i = 21; i < 29; i++) {
		gotoxy(i, 1); printf("%c", 220);
		gotoxy(i, 5); printf("%c", 220);
	};
	for (int i = 2; i < 5; i++) {
		gotoxy(21, i); printf("%c", 219);
		gotoxy(29, i); printf("%c", 219);
	};
	gotoxy(21, 1); printf("%c", 220);
	gotoxy(21, 5); printf("%c", 219);
	gotoxy(29, 1); printf("%c", 220);
	gotoxy(29, 5); printf("%c", 219);
	//Valor
	gotoxy(25, 3); printf("%c", 2);
	gotoxy(23, 2); printf("%c", 2);
	gotoxy(27, 4); printf("%c", 2);
	//
	gotoxy(10, 5);
}
void dibujoDado4() {
	for (int i = 31; i < 39; i++) {
		gotoxy(i, 1); printf("%c", 220);
		gotoxy(i, 5); printf("%c", 220);
	};
	for (int i = 2; i < 5; i++) {
		gotoxy(31, i); printf("%c", 219);
		gotoxy(39, i); printf("%c", 219);
	};
	gotoxy(31, 1); printf("%c", 220);
	gotoxy(31, 5); printf("%c", 219);
	gotoxy(39, 1); printf("%c", 220);
	gotoxy(39, 5); printf("%c", 219);
	//Valor
	gotoxy(33, 2); printf("%c", 2);
	gotoxy(33, 4); printf("%c", 2);
	gotoxy(37, 2); printf("%c", 2);
	gotoxy(37, 4); printf("%c", 2);
	//
	gotoxy(10, 5);
}
void dibujoDado5() {
	for (int i = 41; i < 49; i++) {
		gotoxy(i, 1); printf("%c", 220);
		gotoxy(i, 5); printf("%c", 220);
	};
	for (int i = 2; i < 5; i++) {
		gotoxy(41, i); printf("%c", 219);
		gotoxy(49, i); printf("%c", 219);
	};
	gotoxy(41, 1); printf("%c", 220);
	gotoxy(41, 5); printf("%c", 219);
	gotoxy(49, 1); printf("%c", 220);
	gotoxy(49, 5); printf("%c", 219);
	//Valor
	gotoxy(45, 3); printf("%c", 2);
	gotoxy(43, 2); printf("%c", 2);
	gotoxy(43, 4); printf("%c", 2);
	gotoxy(47, 2); printf("%c", 2);
	gotoxy(47, 4); printf("%c", 2);
	//
	gotoxy(10, 5);
}
void dibujoDado6() {
	for (int i = 51; i < 59; i++) {
		gotoxy(i, 1); printf("%c", 220);
		gotoxy(i, 5); printf("%c", 220);
	};
	for (int i = 2; i < 5; i++) {
		gotoxy(51, i); printf("%c", 219);
		gotoxy(59, i); printf("%c", 219);
	};
	gotoxy(51, 1); printf("%c", 220);
	gotoxy(51, 5); printf("%c", 219);
	gotoxy(59, 1); printf("%c", 220);
	gotoxy(59, 5); printf("%c", 219);
	//Valor
	gotoxy(53, 2); printf("%c", 2);
	gotoxy(53, 3); printf("%c", 2);
	gotoxy(53, 4); printf("%c", 2);
	gotoxy(57, 2); printf("%c", 2);
	gotoxy(57, 3); printf("%c", 2);
	gotoxy(57, 4); printf("%c", 2);
	//
	gotoxy(10, 5);
}

int main()
{
	srand(time(NULL));  // Init randomizer
	vector<int> dices;  // Tiro de dados
	vector<int> times;  // Contador de repeticiones

    // Carga el tiro de dados (vector)
    // con números al azar entre 1 y 6
	for (int i = 0; i < 6; i++)
		dices.push_back(rand() % 6 + 1);

    // Cuenta repeticiones del número 'x' en el tiro
	for (int x = 1; x <= 6; x++)
		times.push_back(count(dices.begin(), dices.end(), x));

	// Combinaciones ganadoras
	bool game_1 = false;        // Uno o dos 1 (100 por cada uno)
	bool game_5 = false;        // uno o dos 5 (50 por cada uno)
	bool trio = false;          // Tres 1 (1000)
	bool trio_x = false;        // Tres iguales (X*100)
	bool trio_xplus = false;    // Cuatro o cinco iguales (X*200)
	bool trio_ext = false;      // Cuatro o cinco unos (2000)
	bool triple_par = false;    // Tres pares (1000)
	int long_ladder = 0;        // Escalera de 6 dados (1500)
	bool sextet = false;        // Seis unos (gana)

	// Puntajes
	int total_score = 0;
	bool sextet_win = false;

    // Aux
	int number;

   // Chequea si el tiro es una escalera larga
	for (auto n : times) {
		if (n == 1)
            long_ladder++;
		else
            break;
	}

	for (int i = 0; i < 6; i++)
	{
		switch (dados[i]) {
		case 1:
			gotoxy();
			break;
		case 2:

			break;
		case 3:
			break;
		case 4:

			break;
		case 5:

			break;
		}
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
		if ( !triple_par && !sextet ) {
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
			cout << "Conseguiste un trío ampliado de " << number << "! +" << number * 200 << "\n";
			if (game_1) {
				partial_scores.push_back(times[0] * 100);
				cout << "También conseguiste un juego de unos! Pero estos puntos no se cuentan." << "\n";
			}
			if (game_5) {
				partial_scores.push_back(times[4] * 50);
				cout << "También conseguiste un juego de cincos! Pero estos puntos no se cuentan." << "\n";
			}
		}

		else if (trio) {
			partial_scores.push_back(1000);
			cout << "Conseguiste un trío! +1000\n";
			if (game_1) {
				partial_scores.push_back(times[0] * 100);
				cout << "También conseguiste un juego de unos! Pero estos puntos no se cuentan." << "\n";
			}
			if (game_5) {
				partial_scores.push_back(times[4] * 50);
				cout << "También conseguiste un juego de cincos! Pero estos puntos no se cuentan." << "\n";
			}
		}

		else if (trio_x) { 
			partial_scores.push_back(number * 100); 
			cout << "Conseguiste un trío de " << number << "! +" << number * 100 << "\n";
			if (game_1) {
				partial_scores.push_back(times[0] * 100);
				cout << "Tambien conseguiste un juego de unos! Pero estos puntos no se cuentan." << "\n";
			}
			if (game_5) {
				partial_scores.push_back(times[4] * 50);
				cout << "Tambien conseguiste un juego de cincos! Pero estos puntos no se cuentan." << "\n";
			}
		}

		else if (game_1) {
			partial_scores.push_back(times[0] * 100);
			cout << "Conseguiste un juego de unos! +" << times[0] * 100 << "\n";
		}

		else if (game_5) {
			partial_scores.push_back(times[4] * 50);
			cout << "Conseguiste un juego de cincos! +" << times[4] * 50 << "\n";
		}

		else {
			cout << "No conseguiste ninguna combinacion.\n";
			for (auto x : dados) { cout << x; }
			return 0;
		}

		if (sextet_win) {
			cout << "TE SALIÓ UN SEXTETO!!!" << endl << endl << endl;
			cout << "██╗    ██╗██╗███╗   ██╗███╗   ██╗███████╗██████╗" << endl;
			cout << "██║    ██║██║████╗  ██║████╗  ██║██╔════╝██╔══██╗" << endl;
			cout << "██║ █╗ ██║██║██╔██╗ ██║██╔██╗ ██║█████╗  ██████╔╝" << endl;
			cout << "██║███╗██║██║██║╚██╗██║██║╚██╗██║██╔══╝  ██╔══██╗" << endl;
			cout << "╚███╔███╔╝██║██║ ╚████║██║ ╚████║███████╗██║  ██║" << endl;
			cout << "╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝" << endl;
		}

		else {
			sort(partial_scores.begin(), partial_scores.end());
			total_score += partial_scores[(partial_scores.size() - 1)];

			for (auto x : dados)
                cout << x;

			cout << endl;
			cout << total_score;
		}
	}
}
