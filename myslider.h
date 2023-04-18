#ifndef MYSLIDER_H
#define MYSLIDER_H

#include <QMouseEvent>
#include <QSlider>

class MySlider : public QSlider
{
    Q_OBJECT
public:
    explicit MySlider(QWidget* parent = nullptr);
protected:
    void mousePressEvent(QMouseEvent* ev);
    void mouseReleaseEvent(QMouseEvent* ev);
signals:
    void mousepress(int value);
    void mouserelease(int value);
public slots:
};

#endif // MYSLIDER_H

