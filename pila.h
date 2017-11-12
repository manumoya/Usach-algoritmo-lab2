
typedef struct _nodo {
    char nombre[20];
    int costo;
    struct _nodo *siguiente;
}Nodo;


typedef struct _pila{
  Nodo *inicio;
  Nodo *final;  
}Pila;

/*  FUNCIONES DE COLA  */ 


void inicializa(Pila *pila){
  pila->inicio = NULL;
  pila->final = NULL; 
}

/* pila push */
void push(Pila *pila, char nombre[20], int costo) {
	/* Crear un nodo nuevo */
  Nodo *nuevo;
  nuevo = (Nodo*)malloc(sizeof(Nodo));

  strcpy(nuevo->nombre,nombre);
  nuevo->costo=costo;
  nuevo->siguiente = NULL;

  /* Si primero es NULL, la cola estaba vacía, ahora primero apuntará también al nuevo nodo */
  /*printf(" \n pushh nodo: %s", nuevo->nombre);
  printf("\n");
  */
  
  if(pila->inicio==NULL){
    //printf("\n Acá pushh 1ro: %s ",nuevo->nombre);
    pila->final= nuevo;
  }

  /* Si la cola no estaba vacía, añadimos el nuevo como 1ro */
  if(pila->inicio != NULL){
    nuevo->siguiente = pila->inicio;
  }  
 
  /* Ahora, el último elemento de la cola es el nuevo nodo */
  pila->inicio= nuevo;
}

/* cola pop */
void pop(Pila *pila) {
  Nodo *nodo_pop;
  //if (primero==NULL){
  if (pila->inicio==NULL){
    //printf( "\nLa lista está vacía!! (pop)\n" );
    return;
  }  
  nodo_pop = pila->inicio;
  pila->inicio = nodo_pop->siguiente;
  
  //printf("pop primero: %s", nodo_pop->nombre);
  //printf("\n");
  
  free(nodo_pop);
}

/* Imprimir cola */
void print_pila(Pila *pila, int valor_ruta_guardada){
	Nodo *auxiliar;
	auxiliar = pila->inicio;
  
  if (auxiliar==NULL){
    printf( "\nLa lista está vacía!!\n" );
  }else{
    //printf("\nMostrando pila completa:\n");
  } 

  int costo_total=0;
  while (auxiliar!=NULL) {
    costo_total=costo_total + auxiliar->costo;
    printf("nombre: %s", auxiliar->nombre);
    printf(" costo: %d\n", auxiliar->costo);
    auxiliar = auxiliar->siguiente;
  }
  printf("costo total: %d\n", costo_total);

  /*  
  printf("costo_total: %i", costo_total);
  printf(" valor_ruta_guardada: %i\n", valor_ruta_guardada);
  */

  if (costo_total < valor_ruta_guardada  || valor_ruta_guardada==0 ){
       
    abrir_archivo_resultado();
    
    auxiliar = pila->inicio;
    while (auxiliar!=NULL) {
      //costo_total=costo_total + auxiliar->costo;
      //if (costo_total < valor_ruta_guardada){
      guarda_ruta_mejor(auxiliar->nombre,auxiliar->costo);
      //}  
      //printf("nombre: %s", auxiliar->nombre);
      //printf(" costo: %d", auxiliar->costo);
      //printf("\n");
      auxiliar = auxiliar->siguiente;
    }
    
    guarda_ruta_mejor("R",costo_total);
    printf("\n");

    cerrar_archivo_resultado();
  
  }
  
}












