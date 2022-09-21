#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QString>
#include <QList>
#include <QTextStream>
#include <QFile>
#include "math.h"
#include "stdlib.h"
using namespace std;

#define DEFAULT_INT 0
#define DEFAULT_STR ""



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;

    class JournalNote
    {
    private:
        int hour, minute, second;
        QString surname, name, secondName;
        int influence, volume;
    public:
        JournalNote();
        JournalNote(int hour, int minute, int second, QString surname, QString name, QString secondName, int volume, int influence);
        JournalNote(const JournalNote &other);
        ~JournalNote()
        = default;

        int getHour() const;
        void setHour(int hour);

        int getMinute() const;
        void setMinute(int minute);

        int getSecond() const;
        void setSecond(int second);

        QString getSurname() const;
        void setSurname(QString surname);

        QString getName() const;
        void setName(QString name);

        QString getSecondName() const;
        void setSecondName(QString secondName);

        int getInfluence() const;
        void setInfluence(int influence);

        int getVolume() const;
        void setVolume(int volume);
    };


    class ControllerNote : public JournalNote
    {
    private:
        int coffee;
    public:
        ControllerNote();
        ~ControllerNote() = default;
        ControllerNote(int hour, int minute, int second, QString surname, QString name, QString secondName, int volume, int influence);

        int getCoffee() const;
        void setCoffee();
        void setCoffee(int coffee);
    };


    class Collection
    {
    private:
        QList<ControllerNote> collect;
    public:
        void addElem(int index, int hour, int minute, int second, QString surname, QString name, QString secondName, int volume, int influence);
        void delElem(int index);
        int writeInFile(QString filename);
        int readFromFile(QString filename);
        int size();
        QString refresh();
    };

    Collection list;
};


#endif // MAINWINDOW_H

