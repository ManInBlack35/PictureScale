#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QFileInfo>
#include "dialog.h"
#include "ui_dialog.h"
#include "scale.h"
#include <QThreadPool>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    ui->setupUi(this);
    //sc=new Scale;
    //connect(this,SIGNAL (toScale(QString)),sc,SLOT(pictureScale(QString)));
    //connect(sc,SIGNAL (done()),this,SLOT (fromScale()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_browseButton_clicked()
{
    QString path;
    QFileDialog dirChoise;
    path=dirChoise.getExistingDirectory();
    currentDir.setCurrent(path);
    ui->dirLineEdit->setText(path);
}

void Dialog::on_dirLineEdit_textChanged(const QString &arg1)
{
    QFileInfo info(arg1);
    if (info.exists())
    {
        list= Recursive::recurs(arg1,ui->subDirCheckBox->isChecked());
        if (!list.empty())
        {
            if ( QMessageBox::information(this,tr("Information"),
                                     static_cast<QString> ("Find %1 file(s)").arg (list.size()),
                                     QMessageBox::Ok|QMessageBox::Cancel,
                                     QMessageBox::Ok)==QMessageBox::Ok)
            {
                ui->startButton->setEnabled(true);
                ui->subDirCheckBox->setEnabled(false);
            }
            else
            {
                ui->dirLineEdit->clear();
                ui->subDirCheckBox->setEnabled(true);
                ui->startButton->setEnabled(false);
            }
        }
        else
        {
                if ( QMessageBox::warning(this,tr("Warning!!!"),
                                         static_cast<QString> ("No files find!!!"),
                                         QMessageBox::Retry|QMessageBox::Cancel,
                                         QMessageBox::Retry)==QMessageBox::Retry)
                { emit ui->browseButton->click();}
                else
                {
                    ui->subDirCheckBox->setEnabled(true);
                    ui->startButton->setEnabled(false);
                }
        }
    }
}

void Dialog::on_canselButton_clicked()
{
    ui->subDirCheckBox->setEnabled(true);
    ui->dirLineEdit->clear();
    ui->startButton->setEnabled(false);
    ui->stopButton->setEnabled(false);
    ui->progressBar->setMaximum(0);
}

void Dialog::on_startButton_clicked()
{
    n=0;
    ui->progressBar->setMaximum(list.size());
    ui->progressBar->setValue(0);
    QVector <Scale*> scale_list;

    while(!list.empty())
    {
        Scale * scale;
        scale=new Scale (list.takeFirst());
        scale_list.append(scale);
    }

    for (int i=0;i<scale_list.size();++i)
    {
        QThreadPool::globalInstance()->start(scale_list[i]);
    }//*/
    QThreadPool::globalInstance()->waitForDone();

}
void Dialog::fromScale()
{
    ++n;
    ui->progressBar->setValue(n);
    if(n==list.size())
    {
        if(QMessageBox::information(this,tr("Information"),
                                                static_cast<QString> ("Done !!!"),
                                                QMessageBox::Ok|QMessageBox::Close,
                                                QMessageBox::Ok)==QMessageBox::Ok)
                emit ui->canselButton->click();
          else qApp->closeAllWindows();
    }
}
