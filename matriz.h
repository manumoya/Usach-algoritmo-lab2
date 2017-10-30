/*  ======= FUNCIONES DE MATRIZ  ========== */
int largo_matriz;
//char matriz_grafo[5][5];
char primer_nodo[1];
char **matriz_grafo_din;

int get_largo_matriz(){
  return largo_matriz;
}

/*void set_primer_nodo(char prim_nodo[]){
  primer_nodo[0]=prim_nodo[0];
}*/

/*char get_primer_nodo(){
  printf("1er nod %c \n", primer_nodo[0]);
  return primer_nodo[0];
}*/

void set_valores_matriz(){
  for (int i=0; i<largo_matriz; i++){
    for (int j=0; j<largo_matriz; j++){
      matriz_grafo_din[i][j]=0;
    }   
  }
}

void set_matriz_din(int largo){
  largo_matriz=largo+1;

  if (largo_matriz>26){
    printf( "\nMaximo 26 destinos!!\n" );
    return;
  }

  matriz_grafo_din = (char**)malloc(sizeof(int*)*largo_matriz);

  for (int i=0; i<largo_matriz; i++){
      matriz_grafo_din[i]=(char*)malloc(sizeof(int)*largo_matriz);
  }

  set_valores_matriz();

  //printf("larg matriz din : %d \n", largo_matriz );
}

/* generar grafo */
void generar_grafo(char vertices[]) {
  for(int i=0; i<largo_matriz && vertices[i] != '\0'; ++i){
    //printf("char graf : %c", vertices[i] );
    //printf("\n");
    
    /*
    matriz_grafo[0][i+1]=vertices[i];
    matriz_grafo[i+1][0]=vertices[i];
    */

    matriz_grafo_din[0][i+1]=vertices[i];
    matriz_grafo_din[i+1][0]=vertices[i];

  }
}


/* imprimir grafo */
void imprimir_grafo(){
  for (int i=0; i<largo_matriz; i++){
    for (int j=0; j<largo_matriz; j++){
      if (j==0 || i==0){
        printf("%c ", matriz_grafo_din[i][j]);
      }else{
        printf("%d ", matriz_grafo_din[i][j]);
      }  
    }
    printf("\n");   
  }
}

int posicion_nodo(char letra[]){
  int posicion=0;

  /* printf("letra %s ", letra);
  printf("\n"); 
  */

  for (int i=0; i<largo_matriz; i++){
    if ( matriz_grafo_din[0][i] == letra[0]){
      i=largo_matriz+1;
      posicion--;
    }
    posicion++;
  }  
  return posicion;
}

void agregar_adyacencia(char origen[], char destino[], int costo){
  int pos_origen=posicion_nodo(origen);
  int pos_destino=posicion_nodo(destino); 
  int pos_primer_nodo=posicion_nodo(&primer_nodo[0]);

  /*
  printf("primer nodo %s ", &primer_nodo[0] ); 
  printf(" pos orig %d ", pos_origen ); 
  printf(" pos dsti %d ", pos_destino ); 
  printf("\n"); 
  */

  /*  no puede ir al nodo origen  por lo que esta adyacencia no es valida*/
  if (pos_destino != pos_primer_nodo){
    matriz_grafo_din[pos_origen][pos_destino]=costo;  
  }

}

/* deja en cero el grafo*/
void resetear_grafo(char arreglo[]){
  for (int i=0; i<largo_matriz; i++)
      arreglo[i]='\0';
}

/* procesa grafo */
void procesar_grafo(int largo){
  //largo_matriz = largo;

  //printf( "largo matr grafo : %d \n", largo);

  char arrGrafoOut[26];
  resetear_grafo(arrGrafoOut);

  char arrGrafo[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for (int i=0; i<largo; i++){
      arrGrafoOut[i]=arrGrafo[i];
      //printf("char graf: %c \n", arrGrafoOut[i] );
  }
  generar_grafo(arrGrafoOut);
  imprimir_grafo();
  printf("\n");
}
