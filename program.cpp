#include <iostream>
#include "list.hpp"
#include <cstdlib>
#include <cstdio>
#include <dirent.h>
#include "ListaPlayers.hpp"


//char* pegar(char* direction, char* palabra);
//int lenP(char* direction);
void comienzo(listaPlayers *temp, list *n);
bool load(char* direction);
void categorias(listaPlayers *temp, list *n);
void players(listaPlayers *temp, list *n);
void identP(int pCantP, listaPlayers *temp, list *n);
void cantidaRondas(int pCantP, listaPlayers *temp, list *n);
void multiCategorias(listaPlayers *temp, list *n,int cRondas);
void juego(listaPlayers *temp, list *n, bool multi, int cRondas, int rondaAct);

int main(){
	listaPlayers *temp = new listaPlayers();
	list *n = new list();
	n->insertCategory("ciencias");
	n->insertCategory("Matematicas");
	n->insertCategory("Historia");
	n->insertCategory("Geografia");
	n->insertCategory("Lengua");
	n->insertCategory("Deportes");
	n->insertCategory("Lenguajes");
	n->insertCategory("Bases");
	char ini[3];
	int flag = 0;
	
	do {
		cout <<"==================================================\n|\t\t\t\t\t\t |\n|\t\tJuego de Trivia\t\t\t |\n|\t\t\t\t\t\t |\n==================================================" << endl;
		cout << "1. Comenzar\n2. Salir\nElija una opcion: ";
		fflush(stdin);
		cin >> ini;
		fflush(stdin);
		switch (atoi(ini)) {
			case 1:
				flag++;
	            break;
			case 2:
				return 1;
				break;
			default:
				break;
		}
	} while(flag != 1);
	comienzo(temp, n);			
}

void comienzo(listaPlayers *temp, list *n){
	char direction[100];
	int flag = 0;
	do {
		cout << "Ingrese la direccion del directorio: ";		
		fflush(stdin);
		scanf("%s", direction);
		fflush(stdin);
		if (load(direction)){
			flag++;
		} else {
			cout << "Error, ingrese un valor valido" << endl;
			//system("clear");
		}
	} while (flag != 1);
	categorias(temp, n);
}

bool load(char* direction){
	char* palabra;
	DIR *dir;
	struct dirent *ent;
	dir = opendir(direction);
	if (dir){
		do {
			ent = readdir(dir);
			if (ent){
				//palabra = pegar(ent->d_name, palabra);
				//insertCategory(n, palabra);
				cout << ent->d_name << endl;	
			}
		} while (ent);
		closedir(dir);
		return true;
	}else{ return false;}
}

void categorias(listaPlayers *temp, list *n){
	char cat[3];
	char pregunta[3];
	int flag = 0;
	n->printC();
	cout << "Ingrese la categoria que desea jugar: ";
	fflush(stdin);
	cin >> cat;
	fflush(stdin);
	if (n->seekCB(atoi(cat)) != false){	
		n->seekC(n->seekC(atoi(cat)))->setMark();
		do {
			cout << "Desea agregar otra categoria? (1 = si / 2 = No): ";
			fflush(stdin);
			cin >> pregunta;
			fflush(stdin);
			if (atoi(pregunta) == 1){
				flag++;
			}
			if (atoi(pregunta) == 2){
				flag++;
			}
		} while(flag != 1);
		if (atoi(pregunta) == 1){
			categorias(temp, n);
		} else {
			players(temp, n);
		}
		
	} else {
		cout << "Error, no existe esa categoria, indique una nueva" << endl;
		categorias(temp, n);
	}
}

void players(listaPlayers *temp, list *n){
	char ini[3];
	int flag = 0;
	int cantP;
	do {
		cout << "Ingrese la cantidad de jugadores (1-6): ";
		fflush(stdin);
		cin >> ini;
		fflush(stdin);
		switch (atoi(ini)) {
			case 1:
				cantP = 1;
				flag++;
	            break;
			case 2:
				cantP = 2;
				flag++;
				break;
			case 3:
				cantP = 3;
				flag++;
				break;
			case 4:
				cantP = 4;
				flag++;
				break;
			case 5:
				cantP = 5;
				flag++;
				break;
			case 6:
				cantP = 6;
				flag++;
				break;
			default:
				break;
		}
	} while (flag != 1);
	identP(cantP, temp, n);
}

void identP(int pCantP, listaPlayers *temp, list *n){
	string name;
	char nombre[100];
	cout << "Ingrese el nombre del jugador " << pCantP << ": ";
	fflush(stdin);
	cin >> nombre;
	fflush(stdin);
	name = nombre;
	temp->insertPlayer(name);
	if (pCantP > 1){
		identP(pCantP-1, temp, n);
	}
}

void cantidaRondas(int pCantP, listaPlayers *temp, list *n){
	char ini[3];
	int flag = 0;
	do {
		cout << "Ingrese la cantidad de rondas que desea jugar: ";
		fflush(stdin);
		cin >> ini;
		fflush(stdin);
		if (atoi(ini)*pCantP <= n->cantidadPreguntas()){
			flag++;
		} else cout << "No hay suficientes preguntas para esa cantidad de rondas" << endl;
	} while (flag != 1);
	multiCategorias(temp, n, atoi(ini));
}

void multiCategorias(listaPlayers *temp, list *n, int cRondas){
	if (n->cantidadCategorias() > 1){
		juego(temp, n, true, cRondas, 1);
	} else {
		juego(temp, n, false, cRondas, 1);
	}
}

void juego(listaPlayers *temp, list *n, bool multi, int cRondas, int rondaAct){
	char select[3];
	int flag = 0;
	if (multi == true){
		for (nodoPlayer *p = temp->getFirstPlayer(); p != nullptr; p = p->getNextPlayer()){
			cout << "Turno de " << p->getNombreP() << endl;
			cout << "Ronda actual " << rondaAct << endl;
			n->mostrarCategorias();
			do{
				cout << "Ingrese la categoria que desea jugar: ";
				fflush(stdin);
				cin >> select;
				fflush(stdin);
			} while (flag != 1);
		}
		if (cRondas > 1){
			juego(temp, n, true, cRondas-1, rondaAct+1);
		}
	} else {
	
	}
}

/*
char* pegar(char* direction, char* palabra){
	int large = lenP(direction);
	int cont = 0;
	while (cont != large-1){
		palabra[cont] = direction[cont];
		cont++;
	}
	return palabra;
}

int lenP(char* direction){
	int large = 0;
	while (direction[large] != '.'){
		large++;
	}
	return large;
}
*/
