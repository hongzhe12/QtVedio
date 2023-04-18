#include "widget.h"
#include "ui_widget.h"
#include "myslider.h"

Widget::Widget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //    setWindowTitle("");
    move(400, 60);
    m_pMediaPlayer = new QMediaPlayer;//播放器
    m_pVideoWidget = new QVideoWidget(ui->label);//创建播放窗口
    m_MediaPlaylist = new QMediaPlaylist;//播放列表

    //给播放器指定播放队列
    m_pMediaPlayer->setPlaylist(m_MediaPlaylist);
    //给播放器指定播放窗口
    m_pMediaPlayer->setVideoOutput(m_pVideoWidget);

    //设置焦点 为了让键盘事件能生效  你也可设置播放窗口一直获得焦点
    ui->btn_open->setFocusPolicy(Qt::NoFocus);
    ui->btn_fullshow->setFocusPolicy(Qt::NoFocus);
    ui->btn_ht->setFocusPolicy(Qt::NoFocus);
    ui->btn_qj->setFocusPolicy(Qt::NoFocus);
    ui->btn_stop->setFocusPolicy(Qt::NoFocus);
    ui->btn_start->setFocusPolicy(Qt::NoFocus);
    ui->label->setFocusPolicy(Qt::NoFocus);
    ui->label_all_time->setFocusPolicy(Qt::NoFocus);
    ui->label_ct->setFocusPolicy(Qt::NoFocus);
    ui->progress_report->setFocusPolicy(Qt::NoFocus);
    ui->voice_control->setFocusPolicy(Qt::NoFocus);

    //滑块连接
    m_sliderstate = false;//初始化滑块状态
    connect(ui->progress_report, &MySlider::mousepress, [ = ](int val)
    {
        //当鼠标被按下时  先暂停音视频  设置滑块的状态
        m_sliderstate = true;
        m_state = QMediaPlayer::PausedState;
        m_pMediaPlayer->pause();
        qDebug() << "鼠标在滑块上按下" << val;
    });
    connect(ui->progress_report, &MySlider::mouserelease, [ = ](int val)
    {
        m_sliderstate = false;
        m_pMediaPlayer->setPosition(val * 1000); //当鼠标松开时 调整播放位置 *1000是为了把秒转为毫秒
        ui->progress_report->setValue(val * 1000); //进度条也得跟着调整
        m_state = QMediaPlayer::PlayingState;
        m_pMediaPlayer->play();
        qint64 playtime = m_pMediaPlayer->position();
        setget_currenttime(playtime);//显示的时长也得跟着调整
        qDebug() << "鼠标在滑块上松开" << val;
    });

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btn_open_clicked()
{
    m_MediaPlaylist->clear();//清空播放列表
    m_strlist.clear();
    m_strlist = QFileDialog::getOpenFileNames(this, "打开", "C:\"",
                "allfiles(*.*);;"
                "MP3(*.mp3);;"
                "MP4(*.mp4);;"
                "AVI(*.avi)");
    ui->listWidget->clear();//每次打开文件清空列表
    ui->listWidget->insertItems(0, m_strlist); //把歌曲或者视频添加到播放列表

    foreach(QString const& arg, m_strlist) //遍历m_strlist中所有的 string
    {

        QUrl url(arg);//类型转换
        m_MediaPlaylist->addMedia(url);//添加到播放列表中

    }

    m_pVideoWidget->resize(ui->label->size());//设置播放窗口大小
    m_state = QMediaPlayer::PlayingState;
    m_pMediaPlayer->play();//播放
    connect(m_pMediaPlayer, SIGNAL(durationChanged(qint64)),
            this,
            SLOT(getduration(qint64)));//总时长

    connect(m_pMediaPlayer, SIGNAL(positionChanged(qint64)),
            this,
            SLOT(getposition(qint64)));//当前时长
}

void Widget::on_btn_start_clicked()  //播放
{
    m_state = QMediaPlayer::PlayingState;
    m_pMediaPlayer->play();
}

void Widget::on_btn_stop_clicked()//暂停
{
    m_state = QMediaPlayer::PausedState;
    m_pMediaPlayer->pause();
}

void Widget::on_voice_control_valueChanged(int value)//设置声音
{
    m_pMediaPlayer->setVolume(value);
}

