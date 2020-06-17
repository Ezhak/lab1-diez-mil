#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>

using namespace std;

void dibujoDado1() {
	cout << "¦¦¦¦¦¦¦¦¦" << endl;
	cout << "¦       ¦" << endl;
	cout << "¦   o   ¦" << endl;
	cout << "¦       ¦" << endl;
	cout << "¦¦¦¦¦¦¦¦¦" << endl;
	cout << "" << endl;
}
void dibujoDado2() {
	cout << "¦¦¦¦¦¦¦¦¦" << endl;
	cout << "¦o      ¦" << endl;
	cout << "¦       ¦" << endl;
	cout << "¦      o¦" << endl;
	cout << "¦¦¦¦¦¦¦¦¦" << endl;
	cout << "" << endl;
}
void dibujoDado3() {
	cout << "¦¦¦¦¦¦¦¦¦" << endl;
	cout << "¦o      ¦" << endl;
	cout << "¦   o   ¦" << endl;
	cout << "¦      o¦" << endl;
	cout << "¦¦¦¦¦¦¦¦¦" << endl;
	cout << "" << endl;
}
void dibujoDado4() {
	cout << "¦¦¦¦¦¦¦¦¦" << endl;
	cout << "¦o     o¦" << endl;
	cout << "¦       ¦" << endl;
	cout << "¦o     o¦" << endl;
	cout << "¦¦¦¦¦¦¦¦¦" << endl;
	cout << "" << endl;
}
void dibujoDado5() {
	cout << "¦¦¦¦¦¦¦¦¦" << endl;
	cout << "¦o     o¦" << endl;
	cout << "¦   o   ¦" << endl;
	cout << "¦o     o¦" << endl;
	cout << "¦¦¦¦¦¦¦¦¦" << endl;
	cout << "" << endl;
}
void dibujoDado6() {
	cout << "¦¦¦¦¦¦¦¦¦" << endl;
	cout << "¦o     o¦" << endl;
	cout << "¦o     o¦" << endl;
	cout << "¦o     o¦" << endl;
	cout << "¦¦¦¦¦¦¦¦¦" << endl;
	cout << "" << endl;
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
			dibujoDado1();
			cout << " " << endl;
			break;
		case 2:
			dibujoDado2();
			cout << " " << endl;
			break;
		case 3:
			dibujoDado3();
			cout << " " << endl;
			break;
		case 4:
			dibujoDado4();
			cout << " " << endl;
			break;
		case 5:
			dibujoDado5();
			cout << " " << endl;
			break;
		case 6:
			dibujoDado6();
			cout << " " << endl;
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
