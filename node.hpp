#ifndef NODE_HPP
#define NODE_HPP

class Node {
	private:
		// Atributos protegidos
		int dato;
		Node *siguiente;
		Node *anterior;

	public:
		// Constructores
		Node (int dato) {
			this->dato = dato;
			siguiente = nullptr;
			anterior = nullptr;
		}
		
		// Retorno de atributos internos
		int retornarDato () {
			return dato;
		}
		Node* retornarSiguiente () {
			return siguiente;
		}
		Node* retornarAnterior () {
			return anterior;
		}
		
		// Modificación de atributos
		void modificarSiguiente (Node *siguiente) {
			this->siguiente = siguiente;
		}
		void modificarAnterior (Node *anterior) {
			this->anterior = anterior;
		}
};
#endif // NODE_HPP
