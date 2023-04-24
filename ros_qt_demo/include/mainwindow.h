#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rqnode.hpp"
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

    // void updateTopicInfo(QString);

private:
    Ui::MainWindow *ui;
    RQNode *_aQNode;
};
#endif // MAINWINDOW_H
