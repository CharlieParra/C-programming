//Importacion de librerias de cabecera.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 50

//Declaracion de la pila.
struct Pila {
	char arreglo[TAM]; 
	char *ptrCima; //Declaracion de un apuntador de tipo caracter.
};

//Prototipado de funciones.
void ingresarPila (struct Pila *ptrPila, char dato);
char extraerPila (struct Pila *ptrPila);
int pilaVacia (struct Pila *ptrPila);

int main () {
	/* Declaracion e inicializacion de los apuntadores por utilizar (de tipo estructura),
	asi como variables de tipo caracter y tipo entero. */
	struct Pila pila;
	struct Pila *miPtrPila;
	char cadQ[TAM], cadP[TAM];
	char espacio, elemPila, miDato, fin;
	int caracter, i, j;
	
	miPtrPila = &pila;
	miPtrPila -> ptrCima = miPtrPila -> arreglo;
	fin = ')';
	miDato = '(';
	espacio = ' ';
	ingresarPila (miPtrPila, miDato); //Se ingresa el caracter '(' a la pila.
	
	//Se le solicita al usuario ingresar la expresion aritmetica valida en notacion infija con la cual se trabajara.
	printf ("Ingrese una expresi%cn aritm%ctica v%clida en notaci%cn infija: ", 162, 130, 160, 162);
	scanf("\n%[^\n]", cadQ);
	
	//Se imprime en terminal la expresion ingresada por el usuario en notacion infija.
	printf ("\nExpresi%cn aritm%ctica ingresada (notaci%cn infija): %s", 162, 130, 162,cadQ); 
	strncat(cadQ, &fin, 1); //Se agrega el caracter ')' a la cadena ingresada por el usuario.
	cadP[0] = '\0'; //Se inicializa la cadena que almacenara nuestro resultado: la cadena "P".
	
	//Estructura iterativa principal: Examinara la cadena ingresada por el usuario caracter a caracter y de izquierda a derecha.
	for (i = 0; ; i++) {
		if (cadQ[i] == '\0')
			break; //El proceso iterativo termina cuando se llegue al final de la cadena.
	
		caracter = cadQ[i];
		miDato = cadQ[i];
			
		if (caracter > 47 && caracter < 58) //Si se encuentra un operando, lo agregara a "P".
			strncat(cadP, &miDato, 1);
		
		//El mismo caso ocurrira con un punto o una coma, en caso de que el usuario ingrese dichos signos.
		if (cadQ[i] == '.')
			strncat(cadP, &miDato, 1);
			
		if (cadQ[i] == ',')
			strncat(cadP, &miDato, 1);
		
		if (cadQ[i] == '(') //Si se encuentra un parentesis de apertura, dicho caracter se almacenara en la pila.
			ingresarPila (miPtrPila, miDato);
			
		//Si se encuentra un operador, se evaluara su precedencia y se realizaranlos procesos correspondientes con respecto a ella.
		if (cadQ[i] == '+' || cadQ[i] == '-' || cadQ[i] == '*' || cadQ[i] == '/' || cadQ[i] == '^') {
			strncat(cadP, &espacio, 1);
			
			if (cadQ[i] == '^') { //Si el operador es un exponencial...
				//...se evaluaran los operadores ingresados en la pila y se agregar�n a la cadena "P" repetidamente...
				for (;;) { 
					elemPila = extraerPila (miPtrPila);
					
					if (elemPila == '^') {
						strncat(cadP, &elemPila, 1);
						strncat(cadP, &espacio, 1);
					}
					else { //...hasta que se encuentre un parentesis de apertura o un signo de menor precedencia.
						ingresarPila (miPtrPila, elemPila);
						ingresarPila (miPtrPila, miDato);
						break;
					}	
				}
			}
			
			//Se realizara el mismo proceso con los operadores de multiplicacion y division...
			if (cadQ[i] == '*' || cadQ[i] == '/') {
				for (;;) {
					elemPila = extraerPila (miPtrPila);
					
					if (elemPila == '*' || elemPila == '/' || elemPila == '^') {
						strncat(cadP, &elemPila, 1);
						strncat(cadP, &espacio, 1);
					}
					else {
						ingresarPila (miPtrPila, elemPila);
						ingresarPila (miPtrPila, miDato);
						break;
					}
				}
			}
			
			if (cadQ[i] == '+' || cadQ[i] == '-') { //...asi como con los operadores de suma y resta.
				for (;;) {
					elemPila = extraerPila (miPtrPila);
					
					if (elemPila == '+' || elemPila == '-' || elemPila == '*' || elemPila == '/' || elemPila == '^') {
						strncat(cadP, &elemPila, 1);
						strncat(cadP, &espacio, 1);
					}
					else {
						ingresarPila (miPtrPila, elemPila);
						ingresarPila (miPtrPila, miDato);
						break;
					}	
				}
			}
		}
		
		if (cadQ[i] == ')') { //Si se encuentra un parentesis de cierre...
			strncat(cadP, &espacio, 1);
			for (;;) { //...se evaluaran los elementos ingresados en la pila y se agregaran a la cadena "P"...
				elemPila = extraerPila (miPtrPila);
				
				if (elemPila != '(') { 
					strncat(cadP, &elemPila, 1);
					strncat(cadP, &espacio, 1);
				}
				else { //...a menos que el elemento evaluado sea un parentesis de apertura.
					int cadena = strlen(cadP);
					cadP[cadena - 1] = '\0';
					break;
					//En este caso, se terminara el ciclo iterativo sin agregar ninguno de los parentesis en la cadena "P".
				}
			}
		}
	}
	
	for (;;) { //Finalmente, se agregan los operadores restantes a la cadena "P" (en caso de haberlos)...
		if (pilaVacia (miPtrPila) == 0) {
			elemPila = extraerPila (miPtrPila);
			strncat(cadP, &espacio, 1);
			strncat(cadP, &elemPila, 1);
		}
		else {
			//...y se imprime en terminal la expresion ingresada por el usuario en notacion postfija/sufija.
			printf ("\nExpresi%cn convertida a notaci%cn postfija/sufija: %s", 162, 162, cadP);
			return 0;
		}
	}	
}

//Funciones utilizadas.
void ingresarPila (struct Pila *ptrPila, char dato) {
	*ptrPila -> ptrCima = dato;
	ptrPila -> ptrCima++;
}

char extraerPila (struct Pila *ptrPila) {
	ptrPila -> ptrCima--;
	return (*ptrPila -> ptrCima);
}

int pilaVacia (struct Pila *ptrPila) {
	if (ptrPila -> ptrCima == ptrPila -> arreglo)
		return 1;
	else
		return 0;
}
