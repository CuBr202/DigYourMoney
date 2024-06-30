// titlewindow.h
// 标题界面
#ifndef TITLEWINDOW_H
#define TITLEWINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class TitleWindow; }
QT_END_NAMESPACE

class QPushButton;

class TitleWindow : public QWidget
{
    Q_OBJECT

public:
    TitleWindow(QWidget *parent = nullptr);
    ~TitleWindow();

signals:

private slots:
    void on_startButton_clicked();

    void on_exitButton_clicked();

    void on_continueButton_clicked();

    void on_authorButton_clicked();

private:
    Ui::TitleWindow *ui;
};

#endif // TITLEWINDOW_H
