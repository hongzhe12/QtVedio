#ifndef GLOBALKEYFILTER_H
#define GLOBALKEYFILTER_H

#include <QAbstractNativeEventFilter>

class Widget;

class GlobalKeyFilter : public QAbstractNativeEventFilter
{
public:
    explicit GlobalKeyFilter(Widget* widget);

    bool nativeEventFilter(const QByteArray& eventType, void* message, long* result) override;

private:
    Widget* m_widget;
};

#endif // GLOBALKEYFILTER_H
