//Declaracion de las librerias de cabecera.
#include <stdio.h>
#include <math.h>

double distancia (double, double, double, double);

int main () {
	double X1, Y1, X2, Y2, D;
	
	//Obtencion de las coordenadas de los puntos A y B.
	printf ("Ingrese las coordenadas de dos puntos para calcular la distancia entre ellos:");
	printf ("\nEscriba el valor del punto A con respecto al eje x, ya sea entero o decimal: ");
	scanf ("\n%lf", &X1);
	printf ("Escriba el valor del punto A con respecto al eje y, ya sea entero o decimal: ");
	scanf ("\n%lf", &Y1);
	printf ("Escriba el valor del punto B con respecto al eje x, ya sea entero o decimal: ");
	scanf ("\n%lf", &X2);
	printf ("Escriba el valor del punto B con respecto al eje y, ya sea entero o decimal: ");
	scanf ("\n%lf", &Y2);
	
	//Calculo de la distancia entre los puntos A y B.
	D = distancia (X1, Y1, X2, Y2);
	
	printf("\nLas coordenadas del punto A son (%.2lf,%.2lf)", X1, Y1);
	printf("\nLas coordenadas del punto B son (%.2lf,%.2lf)", X2, Y2);
	printf ("\nLa distancia entre el punto A y el punto B es %.2lf", D);
	return 0;
}

//Funciones utilizadas.
double distancia (double X1, double Y1, double X2, double Y2) {
	double d;
	d = sqrt(((X2 - X1) * (X2 - X1)) + ((Y2 - Y1) * (Y2 - Y1)));
	return d;
}
