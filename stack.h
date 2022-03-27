#ifndef STACK_H
#define STACK_H
#include<iostream>
#include"EStackEmpthy.h"
using namespace std;
#include <functional>
template <class T>

class stack
{
    struct Node//список
    {
        T _value;//значения переменной
        Node *prev;//указатель на прошлое звено

    };
    Node *back=nullptr;//последний элемент
    int size=0;//размер
public:
    ~stack();//Деструктор
    void Push(const T &value);//Добавления элемента
    const T Pop();//извлечения значения из стека
    void Iter(std::function<void(const T &value)> f) const ;//Проход по стеку
    int Size();//Размер
    void Clear();//очистка

};
template <class T>
void stack<T>::Push(const T &value)
{
  Node *node=new Node{value,back};
  node->_value=value;
  node->prev=back;
   if (node==nullptr)//поимка пустоты созданого элемента
   {
       throw EStackExcept("Not enough memory.");
   }


   back=node;
   size++;

}
template <class T>
void stack<T>::Clear()
{
    while (back!=nullptr)//очистка стека по шагам
    {
        Node *last=back;//крайний элемент
        back=back->prev;
        delete last;
    }
}
template <class T>
stack<T>::~stack()//деструктор
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
        throw EStackEmpty();//ловля исключений
    }
    const T value=back->_value;
    Node *last =back;
    back=back->prev;
    delete last;
    size--;
    return value;

}
template <class T>
void stack<T>::Iter(std::function<void(const T &value)> f) const
{
    Node *it = back; //перебор всех элементов, начиная с последнего

        while (it != nullptr) //заканчивая первым
        {
            f(it->_value); //вызов функции обратной связи

            it = it->prev;
        }
};

#endif // STACK_H
