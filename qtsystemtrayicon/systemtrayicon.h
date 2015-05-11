#ifndef __GLM_SYSTEMTARYICON_H__
#define __GLM_SYSTEMTARYICON_H__

#include <QObject>
#include <QAction>
#include <QSystemTrayIcon>
#include <QApplication>
#include <QCloseEvent>
#include <QMenu>
#include <QDebug>

class CToolsSystemTrayIcon : public QObject
{
    Q_OBJECT

public:
 //   explicit CToolsSystemTrayIcon(QObject *parent = 0);


    CToolsSystemTrayIcon(QWidget *sysTrayWin, QWidget *parent = 0);

    ~CToolsSystemTrayIcon();


private :
    void creatTrayMenu( );          // 创建系统图片菜单
    void creatTrayIcon( );          // 创建系统托盘图标



protected :
    QSystemTrayIcon *m_sysTrayIcon;        // 系统托盘图标
    QWidget         *m_sysTrayWin;             // 窗体信息
    QMenu           *m_sysTrayMenu;        // 系统托盘右键菜单

    QAction         *m_miniSizeAction;       // 最小化动作
    QAction         *m_maxSizeAction;        // 最大化动作
    QAction         *m_restoreWinAction;     // 还原动作
    QAction         *m_quitAction;           // 退出动作



public slots:
    void iconActivated(QSystemTrayIcon::ActivationReason reason);

protected:
    void closeEvent(QCloseEvent *event);

};



#endif  // __GLM_SYSTEMTARYICON_H__
