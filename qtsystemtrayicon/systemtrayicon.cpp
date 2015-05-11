#include "systemtrayicon.h"

//CToolsSystemTrayIcon::CToolsSystemTrayIcon(QObject *parent) :
//    QObject(parent)
//{

//}


// 初始化系统托盘图标
CToolsSystemTrayIcon::CToolsSystemTrayIcon(QWidget *sysTrayWin, QWidget *parent)
:QObject(parent)
{
    this->m_sysTrayWin = sysTrayWin;

    this->creatTrayMenu( );  // 创建并且关联系统菜单
    this->creatTrayIcon( );  // 创建系统托盘图标
}


CToolsSystemTrayIcon::~CToolsSystemTrayIcon( )
{
    delete  m_sysTrayIcon;        // 系统托盘图标
    // delete  m_sysTrayWin;      // 窗体信息
    delete  m_sysTrayMenu;        // 系统托盘右键菜单

    delete  m_miniSizeAction;       // 最小化动作
    delete  m_maxSizeAction;        // 最大化动作
    delete  m_restoreWinAction;     // 还原动作
    delete	m_quitAction;           // 退出动作
}


// 创建系统托盘图标右键菜单
void CToolsSystemTrayIcon::creatTrayMenu( )
{

    // 创建动作信息
    this->m_miniSizeAction = new QAction("最小化(&N)",this);
    this->m_maxSizeAction = new QAction("最大化(&X)",this);
    this->m_restoreWinAction = new QAction("还 原(&R)",this);
    this->m_quitAction = new QAction("退出(&Q)",this);
    // 关联动作信息以及
    this->connect(this->m_miniSizeAction,SIGNAL(triggered()),this->m_sysTrayWin,SLOT(hide()));
    this->connect(this->m_maxSizeAction,SIGNAL(triggered()), this->m_sysTrayWin,SLOT(showMaximized()));
    this->connect(this->m_restoreWinAction,SIGNAL(triggered()),this->m_sysTrayWin,SLOT(showNormal()));
    this->connect(this->m_quitAction,SIGNAL(triggered( )), qApp, SLOT(quit()));

    // 添加菜单在系统界面上
    //this->m_sysTrayMenu = new QMenu((QWidget*)this->m_sysTrayIcon);
    this->m_sysTrayMenu = new QMenu( );

    this->m_sysTrayMenu->addAction(this->m_miniSizeAction);
    this->m_sysTrayMenu->addAction(this->m_maxSizeAction);
    this->m_sysTrayMenu->addAction(this->m_restoreWinAction);
    this->m_sysTrayMenu->addSeparator( );     // 加入一个分离符
    this->m_sysTrayMenu->addAction(this->m_quitAction);
}


// 创建系统托盘图标
void CToolsSystemTrayIcon::creatTrayIcon()
{
    if(!QSystemTrayIcon::isSystemTrayAvailable())      //判断系统是否支持系统托盘图标
    {
        qDebug( ) <<"该系统不支持系统托盘图标" <<endl;
        return;
    }

    this->m_sysTrayIcon = new QSystemTrayIcon(this->m_sysTrayWin);\
    this->m_sysTrayIcon->setIcon(QIcon(":MyImages/images/ctoolsedit.png"));   //设置图标图片
    this->m_sysTrayIcon->setToolTip("GLMPlayer V1.0");    //托盘时，鼠标放上去的提示信息
    this->m_sysTrayIcon->showMessage("GLMPlayer","Welcome to join GLMPlayer",QSystemTrayIcon::Information,1000);
    this->m_sysTrayIcon->setContextMenu(this->m_sysTrayMenu);     //设置托盘上下文菜单

    // 将系统托盘图标信息与
    this->connect(this->m_sysTrayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));

    this->m_sysTrayIcon->show( );
}


// 系统托盘图标的时间循环处理
// 右键:
// 双击: 打开应用程序
void CToolsSystemTrayIcon::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
    case QSystemTrayIcon::Trigger:
        this->m_sysTrayMenu->show( );
    case QSystemTrayIcon::DoubleClick:
        this->m_sysTrayWin->showNormal( );
        break;
    case QSystemTrayIcon::MiddleClick:
        this->m_sysTrayIcon->showMessage("SystemTrayIcon","Hi,This is my trayIcon",QSystemTrayIcon::Information,10000);
        break;

    default:
        break;
    }
}

void CToolsSystemTrayIcon::closeEvent(QCloseEvent *event)
{
    if (this->m_sysTrayIcon->isVisible())
    {
        this->m_sysTrayIcon->showMessage("SystemTrayIcon","Hi,This is my trayIcon",QSystemTrayIcon::Information,5000);

        this->m_sysTrayWin->hide();     //最小化
        event->ignore( );
    }
    else
        event->accept();
}

