#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QFileSystemModel>
#include <QHBoxLayout>
#include <QTreeView>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QLabel>
#include <QPainter>

void newFile();
void exitBtn();
void paintEvent(QPaintEvent *);

QPushButton* btn = nullptr;
QPushButton* btn1 = nullptr;
QPushButton* btn2 = nullptr;
int count{0};
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget widget;
    widget.setMinimumSize(640, 480);
    widget.setWindowTitle("MonkeyWriter");
    btn = new QPushButton("New File", &widget);
    btn1 = new QPushButton("Open File", &widget);
    btn2 = new QPushButton("Exit", &widget);
    btn->setGeometry(100, 100, 100, 50);
    btn1->setGeometry(100, 200, 100, 50);
    btn2->setGeometry(100, 300, 100, 50);
    QObject::connect(btn, &QPushButton::clicked, newFile);
    QObject::connect(btn2, &QPushButton::clicked, exitBtn);
    QLabel *label = new QLabel("Текст надписи", &widget);
    label->setGeometry(300, 150, 200, 200);
    label->setPixmap(QPixmap("/home/keksonadze/Pictures/AA1KaYJf.jpg").scaled(200, 200, Qt::KeepAspectRatio));
    widget.show();
    return app.exec();
}

void newFile()
{
    QWidget* widget = new QWidget;
    widget->setMinimumSize(640, 480);
    widget->setWindowTitle("Create a new file");
    QTreeView *treeView = new QTreeView();
    QHBoxLayout *layout = new QHBoxLayout(widget);
    layout->addWidget(treeView);
    QFileSystemModel *model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());
    treeView->setModel(model);
    treeView->setRootIndex(model->index(QDir::currentPath()));
    widget->show();
}
void exitBtn()
{
    QCoreApplication::quit();
}

