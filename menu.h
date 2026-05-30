void presentaMenu(Node * iter, int posY){
	Node *aux = iter;
	int repeat=0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); //Color del encabezado (amarillo)
	
	/*limpiamos la pantalla antes de imprimir, haciendo que se imprima espacio en blanco donde anteriormente habian datos
	Dejo los espacios para no hacer otro ciclo for adentro que imprima los espacios en blanco*/
 	
	 for (int i = 0; i < 5; i++) {
        gotoxy(5, posY);
        printf("                          "); // Espacio en blanco para limpiar línea
        gotoxy(25, posY);
        printf("       "); // Espacio en blanco para limpiar el precio
        posY += 2; // Mueve a la siguiente línea del menú
    }
    
    posY=6; //reseteamos la posicion en Y donde volveremos a imprimir los datos
    
	 do {
	 	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15); //color negro
        gotoxy(5, posY);
        printf("%s", aux->plato.nom_plat);
        
        gotoxy(25, posY);
        printf("$%.2f", aux->plato.precio);
        
		posY+=2; //espaciado de dos lineas entre productos
		repeat++;
		
        aux = aux->next;
        
    } while(repeat<5); 
		 	 
}


void selectorMenu(int posY){
		Node* iter = headDLL; //Nodo para saber en que nodo de información nos encontramos para mostrarlo
		Node* first= iter; //Nodo que utilizamos para saber cual es el primer dato que se imprime a partir de este imprimir los siguientes 4 nodos

		char tecla='\0';
		int posX=62,currentOpc=1, selectorY=posY;
		
		//recuadro derecho
		recuadro();
		
		//encabezado
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 30);
		gotoxy(35,1); 
		printf("<<<<<<<<<<QUESADILLAS CHESCO PEREZ>>>>>>>>>>");
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		gotoxy(2,20); 
		printf("Tecla 'Enter' -> Para agregar al carrito");
		gotoxy(2,21); 
		printf("Tecla 'c' -> Para ir al carrito");
		gotoxy(2,22);
		printf("Tecla 'Esc' -> Para salir del sistema");
		
		//color y forma del selector
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),10);
		gotoxy(1, posY); 
		printf(">>");
		
		//imprime la informacion y el menú por primera vez
		presentaMenu(iter, posY);
		informacion(iter, posX, posY);
		
		do{
		
		tecla= getch();  //toma el valor de la tecla presionada	
		
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),0); //colorea en negro el selector anterior para que no quede impreso
 	    gotoxy(1,selectorY);
	    printf(">>");
	    
	    if(tecla==99 || tecla==67){ //tecla 'c' que permite dirigir al usuario a la sección del carrito de compras
	    	system("cls");
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 30);
			gotoxy(0, 0);
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);
	    	carritoLista(headSimpleList);
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 46);
			gotoxy(35, 5);
	    	printf("<<<<<<<<<<HAS SALIDO DEL SISTEMA>>>>>>>>>>\n");
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	    	return;
		}
		
	    if(tecla==13){ //tecla Enter agrega nuevos productos a la lista simple
	    	iter->vigencia-=1; //La vigencia del producto debe disminuir cada que se agrega 
	    	NodeSimple * nuevoNodo= createNodeSimple(iter); //Creamos el nuevo nodo
	    	if(iter->vigencia>=0) { //validamos si el producto está vigente(>=0) si lo es insertamos el nuevo nodo a la lista simple 
	    		insertSimpleList(nuevoNodo);
	    		gotoxy(5,25); 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 78);
				printf("AÑADIDO AL CARRITO"); //Imprimimos el mensaje de añadido al carrito
			}	
			else{ //si la videncia del producto es 0 no permitirá ingresar un nuevo producto 
				gotoxy(5,25); 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 78);
				printf("PRODUCTO SIN VIGENCIA");	
			} 
		
		}
		
		if(tecla==80){ //tecla ABAJO 	
			
			//borrar mensaje de añadido al carrito
			gotoxy(5,25); 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		    printf("AÑADIDO AL CARRITO");
		    
			iter= iter->next;
			informacion(iter, posX, posY);
			currentOpc++;
		 	selectorY+=2;
			
			if(currentOpc==6){
				first= first->next; //actualizamos el primer dato que debemos mostrar
				presentaMenu(first, posY);
				selectorY-=2; //cambiamos la posiion donde debe imprimirse
				currentOpc--; //la opcion disminuye
			}
		
		}
		
		if(tecla==72){//ARRIBA
			//borrar mensaje de añadido al carrito
			gotoxy(5,25); 
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		    printf("AÑADIDO AL CARRITO");
		
			//mostramos la información del nodo anterior
			iter= iter->prev;
			informacion(iter, posX, posY);
		 	currentOpc--;
			selectorY-=2;
			
			//si se regresa al nodo anterior del primero que se muestra
			if(currentOpc==0){
				first= first->prev;//actualizamos el primer dato que debemos mostrar 
				presentaMenu(first, posY); //imprimimos a partir del primer dato que se debe mostrar. En este caso el nodo anterior al primer nodo del menú anterior
				selectorY+=2; //dejamos el selector en la misma posición ya que anteriormente debiamos restarle para que subiera, queda en la primer posicion
				currentOpc+=1; //la opcion queda nuevamente en 1, ya que anteriormente habia quedado en 0
			}
		}
		
		//volvemos a imprimir el selector actualizado
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),10);
		gotoxy(1,selectorY);
		printf(">>");
		
		} while(tecla!=27); //se sale del menú al precionar ESC
		
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 46);
		gotoxy(35, 5);
		printf("<<<<<<<<<<HAS SALIDO DEL SISTEMA>>>>>>>>>>\n");
		printf("\n");
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);
		 
}


