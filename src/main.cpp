#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtQml>
#include <QObject>

#include "jam/client.h"
#include "ui/contact.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Jam::Client client;

    QObject::connect(&app, SIGNAL(lastWindowClosed()), &client, SLOT(closeConnection()));

    QQmlContext *rootContext = engine.rootContext();

    qmlRegisterType<Jam::Client>  ("Client",  1, 0, "Client");
    qmlRegisterType<Jam::Contact> ("Contact", 1, 0, "Contact");
    qmlRegisterType<Jam::Roster>  ("Roster",  1, 0, "Roster");

    rootContext->setContextProperty("jamClient", &client);

    engine.load(QUrl(QStringLiteral("qrc:///login.qml")));

    return app.exec();
}
