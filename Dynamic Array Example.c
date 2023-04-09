//Declaracion de las librerias de cabecera.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    //Inicializacion del generador de numeros aleatorios, basado en el tiempo del sistema.
    time_t t;
    srand ((unsigned) time(NULL));
    int i, n, x, y = -1;
    int *a;
    
    /* El siguiente algoritmo recibira como entrada la cantidad de elementos que contendra un arreglo de numeros enteros
    de uno a tres digitos generados aleatoriamente; posteriormente, evaluara la paridad de cada elemnto del mismo, eliminando
    todo numero impar del arreglo y modificando su capacidad. */
    printf ("Ingrese el n%cmero de elementos que contendr%c el arreglo: \n", 163, 160);
    scanf ("%d", &n);
	a = (int *) malloc (n * sizeof(int)); //Modificacion de la capacidad del arreglo.
    
    if (a == NULL) { //Validacion de la correcta asignacion de memoria.
        printf ("Error de asignaci%cn de memoria.", 162);
        exit (0);
    }
    
    //Se mustran en pantalla los numeros generados aleatoriamente.
    printf ("Los n%cmeros generados en el arreglo son:\n", 163);
    for(i = 0 ; i < n ; i++) {
        a[i] = rand() % 1000;
        printf ("%d\n", a[i]);
    }
    printf ("Por ende, el arreglo contiene %d elemento(s).\n", n);
    
    //Evaluacion de la paridad de los numeros.
    for (i = 0 ; i < n ; i++) { //Si el entero evaluado es par, se mantiene en el arreglo; si es impar, se remplaza por otro elemento par del arreglo.
        x = a[i] % 2;
        if (x == 0) {
            y++;
            a[y] = a[i]; //El elemento se reingresa en una posicion vacia del arreglo.
        }
    }
    if (y == -1) {
    	printf ("El arreglo no contiene n%cmeros pares.", 163);
    	return 0;
    }
    y++;
    a = (int *) realloc (a, y * sizeof(int)); //Reasignacion de la cantidad de elementos del arreglo.
    
    printf ("Los n%cmeros pares del arreglo son:\n", 163);
    for (i = 0 ; i < y ; i++) {
    	printf ("%d\n", a[i]);
    }
    printf ("Debido a lo anterior, el nuevo arreglo contiene %d elemento(s).\n", y); //Impresion de la nueva capacidad del arreglo
    
    free (a);
    a = NULL;
    return 0;
}