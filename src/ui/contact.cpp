#include "contact.h"

Jam::Contact::Contact(QObject *parent)
    : QObject(parent)
{
    qDebug("Jam::Contact copy");
    //j_name = parent->;
    //j_online = parent.j_online;
}

Jam::Contact::Contact(gloox::RosterItem *item)
{
    j_name = item->name().data();
    j_online = item->online();
    qDebug("new item");
}


QString Jam::Contact::name()
{
    return j_name;
}

bool Jam::Contact::isOnline()
{
    return j_online;
}
