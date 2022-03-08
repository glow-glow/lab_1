#include <QCoreApplication>
#include <stack.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    stack<int> kek;
    cout<<kek.Size()<<endl;
    kek.Push(1);//add 1
    kek.Push(2);// add 2
    kek.Iter();// show stack
    kek.Pop();// Вытащил последний элемент
    cout<<endl;
    kek.Iter();//show stack
    stack<char> lol;
    lol.Pop();//check except

    return a.exec();
}
