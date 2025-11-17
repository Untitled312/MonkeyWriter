#ifndef WORKINGAREA_H
#define WORKINGAREA_H

#include <QWidget>
#include <QToolBar>

class wArea: public QWidget
{
    Q_OBJECT
public:
    explicit wArea(QWidget *parent = nullptr);
private:
    QToolBar *toolbar;
private slots:
    void test();
};

#endif // WORKINGAREA_H
