#ifndef COLA_HPP_INCLUDED
#define COLA_HPP_INCLUDED
template <typename Tipo>
class Cola{
public:
    //Constructor por default
    Cola();
    //Constructor de copias
    Cola(const Cola &c);
    //Operador =
    Cola & operator= (const Cola &v);
    //Destructor
    ~Cola();
    //Encolar
    void Encolar(Tipo valor);
    //Desencolar
    void Desencolar();
    //Conocer primero de la cola
    Tipo ObtenerPrimero();
    //Conocer el ultimo de la cola
    Tipo ObtenerUltimo();
    //Conocer el numero de elementos
    int CantidadElementos();
    //Conocer si está vacía
    bool EstaVacia() const;
    //Vaciar
    void Vaciar();
    //imprimir
    void imprimir() const;
private:
    int numElem;
    struct Elemento{
        Tipo valor;
        Elemento *siguiente;

    }*ultimo;
};

#include "Cola.tpp"

#endif // COLA_HPP_INCLUDED
