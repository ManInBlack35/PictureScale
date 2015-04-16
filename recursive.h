#ifndef RECURSIVE_H
#define RECURSIVE_H

#include <QObject>

class Recursive : public QObject
{
    Q_OBJECT
public:
    explicit Recursive(QObject *parent = 0);
    static QStringList recurs(const QString & path, bool subDir);

signals:

public slots:

};

#endif // RECURSIVE_H
