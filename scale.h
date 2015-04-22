#ifndef SCALE_H
#define SCALE_H

#include <QObject>
#include <QRunnable>

class Scale : public QRunnable
{
    //Q_OBJECT
public:
    //explicit Scale(QObject *parent = 0);
    Scale (const QString & path);

/*signals:
    void done();

public slots:
    void pictureScale(const QString & path);//*/
private:
    virtual void run();
    QString cur_path;
};

#endif // SCALE1_H
