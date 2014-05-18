#include "roster.h"

namespace Jam {

void Roster::handleItemAdded (const gloox::JID &jid)
{
    qDebug("handleItemAdded");
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
    qDebug("handleItemUpdated");
}

void Roster::handleItemUnsubscribed (const gloox::JID &jid)
{
    qDebug("handleItemUnsubscribed");
}

void Roster::handleRoster (const gloox::Roster &initialRoster)
{
    qDebug("handleRoster");
    roster = &initialRoster;
}

void Roster::handleRosterPresence (const gloox::RosterItem &item, const std::string &resource, gloox::Presence::PresenceType presence, const std::string &msg)
{
    qDebug("handleRosterPresence");
}

void Roster::handleSelfPresence (const gloox::RosterItem &item, const std::string &resource, gloox::Presence::PresenceType presence, const std::string &msg)
{
    qDebug("handleSelfPresence");
}

bool Roster::handleSubscriptionRequest (const gloox::JID &jid, const std::string &msg)
{
    qDebug("handleSubscriptionRequest");
}

bool Roster::handleUnsubscriptionRequest (const gloox::JID &jid, const std::string &msg)
{
    qDebug("handleUnsubscriptionRequest");
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
