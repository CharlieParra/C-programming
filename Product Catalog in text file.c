//Importacion de librerias de cabecera.
#include <stdio.h>
#include <stdlib.h>

//Declaracion de estructura "Catalogo", que almacenara los datos de cada producto 
struct catalogo {
	char ID[15], Nombre[30], Descripcion[200];
	float Costo;
} producto[1];

//Prototipado de la funcion secundaria.
void NuevoProducto (int);
FILE* archivo; //Declaracion de un apuntador de tipo archivo.

//Funcion principal.
int main () {
	int i = 0, n = 1, x;
	int* a;
	char caracter;
	
	/* El siguiente programa permite la creacion de un archivo de texto que almacenara una serie de productos que seran ingresados por el usuario.
	Para ello, se crea un archivo de texto con permisos de escritura para los datos relacionados a cada producto ingresado.*/
	archivo = fopen ("catProductos.txt", "wt");
	if (archivo == NULL) { //Validacion de asignacion de memoria.
        printf ("Error de asignaci%cn de memoria.", 162);
        exit (0);
    }
	fprintf (archivo, "Cat%clogo de productos:\n\n", 160);
	
	Inicio:
	NuevoProducto (i); //Creacion de un nuevo producto en la estructura Catalogo.
	i++;
	n++;
	a = (int *) malloc (n * sizeof(int)); //Modificacion de la capacidad de la estructura dinamica.
	if (a == NULL) { //Validacion de la correcta asignacion de memoria.
        printf ("Error de asignaci%cn de memoria.", 162);
        exit (0);
    }
	
	Seleccion:
	printf ("Desea agregar un nuevo producto?\n");
	printf ("1. S%c.\n", 161);
	printf ("2. No.\n");
	scanf ("%d", &x);
	
	if (x == 1)
		goto Inicio;
	else if (x == 2) {
		for (i = 0; i < n - 1; i++) { //Se ingresan en el archivo de texto los datos de los productos ingresados a la estructura Catalogo.
			fprintf (archivo, "%s", "--- Producto No. ");
			fprintf (archivo, "%d", i + 1);
			fprintf (archivo, "%s", " ---");
			fprintf (archivo, "%c", '\n');
			fprintf (archivo, "%s", "ID: ");
			fprintf (archivo, "%s", producto[i].ID);
			fprintf (archivo, "%c", '\n');
			fprintf (archivo, "%s", "Nombre: ");
			fprintf (archivo, "%s", producto[i].Nombre);
			fprintf (archivo, "%c", '\n');
			fprintf (archivo, "%s", "Descripci%cn: ", 162);
			fprintf (archivo, "%s", producto[i].Descripcion);
			fprintf (archivo, "%c", '\n');
			fprintf (archivo, "%s", "Precio por unidad: $");
			fprintf (archivo, "%.2f", producto[i].Costo);
			fprintf (archivo, "%c", '\n');
			fprintf (archivo, "%c", '\n');
		}
		//Liberacion de memoria y cierre del archivo de texto.
		free (a);
		a = NULL;
		fclose (archivo);
	}	
	else {
		printf ("Respuesta inv%clida, por favor ingrese una de las opciones mostradas. ", 160);
		goto Seleccion;
	}
	
	//Se muestra en pantalla el contenido del archivo de texto; para ello, se abre el archivo con permisos de lectura.
	archivo = fopen ("catProductos.txt", "r");
	if (archivo == NULL)
		printf ("Error de apertura de archivo.");
	else {
		printf ("\nEl contenido del archivo generado es:\n\n");
	}
	
	caracter = fgetc (archivo);
	while (caracter != EOF) {
		printf ("%c", caracter);
		caracter = fgetc (archivo);
	}
	
	//Cierre del archivo de texto y fin del programa
	fclose (archivo);
	return 0;
}

//Funcion secundaria implementada en el programa.
void NuevoProducto (int i) { //Se solicitan al usuario los datos relacionados con el producto que sera agregado a la estructura Catalogo.
	fflush (stdin);
	printf ("Ingrese el ID de su producto:\n");
	scanf ("%[^\n]", producto[i].ID);
	fflush (stdin);
	printf ("Ingrese el nombre de su producto:\n");
	scanf ("%[^\n]", producto[i].Nombre);
	fflush (stdin);
	printf ("Ingrese la descripci%cn de su producto:\n", 162);
	scanf ("%[^\n]", producto[i].Descripcion);
	fflush (stdin);
	printf ("Ingrese el costo unitario de su producto:\n");
	scanf ("%f", &producto[i].Costo);
	fflush (stdin);
}
