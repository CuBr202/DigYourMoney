// mainwindow.h
// 游戏主界面
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QTimer>
#include "playerdata.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QPushButton;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr,PlayerData pld=PlayerData());
    void updateGameEvents();

    ~MainWindow();

signals:

private slots:
    void on_gambleButton_clicked();
    void on_pushButton_clicked();
    void on_mainButton_clicked();

    void on_unbreakButton_clicked();

    void on_speedButton_clicked();

    void on_accButton_clicked();
    void accEnd();

    void on_pushUnsaveButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *gameTimer;
    QTimer *accTimer;
    PlayerData pl;
};

QString Sci(long long x);

#endif // MAINWINDOW_H
