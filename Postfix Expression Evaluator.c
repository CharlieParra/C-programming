//Importacion de librerias de cabecera.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define TAM 50

//Declaracion de la pila estatica.
struct Pila {
	float arreglo[TAM]; 
	float *ptrCima; //Declaracion de un apuntador de tipo flotante.
};

//Prototipado de funciones.
void ingresarPila (struct Pila *ptrPila, float dato);
float extraerPila (struct Pila *ptrPila);
int pilaVacia (struct Pila *ptrPila);

int main () {
	//Declaracion e inicializacion de los apuntadores por utilizar (de tipo estructura), asi como variables de tipo caracter, entero y flotante.
	struct Pila pila;
	struct Pila *miPtrPila;
	char cadP[TAM], aux[10];
	char espacio, miDato, fin;
	int caracter, i;
	float A, B, C, valor;
	
	miPtrPila = &pila;
	miPtrPila -> ptrCima = miPtrPila -> arreglo;
	fin = ')';
	espacio = ' ';
	
	//Se le solicita al usuario ingresar la expresion aritmetica valida en notacion postfija/sufija con la cual se trabajara.
	printf ("Ingrese una expresi%cn aritm%ctica v%clida en notaci%cn postfija/sufija, separando cada elemento con UN espacio o coma: ", 162, 130, 160, 162);
	scanf("\n%[^\n]", cadP);
	
	printf ("\nExpresi%cn aritm%ctica en notaci%cn postfija ingresada: %s", 162, 130, 162, cadP); //Se imprime en terminal la expresion ingresada por el usuario.
	strncat(cadP, &fin, 1); //Se agrega el caracter ')' a la cadena ingresada por el usuario.
	aux[0] = '\0'; //Se inicializa la cadena auxiliar que nos permitira procesar cada uno los valores de la cadena P adecuadamente.
	
	for (i = 0; ; i++) { //Estructura iterativa principal: Examinara la cadena ingresada por el usuario caracter a caracter y de izquierda a derecha.
		if (cadP[i] == '\0')
			break; //El proceso iterativo termina cuando se llegue al final de la cadena.
	
		caracter = cadP[i];
		miDato = cadP[i];
			
		//Si se encuentra un operando, este se agregara caracter a caracter en nuestra cadena auxiliar.
		if (caracter > 47 && caracter < 58)
			strncat(aux, &miDato, 1);
		
		if (cadP[i] == '.')
			strncat(aux, &miDato, 1);
			
		//Cuando se encuentre un caracter de separacion, ya sea un espacio o una coma..
		if (cadP[i] == ' ' || cadP[i] == ',') {
			if (aux[0] != '\0') { //...y nuestra cadena auxiliar tenga un valor almacenado...
				A = atof(aux); //...se realizara la conversion de dicha cadena a una variable de tipo flotante...
				ingresarPila (miPtrPila, A); //...y se enviara a la cima de nuestra pila.
				aux[0] = '\0'; //Ademas, nuestra cadena auxiliar se reiniciara para recibir el siguiente valor de la cadena P.
			}
		}
			
		//Si se encuentra un operador, se realizara la operacion correspondiente los dos ultimos operandos ingresados en la pila.
		if (cadP[i] == '+' || cadP[i] == '-' || cadP[i] == '*' || cadP[i] == '/' || cadP[i] == '^') {
			A = extraerPila (miPtrPila);
			B = extraerPila (miPtrPila);
			
			if (cadP[i] == '+')
				C = B + A;
			
			if (cadP[i] == '-')
				C = B - A;
			
			if (cadP[i] == '*')
				C = B * A;
			
			if (cadP[i] == '/')
				C = B / A;
			
			if (cadP[i] == '^')
				C = pow(B, A);
			
			//Tras realizar la operacion correspondiente con dichos operandos, el resultado obtenido sera enviado a la cima de la pila.
			ingresarPila (miPtrPila, C);
		}
	}
	
	//Finalmente, ya procesada la expresion de la cadena P por completo, se extraera el resultado de nuestra pila y se imprimira en pantalla.
	valor = extraerPila (miPtrPila);
	printf ("\nResultado de la expresi%cn en notaci%cn postfija/sufija: %.2f", 162, 162, valor);
	
	return 0;
}

//Funciones utilizadas.
void ingresarPila (struct Pila *ptrPila, float dato) {
	*ptrPila -> ptrCima = dato;
	ptrPila -> ptrCima++;
}

float extraerPila (struct Pila *ptrPila) {
	ptrPila -> ptrCima--;
	return (*ptrPila -> ptrCima);
}
