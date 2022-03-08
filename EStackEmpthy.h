#ifndef ESTACKEMPTHY_H
#define ESTACKEMPTHY_H
#include "EStackExcept.h"

class EStackEmpty:public EStackExcept//Наследования EStackExcept
{
public:
    EStackEmpty():EStackExcept("Stack is empty")//Дефолтный конструктор
    {

    }
    EStackEmpty(const EStackEmpty &obj):EStackExcept(obj)
    {

    }

};
#endif // ESTACKEMPTHY_H
