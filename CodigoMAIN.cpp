#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>
#include <windows.h> 
#include <stdio.h>

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
	srand(time(NULL)); //rand
	vector<int> dados; //tiro de dados
	vector<int> cont; //contador de numeros
	for (int i = 0; i < 6; i++) //carga el tiro de dados (vector)
	{
		dados.push_back(rand() % 6 + 1); //numeros random del 1 al 6
	}
	for (int x = 1; x <= 6; x++)
	{
		int count_x = count(dados.begin(), dados.end(), x); //cuenta cuantas veces aparece un numero(x) en el tiro
		cont.push_back(count_x);
	}

	//Combinaciones especiales
	bool sexteto = false; //Seis unos
	bool tri_amp = false; //Cuatro o cinco unos
	bool tri = false; //Tres unos
	bool tri_par = false; //Tres pares
	bool juego_1 = false; //uno o dos unos
	bool juego_5 = false; //uno o dos cinco
	bool trio_x = false; //tres de un numero
	bool trio_xx = false; //cuatro o cinco de un numero
	int escalera_larga = 0; //una escalera de numeros (1-6)
	//Puntajes
	int puntaje_total = 0;
	int puntaje_partida = 0;
	bool ganador_sex = false;
	//aux
	int numero;

	for (auto n : cont) //chequea si el tiro es una escalera larga
	{
		if (n == 1) escalera_larga++;
		else break;
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

	if (escalera_larga != 6) //chequea por trio, trio ampliado o un sexteto (si es que no hay una escalera)
	{
		if (cont[0] > 2)
		{
			if ((cont[0] == 4) || (cont[0] == 5)) tri_amp = true;
			else if (cont[0] == 3) tri = true;
			else sexteto = true;
		}

		if ((tri == false) && (tri_amp == false) && (sexteto == false))
		{
			tri_par = true;
			for (auto n : cont) //chequea si hay triple par (si no hay ninguno de los trios o sextetos)
			{
				if (n % 2 != 0)
				{
					tri_par = false;
					break;
				}
			}
			for (int i = 1; i < 6; i++) //chequea si hay un trio o un trio++
			{
				if (cont[i] == 3) 
				{
					trio_x = true; 
					numero = i + 1;
				}
				else if ((cont[i] == 4) || (cont[i] == 5)) {
					trio_xx = true; 
					numero = i + 1;
				}
			}
		}

		if ((tri_par == false) && (sexteto == false)) //chequea si hay juegos de unos o cincos
		{
			if ((cont[0] == 1) || (cont[0] == 2)) juego_1 = true;
			if ((cont[4] == 1) || (cont[4] == 2)) juego_5 = true;
		}
	}
	
	//Puntajes

	if (sexteto == true) ganador_sex = true;
	else {
		vector<int> puntaje; //para chequear cual es el puntaje mas grande;
		if (tri_amp == true) 
		{ 
			puntaje.push_back(2000); 
			cout << "Conseguiste un trio ampliado! +2000\n";
		}
		else if (escalera_larga == 6) 
		{ 
			puntaje.push_back(1500); 
			cout << "Conseguiste una escalera larga! +1500\n";
		}
		else if (tri_par == true) 
		{ 
			puntaje.push_back(1000); 
			cout << "Conseguiste un triple par! +1000\n";
		}
		else if (trio_xx == true) 
		{ 
			puntaje.push_back(numero * 200); 
			cout << "Conseguiste un trio ampliado de " << numero << "! +" << numero * 200 << "\n";
			if (juego_1 == true)
			{
				puntaje.push_back(cont[0] * 100);
				cout << "Tambien conseguiste un juego de unos! Pero estos puntos no se cuentan." << "\n";
			}
			if (juego_5 == true)
			{
				puntaje.push_back(cont[4] * 50);
				cout << "Tambien conseguiste un juego de cincos! Pero estos puntos no se cuentan." << "\n";
			}
		}
		else if (tri == true)
		{
			puntaje.push_back(1000);
			cout << "Conseguite un trio! +1000\n";
			if (juego_1 == true)
			{
				puntaje.push_back(cont[0] * 100);
				cout << "Tambien conseguiste un juego de unos! Pero estos puntos no se cuentan." << "\n";
			}
			if (juego_5 == true)
			{
				puntaje.push_back(cont[4] * 50);
				cout << "Tambien conseguiste un juego de cincos! Pero estos puntos no se cuentan." << "\n";
			}
		}
		else if (trio_x == true) 
		{ 
			puntaje.push_back(numero * 100); 
			cout << "Conseguiste un trio de " << numero << "! +" << numero * 100 << "\n";
			if (juego_1 == true)
			{
				puntaje.push_back(cont[0] * 100);
				cout << "Tambien conseguiste un juego de unos! Pero estos puntos no se cuentan." << "\n";
			}
			if (juego_5 == true)
			{
				puntaje.push_back(cont[4] * 50);
				cout << "Tambien conseguiste un juego de cincos! Pero estos puntos no se cuentan." << "\n";
			}
		}
		else if (juego_1 == true)
		{
			puntaje.push_back(cont[0] * 100);
			cout << "Conseguiste un juego de unos! +" << cont[0] * 100 << "\n";
		}
		else if (juego_5 == true)
		{
			puntaje.push_back(cont[4] * 50);
			cout << "Conseguiste un juego de cincos! +" << cont[4] * 50 << "\n";
		}
		else 
		{
			cout << "No conseguiste ninguna combinacion.\n";
			for (auto x : dados) { cout << x; }
			return 0;
		}
		
		if (ganador_sex == true) 
		{
			cout << "TE SALIO UN SEXTETO!!!" << endl << endl << endl; //Completar acá <---
			cout << "██╗    ██╗██╗███╗   ██╗███╗   ██╗███████╗██████╗" << endl;
			cout << "██║    ██║██║████╗  ██║████╗  ██║██╔════╝██╔══██╗" << endl;
			cout << "██║ █╗ ██║██║██╔██╗ ██║██╔██╗ ██║█████╗  ██████╔╝" << endl;
			cout << "██║███╗██║██║██║╚██╗██║██║╚██╗██║██╔══╝  ██╔══██╗" << endl;
			cout << "╚███╔███╔╝██║██║ ╚████║██║ ╚████║███████╗██║  ██║" << endl;
			cout << "╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝" << endl;
		}
		else
		{
			sort(puntaje.begin(), puntaje.end());
			puntaje_partida += puntaje[(puntaje.size() - 1)];

			for (auto x : dados) { cout << x; }
			cout << endl;
			cout << puntaje_partida;
		}
	}
}