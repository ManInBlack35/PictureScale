#include <QPixmap>
#include <QFileInfo>
#include "scale.h"

Scale::Scale(QObject *parent) :
    QObject(parent)
{
}

void Scale::pictureScale(const QString & path)
{
    QPixmap picture (path);
    QFileInfo info (path);
    int w=picture.width(),h=picture.height();
    picture=picture.scaled(w/2,h/2, Qt::KeepAspectRatio,Qt::SmoothTransformation);
    QString newPath(path);
    newPath.remove("."+info.suffix());
    newPath.append("_scaled."+info.suffix());
    picture.save(newPath);
    emit done();
}
