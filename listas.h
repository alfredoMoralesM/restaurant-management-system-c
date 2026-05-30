void crearLista(){
	PLA platillo;
	/*Abrimos el archivo donde tenemos guardados los datos de los platillos*/
	FILE *file = fopen("data.txt", "r");
	
	if(file == NULL){
		printf("No hay personas\n");
		fclose (file);
		return;
	}
	
	while(!feof(file)){
			fscanf(file,"%d\t%[^\t]\t%[^\t]\t%f\t%d\t%d\t%d%[^\n]\n",
			&platillo.id_plat,platillo.nom_plat, platillo.desc,&platillo.precio,&platillo.tiempo,&platillo.rated,&platillo.vigente);		
			Node* n = createNode(platillo); //Por cada platillo crearemos un nuevo nodo 
			list_insertCircular(n);	//el nodo creado por platillo lo insertamos en una lista circular doble
	}
		
	//Se cierra el archivo
	fclose(file);
}
	

Node* createNode(PLA platillo) {
	Node* newNode = new Node(); //esto es un malloc para asignar memoria al nuevo nodo
	
	//asignaciones de los valores que tendrá cada platillo obteniendolas de una estructura y pasandolas al nodo
	newNode->plato.id_plat = platillo.id_plat;
	strcpy(newNode->plato.nom_plat, platillo.nom_plat);
	strcpy(newNode->plato.desc, platillo.desc);
	newNode->plato.precio = platillo.precio;
	newNode->plato.tiempo = platillo.tiempo;
	newNode->plato.rated = platillo.rated;
	newNode->plato.vigente = platillo.vigente;
	
	newNode->next= NULL;
	newNode->prev= NULL;
	return newNode;
}

NodeSimple* createNodeSimple(Node * listaCircular) {
	NodeSimple* newNodeSimple = new NodeSimple(); /*esto es un malloc para asignar memoria al nuevo nodo simple que nos ayudará 
	a insertar en el carrito*/
	
	//asignaciones de los valores que tendrá cada nodo de platillo obteniendolas del nodo de la lista circular en la que se encontrará en el menú
	newNodeSimple->plato.id_plat = listaCircular->plato.id_plat;
	strcpy(newNodeSimple->plato.nom_plat, listaCircular->plato.nom_plat);
	strcpy(newNodeSimple->plato.desc, listaCircular->plato.desc);
	newNodeSimple->plato.precio = listaCircular->plato.precio;
	newNodeSimple->plato.tiempo = listaCircular->plato.tiempo;
	newNodeSimple->plato.rated = listaCircular->plato.rated;
	newNodeSimple->plato.vigente = listaCircular->plato.vigente;
	
	newNodeSimple->next= NULL;

	return newNodeSimple;
}

void list_insertCircular(Node * newNode) {
	//las inserciones a la lista circular se harán al final de la lista
	
	if(headDLL==NULL){ //caso donde la lista está vacía
		headDLL = newNode;
		newNode->next = newNode->prev = newNode;
		return;
	}
	
	Node* last = headDLL->prev; //guardamos el nodo del último platillo
	newNode->prev = last; //el prev del nuevo nodo se asigna el último platillo
	newNode->next = headDLL; //el next del nuevo nodo apunta a la cabeza
	last->next= newNode; //el next del último nodo debe apuntar al nuevo nodo insertado
	headDLL->prev = newNode; //el prev del nodo principal debe apuntar al nuevo nodo
}

int enCarrito(NodeSimple *nodoInsertar){ 
	/*funcion que nos permite conocer si el nuevo nodo que queremos insertar
	ya se encuentra dentro de la lista del carrito 0->no se encuentra en el carrito
	1-> ya se encuentra en el carrito*/

	NodeSimple *current = headSimpleList;
	
	if(current==NULL) return 0; //caso donde la lista está vacía retorna un 0
	
	while(current != NULL){ 
		if(current->plato.id_plat == nodoInsertar->plato.id_plat){
			return 1; //caso donde ya se encuentra en el carrito
		}
		current = current->next;
	}
	
	return 0;
}

