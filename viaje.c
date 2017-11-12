#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "matriz.h"
#include "file.h"
#include "pila.h"


void resetear_rutas(int arrRutas[]){
  int largo_rutas = get_largo_matriz();
  for (int i=0; i<largo_rutas; i++)
      arrRutas[i]=0;
}
void imprimir_rutas(int arrRutas[]){
  int largo_rutas = get_largo_matriz();
  for (int i=0; i<largo_rutas; i++){
    printf("ady %d ", arrRutas[i]);
    printf("\n"); 
  }
}



void backtrack_rutas(int posNodoIni, Pila *pila){

  int largo_rutas = get_largo_matriz();
  int *nuevas_rutas;
  nuevas_rutas = (int*)malloc(sizeof(int*)*largo_matriz);

  /* guarda todas las adyacencias del nodo*/
  resetear_rutas(nuevas_rutas);
  int cont_ruta=0;
  for (int i=1; i<largo_matriz; i++){
    int valor = matriz_grafo_din[posNodoIni][i];
    if (valor != 0){
      nuevas_rutas[cont_ruta]=i;
      cont_ruta++;
    }
  }



  if (cont_ruta==0){ // no tien adyacencia

    printf("\nCalcular ruta y costo \n"); 

    int valor_ruta_guardada = lee_resultado();
    
    /*
    printf("valor ruta guardada %d", valor_ruta_guardada); 
    printf("\n");
    */

    print_pila(pila, valor_ruta_guardada);
    pop(pila);
    
  }else{

    for (int i=0; i<largo_matriz; i++){
      if (nuevas_rutas[i]!=0){
        char nombre_nodo = matriz_grafo_din[nuevas_rutas[i]][0];
        int costo_nodo =matriz_grafo_din[posNodoIni][nuevas_rutas[i]];


        if (&nombre_nodo != pila->inicio->nombre){
          
          push(pila, &nombre_nodo, costo_nodo);
          backtrack_rutas(nuevas_rutas[i], pila);
        
        }/*else{
          printf("q pasa acá??? \n"); 
        }*/
      }
    }
    pop(pila);
  }

}


int main() {

  Pila *pila;
  if ((pila = (Pila *) malloc (sizeof (Pila))) == NULL) 
    return -1;
  inicializa(pila);

  abrir_archivo();
  leer_archivo();
  cerrar_archivo();

  limpiar_archivo_resultado();  

  push(pila, &primer_nodo[0], 0);
  backtrack_rutas( posicion_nodo( &primer_nodo[0] ), pila);

  mostrar_mejor_ruta();

  /*
  int calculo = (int) strtol("155533333", (char **)NULL, 10);
  printf("calculo %i\n", calculo);
  */

}