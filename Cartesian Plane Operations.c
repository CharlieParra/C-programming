//Declaracion de las librerias de cabecera.
#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

//Prototipado de funciones.
double moduloA (double, double);
double moduloB (double, double);
double anguloA (double, double);
double anguloB (double, double);
double distancia (double, double, double, double);
double ecuacionA (double, double, double, double);
double ecuacionB (double, double, double, double);
double pendiente (double, double, double, double);
double suma (double, double, double, double);
double resta (double, double, double, double);
double multiplicacionA (double, double, double, double);
double multiplicacionB (double, double, double, double);
double cocienteA (double, double, double, double);
double cocienteB (double, double, double, double);

//Funcion principal
int main () {
	double X1, Y1, X2, Y2, D, M1, M2, A1, A2, E1, E2, P, S, R, P1, P2, C1, C2;
	
	//Se le solicita al usuario ingresar las coordenadas de los ejes (X,Y) de los puntos A y B con los cuales se trabajara.
	printf ("Ingrese las coordenadas de dos puntos para calcular la distancia entre ellos:");
	printf ("\nEscriba el valor del punto A con respecto al eje x, ya sea entero o decimal: ");
	scanf ("\n%lf", &X1);
	printf ("Escriba el valor del punto A con respecto al eje y, ya sea entero o decimal: ");
	scanf ("\n%lf", &Y1);
	printf ("Escriba el valor del punto B con respecto al eje x, ya sea entero o decimal: ");
	scanf ("\n%lf", &X2);
	printf ("Escriba el valor del punto B con respecto al eje y, ya sea entero o decimal: ");
	scanf ("\n%lf", &Y2);
	
	//Conversion de los datos enteros a flotantes.
	X1 = X1 / 1.00;
	Y1 = Y1 / 1.00;
	X2 = X2 / 1.00;
	Y2 = Y2 / 1.00;
	
	//Ejecucion de las operaciones correspondientes.
	M1 = moduloA (X1, Y1);
	M2 = moduloB (X2, Y2);
	A1 = anguloA (X1, Y1);
	A2 = anguloB (X2, Y2);
	D = distancia (X1, Y1, X2, Y2);
	E1 = ecuacionA (X1, Y1, X2, Y2);
	E2 = ecuacionB (X1, Y1, X2, Y2);
	P = pendiente (X1, Y1, X2, Y2);
	S = suma (X1, Y1, X2, Y2);
	R = resta (X1, Y1, X2, Y2);
	P1 = multiplicacionA (X1, Y1, X2, Y2);
	P2 = multiplicacionB (X1, Y1, X2, Y2);
	C1 = cocienteA (X1, Y1, X2, Y2);
	C2 = cocienteB (X1, Y1, X2, Y2);
	
	printf ("\nLas coordenadas del punto A son (%.2lf,%.2lf), por lo que su m%cdulo es %.2lf, mientras que su %cngulo es de %.2lf%c", X1, Y1, 162, M1, 160, A1, 248);
	printf ("\nLas coordenadas del punto B son (%.2lf,%.2lf), por lo que su m%cdulo es %.2lf, mientras que su %cngulo es de %.2lf%c", X2, Y2, 162, M2, 160, A2, 248);
	printf ("\nLa distancia entre el punto A y el punto B es %.2lf", D);
	printf ("\nLa ecuaci%cn de la recta del punto A es y = %.2lfx + %.2lf", 162, P, E1);
	printf ("\nLa ecuaci%cn de la recta del punto B es y = %.2lfx + %.2lf", 162, P, E2);
	printf ("\nPor ende, la pendiente de la recta formada por los puntos A y B es %.2lf", P);
	printf ("\n\nEl resultado de la suma de los puntos A y B es %.2lf", S);
	printf ("\nEl resultado de la resta de los puntos A y B es %.2lf", R);
	printf ("\nEl producto de la multiplicaci%cn de los puntos A y B es %.2lf, %.2lf", 162, P1, P2);
	printf ("\nEl cociente de la divisi%cn de los puntos A y B es %.2lf, %.2lf", 162, C1, C2);
	return 0;
}

//Funciones secundarias utilizadas
double moduloA (double X1, double Y1) {
	double mA;
	mA = sqrt((X1 * X1) + (Y1 * Y1));
	return mA;
}

double moduloB (double X2, double Y2) {
	double mB;
	mB = sqrt((X2 * X2) + (Y2 * Y2));
	return mB;
}

double anguloA (double X1, double Y1) {
	double aA;
	if (X1 < 0) {
		if (Y1 < 0) {
			aA = (((atan(fabs(Y1)/fabs(X1)))*180)/PI) + 180;
		}
		else {
			aA = (((atan(fabs(X1)/fabs(Y1)))*180)/PI) + 90;
		}
	}
	else {
		if (Y1 < 0) {
			aA = (((atan(fabs(X1)/fabs(Y1)))*180)/PI) + 270;	
		}
		else {
			aA = (((atan(fabs(Y1)/fabs(X1)))*180)/PI);
		}
	}
	return aA;
}

double anguloB (double X2, double Y2) {
	double aB;
	if (X2 < 0) {
		if (Y2 < 0) {
			aB = (((atan(fabs(Y2)/fabs(X2)))*180)/PI) + 180;
		}
		else {
			aB = (((atan(fabs(X2)/fabs(Y2)))*180)/PI) + 90;
		}
	}	
	else {
		if (Y2 < 0) {
			aB = (((atan(fabs(X2)/fabs(Y2)))*180)/PI) + 270;	
		}
		else {
			aB = (((atan(fabs(Y2)/fabs(X2)))*180)/PI);
		}
	}
	return aB;
}

double distancia (double X1, double Y1, double X2, double Y2) {
	double d;
	d = sqrt(((X2 - X1) * (X2 - X1)) + ((Y2 - Y1) * (Y2 - Y1)));
	return d;
}

double ecuacionA (double X1, double Y1, double X2, double Y2) {
	double eA;
	eA = (pendiente (X1, Y1, X2, Y2) * (-X1)) + Y1;
	return eA;
}

double ecuacionB (double X1, double Y1, double X2, double Y2) {
	double eB;
	eB = (pendiente (X1, Y1, X2, Y2) * (-X2)) + Y2;
	return eB;
}

double pendiente (double X1, double Y1, double X2, double Y2) {
	double m;
	m = (Y2 - Y1) / (X2 - X1);
	return m;
}

double suma (double X1, double Y1, double X2, double Y2) {
	double s;
	s = (X1 + X2) + (Y1 + Y2);
	return s;
}

double resta (double X1, double Y1, double X2, double Y2) {
	double r;
	r = (X1 - X2) + (Y1 - Y2);
	return r;
}

double multiplicacionA (double X1, double Y1, double X2, double Y2) {
	double mA;
	mA = (moduloA (X1, Y1) * moduloB (X2, Y2));
	return mA;
}

double multiplicacionB (double X1, double Y1, double X2, double Y2) {
	double mB;
	mB = (anguloA (X1, Y1) + anguloB (X2, Y2));
	return mB;
}

double cocienteA (double X1, double Y1, double X2, double Y2) {
	double cA;
	cA = (moduloA (X1, Y1) / moduloB (X2, Y2));
	return cA;
}

double cocienteB (double X1, double Y1, double X2, double Y2) {
	double cB;
	cB = (anguloA (X1, Y1) - anguloB (X2, Y2));
	return cB;
}