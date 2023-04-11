//Importacion de las librerias de cabecera.
#include <stdio.h>

//Creacion de la estructura "directorio" que albergara la informacion basica de los contactos del usuario.
struct directorio {
	char ID[15], Nombre[30], APaterno[20], AMaterno[20], Domicilio[50], RFC[15], NFijo[15], NMovil[15], Email[20], Facebook[30], Twitter[20];
} contacto[100];

//Prototipado de funciones secundarias.
void NuevoContacto(int);
void BuscarContacto();
void ModificarContacto();
void EliminarContacto();

//Funcion principal.
int main () {
	unsigned char x, y, i = 0;
	
	//Menu principal del programa "Directorio".
	Inicio:
	printf ("Del siguiente men%c de opciones, seleccione mediante el ingreso de su n%cmero correspondiente
			la operaci%cn que desea realizar en su agenda:\n", 163, 163, 162);
	printf ("1. A%cadir nuevo contacto.\n", 164);
	printf ("2. Buscar contacto por nombre.\n");
	printf ("3. Modificar contacto existente.\n");
	printf ("4. Eliminar contacto.\n");
	printf ("5. Salir.\n");
	scanf ("%d", &x);
	fflush (stdin);
	
	switch (x) {
		case 1:
			NuevoContacto(i);
			i++;
			break;
		case 2:
			if (i == 0)
				printf("Para realizar esta operaci%cn por favor aseg%crese de agregar previamente un contacto.", 162, 163);
			else
				BuscarContacto();
			break;
		case 3:
			if (i == 0)
				printf("Para realizar esta operaci%cn por favor aseg%crese de agregar previamente un contacto.", 162, 163);
			else
				ModificarContacto();
			break;
		case 4:
			if (i == 0)
				printf("Para realizar esta operaci%cn por favor aseg%crese de agregar previamente un contacto.", 162, 163);
			else
				EliminarContacto();
			break;
		case 5:
			return 0;
			break;
		default: printf ("Opci%cn inv%clida, por favor seleccione una operaci%cn mediante el n%cmero entero que le corresponda.", 162, 160, 162, 163);
	}
	
	printf ("\nDesea realizar otra operaci%cn? (Seleccione una de las dos opciones mediante el n%cmero entero que le corresponda)\n", 162, 163);
	printf ("1. S%c.\n", 161);
	printf ("2. No.\n");
	scanf ("%d", &y);
	fflush (stdin);
	
	switch (y) {
		case 1:
			goto Inicio;
			break;
		case 2:
			return 0;
			break;
		default: printf ("Opci%cn inv%clida, por favor seleccione una operaci%cn mediante el n%cmero entero que le corresponda.", 162, 160, 162, 163);
	}
	
	return 0;
}

//Funciones secundarias implementadas en el programa.
void NuevoContacto(int i) {
	fflush (stdin);
	//Se le solicita al usuario ingresar los datos correspondientes al nuevo contacto del directorio.
	printf ("Ingrese el ID del contacto: ");
	scanf ("%[^\n]", contacto[i].ID);
	fflush (stdin);
	printf ("\nIngrese el nombre del contacto: ");
	scanf ("%[^\n]", contacto[i].Nombre);
	fflush (stdin);
	printf ("\nIngrese el apellido paterno del contacto: ");
	scanf ("%[^\n]", contacto[i].APaterno);
	fflush (stdin);
	printf ("\nIngrese el apellido materno del contacto: ");
	scanf ("%[^\n]", contacto[i].AMaterno);
	fflush (stdin);
	printf ("\nIngrese el domicilio del contacto: ");
	scanf ("%[^\n]", contacto[i].Domicilio);
	fflush (stdin);
	printf ("\nIngrese el RFC del contacto: ");
	scanf ("%[^\n]", contacto[i].RFC);
	fflush (stdin);
	printf ("\nIngrese el n%cmero de tel%cfono fijo del contacto: ", 163, 130);
	scanf ("%[^\n]", contacto[i].NFijo);
	fflush (stdin);
	printf ("\nIngrese el n%cmero de celular del contacto: ", 163);
	scanf ("%[^\n]", contacto[i].NMovil);
	fflush (stdin);
	printf ("\nIngrese el correo electr%cnico del contacto: ", 162);
	scanf ("%[^\n]", contacto[i].Email);
	fflush (stdin);
	printf ("\nIngrese el nombre de usuario de Facebook del contacto: ");
	scanf ("%[^\n]", contacto[i].Facebook);
	fflush (stdin);
	printf ("\nIngrese el nombre de usuario de Twitter del contacto: ");
	scanf ("%[^\n]", contacto[i].Twitter);
	fflush (stdin);
}

void BuscarContacto() {
	char busqueda[30];
	int j, k, x, contador = 0;
	printf ("Escriba el nombre del contacto que desea loclizar
			(Aseg%crese de que dicho contacto se ingrese en el campo de b%csqueda
			con la misma sintaxis con la cual se a%cadi%c a la agenda):\n", 163, 163, 164, 162);
	scanf ("%[^\n]", busqueda);
	fflush (stdin);
	//Proceso de busqueda de contactos en el directorio
	for (j = 0; j < 100; j++) {
		x = 1;
		if (contacto[j].Nombre[0] == '\0')
			x = x;
		else {
			for (k = 0; k < 30; k++) {
				if (busqueda[k] == contacto[j].Nombre[k] && x == 1)
					x = 1;
				else
					x = 0;
				if (busqueda[k] == '\0' &&  x == 1) { //Impresion en pantalla de los datos del contacto encontrado.
					printf ("Se ha encontrado el siguiente contacto:\n");
					printf ("\nID: %s", contacto[j].ID);
					printf ("\nNombre: %s %s %s", contacto[j].Nombre, contacto[j].APaterno, contacto[j].AMaterno);
					printf ("\nDomicilio: %s", contacto[j].Domicilio);
					printf ("\nRFC: %s", contacto[j].RFC);
					printf ("\nN%cmero de tel%cfono: %s", 163, 130, contacto[j].NFijo);
					printf ("\nN%cmero de celular: %s", 163, contacto[j].NMovil);
					printf ("\nCorreo electr%cnico: %s", 162, contacto[j].Email);
					printf ("\nFacebook: %s", contacto[j].Facebook);
					printf ("\nTwitter: %s\n", contacto[j].Twitter);
					contador++;
				}
			}
		}
	}
	if (contador == 0)
	printf ("No se han encontrado contactos relacionados con la b%csqueda.", 163);
	else if (contador == 1)
	printf ("Se ha encontrado 1 resultado relacionado con la b%csqueda.", 163);
	else
	printf ("Se encontraron %d resultados relacionados con la b%csqueda.", contador, 163);
}

void ModificarContacto () {
	int a, b, c;
	printf ("Ingrese el n%cmero relacionado con el contacto que desea modificar
			(entendiendo que la agenda posee un l%cmite de 100 contactos
			y que al primer contacto a%cadido le corresponde el n%cmero 1):\n", 163, 161, 164, 163);
	scanf ("%d", &a);
	if (contacto[a - 1].Nombre[0] == '\0' && contacto[a - 1].APaterno[0] == '\0')
		printf ("El contacto relacionado con el n%cmero ingresado no existe,
				aseg%crese de ingresar un n%cmero relacionado con un contacto a%cadido anteriormente.", 163, 163, 163, 164);
	else { //Se muestra en pantalla el contacto que sera modificado por el usuario
		printf ("El contacto seleccionado es el siguiente:\n");
		Modificar:
		printf ("\n1. ID: %s", contacto[a - 1].ID);
		printf ("\n2. Nombre: %s", contacto[a - 1].Nombre);
		printf ("\n3. Apellido paterno: %s", contacto[a - 1].APaterno);
		printf ("\n4. Apellido materno: %s", contacto[a - 1].AMaterno);
		printf ("\n5. Domicilio: %s", contacto[a - 1].Domicilio);
		printf ("\n6. RFC: %s", contacto[a - 1].RFC);
		printf ("\n7. N%cmero de tel%cfono: %s", 163, 130, contacto[a - 1].NFijo);
		printf ("\n8. N%cmero de celular: %s", 163, contacto[a - 1].NMovil);
		printf ("\n9. Correo electr%cnico: %s", 162, contacto[a - 1].Email);
		printf ("\n10. Facebook: %s", contacto[a - 1].Facebook);
		printf ("\n11. Twitter: %s\n", contacto[a - 1].Twitter);
	}
	printf ("Seleccione el elemento que desea modificar mediante el ingreso de su n%cmero correspondiente:", 163);
	scanf ("\n%d", &b);
	fflush (stdin);
	switch (b) { //Se solicita al usuario ingresar el nuevo dato correspondiente a la(s) opcion(es) elegida(s).
		case 1:
			contacto[a - 1].ID[0] = '\0';
			printf ("Ingrese el ID de su contacto: ");
			scanf ("%[^\n]", contacto[a - 1].ID);
			fflush (stdin);
			break;
		case 2:
			contacto[a - 1].Nombre[0] = '\0';
			printf ("Ingrese el nombre de su contacto: ");
			scanf ("%[^\n]", contacto[a - 1].Nombre);
			fflush (stdin);
			break;
		case 3:
			contacto[a - 1].APaterno[0] = '\0';
			printf ("Ingrese el apellido paterno de su contacto: ");
			scanf ("%[^\n]", contacto[a - 1].APaterno);
			fflush (stdin);
			break;
		case 4:
			contacto[a - 1].AMaterno[0] = '\0';
			printf ("Ingrese el apellido materno de su contacto: ");
			scanf ("%[^\n]", contacto[a - 1].AMaterno);
			fflush (stdin);
			break;
		case 5:
			contacto[a - 1].Domicilio[0] = '\0';
			printf ("Ingrese el nuevo domicilio de su contacto: ");
			scanf ("%[^\n]", contacto[a - 1].Domicilio);
			fflush (stdin);
			break;
		case 6:
			contacto[a - 1].RFC[0] = '\0';
			printf ("Ingrese el RFC de su contacto: ");
			scanf ("%[^\n]", contacto[a - 1].RFC);
			fflush (stdin);
			break;
		case 7:
			contacto[a - 1].NFijo[0] = '\0';
			printf ("Ingrese el nuevo n%cmero de tel%cfono fijo de su contacto: ", 163, 130);
			scanf ("%[^\n]", contacto[a - 1].NFijo);
			fflush (stdin);
			break;
		case 8:
			contacto[a - 1].NMovil[0] = '\0';
			printf ("Ingrese el nuevo n%cmero de celular de su contacto: ", 163);
			scanf ("%[^\n]", contacto[a - 1].NMovil);
			fflush (stdin);
			break;
		case 9:
			contacto[a - 1].Email[0] = '\0';
			printf ("Ingrese el nuevo correo electr%cnico de su contacto: ", 162);
			scanf ("%[^\n]", contacto[a - 1].Email);
			fflush (stdin);
			break;
		case 10:
			contacto[a - 1].Facebook[0] = '\0';
			printf ("Ingrese el nuevo nombre de usuario de Facebook de su contacto: ");
			scanf ("%[^\n]", contacto[a - 1].Facebook);
			fflush (stdin);
			break;
		case 11:
			contacto[a - 1].Twitter[0] = '\0';
			printf ("Ingrese el nuevo nombre de usuario de Twitter de su contacto: ");
			scanf ("%[^\n]", contacto[a - 1].Twitter);
			fflush (stdin);
			break;
		default: printf ("Opci%cn inv%clida, por favor seleccione una operaci%cn mediante el n%cmero entero que le corresponda.", 162, 160, 162, 163);
	}
	printf ("%cDesea modificar otro elemento de su contacto? (Seleccione una de las dos opciones mediante el n%cmero entero que le corresponda)\n", 168, 163);
	printf ("1. S%c.\n", 161);
	printf ("2. No.\n");
	scanf ("%d", &c);
	fflush (stdin);
	switch (c) {
		case 1:
			goto Modificar;
			break;
		case 2:
			break;
		default: printf ("Opci%cn inv%clida, por favor seleccione una operaci%cn mediante el n%cmero entero que le corresponda.", 162, 160, 162, 163);
	}
}

void EliminarContacto () {
	int m, n;
	Eliminar:
	printf ("Ingrese el n%cmero relacionado con el contacto que desea eliminar
			(entendiendo que la agenda posee un l%cmite de 100 contactos
			y que al primer contacto a%cadido le corresponde el n%cmero 1):\n", 163, 161, 164, 163);
	scanf ("%d", &m);
	if (contacto[m - 1].Nombre[0] == '\0' && contacto[m - 1].APaterno[0] == '\0')
		printf ("El contacto relacionado con el n%cmero ingresado no existe,
				aseg%crese de ingresar un n%cmero relacionado con un contacto a%cadido anteriormente.", 163, 163, 163, 164);
	else { //Se muestra en pantalla el contacto que sera eliminado por el usuario.
		printf ("El contacto seleccionado es el siguiente:\n");
		printf ("\n1. ID: %s", contacto[m - 1].ID);
		printf ("\n2. Nombre: %s", contacto[m - 1].Nombre);
		printf ("\n3. Apellido paterno: %s", contacto[m - 1].APaterno);
		printf ("\n4. Apellido materno: %s", contacto[m - 1].AMaterno);
		printf ("\n5. Domicilio: %s", contacto[m - 1].Domicilio);
		printf ("\n6. RFC: %s", contacto[m - 1].RFC);
		printf ("\n7. N%cmero de tel%cfono: %s", 163, 130, contacto[m - 1].NFijo);
		printf ("\n8. N%cmero de celular: %s", 163, contacto[m - 1].NMovil);
		printf ("\n9. Correo electr%cnico: %s", 162, contacto[m - 1].Email);
		printf ("\n10. Facebook: %s", contacto[m - 1].Facebook);
		printf ("\n11. Twitter: %s\n", contacto[m - 1].Twitter);
	}
	printf ("Dicho contacto ser%c eliminado permanentemente, %cdesea continuar de todos modos?:\n", 160, 168);
	printf("1. S%c.\n", 161);
	printf("2. No.\n");
	scanf("%d", &n);
	fflush (stdin);
	switch (n) {
		case 1: //Se elimina el contacto seleccionado por el usuario al borrar los datos relacionados con dicho contacto
			contacto[m - 1].ID[0] = '\0';
			contacto[m - 1].Nombre[0] = '\0';
			contacto[m - 1].APaterno[0] = '\0';
			contacto[m - 1].AMaterno[0] = '\0';
			contacto[m - 1].Domicilio[0] = '\0';
			contacto[m - 1].RFC[0] = '\0';
			contacto[m - 1].NFijo[0] = '\0';
			contacto[m - 1].NMovil[0] = '\0';
			contacto[m - 1].Email[0] = '\0';
			contacto[m - 1].Facebook[0] = '\0';
			contacto[m - 1].Twitter[0] = '\0';
			printf ("Contacto eliminado exitosamente.");
			break;
		case 2:
			break;
		default: printf ("Opci%cn inv%clida, por favor seleccione una operaci%cn mediante el n%cmero entero que le corresponda.", 162, 160, 162, 163);
	}
	printf ("%cDesea eliminar otro contacto?:\n", 168);
	printf ("1. S%c.\n", 161);
	printf ("2. No.\n");
	scanf ("%d", &n);
	fflush (stdin);
	switch (n) {
		case 1:
			goto Eliminar;
			break;
		case 2:
			break;
		default: printf ("Opci%cn inv%clida, por favor seleccione una operaci%cn mediante el n%cmero entero que le corresponda.", 162, 160, 162, 163);
	}
}