#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;
int num_Nodos = 1; //variable global
int posicion_Tortuga = 1;
int posicion_Liebre = 1;

struct nodo { //Nodos de la lista
	int id_Posicion=0;
	int id_Posicion_Tortuga = 1;
	int id_Posicion_Liebre = 1;
	bool tortuga_en_Nodo = false;
	bool liebre_en_Nodo = false;
	nodo* siguiente= NULL;
	nodo* atras= NULL;
}*primero, *ultimo;

void comenzarCarrera();
void insertarNodo();
void mostrarLista();
int funcionRandom();
void moverTortuga(nodo* nodo_Temporal);
void buscarNodo(int posicion, string animal);
void resetearPosiciones(string animal);
void moverLiebre(nodo* nodo_Temporal);

int main() {
	srand(time(NULL));
	for (int i = 0; i < 70; i++) {
		insertarNodo();
	}
	comenzarCarrera();

	nodo* nodo_Temporal = new nodo();
	nodo_Temporal = primero;

	while(nodo_Temporal->id_Posicion_Tortuga < 70 && nodo_Temporal->id_Posicion_Liebre < 70){

		moverTortuga(nodo_Temporal);
		moverLiebre(nodo_Temporal);
		mostrarLista();
	}

}

int funcionRandom() {
	int numeroAleatorio = 0;
	numeroAleatorio = 1 + rand() % (10);
	return numeroAleatorio;

}
void moverTortuga(nodo* nodo_Temporal) {

		int numero = funcionRandom();

		if (numero <= 5) {
			nodo_Temporal->id_Posicion_Tortuga += 3;
		}

		else if (numero > 5 && numero <= 7) {
			nodo_Temporal->id_Posicion_Tortuga -= 6;
		}

		else if (numero > 7 && numero <= 10) {
			nodo_Temporal->id_Posicion_Tortuga += 1;
		}

		if (nodo_Temporal->id_Posicion_Tortuga < 1) {
			nodo_Temporal->id_Posicion_Tortuga = 1;
			resetearPosiciones("Tortuga");
			buscarNodo(nodo_Temporal->id_Posicion_Tortuga, "Tortuga");
			cout << endl;
		}
		else if (nodo_Temporal->id_Posicion_Tortuga > 70) {
			nodo_Temporal->id_Posicion_Tortuga = 70;
			resetearPosiciones("Tortuga");
			buscarNodo(nodo_Temporal->id_Posicion_Tortuga, "Tortuga");
			cout << endl;

		}
		else {
			resetearPosiciones("Tortuga");
			buscarNodo(nodo_Temporal->id_Posicion_Tortuga, "Tortuga");
			cout << endl;
		}
	}
void moverLiebre(nodo* nodo_Temporal) {
		int numero = funcionRandom();

		if (numero ==1 || numero== 2) {
			
		}

		else if (numero ==3 || numero == 4) {
			nodo_Temporal->id_Posicion_Liebre += 9;
		}

		else if (numero == 5) {
			nodo_Temporal->id_Posicion_Liebre -= 12;
		}

		else if (numero >= 6 && numero <= 8) {
			nodo_Temporal->id_Posicion_Liebre += 1;
		}

		else if (numero >= 9 && numero <= 10) {
			nodo_Temporal->id_Posicion_Liebre -= 2;
		}

		if (nodo_Temporal->id_Posicion_Liebre < 1) {
			nodo_Temporal->id_Posicion_Liebre = 1;
			resetearPosiciones("Liebre");
			buscarNodo(nodo_Temporal->id_Posicion_Liebre, "Liebre");
			cout << endl;
		}
		else if (nodo_Temporal->id_Posicion_Liebre > 70) {
			nodo_Temporal->id_Posicion_Liebre = 70;
			resetearPosiciones("Liebre");
			buscarNodo(nodo_Temporal->id_Posicion_Liebre, "Liebre");
			cout << endl;

		}
		else {
			resetearPosiciones("Liebre");
			buscarNodo(nodo_Temporal->id_Posicion_Liebre, "Liebre");
			cout << endl;
		}
	}
void comenzarCarrera() {
	primero->liebre_en_Nodo = true;
	primero->tortuga_en_Nodo = true;
	cout << "              ---------------------------------- BANG! ----------------------------------" << endl;
	cout << "              |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
	cout << "              ------------------------------- Y ARRANCA! --------------------------------"<< endl<<endl;
	mostrarLista();
}

void buscarNodo(int posicion, string animal) {

	nodo* nodo_Temp = new nodo();
	nodo_Temp = primero;

	if (primero != NULL) {
		if (animal == "Tortuga") {
			while (nodo_Temp != NULL) {

				if (nodo_Temp->id_Posicion == posicion) {

					break;
				}

				nodo_Temp = nodo_Temp->siguiente;
			}

			nodo_Temp->tortuga_en_Nodo = true;
		}
		if (animal == "Liebre") {
			while (nodo_Temp != NULL) {

				if (nodo_Temp->id_Posicion == posicion) {

					break;
				}

				nodo_Temp = nodo_Temp->siguiente;
			}

			nodo_Temp->liebre_en_Nodo = true;
		}
	}
}

void resetearPosiciones(string animal) {
	nodo* nodo_Temp = new nodo();
	nodo_Temp = primero;

	while (nodo_Temp != NULL) {
		
		if(animal == "Tortuga"){
			nodo_Temp->tortuga_en_Nodo = false;
		}
		else {
			nodo_Temp->liebre_en_Nodo = false;
		}
		nodo_Temp = nodo_Temp->siguiente;
	}
}

void insertarNodo() {
	nodo* nuevo = new nodo();

	if (primero == NULL) {
		primero = nuevo;
		ultimo = primero;
		primero->id_Posicion = num_Nodos;
	}
	else {
		ultimo->siguiente = nuevo;
		nuevo->atras = ultimo;
		nuevo->id_Posicion = num_Nodos;
		ultimo = nuevo;
	}
	
	num_Nodos++;
}
void mostrarLista() {
	
	nodo* nodo_Temporal = new nodo();
	nodo_Temporal = primero;
	
	
	if (primero != NULL) {
		int contador = 1;

		while (nodo_Temporal != NULL) {

			if (nodo_Temporal->liebre_en_Nodo == true &&  nodo_Temporal->tortuga_en_Nodo==true) {
				
				cout << "    |L,T| ";
			}
			else if (nodo_Temporal->liebre_en_Nodo == true ) {

				cout << "    |L, | ";
			}
			else if (nodo_Temporal->tortuga_en_Nodo==true) {

				cout << "    | ,T| ";
			}
			else {
				cout << "    | , | ";
			}
			if (contador % 10 == 0) {
				cout << endl;
			}
			nodo_Temporal = nodo_Temporal->siguiente;
			contador++;
		}
	}
	else {
		cout << "\n La lista se encuentra vacia\n\n";
	}
}
