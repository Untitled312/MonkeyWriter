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
#include <QPropertyAnimation>
#include <menu.cpp>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    menuWindow menu;
    return app.exec();
}
