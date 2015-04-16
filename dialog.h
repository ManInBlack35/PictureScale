#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDir>
#include <QString>
#include "recursive.h"
#include "scale.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_browseButton_clicked();

    void on_dirLineEdit_textChanged(const QString &arg1);

    void on_canselButton_clicked();

    void on_startButton_clicked();

    void fromScale();

signals:
    void toScale(const QString& path);

private:
    int n;
    Scale * sc;
    QStringList list;
    QDir currentDir;
    Ui::Dialog *ui;
};

#endif // DIALOG_H
