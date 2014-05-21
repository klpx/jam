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
    j_jid = item->jid().data();
    j_name = item->jid().data();
    j_online = item->online();

    emit nameChanged();
    emit isOnlineChanged();
}

void Jam::Contact::update(gloox::RosterItem *item)
{
    j_jid = item->jid().data();
    j_name = item->jid().data();
    j_online = item->online();

    emit nameChanged();
    emit isOnlineChanged();
}

QString Jam::Contact::name()
{
    return j_name;
}

QString Jam::Contact::jid()
{
    return j_jid;
}

bool Jam::Contact::isOnline()
{
    return j_online;
}
