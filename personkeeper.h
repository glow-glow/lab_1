#ifndef PERSONKEEPER_H
#define PERSONKEEPER_H
#include<stack.h>
#include<person.h>
#include <QString>
#include <QTextStream>
#include <QFile>
class PersonKeeper
{
private:
    PersonKeeper();
    PersonKeeper(const PersonKeeper &);
    ~PersonKeeper();

    PersonKeeper &operator=(const PersonKeeper &);
    stack<Person> _stack;

public:

    static PersonKeeper &Instance();

    void readPersons(QString path);
    void writePersons(QString path) const;

    QStringList ToQStringList() const; //

    int Size();
    void Clear();
};

#endif // PERSONKEEPER_H
