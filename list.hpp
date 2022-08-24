#ifndef LIST_HPP
#define LIST_HPP

#include "node.hpp"

class list {
	private:
		Node *primero;
		int cont;

	public:
		list() {
			primero = nullptr;
			cont = 0;
		}

		void insertar (Node *nuevo){
			Node *actual = primero;
			if (actual != nullptr) {
				while (actual->retornarSiguiente() != nullptr)
					actual = actual->retornarSiguiente();
				actual->modificarSiguiente(nuevo);
			} else {
				primero = nuevo;
			}
			cont++;
		}

		void imprimir () {
			Node *actual = primero;
			int posicion = 0;
			
			while (actual != NULL) {
				printf ("%i\t[%i]\n", posicion++, actual->retornarDato ());
				actual = actual->retornarSiguiente ();
			}
		}

		void mergeSort () {

		}

		void selectionSort () {

		}

		void binSort () {

		}
};

#endif // LIST_HPP