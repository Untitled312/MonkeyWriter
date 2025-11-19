#include <menu.h>
#include <workingArea.h>
#include <QTreeView>
#include <QGridLayout>
#include <QFileSystemModel>
#include <QTreeView>
#include <QItemSelectionModel>
#include <QFile>
#include <QMovie>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    MyWidget::monkeySpinning();
}

// void MyWidget::paintEvent(QPaintEvent *event)
// {
//     Q_UNUSED(event);
//     QPainter painter(this);
//     painter.draw(320, 150, 200, 200, QPixmap(":/assets/images/AA1KaYJf.jpg"));
// }

void MyWidget::monkeySpinning(){
    QMovie *movie = new QMovie("/home/keksonadze/Downloads/monkey.gif");
    movie->setScaledSize(QSize(400, 400));
    QLabel *processLabel = new QLabel(this);
    processLabel->setMovie(movie);
    processLabel->setGeometry(230, 50, 400, 400);
    movie->start();
}

menuWindow::menuWindow(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(this->width(), this->height());
    MyWidget* imageWidget= new MyWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(imageWidget);
    setLayout(mainLayout);
    QPushButton* btn = new QPushButton("New File", this);
    QPushButton* btn1 = new QPushButton("Open File", this);
    QPushButton* btn2 = new QPushButton("Exit", this);
    this->setMinimumSize(640, 480);
    this->setWindowTitle("MonkeyWriter");
    QLabel *label = new QLabel(this);
    label->setText("<p style='font-size: 40px;'><b>MonkeyWriter</b></p>");
    label->setGeometry(280, 0, 400, 200);
    QObject::connect(btn, &QPushButton::clicked, this, &menuWindow::newFile);
    QObject::connect(btn1, &QPushButton::clicked, this, &menuWindow::openFile);
    QObject::connect(btn2, &QPushButton::clicked, this, &menuWindow::exitBtn);
    btn->setGeometry(100, 100, 100, 50);
    btn1->setGeometry(100, 200, 100, 50);
    btn2->setGeometry(100, 300, 100, 50);
    this->show();
}

selectItem::selectItem(QWidget *parent)
    : QWidget(parent)
{
    model = new QFileSystemModel;
    treeView = new QTreeView();
    QGridLayout *layout = new QGridLayout(this);
    QPushButton* btn = new QPushButton("Open File", this);
    QPushButton* btn1 = new QPushButton("Cancel", this);
    QObject::connect(btn, &QPushButton::clicked, this, &selectItem::selectFile);
    QObject::connect(btn1, &QPushButton::clicked, this, &QWidget::close);
    this->setMinimumSize(640, 480);
    this->setFixedSize(width(), height());
    this->setWindowTitle("Open file");
    layout->addWidget(treeView, 0, 0, 1, 2);
    model->setRootPath(QDir::currentPath());
    treeView->setModel(model);
    treeView->setRootIndex(model->index(QDir::currentPath()));
    layout->addWidget(btn, 1, 1, Qt::AlignRight);
    layout->addWidget(btn1, 1, 1, Qt::AlignHCenter);
    layout->setHorizontalSpacing(120);
    this->show();
}

void selectItem::selectFile()
{
    QModelIndexList selectedIndex = treeView->selectionModel()->selectedIndexes();
    if(!selectedIndex.empty())
        QMessageBox::information(this, "Warning", model->filePath(selectedIndex[0]));
    QWidget::close();
    wArea* area = new wArea(nullptr, 1, model->filePath(selectedIndex[0]));
    area->show();
}


void menuWindow::openFile(){
    selectItem* itemFile = new selectItem;
}

void menuWindow::newFile()
{
    wArea* area = new wArea;
    area->show();
}

void menuWindow::exitBtn()
{
    QCoreApplication::quit();
}