void insertSimpleList(NodeSimple *newNode) {
    int estaEnCarrito; 
    
	NodeSimple *current = headSimpleList;
    
    estaEnCarrito= enCarrito(newNode); //verificamos si el nuevo nodo ya está dentro de la lista simple antes de insertar
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(0, 0);

    if (current == NULL) { 
		/*el caso 1:  si la lista está vacía en ese caso insertaremos el nuevo nodo y asignaremos como 1 la cantidad del nuevo producto que se agregó
    	para el subtotal multiplicaremos el precio del producto por la cantidad de productos que hay actualmente en el carrito*/
		
		newNode->cantidad = 1;
        newNode->subtotal = newNode->plato.precio * newNode->cantidad;
        headSimpleList = newNode;
        return;
    }
    
    if (enCarrito(newNode) == 1) {
    	
		/*Caso 2: si el nuevo nodo ya está dentro del carrito no insertaremos un nuevo nodo, solamente modificamos la cantidad en el mismo nodo del que se quiere 
		agregar el producto, para eso utilizamos el ciclo while que recorre la lista, cuando encuentra el producto le aumenta la cantidad y vuelva a 
		calcular el subtotal*/
		
        while (current != NULL) {
            if (current->plato.id_plat == newNode->plato.id_plat) {
                current->cantidad += 1;  
                current->subtotal = current->plato.precio * current->cantidad;
                return;  
            }
            
            current = current->next;
        }
        
    } else if(enCarrito(newNode)==0){
    	
    	/*caso 3: Si no está el producto en el carrito, recorremos la lista hasta el último nodo e insertamos el nuevo nodo a la lista
		la cantidad la igualaremos a 1 ya que es la primer vez que se agrega y calcularemos ell subtotal*/
        while (current->next != NULL) {
            current = current->next;
        }
        newNode->cantidad = 1;
        newNode->subtotal = newNode->plato.precio * newNode->cantidad;
        current->next = newNode;
    }
}



void carritoLista(NodeSimple *headSimpleList){
	
		float total=0;
		int platillos=0, tiempoEntrega=0;
		float envio=0;
		int x=35, y=5;
		char tecla= '\0';
		NodeSimple *current = headSimpleList;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 46);
		gotoxy(40, 2);
		printf("<<<<<<<<<<QUESADILLAS CHESCO PEREZ>>>>>>>>>>\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		
		/*recuadro que nos ayuda a dibuajar las secciones donde se encontrará los productos y el total de compra más el envío*/
		
		//parte inferior
		gotoxy(2, 10);
		for(int i=0;i<32;i++){
			printf("_");	
		}
		//parte superior
		gotoxy(2, 5);
		for(int i=0;i<32;i++){
			printf("_");	
		}
		
		while(current != NULL){
			
			/*Recorreremos la lista simple para imprimir todos los productos que se añadieron al carrito*/
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			x=45;
			platillos+=current->cantidad; //nos ayuda a conocer cuantos platillos en total se pidiron
			gotoxy(x,y);
			printf("NOMBRE: %s\n", current->plato.nom_plat);
			y++;
			gotoxy(x,y);
			for (int i = 0; i < 20; i++) {
			    printf("%c", current->plato.desc[i]);
			}
			y++;
			gotoxy(x,y);
			printf("PRECIO: $%.2f \n", current->plato.precio);
			y-=2;
			x+=25;
			gotoxy(x,y);
			printf("CANTIDAD: %d\n", current->cantidad);
			y++;
			gotoxy(x,y);
			printf("SUBTOTAL: $%.2f\n", current->subtotal);
			y+=2;
			gotoxy(x,y);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			gotoxy(x-25,y);
			printf("_______________________________________________________________");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			y+=5;
			
			total+= current->subtotal;
			current = current->next;
		}
			
			/*Condiciones para conocer el tiempo de entrega del pedido total */
			if(platillos<3 && platillos> 0){
				tiempoEntrega= 30;
			} else if(platillos>=3){
				tiempoEntrega= 45;
			} else if(platillos==0){
				tiempoEntrega=0;
			}
			
			/*Calculamos el costo de envío*/
			envio = total*0.10;
			
			/*Imprimimos la seccion de total, tiempo y costo de entrega*/
			gotoxy(3,8);
			printf("ENTREGA\n");
			gotoxy(3,9);
			printf("%d MINUTOS", tiempoEntrega);
			gotoxy(15,8);
			printf("ENVIO\n");
			gotoxy(15,9);
			printf("$%.2f", envio);
			gotoxy(25,8);
			printf("TOTAL\n");
			gotoxy(25,9);
			printf("$%.2f", total);
			
			gotoxy(3,20);
			printf("PRESIONA 't' PARA TERMINAR LA COMPRA");
			gotoxy(3,21);
			printf("PRESIONA 'r' PARA AGREGAR ");
			gotoxy(3,22);
			printf(" MAS PRODUCTOS AL CARRITO");
			gotoxy(3,23);
		
			tecla= getch();
			
			/*Si el usuario presiona la tecla 'r' el usuario puede regresar a agregar más productos*/
			if(tecla==114 ||  tecla==82){ //si tecla es 'r'
				system("cls");
				selectorMenu(6);	
			}  
			
			/*Si el usuario presiona la tecla 't' la compra se finaliza y el usuario saldrá del sistema presionando Enter*/
			if(tecla==116 || tecla==84){ //tecla 't'
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 46);
				gotoxy(3,25);
				printf("COMPRA COMPLETADA");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				gotoxy(3,26);
				printf("PRESIONA 'Enter' PARA SALIR DEL SISTEMA");
				gotoxy(3,28);
				
				tecla=getch();
				
				if(tecla==13){ //tecla enter
					system("cls");
					return;
				}
		}  
}


