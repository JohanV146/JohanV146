#ifndef LIST_HPP
#define LIST_HPP

#include "node.hpp"

class list {
private:
	int countC;
	int countP;
	node *first;
public:
	// Metodo constructor
	list () {
		this->countC = 1;
		this->countP = 1;
		this->first = nullptr;
	}

	//Se encarga de insertar las categorias.
	void insertCategory (string pCategory) {
		node *temp = new node(pCategory, countC);
		temp->setNextC (first);
		first = temp;
		countC++;
	}

	//Se encarga de insertar las preguntas.
	void insertQuestion (string pCategory, string pQuestion, string pOptions, string pResponse) {
		node *n1 = seekC (pCategory);

		if (n1 == nullptr) {
			insertCategory (pCategory);
			n1 = seekC (pCategory);
		}

		node *t = n1->getNextP ();
		node *n = new node (pQuestion, pOptions, pResponse, countP);
		countP++;

		n1->setNextP (n);
		n->setNextP (t);
	}
	
	// comprueba si existe la categoria
	bool seekCB (int i) {
		if (i >= countC)
			return false;
		for (node *t = first; t != nullptr; t = t->getNextC ()){
			if (t->getId() == i)
				return true;
		}
		return false;
	}
	
	// Busca La categoria por ID
	string seekC (int i) {
		for (node *t = first; t != nullptr; t = t->getNextC ()){
			if (t->getId() == i)
				return t->getDato();
		}
		return nullptr;
	}

	// Busca la categoria por nombre
	node* seekC (string v) {
		for (node *t = first; t != nullptr; t = t->getNextC ())
			if (t->getDato() == v)
				return t;
		return nullptr;
	}
	
	void printC(){
		for (node *v = first; v != nullptr; v = v->getNextC()){
			if (v->getMark() != true)
				cout << v->getId() << ". " << v->getDato().c_str() << endl;
		}
	}
	
	int cantidadPreguntas(){
		int cont = 0;
		for (node *v = first; v != nullptr; v = v->getNextC()){
			if (v->getMark() == true){
				for (node *a = v->getNextP(); a != nullptr; a = a->getNextP()){
					cont++;
				}
			}
		}
		return cont;
	}
	
	int cantidadCategorias(){
		int cont = 0;
		for (node *v = first; v != nullptr; v = v->getNextC()){
			if (v->getMark() == true){
				cont++;
			}
		}
		return cont;
	}
	
	void mostrarCategorias(){
		for (node *v = first; v != nullptr; v = v->getNextC()){
			if (v->getMark() == true)
				cout << v->getId() << ". " << v->getDato().c_str() << endl;
		}
	}

	// Metodo accesor
	int getcountC(){ return countC; }
	
	// Metodo accesor
	int getcountP(){ return countP; }
	
	// Metodo accesor
	node* getFirst(){ return first; }

	// Metodo accesor
	void setFirst(node *pFirst){ this->first = pFirst; }
};

#endif // LIST_HPP
