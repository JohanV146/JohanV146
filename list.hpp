#ifndef LIST_HPP
#define LIST_HPP

#include "node.hpp"

class list {
private:
	int countC;
	int countP;
	node *first;
public:
	list () {
		this->countC = 1;
		this->countP = 1;
		this->first = nullptr;
	}

	//Se encarga de insertar las categorias.
	void insertCategory (string pCategory) {
		node *newCategory = new node(pCategory, countC);
		newCategory->setNextC (first);
		first = newCategory;
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

	// Busca La categoria por ID
	string seekC (int i) {
		if (i >= countC)
			return (char*)'\0';
		node *t = first;
		for (int p = 0; p < i; p++)
			t = t->getNextC ();
		return t->getDato ();
	}

	// Busca la categoria por nombre
	node* seekC (string v) {
		for (node *t = first; t != nullptr; t = t->getNextC ())
			if (t->getDato() == v)
				return t;
		return nullptr;
	}

	int getcountC(){ return countC; }
	int getcountP(){ return countP; }
	node* getFirst(){ return first; }

	void setFirst(node *pFirst){ this->first = pFirst; }
};

#endif // LIST_HPP