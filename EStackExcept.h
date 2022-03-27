#ifndef ESTACKEXCEPT_H
#define ESTACKEXCEPT_H
#include<cstring>

class EStackExcept
{
   private: char *_mes;//сообщения
   public:
    EStackExcept(const char *mes)//консруктор
    {
        mes=new char[strlen(mes)+1];//выделяем память
        strcpy(_mes,mes);
    }
    EStackExcept(const EStackExcept &obj)//копируем
    {
        _mes=new char[strlen(obj._mes)+1];//выделяем память
         strcpy(_mes,obj._mes);

    }
    ~EStackExcept()
    {
        delete _mes;
    }

};
#endif // ESTACKEXCEPT_H
