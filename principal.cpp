#include "librerias.h"
//archivo de hoy documentado individual

int main(){
	
	//posiciones iniciales del menú
	int posY=6, posX=20;
	
	//Portada
	portada();
	datos();
	getch();
	system("cls");
	
	//Creacion de lista
	crearLista();
	
	//Funcionalidad menú
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	selectorMenu(posY);	
	
	return 0;
}
