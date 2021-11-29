#include "mainwindow.h"
#include <QDialog>
#include <QInputDialog>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QDoubleSpinBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    w = QGuiApplication::screens().at(0)->geometry().width();
    h = QGuiApplication::screens().at(0)->geometry().height();

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

    toolbar->setStyleSheet("QToolBar {background: rgb(255, 255, 255)}");

    scene = new QGraphicsScene();
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(centralWidget()->rect());
    ui->graphicsView->setScene(scene);
    setCentralWidget(ui->graphicsView);
    scene->setBackgroundBrush(Qt::black);

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
    bool ok;
    double r = QInputDialog::getDouble(this, "Круг", "Радиус:", 0, 1, 1000, 2, &ok);
    if(ok)
    {
        Circle* circle = new Circle(r);
        scene->addItem((Figure*)circle);
        circle->setFlag(QGraphicsItem::ItemIsMovable);
        figures.append(circle);
    }

}

void MainWindow::slotCreateTriangle()
{
    QDialog* dialog = new QDialog();
    dialog->setWindowTitle("Треугольник");
    QFormLayout* formLayout = new QFormLayout();

    QDoubleSpinBox* X1 = new QDoubleSpinBox();
    X1->setMinimum(0);
    X1->setMaximum(w);
    QDoubleSpinBox* Y1 = new QDoubleSpinBox();
    Y1->setMinimum(0);
    Y1->setMaximum(h);
    QDoubleSpinBox* X2 = new QDoubleSpinBox();
    X2->setMinimum(0);
    X2->setMaximum(w);
    QDoubleSpinBox* Y2 = new QDoubleSpinBox();
    Y2->setMinimum(0);
    Y2->setMaximum(h);
    QDoubleSpinBox* X3 = new QDoubleSpinBox();
    X3->setMinimum(0);
    X3->setMaximum(w);
    QDoubleSpinBox* Y3 = new QDoubleSpinBox();
    Y3->setMinimum(0);
    Y3->setMaximum(h);

    formLayout->addRow("x1:", X1);
    formLayout->addRow("y1:", Y1);
    formLayout->addRow("x2:", X2);
    formLayout->addRow("y2:", Y2);
    formLayout->addRow("x3:", X3);
    formLayout->addRow("y3:", Y3);

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    connect(buttonBox, SIGNAL(accepted()), dialog, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), dialog, SLOT(reject()));
    formLayout->addWidget(buttonBox);
    dialog->setLayout(formLayout);

    int result = dialog->exec();

    if(result == QDialog::Accepted)
    {
        try
        {
            Triangle* triangle = new Triangle(X1->value(), Y1->value(),
                                    X2->value(), Y2->value(),
                                    X3->value(), Y3->value());
            scene->addItem((Figure*)triangle);
            triangle->setFlag(QGraphicsItem::ItemIsMovable);
            figures.append(triangle);
        }
        catch(...)
        {

        }
    }
    delete X1;
    delete Y1;
    delete X2;
    delete Y2;
    delete X3;
    delete Y3;
    delete formLayout;
    delete buttonBox;
    delete dialog;
}

void MainWindow::slotCreateRing()
{
    QDialog* dialog = new QDialog();
    dialog->setWindowTitle("Кольцо");
    QFormLayout* formLayout = new QFormLayout();
    QDoubleSpinBox* r = new QDoubleSpinBox();
    r->setMinimum(1);
    r->setMaximum(1000);
    QDoubleSpinBox* R = new QDoubleSpinBox();
    R->setMinimum(1);
    R->setMaximum(1000);
    formLayout->addRow("Маленький радиус", r);
    formLayout->addRow("Большой радиус", R);
    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    connect(buttonBox, SIGNAL(accepted()), dialog, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), dialog, SLOT(reject()));
    formLayout->addWidget(buttonBox);
    dialog->setLayout(formLayout);

    int result = dialog->exec();

    if(result == QDialog::Accepted)
    {
        try
        {
            Ring* ring = new Ring(r->value(),R->value());
            scene->addItem((Figure*)ring);
            ring->setFlag(QGraphicsItem::ItemIsMovable);
            figures.append(ring);
        }
        catch(...)
        {

        }
    }
    delete r;
    delete R;
    delete formLayout;
    delete buttonBox;
    delete dialog;
}

void MainWindow::slotDelete()
{
    qDeleteAll(figures.begin(), figures.end());
    figures.clear();
}
