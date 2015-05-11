/**
******************************************************************************
*   CopyRight  : 2012-2013, HerBinUnversity, GatieMe                         *
*   File Name  : mainwindow.h                                                *
*   Description: 多文档编辑器主窗口类头文件                                     *
*   Author     : Gatie_Me                                                    *
*   Version    : Copyright 2012                                              *
*   Data_Time  : 20112-8-29 10:28:43                                         *
*   Content    : Qt设置の多文档编辑器                                           *
******************************************************************************
**/

/**
**************************************************************************
*2012/10/21_20:35  -=> 更新菜单状态。                                      *
*&_MdiWindow头文件中添加中心部件类MdiChild的前置声明                         *
*&_MdiWindow类声明中添加间隔器成员变量QAction *actionSeparator*             *
*&_MdiWindow类声明中添加活动窗口函数MdiChild *activeMdiChild( )             *
*************************************************************************
**/

/**
****************************************************************************
*2012/10/21_21:00  -=> 充实新建文件操作                                      *
*&_MdiWindow类声明中添加活动窗口函数[private slot:]MdiChild *activeMdiChild( )*
****************************************************************************
**/

/**
****************************************************************************
*2012/10/22_19:48  -=> 实现打开文件操作                                      *                                     *
*&_MdiWindow头文件中添加QMdiSubWindow的前置声明                               *
*&_查找子窗口函数QMdiSubWindow *findMdiChild(const QString &fileName);       *
*&_设置活动子窗口void setActiveSubWindow(QWidget *window);                   *
****************************************************************************
**/

// Question:如何实现没打开一个文件窗口就在窗口菜单中列出其文件名
//          而且可以在这个列表中选择一个子窗口, 将它设置为活动窗口
//          实现方法采用菜单影射类QSignalMapper
/**
****************************************************************************
*2012/10/23_18:43  -=> 添加子窗口的列表                                      *
*&_MdiWindow头文件中添加QSignalMapper的前置声明
****************************************************************************
**/

/**
****************************************************************************
*2012/10/25_16:20  -=> 实现其他菜单的功能[剪切, 复制]                          *
*实现保存文件, 剪切, 复制操作的信号槽函数                                       *
****************************************************************************
**/

/**
****************************************************************************
*2012/10/31 18:48   -=>  保存窗口的设置                                      *
*完善交互信息, 使软件可以保存用户对窗口的一些设置                                 *
*添加private函数声明                                                         *
*               void readSetting( )读入窗口设置                              *
*               void writeSetting( )写入窗口设置                             *
*添加protected函数声明                                                       *
*               void closeEvenet(QCloseEvent *event)关闭事件                *                              *
****************************************************************************
**/



/**
***************************************************************************
*2012/11/21 19:48  -=> 添加查找和替换字符块的函数操作以及使用拖放打开文件的操作
*添加两个私有槽private slots声明：
*   void textFind( );          // 查找文本
*   void findNext( );          // 查找下一个
*   void drapEnterEvent(QDropEnterEvent *event);                 // 拖入进入事件
*   void dropEent(QDropEvent *event);           // 放下事件
****************************************************************************
**/

/**
****************************************************************************
*2012/11/23 18:34  -=> 添加在状态栏显示编辑器中光标所在的行号和列号, 并设置状元栏   *
*添加私有槽private slots声明：                                                *
*void showTextRowAndCol( );          // 在状态栏显示行号和列号                 *
*添加私有函数声明                                                             *
*    void initWindow( );                 // 初始化窗口                        *
****************************************************************************
**/


/**
****************************************************************************
*2012/11/23 19:17   -=> 添加打印文档, 打印预览, 以及生成PDF                     *
*添加私有槽private slots声明：                                                *
*    void doPrint( );                    // 打印文档的函数                    *
*    void doPrintPreView( );             // 打印预览函数                      *
*    void printPreview(QPrinter *printer);       // 生成PDF的函数            *
*    void createPdf( );                          // 生成PDF文件             *
****************************************************************************
**/


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QPrinter>
#include "mysyntaxhighlighter.h"
#include "systemtrayicon.h"
#include "ctoolspackage.h"