void  Widget::resizeEvent(QResizeEvent* event)
{
    m_pVideoWidget->resize(ui->label->size());//设置播放窗口大小
}

void Widget::on_btn_fullshow_clicked()//全屏
{

    showMaximized();
}


void Widget::keyPressEvent(QKeyEvent* e)//键盘控制暂停和窗口还原
{
    if(Qt::Key_Escape == e->key())
    {
        resize(930, 710);
        move(400, 60);
    }

    if(Qt::Key_Space == e->key())
    {
        if(m_state == QMediaPlayer::PlayingState)
        {
            m_state = QMediaPlayer::PausedState;
            m_pMediaPlayer->pause();
        }
        else if(m_state == QMediaPlayer::PausedState)
        {
            m_state = QMediaPlayer::PlayingState;
            m_pMediaPlayer->play();
        }
    }
}
void Widget::mouseDoubleClickEvent(QMouseEvent* e)//鼠标双击事件
{
    showMaximized();//最大化
}

void Widget::mousePressEvent(QMouseEvent* e)//鼠标控制播放状态
{
    if(Qt::LeftButton == e->button())
    {
        if(m_state == QMediaPlayer::PausedState)
        {
            m_state = QMediaPlayer::PlayingState;
            m_pMediaPlayer->play();
        }
        else if(m_state == QMediaPlayer::PlayingState)
        {
            m_state = QMediaPlayer::PausedState;
            m_pMediaPlayer->pause();
        }
    }


}

void Widget::getduration(qint64 playtime)//总时长槽
{
    if(!m_sliderstate)
    {
        playtime = m_pMediaPlayer->duration();
        setget_Alltime(playtime);
    }
}

void Widget::setget_Alltime(qint64 playtime)//获取视频总时长并设置到标签,滑条
{
    playtime /= 1000;
    ui->progress_report->setMinimum(0);//设置进度条的最大值最小值
    ui->progress_report->setMaximum(playtime);

    m_hour = playtime / 3600;
    m_munete = (playtime - m_hour * 3600) / 60;
    m_second = playtime - m_hour * 3600 - m_munete * 60;
    //qDebug()<<m_hour<<m_munete<<m_second;
    QString str = QString("%1:%2:%3").arg(m_hour).arg(m_munete).arg(m_second);
    ui->label_all_time->setText(str);
}

void Widget::setget_currenttime(qint64 playtime)//获取当时播放位置并设置
{
    //playtime时间的毫秒 一下操作是将毫秒转为为h-m-s
    playtime /= 1000;
    settimeslider(playtime);
    int h, m, s;
    h = playtime / 3600;
    m = (playtime - h * 3600) / 60;
    s = playtime - h * 3600 - m * 60;
    //qDebug()<<h<<m<<s;
    QString str = QString("%1:%2:%3").arg(h).arg(m).arg(s);
    ui->label_ct->setText(str);
}

void Widget::getposition(qint64 playtime)   //获取当前播放位置槽
{
    if(!m_sliderstate)
    {
        playtime = m_pMediaPlayer->position();//获取当前播放位置
        setget_currenttime(playtime);
    }
}

void Widget::settimeslider(qint64 playtime)//设置进度条
{
    if(!m_sliderstate)
    {
        ui->progress_report->setValue(playtime);
    }
}


void Widget::on_btn_ht_clicked()//上一个
{
    m_pMediaPlayer->stop();//先暂停
    int count = m_MediaPlaylist->mediaCount();
    if(0 == count)
    {
        return;
    }
    m_MediaPlaylist->previous();
    m_pMediaPlayer->play();
}

void Widget::on_btn_qj_clicked()//下一个
{
    m_pMediaPlayer->stop();//先暂停
    int count = m_MediaPlaylist->mediaCount();//获取播放列表中的行总数
    if(0 == count)
    {
        return;
    }
    m_MediaPlaylist->next();//下一个
    m_pMediaPlayer->play();
}


//获取双击的哪一行 并设置播放
void Widget::on_listWidget_doubleClicked(const QModelIndex& index)
{
    int i = index.row();//获取选中行
    m_MediaPlaylist->setCurrentIndex(i);//将播放列表中的当前行换为list中选中的行
    m_pMediaPlayer->play();
}

