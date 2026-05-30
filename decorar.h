void datos(){
	/*Imprime toda la información del proyecto justo del lado derecho de la imagen de portada*/
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 30);
	gotoxy(80, 5);
	printf("QUESADILLAS 'CHESCO PEREZ'", 130, 161);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 96);
	gotoxy(75, 10);
	printf("Universidad Polit%ccnica de San Luis Potos%c", 130, 161);
	gotoxy(80, 11);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),96);
	printf("Laboratorio Programaci%cn II", 162);
	gotoxy(85, 12);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 96);
	printf("Proyecto Restaurante");
	gotoxy(78, 13);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 96);
	printf("Morales Meza Christian Alfredo ");
	gotoxy(85, 14);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 96);
	printf("Beltran Reyna David");
	gotoxy(82, 15);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 96);
	printf("Matr%ccula 184937 & 183636", 161);
	gotoxy(81, 20);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 46);
	printf("Cualquier tecla para continuar");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void portada(){
	int aux=0;
	FILE *archivo = fopen("portada.txt", "r");
	
	/*leemos el archivo txt recorriendo el archivo mediante dos ciclos for para conocer el color del
	cual colocaremos la figura*/
	for (int i=0; i<26; i++){
		for (int j=0; j<72; j++){
			fscanf(archivo, "%d\t", &aux);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), aux);
			printf("%c", 219);
		}
		printf("\n");
	}
}

void recuadro(){

	/*funcion que ayuda a dibujar el recuadro en la parte derecha de la pantalla
	para colocar la informacion de los productos*/
	
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),10);
	int ladoY=5;
	
	//lado izquierdo
	for(int i=0;i<10;i++){
		gotoxy(58, ladoY);
		printf("%c", 186);
		ladoY++; 
		gotoxy(58, ladoY);
		printf("%c", 0);
		ladoY++;	
	}
	
	//parte inferior
	gotoxy(59, ladoY-1);
	for(int i=0;i<20;i++){
		printf("%c ", 205);	
	}
	
	//parte superior
	gotoxy(59, 4);
	for(int i=0;i<20;i++){
		printf("%c ", 205);	
	}
	
	
	//lado derecho
	ladoY=5;
	for(int i=0; i<10; i++){
		gotoxy(98, ladoY);
		printf("%c", 186);
		ladoY++; 
		gotoxy(98, ladoY);
		printf("%c", 0);
		ladoY++;	
	}
	
}
