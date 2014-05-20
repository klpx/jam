#ifndef CONTACT_H
#define CONTACT_H

#include <QObject>
#include <string>
#include <gloox/rosteritem.h>

namespace Jam {
    class Contact;
}

class Jam::Contact : public QObject
{
    Q_OBJECT
    
    Q_PROPERTY(QString name READ name)
    Q_PROPERTY(bool isOnline READ isOnline)
    
public:
    Contact(QObject *parent = 0);
    Contact(gloox::RosterItem *);

    QString name();
    bool isOnline();

signals:

public slots:
    
private:
    QString j_name;
    bool j_online;
};

#endif // CONTACT_H
