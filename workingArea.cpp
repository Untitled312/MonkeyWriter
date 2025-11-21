#include <QToolBar>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QTextCursor>
#include <QFont>
#include <QTextCharFormat>
#include <QFileDialog>
#include <QFontDialog>
#include <QColorDialog>
#include <workingArea.h>


wArea::wArea(QWidget *parent, int status, QString string)
    : QWidget(parent)
{
    setStyleSheet("background-color: #FFF8DC");
    this->setMinimumSize(640, 480);
    toolbar = new QToolBar(this);
    textEdit = new QTextEdit(this);
    QVBoxLayout* layout = new QVBoxLayout(this);
    QAction *newAction = new QAction(QIcon(":/assets/icons/banana.ico"), "Save as", this);
    QAction *newActionBold = new QAction(QIcon(":/assets/icons/bold.png"), "Bold", this);
    QAction *newActionItalic = new QAction(QIcon(":/assets/icons/italic.ico"), "Italic", this);
    QAction *newActionUnderline = new QAction(QIcon(":/assets/icons/underline.ico"), "Underline", this);
    QAction *newActionStrike = new QAction(QIcon(":/assets/icons/strikethrough.ico"), "Strikethrough", this);
    QAction *newActionBig = new QAction(QIcon(":/assets/icons/up.ico"), "Increase font size", this);
    QAction *newActionSmall = new QAction(QIcon(":/assets/icons/down.ico"), "Decrease font size", this);
    QAction *newActionColor = new QAction(QIcon(":/assets/icons/palette.ico"), "Decrease font size", this);
    QAction *newActionFont = new QAction(QIcon(":/assets/icons/font.ico"), "Choose a font", this);
    newAction->setStatusTip("Create a new file");
    connect(newAction, &QAction::triggered, this, &wArea::savingFile);
    connect(newActionBold, &QAction::triggered, this, &wArea::bold);
    connect(newActionItalic, &QAction::triggered, this, &wArea::italic);
    connect(newActionUnderline, &QAction::triggered, this, &wArea::underline);
    connect(newActionStrike, &QAction::triggered, this, &wArea::strikethrough);
    connect(newActionBig, &QAction::triggered, this, &wArea::bigFont);
    connect(newActionSmall, &QAction::triggered, this, &wArea::smallFont);
    connect(newActionColor, &QAction::triggered, this, &wArea::colorFont);
    connect(newActionFont, &QAction::triggered, this, &wArea::chooseFont);
    toolbar->addAction(newAction);
    toolbar->addSeparator();
    toolbar->addAction(newActionBold);
    toolbar->addSeparator();
    toolbar->addAction(newActionItalic);
    toolbar->addSeparator();
    toolbar->addAction(newActionUnderline);
    toolbar->addSeparator();
    toolbar->addAction(newActionStrike);
    toolbar->addSeparator();
    toolbar->addAction(newActionBig);
    toolbar->addSeparator();
    toolbar->addAction(newActionSmall);
    toolbar->addSeparator();
    toolbar->addAction(newActionColor);
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
    QTextCursor cursor = textEdit->textCursor();
    fmt = cursor.charFormat();
    if (textEdit->fontWeight() == QFont::Normal){
        fmt.setFontWeight(QFont::Bold);
    }
    else{
        fmt.setFontWeight(QFont::Normal);
    }
    if (!cursor.hasSelection())
        textEdit->setCurrentCharFormat(fmt);
    cursor.mergeCharFormat(fmt);
}

void wArea::italic(){
    QTextCharFormat fmt;
    QTextCursor cursor = textEdit->textCursor();
    fmt = cursor.charFormat();
    if (textEdit->fontItalic() == 0){
        fmt.setFontItalic(1);
    }
    else{
        fmt.setFontItalic(0);
    }
    if (!cursor.hasSelection())
        textEdit->setCurrentCharFormat(fmt);
    cursor.mergeCharFormat(fmt);
}

void wArea::underline(){
    QTextCharFormat fmt;
    QTextCursor cursor = textEdit->textCursor();
    fmt = cursor.charFormat();
    if (textEdit->fontUnderline() == 0){
        fmt.setFontUnderline(1);
    }
    else{
        fmt.setFontUnderline(0);
    }
    if (!cursor.hasSelection())
        textEdit->setCurrentCharFormat(fmt);
    cursor.mergeCharFormat(fmt);
}

void wArea::strikethrough(){
    QTextCharFormat fmt;
    QTextCursor cursor = textEdit->textCursor();
    fmt = cursor.charFormat();
    if (textEdit->currentFont().strikeOut() == 0){
        fmt.setFontStrikeOut(1);
    }
    else{
        fmt.setFontStrikeOut(0);
    }
    if (!cursor.hasSelection())
        textEdit->setCurrentCharFormat(fmt);
    cursor.mergeCharFormat(fmt);
}

void wArea::bigFont(){
    QTextCharFormat fmt;
    QTextCursor cursor = textEdit->textCursor();
    fmt = cursor.charFormat();
    fmt.setFontPointSize(fmt.font().pointSize() + 1);
    if (!cursor.hasSelection())
        textEdit->setCurrentCharFormat(fmt);
    cursor.mergeCharFormat(fmt);
}

void wArea::smallFont(){
    QTextCharFormat fmt;
    QTextCursor cursor = textEdit->textCursor();
    fmt = cursor.charFormat();
    if (fmt.font().pointSize() > 1)
        fmt.setFontPointSize(fmt.font().pointSize() - 1);
    if (!cursor.hasSelection())
        textEdit->setCurrentCharFormat(fmt);
    cursor.mergeCharFormat(fmt);
}

void wArea::colorFont(){
    QTextCharFormat fmt;
    QTextCursor cursor = textEdit->textCursor();
    QColor color = QColorDialog::getColor(Qt::black, this);
    if (!cursor.hasSelection()){
        textEdit->setTextColor(color);
    }
    fmt.setForeground(color);
    cursor.mergeCharFormat(fmt);
}

void wArea::chooseFont(){
    bool flag;
    QTextCharFormat fmt;
    QTextCursor cursor = textEdit->textCursor();
    QFont font = QFontDialog::getFont(&flag, QFont("Helvetica", 10), this);
    if (!cursor.hasSelection()){
        textEdit->setCurrentFont(font);
    }
    if (flag)
    {
        fmt.setFont(font);
        cursor.mergeCharFormat(fmt);
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

