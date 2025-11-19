#include <QToolBar>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QTextCursor>
#include <QFont>
#include <QTextCharFormat>
#include <QFileDialog>
#include <QFontDialog>
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
    QAction *newActionUnderline = new QAction(QIcon(":/assets/icons/underline.ico"), "New", this);
    QAction *newActionFont = new QAction(QIcon(":/assets/icons/font.ico"), "New", this);
    newAction->setStatusTip("Create a new file");
    connect(newAction, &QAction::triggered, this, &wArea::savingFile);
    connect(newActionBold, &QAction::triggered, this, &wArea::bold);
    connect(newActionItalic, &QAction::triggered, this, &wArea::italic);
    connect(newActionUnderline, &QAction::triggered, this, &wArea::underline);
    connect(newActionFont, &QAction::triggered, this, &wArea::chooseFont);
    toolbar->addAction(newAction);
    toolbar->addSeparator();
    toolbar->addAction(newActionBold);
    toolbar->addSeparator();
    toolbar->addAction(newActionItalic);
    toolbar->addSeparator();
    toolbar->addAction(newActionUnderline);
    toolbar->addSeparator();
    toolbar->addAction(newActionFont);
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

void wArea::underline(){
    QTextCharFormat fmt;
    if (textEdit->fontUnderline() == 0){
        fmt.setFontUnderline(1);
    }
    else{
        fmt.setFontUnderline(0);
    }
    QTextCursor cursor = textEdit->textCursor();
    if (!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    cursor.mergeCharFormat(fmt);
}

void wArea::chooseFont(){
    bool flag;
    QFont font = QFontDialog::getFont(&flag, QFont("Helvetica", 10), this);
    if (flag)
    {
        textEdit->setFont(font);
    }
}

void wArea::savingFile(){
    QString filename = QFileDialog::getSaveFileName(this, "Save As");
    if (filename.isEmpty())
        return;
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);
    out << textEdit->toHtml();
    file.close();
}

