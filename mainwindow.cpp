#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


MainWindow::JournalNote::JournalNote()
{
    influence = hour = minute = second = DEFAULT_INT;
    surname = name = secondName = DEFAULT_STR;
    volume = 1;
}
MainWindow::JournalNote::JournalNote(int hour, int minute, int second, QString surname, QString name, QString secondName, int volume, int influence)
{
    if (hour >= 0 && hour <= 24)
        this->hour = hour;
    else
        throw invalid_argument("hour < 0 or hour > 24");

    if (minute >= 0 && minute <= 60)
        this->minute = minute;
    else
        throw invalid_argument("minute < 0 or minute > 60");

    if (second >= 0 && second <= 60)
        this->second = second;
    else
        throw invalid_argument("second < 0 or second > 60");

    this->surname = surname;
    this->name = name;
    this->secondName = secondName;
    if (volume <= 0)
    {
        throw invalid_argument("volume <= 0");
    }
    else
    {
        this->volume = volume;
    }
    if (influence < 0 && abs(influence) > volume)
    {
        throw invalid_argument("-influence > volume");
    }
    else
    {
        this->influence = influence;
    }
}
MainWindow::JournalNote::JournalNote(const JournalNote &other)
{
    this->hour = other.hour;
    this->minute = other.minute;
    this->second = other.second;
    this->surname = other.surname;
    this->name = other.name;
    this->secondName = other.secondName;
    this->influence = other.influence;
}


int MainWindow::JournalNote::getHour() const
{
    return hour;
}
void MainWindow::JournalNote::setHour(int hour)
{
    if (hour >= 0 && hour <= 24)
        this->hour = hour;
    else
        throw invalid_argument("hour < 0 or hour > 24");
}

int MainWindow::JournalNote::getMinute() const
{
    return minute;
}
void MainWindow::JournalNote::setMinute(int minute)
{
    if (minute >= 0 && minute <= 60)
        this->minute = minute;
    else
        throw invalid_argument("minute < 0 or minute > 60");
}

int MainWindow::JournalNote::getSecond() const
{
    return second;
}
void MainWindow::JournalNote::setSecond(int second)
{
    if (second >= 0 && second <= 60)
        this->second = second;
    else
        throw invalid_argument("second < 0 or second > 60");
}

QString MainWindow::JournalNote::getSurname() const
{
    return surname;
}
void MainWindow::JournalNote::setSurname(QString surname)
{
    this->surname = surname;
}

QString MainWindow::JournalNote::getName() const
{
    return name;
}
void MainWindow::JournalNote::setName(QString name)
{
    this->name = name;
}

QString MainWindow::JournalNote::getSecondName() const
{
    return secondName;
}
void MainWindow::JournalNote::setSecondName(QString secondName)
{
    this->secondName = secondName;
}

int MainWindow::JournalNote::getInfluence() const
{
    return influence;
}
void MainWindow::JournalNote::setInfluence(int influence)
{
    if (influence < 0 && abs(influence) > volume)
    {
        throw invalid_argument("-influence > volume");
    }
    else
    {
        this->influence = influence;
    }
}

int MainWindow::JournalNote::getVolume() const
{
    return volume;
}
void MainWindow::JournalNote::setVolume(int volume)
{
    if (volume <= 0)
    {
        throw invalid_argument("volume <= 0");
    }
    else
    {
        this->volume = volume;
    }
}




MainWindow::ControllerNote::ControllerNote()
{
    this->setHour(DEFAULT_INT);
    this->setMinute(DEFAULT_INT);
    this->setSecond(DEFAULT_INT);
    this->setSurname(DEFAULT_STR);
    this->setName(DEFAULT_STR);
    this->setSecondName(DEFAULT_STR);
    this->setVolume(1);
    this->setInfluence(DEFAULT_INT);
    coffee = 1;
}
MainWindow::ControllerNote::ControllerNote(int hour, int minute, int second, QString surname, QString name, QString secondName, int volume, int influence)
{
    if (hour >= 0 && hour <= 24)
        this->setHour(hour);
    else
        throw invalid_argument("hour < 0 or hour > 24");

    if (minute >= 0 && minute <= 60)
        this->setMinute(minute);
    else
        throw invalid_argument("minute < 0 or minute > 60");

    if (second >= 0 && second <= 60)
        this->setSecond(second);
    else
        throw invalid_argument("second < 0 or second > 60");

    this->setSurname(surname);
    this->setName(name);
    this->setSecondName(secondName);
    if (volume <= 0)
    {
        throw invalid_argument("volume <= 0");
    }
    else
    {
        this->setVolume(volume);
    }
    if (influence < 0 && abs(influence) > volume)
    {
        throw invalid_argument("-influence > volume");
    }
    else
    {
        this->setInfluence(influence);
    }
    coffee = volume + influence;
}

