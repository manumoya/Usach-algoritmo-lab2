# Usach-algoritmo-lab1
Idea:
1. Calcular matriz de adyacencia del grafo.
2. Identificar nodo de inicio.
3. Recorrer rutas del nodo (recursivo)
3.1. Determinar todas las rutas del nodo.
3.1.1. Si el nodo no tiene rutas, calcular costo
3.1.1.1. Comparar costo y almacenar el menor
3.1.1.2. Sacar nodo de pila (pop)
3.1.2. Si el nodo seleccionado no est\'{a} el la pila (inicio)
3.1.2.1. Poner nodo en la pila (push)
3.1.2.2. Recorrer rutas del nodo (recursivo)
3.1.2.Sacar nodo de pila (pop)

Compliar: gcc viaje.c -o viaje.out

Correr: ./viaje.out