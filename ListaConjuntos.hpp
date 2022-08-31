
#ifndef LISTACONJUNTOS_HPP
#define LISTACONJUNTOS_HPP
//importaciones.
#include "Utility.hpp"
#include "Elemento.hpp"
#include "Estructura.hpp"

/*****Nombre***************************************
 * ListaConjuntos
 *****Descripción**********************************
 * Es una lista de conjuntos, es decir contiene
 * elementos y estructuras.
 *****Atributos************************************
 * ListaC *apPrimerC;
 * int aId;
 *****Métodos**************************************
 * Metodo constructor
 * Metodos accesores
 * void PrintarElementos()
 * void PrintarEstructuras()
 * void BorrarEstructura(int pId)
 * bool AgregarConjunto(ListaC* Lista)
 * bool ExisteElemento(int pId)
 * ListaC* RetornarEstructura(int pId)
 * ListaC* RetornarElemento(int pId)
 **************************************************/
template<class ListaC>
class ListaConjuntos {
  //Primer nodo.
  ListaC *apPrimerC;
  int aId;

public:
    
/*****Nombre***************************************
 * ListaConjuntos
 *****Descripción**********************************
 * Es el metodo constructor
 **************************************************/
    ListaConjuntos() {
      this->apPrimerC = nullptr;
      aId = 1;
    }

/*****Nombre***************************************
 * PrintarElementos
 *****Descripción**********************************
 * Printa todos los elementos del objeto.
 **************************************************/
    void PrintarElementos() {
      ListaC *temporal = apPrimerC;
      std::cout << "===============================================================\n";
      std::cout << "======================Lista de elementos=======================\n";
      while(temporal) {
        //std::cout << "===============================================================\n";
        std::cout << "////////////////////////Elemento "<< temporal->GetId() <<"/////////////////////////////";
        std::cout << "\nEl ID del elemento es: " << temporal->GetId() << std::endl;
        std::cout << "El nombre del elemento es: ";
        temporal->GetNombre()->Print();
        std::cout << "\nLos atributos asociados al elemento son :\n";
        std::cout << "===============================================================\n";
        temporal->PrintAtributos();

        temporal = temporal->GetSig();
      }
    }

/*****Nombre***************************************
 * 
 *****Descripción**********************************
 * 
 *****Retorno**************************************
 * 
 *****Entradas*************************************
 * 
 **************************************************/
    //Se encarga de printar las estructuras.
    void PrintarEstructuras() {
      ListaC *temporal = apPrimerC;
      std::cout << "\n===============================================================\n";
      std::cout << "=====================Lista de estructuras======================\n";
      while(temporal) {
        std::cout << "///////////////////////Estructura "<< temporal->GetId() <<"////////////////////////////";
        std::cout << "\n|El ID de la estructura es: " <<temporal->GetId() << "|" << std::endl;
        temporal->PrintEstructura();
        temporal = temporal->GetSig();
      }
    }

/*****Nombre***************************************
 * 
 *****Descripción**********************************
 * 
 *****Retorno**************************************
 * 
 *****Entradas*************************************
 * 
 **************************************************/
    //Obtiene el nombre de los objetos.
    void GetNombre() {
      apPrimerC->GetNombre();
    }

/*****Nombre***************************************
 * 
 *****Descripción**********************************
 * 
 *****Retorno**************************************
 * 
 *****Entradas*************************************
 * 
 **************************************************/
    //Agrega Conjuntos.
    bool AgregarConjunto(ListaC* Lista) {
      if (apPrimerC == nullptr) {
        this->apPrimerC = Lista;
        aId++;
        return true;
      } else {
        ListaC *temporal = apPrimerC;
        while(temporal->GetSig() != nullptr) {
          temporal = temporal->GetSig();
        }
        temporal->SetSig(Lista);
        Lista->SetAnt(temporal);
        aId++;
        return true;

      }
    }

/*****Nombre***************************************
 * 
 *****Descripción**********************************
 * 
 *****Retorno**************************************
 * 
 *****Entradas*************************************
 * 
 **************************************************/
    //Eliminar la estructura señalada.
    void BorrarEstructura(int pId) {
      ListaC *temporal = apPrimerC;
      ListaInstancia* lista;
      lista = apPrimerC-> GetListaInstancias();
      
      if (temporal->GetSig() == nullptr) {
        if (lista->GetPrimerInstancia() == nullptr){
          this->apPrimerC = nullptr;
          std::cout << "Borrado con exito.";
        } else {
          std::cout << "No se puede realizar el Borrado, la lista contiene datos.";
        }
      } 
      else {
        std::cout << lista->GetPrimerInstancia() << std::endl;
        while(temporal) {
          if (temporal->GetId() == pId) {
            //En caso de que sea el primer elemento.
            if (temporal->GetAnt() == nullptr) {
              this->apPrimerC = apPrimerC->GetSig();
              if (lista->GetPrimerInstancia() == nullptr) {
                apPrimerC->SetAnt(nullptr);
                std::cout << "Borrado con exito.";
                break;
              } else {
                std::cout << "No se puede realizar el borrado, la lista contiene datos.";
                break;
              }
            }
            //En caso de que sea el ultimo.
            if (temporal->GetSig() == nullptr) {
              if (lista->GetPrimerInstancia() == nullptr) {
                temporal->GetAnt()->SetSig(nullptr);
                temporal = temporal->GetSig();
                std::cout << "Borrado realizado con exito.";
                break;
              } else {
                std::cout << "No se puede realizar el borrado, la lista contiene datos.";
                break;
              }
            } 
            //en cualquier otro caso.
            else {
              if (lista->GetPrimerInstancia() == nullptr) {
                temporal->GetAnt()->SetSig(temporal->GetSig());
                temporal->GetSig()->SetAnt(temporal->GetAnt());
                temporal = temporal->GetSig();
                std::cout << "El borrado exitoso.";
                break;
              } else {
                std::cout << "No se puede realizar el borrado., la lista contiene elementos.";
                break;
              }
            }
          } 
          else 
            temporal = temporal->GetSig();
        }
      } 
    }

/*****Nombre***************************************
 * 
 *****Descripción**********************************
 * 
 *****Retorno**************************************
 * 
 *****Entradas*************************************
 * 
 **************************************************/
    //Buscar elemento.
    bool ExisteElemento(int pId) {
      ListaC *temporal = apPrimerC;
      bool interruptor = false;
      if (temporal != nullptr) {
        while(temporal) {
          if (temporal->GetId() == pId) {
            interruptor = true;
            temporal = temporal->GetSig();
          } else {
            temporal = temporal->GetSig();
          }
        } 
        return interruptor;
      } else {
        return interruptor;
      }
    }

/*****Nombre***************************************
 * 
 *****Descripción**********************************
 * 
 *****Retorno**************************************
 * 
 *****Entradas*************************************
 * 
 **************************************************/
        //Buscar elemento.
    ListaC* RetornarEstructura(int pId) {
      ListaC *temporal = apPrimerC;
      bool interruptor = false;
      if (temporal != nullptr) {
        while(temporal) {
          if (temporal->GetId() == pId) {
            return temporal;
            temporal = temporal->GetSig();
          } else {
            temporal = temporal->GetSig();
          }
        } 
        return nullptr;
      } 
      return nullptr;
    }

/*****Nombre***************************************
 * 
 *****Descripción**********************************
 * 
 *****Retorno**************************************
 * 
 *****Entradas*************************************
 * 
 **************************************************/
    ListaC* GetPrimerC() {
      return apPrimerC;
    }

/*****Nombre***************************************
 * 
 *****Descripción**********************************
 * 
 *****Retorno**************************************
 * 
 *****Entradas*************************************
 * 
 **************************************************/
    //Obtiene el ID de la clase.
    int GetaId() {
      return aId;
    } 

/*****Nombre***************************************
 * 
 *****Descripción**********************************
 * 
 *****Retorno**************************************
 * 
 *****Entradas*************************************
 * 
 **************************************************/
    ListaC* RetornarElemento(int pId) {
      ListaC *temporal = apPrimerC;
      while (temporal) {
        if (temporal->GetId() == pId) {
          return temporal;
        } else {
          temporal = temporal->GetSig();
        }
      }
      return nullptr;
    }
};

#endif //LISTACONJUNTOS_HPP