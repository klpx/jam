#ifndef JAMCLIENT_H
#define JAMCLIENT_H

#include <QObject>
#include <QString>

#include <gloox/client.h>
#include <gloox/jid.h>
#include <gloox/presencehandler.h>
#include <gloox/connectionlistener.h>
#include <gloox/messagesessionhandler.h>
#include <gloox/message.h>
#include <gloox/disco.h>

#include <thread>
#include <list>

#include "src/jam/roster.h"
#include "src/jam/chat.h"

namespace Jam {
    class Client;
}

class Jam::Client :
        public QObject,
        gloox::ConnectionListener, gloox::PresenceHandler, gloox::MessageSessionHandler
{
    Q_OBJECT
    Q_PROPERTY(bool connected READ isConnected NOTIFY connectedChanged)
    Q_PROPERTY(Jam::Roster* roster READ getRoster)

public:
    Client(QObject *parent=0);
    ~Client();

    virtual void handlePresence( const gloox::Presence& );
    virtual void onConnect();
    virtual bool onTLSConnect( const gloox::CertInfo& );
    virtual void onDisconnect( gloox::ConnectionError  );
    virtual void handleMessageSession( gloox::MessageSession * );

    bool isConnected() const { return connected; }
    Jam::Roster *getRoster() { return roster; }

public slots:
    void connect(QString, QString);
    void ping();
    void closeConnection();
    void subscribe(QString username);

signals:
    void connectedChanged();

private:
    bool connected;
    void setConnected(bool);

    gloox::JID j_jid;
    gloox::Client *j_clientp = 0;

    std::thread connection_thread;
    bool connection_thread_started = false;

    Jam::Roster *roster = 0;

    std::list<Jam::Chat> chats;
};

#endif // JAMCLIENT_H
