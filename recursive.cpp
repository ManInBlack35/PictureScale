#include <QFileInfo>
#include <QDir>
#include <QStringList>
#include "recursive.h"

Recursive::Recursive(QObject *parent) :
    QObject(parent)
{
}

 QStringList Recursive::recurs(const QString & path, bool subDir)  //рекурсія для знаходження файлів в папкавх
{
    QStringList list;
    QFileInfo info(path);
    QDir::Filters flag;
    if (subDir)
    {
        flag=QDir::AllEntries | QDir::NoDotAndDotDot;
    }
    else flag=QDir::Files;
    if (info.isDir()) //якщо директорія, передивляємося вміст
    {
        QDir dir_rec(path);

        QStringList list_rec(dir_rec.entryList(flag)); //передивляємося вміст
        if (list_rec.size()>0) //якщо список не пустий
            for (int i=0; i<list_rec.size();++i)
            {
                QString path1=dir_rec.canonicalPath()+"/"+list_rec[i];
                list.append(recurs(path1,subDir)); //розгортаємо все дерево файлів та папок
            }
    } else
    {
        if (info.suffix()=="img"||info.suffix()=="jpg"
                ||info.suffix()=="JPG"||info.suffix()=="bmp")
            list.append(path);
    }

    return list;
}
