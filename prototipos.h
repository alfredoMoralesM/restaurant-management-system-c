//PROTOTIPOS
void crearLista();
void portada();
void datos();
void recuadro();
void selectorMenu(int posY);
void limpiaMenu(int posY, int numItems);

//prototipos para las listas
Node* createNode(PLA platillo);
NodeSimple* createNodeSimple(Node * listaCircular);
void list_insertCircular(Node* newNode); 
void informacion(Node * current, int posX, int posY);
void insertSimpleList(NodeSimple * newNode);
void carritoLista(NodeSimple *headSimpleList);
int enCarrito(NodeSimple *nodoInsertar);
