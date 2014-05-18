#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "jam/client.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Jam::Client client;
    engine.rootContext()->setContextProperty("jamClient", &client);

    engine.load(QUrl(QStringLiteral("qrc:///login.qml")));

    return app.exec();
}
