#ifndef JAM_CHAT_H
#define JAM_CHAT_H

#include <QObject>
#include <gloox/messagesessionhandler.h>
#include <gloox/messagehandler.h>
#include <gloox/message.h>

namespace Jam {

class Chat : public QObject, public gloox::MessageHandler
{
    Q_OBJECT
public:
    explicit Chat(QObject *parent = 0);
    Chat(gloox::MessageSession *);

    virtual void handleMessage (const gloox::Message& msg, gloox::MessageSession *session = 0);

signals:

public slots:


private:
};

} // namespace Jam

#endif // JAM_CHAT_H
