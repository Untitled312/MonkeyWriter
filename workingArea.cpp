#include <QToolBar>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QTextCursor>
#include <QFont>
#include <QTextCharFormat>
#include <workingArea.h>

wArea::wArea(QWidget *parent, int status, QString string)
    : QWidget(parent)
{
    this->setMinimumSize(640, 480);
    toolbar = new QToolBar(this);
    textEdit = new QTextEdit(this);
    QVBoxLayout* layout = new QVBoxLayout(this);
    QAction *newAction = new QAction(QIcon(":/assets/icons/banana.ico"), "New", this);
    QAction *newActionBold = new QAction(QIcon(":/assets/icons/bold.png"), "New", this);
    QAction *newActionItalic = new QAction(QIcon(":/assets/icons/italic.ico"), "New", this);
    newAction->setStatusTip("Create a new file");
    connect(newAction, &QAction::triggered, this, &wArea::test);
    connect(newActionBold, &QAction::triggered, this, &wArea::bold);
    connect(newActionItalic, &QAction::triggered, this, &wArea::italic);
    toolbar->addAction(newAction);
    toolbar->addSeparator();
    toolbar->addAction(newActionBold);
    toolbar->addSeparator();
    toolbar->addAction(newActionItalic);
    toolbar->addSeparator();
    layout->addWidget(toolbar);
    layout->addWidget(textEdit);
    if (status == 1){
        QFile* file = new QFile(string);
        file->open(QIODevice::ReadOnly);
        QTextStream textStream(file);
        QString line = textStream.readAll();
        file->close();
        textEdit->setText(line);
    }
    textEdit->show();
}

void wArea::test(){
    QMessageBox::information(this, "Warning", "ooga-booga!");
}

void wArea::bold(){
    QTextCharFormat fmt;
    if (textEdit->fontWeight() == QFont::Normal){
        fmt.setFontWeight(QFont::Bold);
    }
    else{
        fmt.setFontWeight(QFont::Normal);
    }
    QTextCursor cursor = textEdit->textCursor();
    if (!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    cursor.mergeCharFormat(fmt);
}

void wArea::italic(){
    QTextCharFormat fmt;
    if (textEdit->fontItalic() == 0){
        fmt.setFontItalic(1);
    }
    else{
        fmt.setFontItalic(0);
    }
    QTextCursor cursor = textEdit->textCursor();
    if (!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    cursor.mergeCharFormat(fmt);
}
