#include <stdio.h>
#include <stdlib.h>
#include "list.hpp"

int main () {
	const int cantidad = 30;
	list *numeros = new list ();
	srand (time(nullptr));
	
	for (int i = 0; i < cantidad; i++) {
		numeros->insertar (new Node (rand ()));
	}
	
	printf ("Before sort:\n");
	numeros->imprimir ();
}
