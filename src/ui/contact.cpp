#include "contact.h"

//Contact::Contact(QObject *parent) :
//    QObject(parent)
//{
//}

Jam::Contact::Contact(QObject *parent)
    : QObject(parent)
{
    j_name = "no name";
}


Jam::Contact::Contact(std::string name)
{
    j_name = name.data();
}
