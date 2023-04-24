#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qmynode.hpp"
#include <iostream>
QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void sendmsgs(int id);

private:
    Ui::MainWindow *ui;
    QMyNode *commNode;
};
#endif // MAINWINDOW_H
