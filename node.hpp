#ifndef NODE_HPP
#define NODE_HPP

#include <string>
using namespace std;

class node {
private:
	string dato;
	string options;
	string response;
	bool mark;
	int id;
	node *nextC;
	node *nextP;
public:
	// Metodo constructor
	node (string pCategory, int pId) {
		this->dato = pCategory;
		this->mark = false;
		this->id = pId;
		this->nextC = nullptr;
		this->nextP = nullptr;
	}
	
	// Metodo constructor
	node (string pQuestion, string pOptions, string pResponse, int pId) {
		this->dato = pQuestion;
		this->options = pOptions;
		this->response = pResponse;
		this->mark = false;
		this->id = pId;
		this->nextC = nullptr;
		this->nextP = nullptr;
	}
	
	// Metodo accesor
	string getDato(){ return dato; }
	
	// Metodo accesor
	string getOptions(){ return options; }
	
	// Metodo accesor
	string getResponse(){ return response; }
	
	// Metodo accesor
	bool getMark(){ return mark; }
	
	// Metodo accesor
	int getId(){ return id; }
	
	// Metodo accesor
	node* getNextC(){ return nextC; }
	
	// Metodo accesor
	node* getNextP(){ return nextP; }
	
	// Metodo accesor
	void setMark(){ mark = true; }
	
	// Metodo accesor
	void clearMark(){ mark = false; }
	
	// Metodo accesor
	void setNextC(node *pNextC){ nextC = pNextC; }
	
	// Metodo accesor
	void setNextP(node *pNextP){ nextP = pNextP; }
};
#endif // NODE_HPP
