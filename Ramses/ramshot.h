#ifndef RAMSHOT_H
#define RAMSHOT_H

#include <QObject>
#include "ramstagestatus.h"
#include "ramasset.h"

class RAMShot : public QObject
{
    Q_OBJECT
public:
    explicit RAMShot(int i, QString n, double d = 0.0,int so = 0, QObject *parent = 0);
    int getId();
    QString getName();
    double getDuration();
    int getOrder();
    void addStatus(RAMStageStatus *s);
    QList<RAMStageStatus *> getStatuses();
    void addAsset(RAMAsset *a);
    QList<RAMAsset *> getAssets();

signals:
    void shotStatusUpdated(RAMStatus*,RAMStage*,RAMShot*);

public slots:
    void updateShotStatus(RAMStatus* status,RAMStage* stage);

private:
    double duration;
    QString name;
    int id;
    int shotOrder;
    QList<RAMStageStatus *> statuses;
    QList<RAMAsset *> assets;
};

#endif // RAMSHOT_H
