#ifndef NODOPLAYER_HPP
#define NODOPLAYER_HPP

class nodoPlayer {
private:
	string nombre;
	int score;
	int id;
	nodoPlayer *nextPlayer;
public:
	nodoPlayer (string pNombre, int pId) {
		this->nombre = pNombre;
		this->score = 0;
		this->id = pId;
		this->nextPlayer = nullptr;
	}


string getNombreP(){ return nombre; }
int getScore(){ return score; }
int getIdP(){ return id; }
nodoPlayer* getNextPlayer(){ return nextPlayer; }

void setNextPlayer(nodoPlayer *pNextPlayer){ nextPlayer = pNextPlayer; }
void setScore(){ score++; }

};
#endif // NODOPLAYER_HPP