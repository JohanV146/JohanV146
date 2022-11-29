#ifndef NODOPLAYER_HPP
#define NODOPLAYER_HPP

class nodoPlayer {
private:
	string nombre;
	int score;
	int id;
	nodoPlayer *nextPlayer;
public:
	// Metodo constructor
	nodoPlayer (string pNombre, int pId) {
		this->nombre = pNombre;
		this->score = 0;
		this->id = pId;
		this->nextPlayer = nullptr;
	}

	// Metodo accesor
	string getNombreP(){ return nombre; }
	
	// Metodo accesor
	int getScore(){ return score; }
	
	// Metodo accesor
	int getIdP(){ return id; }
	
	// Metodo accesor
	nodoPlayer* getNextPlayer(){ return nextPlayer; }

	// Metodo accesor
	void setNextPlayer(nodoPlayer *pNextPlayer){ nextPlayer = pNextPlayer; }
	
	// Metodo accesor
	void setScore(){ score++; }

};
#endif // NODOPLAYER_HPP
