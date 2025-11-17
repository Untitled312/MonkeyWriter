#include <QBoxLayout>
#include <QToolBar>
#include <QMessageBox>
#include <workingArea.h>

wArea::wArea(QWidget *parent)
    : QWidget(parent)
{
    this->setMinimumSize(640, 480);
    toolbar = new QToolBar(this);
    QAction *newAction = new QAction(QIcon(":/assets/images/2.jpeg"), "New", this);
    newAction->setStatusTip("Create a new file");
    connect(newAction, &QAction::triggered, this, &wArea::test);
    toolbar->addAction(newAction);
    toolbar->addSeparator();
}

void wArea::test(){
    QMessageBox::information(this, "Warning", "ooga-booga!");
}