class MdiChild; // 添加中心部件类的前置声明[2012/10/21_20:35]
class QMdiSubWindow;    // 部件类前置声明[2012/10/22_19:48]
class QSignalMapper;        // 菜单信号类前置声明[2012/10/23_18:43]

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:  // 私有槽声明

    void updataMenus( );            // 更新菜单[2012/10/21_20:35 ]

    void updataWindowMenu( );           // 更新窗口菜单[2012/10/23_18:43]

    MdiChild* createMdiChild( );        // 创建子窗口[2012/10/21_21:00]

    void setActiveSubWindow(QWidget *window);   // 设置活动子窗口[2012/10/22_19:48]

    void textFind( );           // 查找字符串的函数

    void findNext( );           // 查找下一个

    void showTextRowAndCol( );          // 在状态栏显示行号和列号[2012/11/23 18:34]

    void doPrint( );                    // 打印文档的函数

    void doPrintPreView( );             // 打印预览函数

    void printPreview(QPrinter *printer);       // 显示打印预览

    void createPdf( );                          // 生成PDF文件

    void on_actionNew_triggered();  // 新建文件的操作槽

    void on_actionOpen_triggered(); // 打开文件的操作槽

    void on_actionSave_triggered(); // 保存文件的操作信号槽

    void on_actionUndo_triggered();

    void on_actionClose_triggered();

    void on_actionAbout_triggered();

    void on_actionAboutQt_triggered();

    void on_actionSaveAs_triggered();

    void on_actionExit_triggered();

    void on_actionCloseAll_triggered();

    void on_actionFind_triggered();

    void on_actionProp_triggered();

    void on_actionRedo_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionTile_triggered();

    void on_actionCascade_triggered();

    void on_actionNext_triggered();

    void on_actionPrevious_triggered();

    //  插桩的槽函数
    void slotCodeProp(QString &srcFname, QString &destFname);
    void on_actionLexical_triggered();


    //  词法分析处理函数
    void InitLexicalTableWidget( );     // 初始化表格
    void ShowLexicalTable(BinaryTuple douTuple);
    void slotCodeLexical(QString &sfcFname, BinaryTuple douTuple);

protected:
    void closeEvent(QCloseEvent *event);        // 关闭事件[2012/10/31 18:48]

    void dragEnterEvent(QDragEnterEvent *event);                 // 拖入进入事件

    void dropEvent(QDropEvent *event);           // 放下事件

    //void InitLexicalTableWidget();      // 初始化

private:
    Ui::MainWindow *ui;
    MySyntaxHighlighter *highlighter;

    // 下面的动作用于创建一个间隔期器,
    // 将来在窗口菜单中显示子窗口列表时, 可以用它与前面的菜单动作分隔开
    QAction *actionSeparator;           // 间隔器[2012/10/21_20:35]
    QSignalMapper *windowMapper;        // 信号映射器[2012/10/23_18:43]
    CToolsSystemTrayIcon *sysTrayIcon;   //  系统托盘程序

    // CTools工具包
    CToolsPackage   *m_ctools;          // CTools工具包

    MdiChild *activeMdiChild( );    // 活动窗口[2012/10/21_20:35]

    QMdiSubWindow *findMdiChild(const QString &fileName);   // 查找子窗口[2012/10/22_19:48]

    void OpenFile(QString &fileName);               //  打开文件

    void readSetting( );                // 读取窗口设置[2012/10/31 18:48]
    void writeSetting( );               // 写入窗口设置[2012/10/31 18:48]
    void initWindow( );                 // 初始化窗口[2012/11/23 18:34]
};

#endif // MAINWINDOW_H
