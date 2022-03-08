#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "EStackEmpthy.h"

using namespace std;

template <class T>

class stack
{
    struct Node//список
    {
        T _value;//Значения переменной
        Node *prev;// указатель на прошлое звено

    };

    Node *back=nullptr;//последний элемент
    int size=0;//размер
    public:
    ~stack();//Деструктор
    void Push(const T &value);//Добавления элемента
    const T Pop();//извлечения значения из стека
    void Iter() ;//Проход по стеку
    int Size();//Размер
    void Clear();//очистка

};
template <class T>
void stack<T>::Push(const T &value)
{
  Node *node=new Node{value,back};
   if (node==nullptr)
   {
       throw EStackExcept("Not enough memory.");
   }
   back=node;
   size++;
}
template <class T>
void stack<T>::Clear()
{
    while (back!=nullptr)
    {
        Node *last=back;//Последний элемент
        back=back->prev;
        delete last;
    }
}
template <class T>
stack<T>::~stack()//Деструктор
{
    Clear();
}
template <class T>
int stack<T>::Size()
{
    return size;
}
template <class T>
const T stack<T>::Pop()
{if (back==nullptr)
    {
        throw EStackEmpty();
    }
    const T value=back->_value;
    Node *last =back;
    back=back->prev;
    delete last;
    size--;
    return value;

}
template <class T>
void stack<T>::Iter()
{
    Node *it=back;
    while (it!=nullptr)
    {
        cout<<(it->_value)<<" ";
        it=it->prev;


    }
};

#endif // STACK_H
