#include "chat.h"

namespace Jam {

Chat::Chat(QObject *parent) :
    QObject(parent)
{
}

Chat::Chat(gloox::MessageSession *session)
{
    session->registerMessageHandler(this);
}

void Chat::handleMessage (const gloox::Message& msg, gloox::MessageSession *session)
{
    qDebug(msg.body().data());
}

} // namespace Jam
