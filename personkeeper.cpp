#include "personkeeper.h"

PersonKeeper::PersonKeeper()
{

}

PersonKeeper::~PersonKeeper()
{
    //отсутвеут ,потому что нет динамически созданных объектов
}

PersonKeeper &PersonKeeper::Instance()
{
    static PersonKeeper instance;//Инициализуруем объект через статик, для того чтобы повторно не создовать его при вызове

    return instance;
}


int PersonKeeper::Size()
{
    return _stack.Size();
}

void PersonKeeper::Clear()
{
    return _stack.Clear();
}
void PersonKeeper::readPersons(QString path)
{
    QFile file(path);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))//проверка на открытось
    {
        throw "Error: readPersons(): Couldn't open a file!";
    }

    QTextStream stream(&file);//данные из файла
    QString line;//строка для считывания данных

    while (stream.readLineInto(&line))
    {
        Person kek(line);

        _stack.Push(kek);


    }

    file.close();
}

void PersonKeeper::writePersons(QString path) const
{
    QFile file(path);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))//проверка на открытось
    {
        throw "Error: writePersons(): Couldn't open a file!";
    }

    QTextStream stream(&file);

    _stack.Iter([&]( const Person &value)
    {
        stream << value.getSurname() << '\t' << value.getName() << '\t' << value.getPatronymic() << Qt::endl;

    });

    file.close();
}
