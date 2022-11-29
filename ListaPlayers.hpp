#ifndef LISTAPLAYERS_HPP
#define LISTAPLAYERS_HPP

#include "nodoPlayer.hpp"

class listaPlayers {
private:
	int countPlayer;
	nodoPlayer *firstPlayer;
public:
	// Metodo constructor
	listaPlayers () {
		this->countPlayer = 1;
		this->firstPlayer = nullptr;
	}

	//Se encarga de insertar las categorias.
	void insertPlayer (string pNombre) {
		nodoPlayer *temp = new nodoPlayer(pNombre, countPlayer);
		temp->setNextPlayer (firstPlayer);
		firstPlayer = temp;
		countPlayer++;
	}

	void print(){
		for (nodoPlayer *v = firstPlayer; v != nullptr; v = v->getNextPlayer()){
			cout << v->getNombreP().c_str() << endl;
		}
	}

	// Metodo accesor
	int getCountPlayer(){ return countPlayer; }
	
	// Metodo accesor
	nodoPlayer* getFirstPlayer(){ return firstPlayer; }
	
	// Metodo accesor
	void setFirstPlayer(nodoPlayer *pFirstPlayer){ this->firstPlayer = pFirstPlayer; }
};

#endif // LISTAPLAYERS_HPP
