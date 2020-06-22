#ifndef __DRAW_H_
#define __DRAW_H_

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
using namespace std;

void gotoxy(int, int);

int dibujar_ui(int, int);

void dibujar_marco(int);

void dibujar_dado(int, int);

void menu_de_inicio();

void menu_intermedio(int, int, int, string, string);

#endif // __DRAW_H_
