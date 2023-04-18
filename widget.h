#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMediaPlayer>  //播放器
#include <QVideoWidget>  //播放窗口
#include <QMediaPlaylist>//播放列表
#include <QString>
#include <QFileDialog>//文件窗口
#include <QDebug>
#include <QResizeEvent>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QListWidgetItem>
#include <QObject>

namespace Ui
{
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget* parent = 0);
    void setget_Alltime(qint64 playtime);//获取视频时长并设置到标签
    void setget_currenttime(qint64 playtime);//获取当时播放位置并设置
    void settimeslider(qint64 playtime);//设置进度条
    ~Widget();

private slots:
    void on_btn_open_clicked();//打开音视频

    void on_btn_start_clicked();//播放

    void on_btn_stop_clicked();//暂停

    void on_voice_control_valueChanged(int value);//控制声音

    void on_btn_fullshow_clicked();//全屏显示

    void getduration(qint64 playtime);   //获取时间改变信号

    void getposition(qint64 playtime);   //获取当前播放位置

    void on_btn_ht_clicked();//上一个音视频

    void on_btn_qj_clicked();//下一个音视频

    void on_listWidget_doubleClicked(const QModelIndex& index);

protected:
    void resizeEvent(QResizeEvent* event);
    void keyPressEvent(QKeyEvent* e);
    void mousePressEvent(QMouseEvent* e);
    void mouseDoubleClickEvent(QMouseEvent* e);
private:
    Ui::Widget* ui;
    QStringList         m_strlist;          //文件名列表
    QMediaPlayer*       m_pMediaPlayer;     //播放器
    QVideoWidget*       m_pVideoWidget;     //播放窗口
    QMediaPlaylist*     m_MediaPlaylist;    //播放列表
    QMediaPlayer::State m_state;            //播放状态
    int m_hour;                             //视频总时长
    int m_munete;                           //分钟
    int m_second;                           //秒
    bool m_sliderstate;                     //滑块是否被选中的状态
    int m_slider_crtval;                    //滑块当前值
};

#endif // WIDGET_H

