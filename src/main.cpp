#include <QApplication>
#include <QQmlApplicationEngine>

#include <gloox/jid.h>
#include <gloox/client.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    gloox::JID jid;
    jid.setServer("domain-xmpp.ya.ru");
    jid.setUsername("alex@arigativa.ru");

    gloox::Client client(jid, "*****");
    client.connect();

    return app.exec();
}
