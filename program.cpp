#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <dirent.h>
#include <string>
#include "list.hpp"
#include "ListaPlayers.hpp"
using namespace std;

bool load(char* direction);
void players(listaPlayers *temp);
//char* pegar(char* direction, char* palabra);
//int lenP(char* direction);
void identP(int pCantP, listaPlayers *temp);
void comienzo(listaPlayers *temp);

int main(){
	list *n = new list();
	listaPlayers *temp = new listaPlayers();
	int ini;
	int flag = 0;
	
	do {
		cout <<"==================================================\n|\t\t\t\t\t\t |\n|\t\tJuego de Trivia\t\t\t |\n|\t\t\t\t\t\t |\n==================================================" << endl;
		cout << "1. Comenzar\n2. Salir\nElija una opcion: ";
		fflush(stdin);
		scanf("%i", &ini);
		fflush(stdin);
		switch (ini) {
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
	comienzo(temp);			
}

void comienzo(listaPlayers *temp){
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
	players(temp);
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


void players(listaPlayers *temp){
	int ini;
	int flag = 0;
	int cantP;
	do {
		cout << "Ingrese la cantidad de jugadores (1-6): ";
		fflush(stdin);
		scanf("%i", &ini);
		fflush(stdin);
		switch (ini) {
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
	identP(cantP, temp);
}

void identP(int pCantP, listaPlayers *temp){
	temp->insertarPlayerM(pCantP);
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