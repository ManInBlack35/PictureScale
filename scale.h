#ifndef SCALE_H
#define SCALE_H

#include <QObject>

class Scale : public QObject
{
    Q_OBJECT
public:
    explicit Scale(QObject *parent = 0);

signals:
    void done();

public slots:
    void pictureScale(const QString & path);
};

#endif // SCALE1_H
