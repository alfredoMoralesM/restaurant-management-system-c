#include <stdio.h>
#include <stdlib.h> //libreria para asignacion de memoria
#include <string.h> //libreria para srtcpy
#include <windows.h> //libreria para system cls
#include <conio.h> //libreria para getch
#include <locale.h> //libreria para setlocale

void gotoxy(int x, int y){
	HANDLE hcon= GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dWPos;
	dWPos.X=x;
	dWPos.Y=y;
	SetConsoleCursorPosition(hcon, dWPos);
}

//estructura para definir cada platillo
typedef struct {
	int id_plat;          //id unico del platillo del 100 al 500
	char nom_plat[50];    //nombre corto del platillo
	char desc[200];		  //descripcion del platillo, que contiene
	float precio;         //precio a la venta
	int tiempo;           //tiempo de preparacion
	int rated;            //calificacion de 1 a 5 estrellas
	int vigente;		  //controla si aun se vende o no ese platillo	
}PLA;

typedef struct Node{
	PLA plato;
	int vigencia= 5;
	struct Node* prev;
	struct Node* next;
}Node;

typedef struct NodeSimple{
	PLA plato;
	int cantidad;
	float subtotal;
	int vigente=5;
	struct NodeSimple* next;
	
}NodeSimple;

Node* headDLL;
NodeSimple* headSimpleList; 

#include "prototipos.h"
#include "listas.h"
#include "menu.h"
#include "decorar.h"


