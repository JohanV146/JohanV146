#ifndef NODE_HPP
#define NODE_HPP

#include <string.h>
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
	node (string pQuestion, string pOptions, string pResponse, int pId) {
		this->dato = pQuestion;
		this->options = pOptions;
		this->response = pResponse;
		this->mark = false;
		this->id = pId;
		this->nextC = nullptr;
		this->nextP = nullptr;
	}

	node (string pCategory, int pId) {
		this->dato = pCategory;
		this->options = nullptr;
		this->response = nullptr;
		this->mark = false;
		this->id = pId;
		this->nextC = nullptr;
		this->nextP = nullptr;
	}


string getDato(){ return dato; }
string getOptions(){ return options; }
string getResponse(){ return response; }
bool getMark(){ return mark; }
int getId(){ return id; }
node* getNextC(){ return nextC; }
node* getNextP(){ return nextP; }

void setMark(){ mark = true; }
void clearMark(){ mark = false; }
void setNextC(node *pNextC){ nextC = pNextC; }
void setNextP(node *pNextP){ nextP = pNextP; }

};

#endif // NODE_HPP