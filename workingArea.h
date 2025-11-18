#ifndef WORKINGAREA_H
#define WORKINGAREA_H

#include <QWidget>
#include <QToolBar>
#include <QTextEdit>

class wArea: public QWidget
{
    Q_OBJECT
public:
    explicit wArea(QWidget *parent = nullptr);
private:
    QToolBar *toolbar;
    QTextEdit *textEdit;

private slots:
    void test();
};

#endif // WORKINGAREA_H
