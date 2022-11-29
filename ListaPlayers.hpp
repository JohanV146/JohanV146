#ifndef LISTAPLAYERS_HPP
#define LISTAPLAYERS_HPP

#include "nodoPlayer.hpp"

class listaPlayers {
private:
	int countPlayer;
	nodoPlayer *firstPlayer;
public:
	listaPlayers () {
		this->countPlayer = 1;
		this->firstPlayer = nullptr;
	}

	//Se encarga de insertar las categorias.
	void insertPlayer (string pNombre) {
		nodoPlayer *temp = new nodoPlayer(pNombre, countPlayer);
		countPlayer++;
		if (firstPlayer == nullptr) {
			firstPlayer = temp;
		}else {
			nodoPlayer *aux = firstPlayer->getNextPlayer();
			while(aux->getNextPlayer() != nullptr) {
				aux = aux->getNextPlayer();
			}
			aux->setNextPlayer(temp);
		}
	}

	void insertarPlayerM(int cantP){
		char nombre[100];
		gets(nombre, 100, stdin);
		string name= nombre;
		insertPlayer(name);
		for (nodoPlayer *n = firstPlayer->getNextPlayer(); n != nullptr; n = n->getNextPlayer()){
			cout << n->getNombreP().c_str() << endl;
		}
		if (cantP >=1)
			insertarPlayerM(cantP-1);
	}

	int getCountPlayer(){ return countPlayer; }
	nodoPlayer* getFirstPlayer(){ return firstPlayer; }

	void setFirstPlayer(nodoPlayer *pFirstPlayer){ this->firstPlayer = pFirstPlayer; }
};

#endif // LISTAPLAYERS_HPP