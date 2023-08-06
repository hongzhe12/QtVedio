#include "globalkeyfilter.h"
#include "widget.h"
#include <QKeyEvent>
#include <Windows.h> // 包含声明了 MSG 类型的适当系统头文件

GlobalKeyFilter::GlobalKeyFilter(Widget* widget) : m_widget(widget)
{
}

bool GlobalKeyFilter::nativeEventFilter(const QByteArray& eventType, void* message, long* result)
{
    if (eventType == "windows_generic_MSG")
    {
        MSG* msg = static_cast<MSG*>(message);
        if (msg->message == WM_KEYDOWN)
        {
            int key = msg->wParam;

            // 处理 ESC 键
            if (key == VK_ESCAPE)
            {
                if (m_widget)
                {
                    m_widget->exitFullScreen();
                }
            }

            // 处理空格键
            if (key == VK_SPACE)
            {
                m_widget->togglePlayback();
            }
        }
    }

    // 返回 false 以便继续传递事件
    return false;
}
