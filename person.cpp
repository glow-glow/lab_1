#include "person.h"

Person::Person()//конструктор
{
    name = "nope";
    surname = "nope";
    patronymic = "nope";
}
Person::Person(QString FIO)
{
    QStringList words = FIO.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts); //делим слово на части слово

        if (words.size() != 2 && words.size() != 3) //проверка на наличия формата ввода
        {
            throw "Error: Person(): A string has incorrect format and could not be completely parsed.";
        }

        surname = words[0];

        name = words[1];


        if (words.size() == 3)
        {
            patronymic = words[2];
        }
}
Person::Person(const Person& person)
{
    name = person.name;
    name = person.surname;
    name = person.patronymic;
}

void Person::setName(QString newName)
{
    name = newName;
}
void Person::setSurname(QString newSurname)
{
    surname = newSurname;
}
void Person::setPatronymic(QString newPatronymic)
{
    patronymic = newPatronymic;
}
