#ifndef CONTACT_H
#define CONTACT_H

#include <QObject>
#include <string>

namespace Jam {
    class Contact;
}

class Jam::Contact : public QObject
{
    Q_OBJECT
    
    Q_PROPERTY(QString name READ name)
    
public:
    Contact(QObject *parent = 0);
    Contact(std::string);

    QString name() const { return j_name; }
    void setName(QString &newName) { j_name=newName; }

signals:

public slots:
    
private:
    QString j_name;
};

#endif // CONTACT_H
