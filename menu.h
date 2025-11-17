#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QLabel>
#include <QPainter>


namespace Menu{
    class menuWindow;
    class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);
};

class menuWindow: public QWidget
{
    Q_OBJECT
public:
    explicit menuWindow(QWidget *parent = nullptr);
private slots:
    void newFile();
    void openFile();
    void exitBtn();
};

#endif // MENU_H
