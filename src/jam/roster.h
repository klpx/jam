#ifndef JAM_ROSTER_H
#define JAM_ROSTER_H

#include <QObject>
#include <QQmlListProperty>

#include <gloox/client.h>
#include <gloox/rosterlistener.h>
#include <gloox/rostermanager.h>
#include <gloox/presence.h>
#include <gloox/iq.h>

#include "../ui/contact.h"

namespace Jam {
    class Roster;
}

class Jam::Roster :
        public QObject,
        public gloox::RosterListener
{
    Q_OBJECT
    
    Q_PROPERTY(QQmlListProperty<Jam::Contact> contacts READ contacts NOTIFY onContactsChanged)

public:
    Roster(QObject *parent = 0) : QObject(parent) {}

    QQmlListProperty<Jam::Contact> contacts();

    virtual void handleItemAdded (const gloox::JID &jid);
    virtual void handleItemSubscribed (const gloox::JID &jid);
    virtual void handleItemRemoved (const gloox::JID &jid);
    virtual void handleItemUpdated (const gloox::JID &jid);
    virtual void handleItemUnsubscribed (const gloox::JID &jid);
    virtual void handleRoster (const gloox::Roster &roster);
    virtual void handleRosterPresence (const gloox::RosterItem &item, const std::string &resource, gloox::Presence::PresenceType presence, const std::string &msg);
    virtual void handleSelfPresence (const gloox::RosterItem &item, const std::string &resource, gloox::Presence::PresenceType presence, const std::string &msg);
    virtual bool handleSubscriptionRequest (const gloox::JID &jid, const std::string &msg);
    virtual bool handleUnsubscriptionRequest (const gloox::JID &jid, const std::string &msg);
    virtual void handleNonrosterPresence (const gloox::Presence &presence);
    virtual void handleRosterError (const gloox::IQ &iq);

signals:
    void onContactsChanged();

private:
//    gloox::Client *j_client = 0;
//    gloox::RosterManager *j_roster_manager = 0;
    const gloox::Roster *roster = 0;
    QList<Jam::Contact *> j_contacts;
};

#endif // JAM_ROSTER_H
