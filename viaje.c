#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pila.h"

#include "matriz.h"
#include "file.h"

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
    print_pila(pila);
    pop(pila);
    
  }else{

    for (int i=0; i<largo_matriz; i++){
      if (nuevas_rutas[i]!=0){
        char nombre_nodo = matriz_grafo_din[nuevas_rutas[i]][0];
        int costo_nodo =matriz_grafo_din[posNodoIni][nuevas_rutas[i]];

        //printf("nombre_nodo %s ", &nombre_nodo); 
        //printf(" pila->inicio->nombre %s ", pila->inicio->nombre); 
        //printf(" nodo_existe_en_pila %d ", nodo_existe_en_pila(pila, &nombre_nodo)); 
        //printf("\n"); 

        if (&nombre_nodo != pila->inicio->nombre){
        //if (nodo_existe_en_pila(pila, &nombre_nodo)==0){

          //printf("backtrack_rutas recursivo %s", &nombre_nodo);  
          //printf("\n");
          
          push(pila, &nombre_nodo, costo_nodo);
          backtrack_rutas(nuevas_rutas[i], pila);
        
        }else{
          printf("q pasa acá??? \n"); 
          //print_pila(pila);
          //push(marca, &nombre_nodo, costo_nodo);

          /*char nombre_nodo_orig = matriz_grafo_din[posNodoIni][0]; 
          printf("nombre_nodo %s ", &nombre_nodo);
          printf(" nombre_nodo original %s ", &nombre_nodo_orig);
          printf("\n"); 
          */
            
        }
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

  /*
  Pila_Marca *marca;
  if ((marca = (Pila_Marca *) malloc (sizeof (Pila_Marca))) == NULL) 
    return -1;
  inicializa(marca);
  */


  abrir_archivo();
  leer_archivo();
  cerrar_archivo();


  push(pila, &primer_nodo[0], 0);
  //push(marca, &primer_nodo[0], "");

  backtrack_rutas( posicion_nodo( &primer_nodo[0] ), pila);


}