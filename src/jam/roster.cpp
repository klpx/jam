#include "roster.h"
#include <map>

namespace Jam {

void Roster::init(gloox::RosterManager *initialManager)
{
    manager = initialManager;
    manager->registerRosterListener(this, false);
}

QQmlListProperty<Jam::Contact> Roster::contacts()
{
    return QQmlListProperty<Jam::Contact>(this, j_contacts);
}

void Roster::handleItemAdded (const gloox::JID &jid)
{
    gloox::RosterItem *newItem = manager->getRosterItem(jid);
    if (newItem) {
        Jam::Contact *newContact = new Jam::Contact(newItem);
        j_contacts.append(newContact);
        emit onContactsChanged();
    }
    else {
        qDebug("New item not found in gloox::Roster");
    }
}

void Roster::handleItemSubscribed (const gloox::JID &jid)
{
    qDebug("handleItemSubscribed");
}

void Roster::handleItemRemoved (const gloox::JID &jid)
{
    qDebug("handleItemRemoved");
}

void Roster::handleItemUpdated (const gloox::JID &jid)
{
    gloox::RosterItem *updateItem = manager->getRosterItem(jid);
    if (updateItem) {
        bool updated = false;
        QList<Jam::Contact *>::const_iterator contact;
        for (contact = j_contacts.begin(); contact != j_contacts.end(); ++contact)
        {
            if ((*contact)->jid() == updateItem->jid().data())
            {
                (*contact)->update(updateItem);
                updated = true;
                emit onContactsChanged();
                break;
            }
        }
        if (!updated) {
            qDebug("Item to update is not found in Jam::Roster");
        }
    }
    else {
        qDebug("Item to update is not found in gloox::Roster");
    }
}

void Roster::handleItemUnsubscribed (const gloox::JID &jid)
{
    qDebug("handleItemUnsubscribed");
}

void Roster::handleRoster (const gloox::Roster &initialRoster)
{
    roster = &initialRoster;
    
    gloox::Roster::const_iterator pair;
    for(pair = roster->begin(); pair != roster->end(); ++pair)
    {
        Jam::Contact *contact = new Jam::Contact(pair->second);
        j_contacts.append(contact);
    }
    emit onContactsChanged();
}

void Roster::handleRosterPresence (const gloox::RosterItem &item, const std::string &resource, gloox::Presence::PresenceType presence, const std::string &msg)
{
    QList<Jam::Contact *>::const_iterator contact;
    for (contact = j_contacts.begin(); contact != j_contacts.end(); ++contact)
    {
        if ((*contact)->jid() == item.jid().data())
        {
            (*contact)->update(&item);
            emit onContactsChanged();
            break;
        }
    }
}

void Roster::handleSelfPresence (const gloox::RosterItem &item, const std::string &resource, gloox::Presence::PresenceType presence, const std::string &msg)
{
    qDebug("handleSelfPresence");
}

bool Roster::handleSubscriptionRequest (const gloox::JID &jid, const std::string &msg)
{
    qDebug() << "handleSubscriptionRequest from " << jid.full().data() << " with message: `" << msg.data() << "`";
    manager->ackSubscriptionRequest(jid, true);
}

bool Roster::handleUnsubscriptionRequest (const gloox::JID &jid, const std::string &msg)
{
    qDebug("handleUnsubscriptionRequest, returned true");
    return true;
}

void Roster::handleNonrosterPresence (const gloox::Presence &presence)
{
    qDebug("handleNonrosterPresence");
}

void Roster::handleRosterError (const gloox::IQ &iq)
{
    qDebug("handleRosterError");
}


} // namespace Jam
