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
    connect(A_createCircle, SIGNAL(triggered()), this, SLOT(slotCreateCircle()));

    QPixmap trianglepix(":/images/triangle.png");
    QAction* A_createTriangle = toolbar->addAction(QIcon(trianglepix), "Треугольник");
    connect(A_createTriangle, SIGNAL(triggered()), this, SLOT(slotCreateTriangle()));

    QPixmap ringpix(":/images/ring.png");
    QAction* A_createRing = toolbar->addAction(QIcon(ringpix), "Кольцо");
    connect(A_createRing, SIGNAL(triggered()), this, SLOT(slotCreateRing()));

    QPixmap delete_pix(":/images/delete.png");
    QAction* A_delete_ = toolbar->addAction(QIcon(delete_pix), "Удалить");
    connect(A_delete_, SIGNAL(triggered()), this, SLOT(slotDelete()));

    toolbar->addSeparator();

    QPixmap quitpix(":/images/exit.png");
    QAction *quit = toolbar->addAction(QIcon(quitpix), "Закрыть программу");
    connect(quit, &QAction::triggered, qApp, &QApplication::quit);

    scene = new QGraphicsScene();
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(centralWidget()->rect());
    ui->graphicsView->setScene(scene);
    setCentralWidget(ui->graphicsView);

    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    showFullScreen();
}

MainWindow::~MainWindow()
{
    qDeleteAll(figures.begin(), figures.end());
    figures.clear();
    delete ui;
    delete scene;
    delete toolbar;
}

void MainWindow::slotCreateCircle()
{
    Circle* circle = new Circle(100);
    scene->addItem((Figure*)circle);
    circle->setFlag(QGraphicsItem::ItemIsMovable);
    figures.append(circle);
    circle->setPos(0,0);
}

void MainWindow::slotCreateTriangle()
{
    Triangle* triangle = new Triangle(0,0,100,100,0,100);
    scene->addItem((Figure*)triangle);
    triangle->setFlag(QGraphicsItem::ItemIsMovable);
    figures.append(triangle);
    triangle->setPos(0,0);
}

void MainWindow::slotCreateRing()
{
    Ring* ring = new Ring(100,200);
    scene->addItem((Figure*)ring);
    ring->setFlag(QGraphicsItem::ItemIsMovable);
    figures.append(ring);
    ring->setPos(0,0);
}

void MainWindow::slotDelete()
{
    qDeleteAll(figures.begin(), figures.end());
    figures.clear();
}