int MainWindow::ControllerNote::getCoffee() const
{
    return coffee;
}
void MainWindow::ControllerNote::setCoffee()
{
    coffee = getVolume() + getInfluence();
}
void MainWindow::ControllerNote::setCoffee(int coffee)
{
    if (coffee > 0)
    {
        this->coffee = coffee;
    }
    else
    {
        throw invalid_argument("coffee <= 0");
    }
}



QString MainWindow::Collection::refresh()
{
    QString temp = "";
    for (int i = 0; i < collect.size(); ++i)
    {
        temp.append(QString::number(collect[i].getHour()));
        temp.append(":");
        temp.append(QString::number(collect[i].getMinute()));
        temp.append(":");
        temp.append(QString::number(collect[i].getSecond()));
        temp.append("\n");
        temp.append(collect[i].getSurname());
        temp.append(" ");
        temp.append(collect[i].getName());
        temp.append(" ");
        temp.append(collect[i].getSecondName());
        temp.append("\nCoffee: ");
        temp.append(QString::number(collect[i].getCoffee()));
        temp.append("\n\n");
    }
    return temp;
}
void MainWindow::Collection::addElem(int index, int hour, int minute, int second, QString surname, QString name, QString secondName, int volume, int influence)
{
    ControllerNote temp(hour, minute, second, surname, name, secondName, volume, influence);
    collect.insert(index, temp);
}
void MainWindow::Collection::delElem(int index)
{
    collect.removeAt(index);
}
int MainWindow::Collection::writeInFile(QString filename)
{
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly))
    {
        QTextStream outp(&file);
        for (int i = 0; i < collect.size(); ++i)
        {
            outp << QString::number(collect[i].getHour()) << "\n";
            outp << QString::number(collect[i].getMinute()) << "\n";
            outp << QString::number(collect[i].getSecond()) << "\n";
            outp << collect[i].getSurname() << "\n";
            outp << collect[i].getName() << "\n";
            outp << collect[i].getSecondName() << "\n";
            outp << QString::number(collect[i].getCoffee()) << "\n";
        }
    }
    else
    {
        return 1;
    }

    file.close();
    return 0;
}
int MainWindow::Collection::readFromFile(QString filename)
{
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream inp(&file);
        collect.clear();
        while (!file.atEnd())
        {
            ControllerNote temp;
            temp.setHour(inp.readLine().toInt());
            temp.setMinute(inp.readLine().toInt());
            temp.setSecond(inp.readLine().toInt());
            temp.setSurname(inp.readLine());
            temp.setName(inp.readLine());
            temp.setSecondName(inp.readLine());
            temp.setCoffee(inp.readLine().toInt());
            collect.append(temp);
        }
    }
    else
    {
        return 1;
    }

    file.close();
    return 0;
}
int MainWindow::Collection::size()
{
    return collect.size();
}


void MainWindow::on_pushButton_clicked() //Add
{
    if (!(ui->lineEdit->text().toInt() >= 0 && ui->lineEdit->text().toInt() <= 24))
        QMessageBox::critical(this, "Error", "Hour < 0 or Hour > 24");
    else if (!(ui->lineEdit_2->text().toInt() >= 0 && ui->lineEdit_2->text().toInt() <= 60))
        QMessageBox::critical(this, "Error", "minute < 0 or minute > 60");
    else if (!(ui->lineEdit_3->text().toInt() >= 0 && ui->lineEdit_3->text().toInt() <= 60))
        QMessageBox::critical(this, "Error", "second < 0 or second > 60");
    else if (ui->lineEdit_7->text().toInt() <= 0)
        QMessageBox::critical(this, "Error", "volume <= 0");
    else if (ui->lineEdit_8->text().toInt() < 0 && abs(ui->lineEdit_8->text().toInt()) > ui->lineEdit_7->text().toInt())
        QMessageBox::critical(this, "Error", "-influence > volume");
    else
    list.addElem(ui->lineEdit_9->text().toInt(), ui->lineEdit->text().toInt(), ui->lineEdit_2->text().toInt(), ui->lineEdit_3->text().toInt(),
                 ui->lineEdit_4->text(), ui->lineEdit_5->text(), ui->lineEdit_6->text(), ui->lineEdit_7->text().toInt(), ui->lineEdit_8->text().toInt());
}
void MainWindow::on_pushButton_2_clicked() //Delete
{
    list.delElem(ui->lineEdit_10->text().toInt());
}
void MainWindow::on_pushButton_3_clicked() //Write
{
    if (list.writeInFile(ui->lineEdit_11->text()))
    {
        QMessageBox::critical(this, "Error", "Could not open file!");
    }
}
void MainWindow::on_pushButton_4_clicked() //Read
{
    if (list.readFromFile(ui->lineEdit_11->text()))
    {
        QMessageBox::critical(this, "Error", "Could not open file!");
    }
}
void MainWindow::on_pushButton_5_clicked() //Refresh
{
    ui->textEdit->setText(list.refresh());
}