void informacion(Node * current, int posX, int posY){
		int caracteresTexto = 35; // Define el número maximo de caracteres por linea
		int currentTexto = 0; // Contador de caracteres en la linea actual
	
		//id del platillo
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);//color negro
		gotoxy(posX, posY);
		printf("PLATILLO: %d", current->plato.id_plat);
		posY+=2;
		
		//limpiamos el espacio del nombre del platillo anterior para poder imprimir el nuevo nombre sin que queden caracteres anteriores
		for(int i=0; i<30; i++){
			gotoxy(posX, posY);
			printf(" ");
			posX++;
		}
		
		posX= 62; //reasignamos la posicion de X para imprimir en el mismo lugar
		
		//nombre del platillo
		gotoxy(posX, posY);
		printf("%s", current->plato.nom_plat);
		posY+=2;
		int aux= posY; /*guardo la posicion de 'Y' en que se deberá escribir la descripción, ya que el siguiente 
		for limpiará la descripción anterior y modificará la posY*/
		
		gotoxy(posX, posY);
		for (int i = 0; i < 200; i++) {
		    printf(" ");
		    currentTexto++;
		    // Si se llega al límite de la línea se cambia de línea
		    if (currentTexto >= caracteresTexto) {
		        posY += 1; // Mover a la siguiente línea
		        gotoxy(posX, posY);
		        currentTexto = 0; // Reiniciar el contador de caracteres
		    }
		}
		
		/*descripcion del platillo, recorro caracter por caracter, si llego al limite de caracteres por linea sigo escribiendo el resto una 
		linea abajo, para que funcione como salto de linea*/
		
		posY=aux;
		gotoxy(posX, posY);
		currentTexto=0;
		
		for (int i = 0; i < 200; i++) {
		    printf("%c", current->plato.desc[i]);
		    currentTexto++;
		    // Si se llega al límite de la línea se cambia de línea
		    if (currentTexto >= caracteresTexto) {
		        posY += 1; // Mover a la siguiente línea
		        gotoxy(posX, posY);
		        currentTexto = 0; // Reiniciar el contador de caracteres
		    }
		}
		
		//precio del platillo
		gotoxy(posX, posY);
		printf("$%.2f", current->plato.precio);
		posY+=2;
		
		//Tiempo de coccion
		gotoxy(posX, posY);
		printf("%d MINUTOS", current->plato.tiempo);
		posY+=2;
		
		//Calificacion
		gotoxy(posX, posY);
		printf("CALIFICACION: %d ESTRELLAS", current->plato.rated);
		posY+=2;
		
		//Calificacion
		gotoxy(posX, posY);
		if(current->vigencia<=0){
			printf("VIGENCIA: 0");	
		}else{
			printf("VIGENCIA: 1");
		}
}
