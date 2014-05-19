#include "client.h"

Jam::Client::Client(QObject *parent) : QObject(parent)
{
    roster = new Jam::Roster;
    setConnected(false);
}

Jam::Client::~Client()
{
    if (connection_thread_started) {
        connection_thread.join();
    }
    if (j_clientp) {
        delete j_clientp;
    }
    delete roster;
}


void Jam::Client::setConnected(bool value)
{
    connected = value;
    emit connectedChanged();
}

void Jam::Client::connect(QString username, QString password)
{
    connection_thread = std::thread(
        [this] (QString username, QString password) {
            connection_thread_started = true;

            j_jid.setJID("jam@xmpp.ru");

            j_clientp = new gloox::Client(j_jid, "******");
            j_clientp->registerConnectionListener(this);
            j_clientp->registerPresenceHandler(this);

            j_clientp->rosterManager()->registerRosterListener(roster, false);

            j_clientp->connect(true);
        },
        username, password
    );
}

void Jam::Client::ping()
{
    gloox::JID rcpt;
    rcpt.setJID("alex@arigativa.ru");

    gloox::Message::MessageType type(gloox::Message::MessageType::Normal);
    gloox::Message msg(type, rcpt, "ping pong");

    j_clientp->send(msg);
}


void Jam::Client::handlePresence( const gloox::Presence& presence )
{
}

void Jam::Client::onConnect()
{
    setConnected(true);
    qDebug("Connected");
}

bool Jam::Client::onTLSConnect( const gloox::CertInfo& info )
{
    setConnected(true);
    qDebug("Connected with TLS");
    return true;
}

void Jam::Client::onDisconnect( gloox::ConnectionError e )
{
    setConnected(false);
    qDebug("Disconnected");
}
