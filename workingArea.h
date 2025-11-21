#ifndef WORKINGAREA_H
#define WORKINGAREA_H

#include <QWidget>
#include <QToolBar>
#include <QTextEdit>
#include <QFile>
#include <QMessageBox>

class wArea: public QWidget
{
    Q_OBJECT
public:
    explicit wArea(QWidget *parent = nullptr, int status = 0, QString string = "");
private:
    QToolBar *toolbar;
    QTextEdit *textEdit;
private slots:
    void test();
    void bold();
    void italic();
    void underline();
    void strikethrough();
    void bigFont();
    void smallFont();
    void chooseFont();
    void savingFile();
};

#endif // WORKINGAREA_H
