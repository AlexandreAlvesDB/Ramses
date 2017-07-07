#include "ramstatus.h"
#ifdef QT_DEBUG
#include <QtDebug>
#endif

RAMStatus::RAMStatus(DBInterface *db, int i, QString n, QString sN, QColor c, QString d, bool updateDb, QObject *parent) : QObject(parent)
{

    statusId = i;
    statusName = n;
    statusShortName = sN;
    statusColor = c;
    statusDescription = d;
    dbi = db;

    if (updateDb)
    {
        dbi->addStatus(statusName,statusShortName,statusColor.name(),statusDescription,statusId);
    }
}

RAMStatus::~RAMStatus()
{

}

// GET

int RAMStatus::getId()
{
    return statusId;
}

QString RAMStatus::getName()
{
    return statusName;
}

QString RAMStatus::getShortName()
{
    return statusShortName;
}

QColor RAMStatus::getColor()
{
    return statusColor;
}

QString RAMStatus::getDescription()
{
    return statusDescription;
}

// SET

void RAMStatus::setName(QString name, bool updateDb)
{
    statusName = name;
    if (updateDb) update();
    emit nameChanged(name);
}

void RAMStatus::setShortName(QString shortName, bool updateDb)
{
    statusShortName = shortName;
    if (updateDb) update();
    emit shortNameChanged(shortName);
}

void RAMStatus::setColor(QColor color, bool updateDb)
{
    statusColor = color;
    if (updateDb) update();
    emit colorChanged(color);
}

void RAMStatus::setDescription(QString description, bool updateDb)
{
    statusDescription = description;
    if (updateDb) update();
    emit descriptionChanged(description);
}

void RAMStatus::update()
{
    dbi->updateStatus(statusId,statusName,statusShortName,statusColor.name(),statusDescription);
}

void RAMStatus::remove()
{
    dbi->removeStatus(statusId);
    emit statusRemoved(this);
}

bool RAMStatus::operator==(RAMStatus s)
{
    return this->getId() == s.getId();
}

bool RAMStatus::operator==(RAMStatus *s)
{
    return this->getId() == s->getId();
}
