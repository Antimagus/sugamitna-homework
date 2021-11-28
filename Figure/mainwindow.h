#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "ui_mainwindow.h"
#include "Figure.h"
#include <QScreen>
#include <QToolBar>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QToolBar *toolbar;
    QList<QGraphicsItem *> figures;
public slots:
    void slotCreateCircle();
    void slotCreateTriangle();
    void slotCreateRing();
    void slotDelete();
};
#endif // MAINWINDOW_H
