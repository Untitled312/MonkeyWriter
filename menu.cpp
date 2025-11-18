#include <menu.h>
#include <workingArea.h>
#include <QTreeView>
#include <QGridLayout>


MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{

}

void MyWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(320, 150, 200, 200, QPixmap(":/assets/images/AA1KaYJf.jpg"));
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

void menuWindow::openFile()
{
    QWidget* widget = new QWidget;
    widget->setMinimumSize(640, 480);
    widget->setFixedSize(width(), height());
    widget->setWindowTitle("Open file");
    QTreeView *treeView = new QTreeView();
    QGridLayout *layout = new QGridLayout(widget);
    layout->addWidget(treeView, 0, 0, 1, 2);
    QFileSystemModel *model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());
    treeView->setModel(model);
    treeView->setRootIndex(model->index(QDir::currentPath()));
    QPushButton* btn = new QPushButton("Open File", widget);
    QPushButton* btn1 = new QPushButton("Cancel", widget);
    QObject::connect(btn1, &QPushButton::clicked, widget, &QWidget::close);
    layout->addWidget(btn, 1, 1, Qt::AlignRight);
    layout->addWidget(btn1, 1, 1, Qt::AlignHCenter);
    layout->setHorizontalSpacing(120);
    widget->show();
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
