#include <iostream>
#include <algorithm>
#include <functional>
#include <random>
#include <vector>
#include <time.h>
#include <Windows.h> 
#include <stdio.h>
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

//JUEGO
int main()
{
	//dado 1
	for (int i = 1; i <= 9; i++) {
		gotoxy(i, 0); printf("%c", 220); //lado arriba
		gotoxy(i, 4); printf("%c", 223); //lado abajo
	}
	for (int i = 1; i < 4; i++)
	{
		gotoxy(1, i); printf("%c", 219); //lado izquierdo
		gotoxy(9, i); printf("%c", 219); //lado derecho
	}

	//dado 2
	for (int i = 1 + 10; i <= 9 + 10; i++) {
		gotoxy(i, 0); printf("%c", 220); //lado arriba
		gotoxy(i, 4); printf("%c", 223); //lado abajo
	}
	for (int i = 1; i < 4; i++)
	{
		gotoxy(1 + 10, i); printf("%c", 219); //lado izquierdo
		gotoxy(9 + 10, i); printf("%c", 219); //lado derecho
	}

	//dado 3
	for (int i = 1 + 10 * 2; i <= 9 + 10 * 2; i++) {
		gotoxy(i, 0); printf("%c", 220); //lado arriba
		gotoxy(i, 4); printf("%c", 223); //lado abajo
	}
	for (int i = 1; i < 4; i++)
	{
		gotoxy(1 + 10 * 2, i); printf("%c", 219); //lado izquierdo
		gotoxy(9 + 10 * 2, i); printf("%c", 219); //lado derecho
	}

	//dado 4
	for (int i = 1 + 10 * 3; i <= 9 + 10 * 3; i++) {
		gotoxy(i, 0); printf("%c", 220); //lado arriba
		gotoxy(i, 4); printf("%c", 223); //lado abajo
	}
	for (int i = 1; i < 4; i++)
	{
		gotoxy(1 + 10 * 3, i); printf("%c", 219); //lado izquierdo
		gotoxy(9 + 10 * 3, i); printf("%c", 219); //lado derecho
	}

	//dado 5
	for (int i = 1 + 10 * 4; i <= 9 + 10 * 4; i++) {
		gotoxy(i, 0); printf("%c", 220); //lado arriba
		gotoxy(i, 4); printf("%c", 223); //lado abajo
	}
	for (int i = 1; i < 4; i++)
	{
		gotoxy(1 + 10 * 4, i); printf("%c", 219); //lado izquierdo
		gotoxy(9 + 10 * 4, i); printf("%c", 219); //lado derecho
	}

	//dado 6
	for (int i = 1 + 10 * 5; i <= 9 + 10 * 5; i++) {
		gotoxy(i, 0); printf("%c", 220); //lado arriba
		gotoxy(i, 4); printf("%c", 223); //lado abajo
	}
	for (int i = 1; i < 4; i++)
	{
		gotoxy(1 + 10 * 5, i); printf("%c", 219); //lado izquierdo
		gotoxy(9 + 10 * 5, i); printf("%c", 219); //lado derecho
	}

	//srand(time(NULL));  // Init randomizer
    //// Setup ONCE
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1,6);

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


	int pos = 0;
	int i = 0;
	for (auto x : dices)
	{
		switch (x)
		{
		case 1:
			for (i; i < 6; i++)
			{
				if (dices[i] == 1)
				{
					pos = (10 * i);
					break;
				}
			}
			i++;
			gotoxy(5 + pos, 2); printf("%c", 254); //medio
			break;
		case 2:
			for (i; i < 6; i++)
			{
				if (dices[i] == 2)
				{
					pos = (10 * i);
					break;
				}
			}
			i++;
			gotoxy(3 + pos, 1); printf("%c", 254); //punto izquierdo alto
			gotoxy(7 + pos, 3); printf("%c", 254); //punto derecho bajo
			break;

		case 3:
			for (i; i < 6; i++)
			{
				if (dices[i] == 3)
				{
					pos = (10 * i);
					break;
				}
			}
			i++;
			gotoxy(3 + pos, 1); printf("%c", 254); //punto izquierdo alto
			gotoxy(5 + pos, 2); printf("%c", 254); //medio
			gotoxy(7 + pos, 3); printf("%c", 254); //punto derecho bajo
			break;

		case 4:
			for (i; i < 6; i++)
			{
				if (dices[i] == 4)
				{
					pos = (10 * i);
					break;
				}
			}
			i++;
			gotoxy(3 + pos, 1); printf("%c", 254); //punto izquierdo alto
			gotoxy(3 + pos, 3); printf("%c", 254); //punto izquierdo bajo
			gotoxy(7 + pos, 1); printf("%c", 254); //punto derecho alto
			gotoxy(7 + pos, 3); printf("%c", 254); //punto derecho bajo
			break;
		case 5:
			for (i; i < 6; i++)
			{
				if (dices[i] == 5)
				{
					pos = (10 * i);
					break;
				}
			}
			i++;
			gotoxy(3 + pos, 1); printf("%c", 254); //punto izquierdo alto
			gotoxy(3 + pos, 3); printf("%c", 254); //punto izquierdo bajo
			gotoxy(5 + pos, 2); printf("%c", 254); //medio
			gotoxy(7 + pos, 1); printf("%c", 254); //punto derecho alto
			gotoxy(7 + pos, 3); printf("%c", 254); //punto derecho bajo
			break;
		case 6:
			for (i; i < 6; i++)
			{
				if (dices[i] == 6)
				{
					pos = (10 * i);
					break;
				}
			}
			i++;
			gotoxy(3 + pos, 1); printf("%c", 254); //punto izquierdo alto
			gotoxy(3 + pos, 2); printf("%c", 254); //punto izquierdo medio
			gotoxy(3 + pos, 3); printf("%c", 254); //punto izquierdo bajo
			gotoxy(7 + pos, 1); printf("%c", 254); //punto derecho alto
			gotoxy(7 + pos, 2); printf("%c", 254); //punto derecho medio
			gotoxy(7 + pos, 3); printf("%c", 254); //punto derecho bajo
			break;
		default:
			break;
		}
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
			for (auto x : dices) 
                cout << x;

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
            return 0;
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
}
