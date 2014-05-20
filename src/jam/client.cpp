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

void Jam::Client::closeConnection()
{
    if (connected) {
        j_clientp->disconnect();
    }
}


void Jam::Client::setConnected(bool value)
{
    connected = value;
    emit connectedChanged();
}

void Jam::Client::connect(QString username, QString password)
{
    connection_thread = std::thread(
        [this, username, password] () {
            connection_thread_started = true;

            j_jid.setJID(username.toStdString());

            j_clientp = new gloox::Client(j_jid, password.toStdString());

            j_clientp->registerConnectionListener(this);
            j_clientp->registerPresenceHandler(this);
            j_clientp->registerMessageSessionHandler(this);

            j_clientp->rosterManager()->registerRosterListener(roster, false);

            j_clientp->disco()->setVersion("Jam", "0.0.1");
            j_clientp->disco()->setIdentity("client", "pc"); // http://xmpp.org/registrar/disco-categories.html#client

            j_clientp->connect(true);
        }
    );
}

void Jam::Client::subscribe(QString username)
{
    qDebug("Subscribe to");
    qDebug(username.toStdString().data());
    gloox::JID jid(username.toStdString());
    j_clientp->rosterManager()->subscribe(jid);
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
    qDebug("presence");
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

void Jam::Client::handleMessageSession( gloox::MessageSession * session )
{
    chats.emplace_back(session);
}
