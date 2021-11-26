#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Figure.h"
#include <QScreen>
#include <QToolBar>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Figure");
    setWindowIcon(QIcon(":/images/cylinder.png"));

    QPixmap circlepix(":/images/circle.png");
    QPixmap trianglepix(":/images/triangle.png");
    QPixmap ringpix(":/images/ring.png");
    toolbar = addToolBar("toolbar");
    toolbar->addAction(QIcon(circlepix), "Круг");
    toolbar->addAction(QIcon(trianglepix), "Треугольник");
    toolbar->addAction(QIcon(ringpix), "Кольцо");
    toolbar->addSeparator();

    int w = QGuiApplication::screens().at(0)->geometry().width();
    int h = QGuiApplication::screens().at(0)->geometry().height();

    move(0, 0);
    setFixedSize(w, h);

    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    setCentralWidget(ui->graphicsView);
    scene->setSceneRect(geometry());
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    Triangle *triangle = new Triangle(3, 4, 5);
    scene->addItem((Figure*)triangle);
    triangle->setPos(w/2, h/2);
    //scene->addRect(0, 100, 200, 300);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete toolbar;
}

