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
    
    Q_PROPERTY(QString name READ name NOTIFY nameChanged)
    Q_PROPERTY(bool online READ isOnline NOTIFY isOnlineChanged)
    
public:
    Contact(QObject *parent = 0);
    Contact(gloox::RosterItem *);

    QString name();
    QString jid();
    bool isOnline();

    void update(const gloox::RosterItem *);

signals:   
    void isOnlineChanged();
    void nameChanged();

public slots:
    
private:
    QString j_name;
    QString j_jid;
    bool j_online;
};

#endif // CONTACT_H
