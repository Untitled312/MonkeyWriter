#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QLabel>
#include <QPainter>
#include <QTreeView>
#include <QFileSystemModel>
#include <QString>

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

class selectItem : public QWidget
{
    Q_OBJECT
public:
    explicit selectItem(QWidget *parent = nullptr);
private slots:
    void selectFile();
private:
    QTreeView *treeView;
    QFileSystemModel *model;
};

#endif // MENU_H
