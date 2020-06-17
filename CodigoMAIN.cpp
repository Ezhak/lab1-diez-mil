#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>
using namespace std;

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
	bool tri_par = true; //Tres pares
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

	if (escalera_larga != 6) //chequea por trio, trio ampliado o un sexteto (si es que no hay una escalera)
	{
		if (cont[0] > 2)
		{
			if ((cont[0] == 4) or (cont[0] == 5)) tri_amp = true;
			else if (cont[0] == 3) tri = true;
			else sexteto = true;
		}

		if ((tri == false) && (tri_amp == false) && (sexteto == false))
		{
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
				else if ((cont[i] == 4) or (cont[i] == 5)) {
					trio_xx = true; 
					numero = i + 1;
				}
			}
		}

		if ((tri_par == false) && (sexteto == false)) //chequea si hay juegos de unos o cincos
		{
			if ((cont[0] == 1) or (cont[0] == 2)) juego_1 = true;
			if ((cont[4] == 1) or (cont[4] == 2)) juego_5 = true;
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
			cout << "ganador!"; //Completar acá <---
		}
		else
		{
			sort(puntaje.begin(), puntaje.end());
			int lugar = puntaje.size() - 1;
			puntaje_partida += puntaje[lugar];

			for (auto x : dados) { cout << x; }
			cout << endl;
			cout << puntaje_partida;
		}
	}
}