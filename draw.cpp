#include "draw.h"

void gotoxy(int x, int y)
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h, c);
}

int dibujar_ui(int x, int y)
{
    for (int i = 2; i < y; i++) {
        gotoxy(i, 0); putchar(205); //lado arriba
        gotoxy(i, x); putchar(205); //lado abajo
    }
    gotoxy(1, 0); putchar(201); //esquina arriba izquierda
    gotoxy(y, 0); putchar(187); //esquina arriba derecha

    for (int i = 1; i < x; i++) {
        gotoxy(1, i); putchar(186); //lado izquierdo
        gotoxy(y, i); putchar(186); //lado derecho
    }
    gotoxy(1, x); putchar(200); //esquina abajo izquierdo
    gotoxy(y, x); putchar(188); //esquina abajo derecho

    return(x);
}

void dibujar_marco(int x)
{
    int offset_x = 10 * x;
    for (int i = 3 + offset_x; i <= 11 + offset_x; i++) {
        gotoxy(i, 1); putchar(220); //lado arriba
        gotoxy(i, 5); putchar(223); //lado abajo
    }

    for (int i = 2; i < 5; i++) {
        gotoxy(3 + offset_x, i); putchar(219); //lado izquierdo
        gotoxy(11 + offset_x, i); putchar(219); //lado derecho
    }
}

void dibujar_dado(int x, int y)
{
    int offset_x = 10 * x;
    dibujar_marco(x);

    switch (y) {
    case 1:
        gotoxy(7 + offset_x, 3); putchar(254); //medio
        gotoxy(9 + offset_x, 4); printf(" "); //espacio
        break;
    case 2:
        gotoxy(5 + offset_x, 2); putchar(254); //punto izquierdo alto
        gotoxy(9 + offset_x, 4); putchar(254); //punto derecho bajo
        break;
    case 3:
        gotoxy(5 + offset_x, 2); putchar(254); //punto izquierdo alto
        gotoxy(7 + offset_x, 3); putchar(254); //medio
        gotoxy(9 + offset_x, 4); putchar(254); //punto derecho bajo
        break;
    case 4:
        gotoxy(5 + offset_x, 2); putchar(254); //punto izquierdo alto
        gotoxy(5 + offset_x, 4); putchar(254); //punto izquierdo bajo
        gotoxy(9 + offset_x, 2); putchar(254); //punto derecho alto
        gotoxy(9 + offset_x, 4); putchar(254); //punto derecho bajo
        break;
    case 5:
        gotoxy(5 + offset_x, 2); putchar(254); //punto izquierdo alto
        gotoxy(5 + offset_x, 4); putchar(254); //punto izquierdo bajo
        gotoxy(7 + offset_x, 3); putchar(254); //medio
        gotoxy(9 + offset_x, 2); putchar(254); //punto derecho alto
        gotoxy(9 + offset_x, 4); putchar(254); //punto derecho bajo
        break;
    case 6:
        gotoxy(5 + offset_x, 2); putchar(254); //punto izquierdo alto
        gotoxy(5 + offset_x, 3); putchar(254); //punto izquierdo medio
        gotoxy(5 + offset_x, 4); putchar(254); //punto izquierdo bajo
        gotoxy(9 + offset_x, 2); putchar(254); //punto derecho alto
        gotoxy(9 + offset_x, 3); putchar(254); //punto derecho medio
        gotoxy(9 + offset_x, 4); putchar(254); //punto derecho bajo
        break;
    default:
        break;
    }
}

void menu_de_inicio()
{
	dibujar_ui(15, 75);
	gotoxy(3, 2);
	cout << "Bienvenido al juego de 10000!";
	gotoxy(3, 3);
	cout << "Por favor elija un modo de juego:";
	gotoxy(5, 4);
	cout << "1- Modo de 1 jugador.";
	gotoxy(5, 5);
	cout << "2- Modo de 2 jugadores.";
}

void menu_intermedio(int ronda, int puntaje_1, int puntaje_2, string name1, string name2)
{
	dibujar_ui(15, 76);
	for (int i = 3; i < 75; i++) {
		gotoxy(i, 1); putchar(196); //lado arriba
		gotoxy(i, 14); putchar(196); //lado abajo
	}
	gotoxy(2, 1); putchar(218); //esquina arriba izquierda
	gotoxy(75, 1); putchar(191); //esquina arriba derecha

	for (int i = 2; i < 14; i++)
	{
		gotoxy(2, i); putchar(179); //lado izquierdo
		gotoxy(75, i); putchar(179); //lado derecho
	}
	gotoxy(2, 14); putchar(192); //esquina abajo izquierdo
	gotoxy(75, 14); putchar(217); //esquina abajo derecho

	gotoxy(33, 5); cout << "RONDA N° " << ronda;
	gotoxy(28, 6); cout << "PROXIMO TURNO: " << name1;
	gotoxy(25, 8); cout << "Puntaje " << name1 << ": " << puntaje_1;
	gotoxy(25, 9); cout << "Puntaje " << name2 << ": " << puntaje_2;
}
