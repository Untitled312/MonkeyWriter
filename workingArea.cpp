#include <QToolBar>
#include <QVBoxLayout>
#include <QMessageBox>
#include <workingArea.h>

wArea::wArea(QWidget *parent)
    : QWidget(parent)
{
    this->setMinimumSize(640, 480);
    toolbar = new QToolBar(this);
    textEdit = new QTextEdit(this);
    QVBoxLayout* layout = new QVBoxLayout(this);
    QAction *newAction = new QAction(QIcon(":/assets/images/2.jpeg"), "New", this);
    newAction->setStatusTip("Create a new file");
    connect(newAction, &QAction::triggered, this, &wArea::test);
    toolbar->addAction(newAction);
    toolbar->addSeparator();
    layout->addWidget(toolbar);
    layout->addWidget(textEdit);
    textEdit->show();
}

void wArea::test(){
    QMessageBox::information(this, "Warning", "ooga-booga!");
}
