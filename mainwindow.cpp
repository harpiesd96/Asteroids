#include "mainwindow.h"
#include "scene.h"
#include "mainship.h"
#include "bullet.h"

#include <QMenuBar>
#include <QGraphicsView>
//#include <QStatusBar>



MainWindow::MainWindow():QMainWindow()
{

    // add drop down menus
    QMenu* Menu = menuBar()->addMenu("&File");

    //saveAction->setShortcut( QKeySequence::Save );

    QAction* StartAction = Menu->addAction("&Start Game", this, SLOT(StartButton_Clicked()));
    QAction* CloseAction = Menu->addAction("&Exit Game", this, SLOT(close()));


    connect(this, SIGNAL(MainWindow::StartAction), this, SLOT(newGame(Scene*)));

    // connect message signal from scene to showMessage slot


  // create scene and central widget view of scene
  scene = new Scene();
  QGraphicsView *view = new QGraphicsView(scene);
  view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
  view->setFrameStyle(0);
  view->setSceneRect(0,0,800,600);
  view->setBackgroundBrush(QBrush(QImage(":/images/bg.png")));
  setCentralWidget(view);

  
}

void MainWindow::StartButton_Clicked()
{
    mainship *ship = new mainship();
    ship->setTransformOriginPoint(12.5,12.5);
    ship->setRect(0,0,25,25); // change the rect size
    ship->setPen(QPen(Qt::red, 5));
    QPainter::SmoothPixmapTransform;
    ship->setPos(width()/2,height()/2);

    ship->setFlag(QGraphicsItem::ItemIsFocusable);
    ship->setFocus();

    scene->addItem(ship);
}



