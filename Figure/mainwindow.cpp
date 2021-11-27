#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Figure");
    setWindowIcon(QIcon(":/images/cylinder.png"));

    toolbar = addToolBar("toolbar");

    QPixmap circlepix(":/images/circle.png");
    QAction* A_createCircle = toolbar->addAction(QIcon(circlepix), "Круг");
    connect(A_createCircle, SIGNAL(triggered()), this, SLOT(createCircle()));

    QPixmap trianglepix(":/images/triangle.png");
    QAction* A_createTriangle = toolbar->addAction(QIcon(trianglepix), "Треугольник");
    connect(A_createTriangle, SIGNAL(triggered()), this, SLOT(createTriangle()));

    QPixmap ringpix(":/images/ring.png");
    QAction* A_createRing = toolbar->addAction(QIcon(ringpix), "Кольцо");
    connect(A_createRing, SIGNAL(triggered()), this, SLOT(createRing()));

    toolbar->addSeparator();

    QPixmap quitpix(":/images/exit.png");
    QAction *quit = toolbar->addAction(QIcon(quitpix), "Закрыть программу");
    connect(quit, &QAction::triggered, qApp, &QApplication::quit);

    scene = new QGraphicsScene();
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setGeometry(geometry());
    setCentralWidget(ui->graphicsView);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    //ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    //scene->addLine(0, 0, 0, 0, QPen(Qt::red, 100));

    showFullScreen();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete toolbar;
}

void MainWindow::createCircle()
{
    Circle* circle = new Circle(100);
    scene->addItem((Figure*)circle);
    circle->setPos(0,0);
}

void MainWindow::createTriangle()
{
    Triangle* triangle = new Triangle(0,0,100,100,0,100);
    scene->addItem((Figure*)triangle);
    triangle->setPos(0,0);
}

void MainWindow::createRing()
{
    Ring* ring = new Ring(10,20);
    scene->addItem((Figure*)ring);
    ring->setPos(0,0);
}
