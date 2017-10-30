
typedef struct _nodo {
    char nombre[20];
    int costo;
    struct _nodo *siguiente;
}Nodo;

typedef struct _cola{
  Nodo *inicio;
  Nodo *final;  
}Cola;

/*  FUNCIONES DE COLA  */ 


void inicializa(Cola *cola){
  cola->inicio = NULL;
  cola->final = NULL; 
}
  
/* cola push */
void push(Cola *cola, char nombre[20], int costo) {
	/* Crear un nodo nuevo */
  Nodo *nuevo;
  nuevo = (Nodo*)malloc(sizeof(Nodo));

  strcpy(nuevo->nombre,nombre);
  nuevo->costo=costo;
  /* Este será el último nodo, no debe tener siguiente */
  nuevo->siguiente = NULL;

  /* Si primero es NULL, la cola estaba vacía, ahora primero apuntará también al nuevo nodo */
  printf(" \n pushh nodo: %s", nuevo->nombre);
  printf("\n");
  
  if(cola->inicio==NULL){
    //printf("\nAcá 1ro:\n");
    cola->inicio = nuevo;
    //printf("\n Acá pushh 1ro: %s", cola->inicio->nombre);
  
  }

  /* Si la cola no estaba vacía, añadimos el nuevo a continuación de ultimo */
  if(cola->final!=NULL)
    cola->final->siguiente = nuevo;
  
  /* Ahora, el último elemento de la cola es el nuevo nodo */
  cola->final= nuevo;
}

/* cola pop */
void pop(Cola *cola) {
  Nodo *nodo_pop;
  //if (primero==NULL){
  if (cola->inicio==NULL){
    printf( "\nLa lista está vacía!! (pop)\n" );
    return;
  }  
  nodo_pop = cola->inicio;
  cola->inicio = nodo_pop->siguiente;
  
  printf("pop primero: %s", nodo_pop->nombre);
  printf("\n");
  free(nodo_pop);
}

/* Imprimir cola */
void print_cola(Cola *cola){
	Nodo *auxiliar;
	auxiliar = cola->inicio;
  printf("\nMostrando cola completa:\n");
  if (auxiliar==NULL) printf( "\nLa lista está vacía!!\n" );
  while (auxiliar!=NULL) {
    printf("nombre: %s", auxiliar->nombre);
    printf(" costo: %d", auxiliar->costo);
    printf("\n");
    auxiliar = auxiliar->siguiente;
  }
  printf("\n");
}
