/**
******************************************************************************
*   CopyRight  : 2012-2013, HerBinUnversity, GatieMe                         *
*   File Name  : mainwindow.h                                                *
*   Description: 多文档编辑器中心部件类头文件                                    *
*   Author     : Gatie_Me                                                    *
*   Version    : Copyright 2012                                              *
*   Data_Time  : 20112-8-29 10:28:43                                         *
*   Content    : Qt设置の多文档编辑器                                          *
******************************************************************************
**/



/**
****************************************************************************
*2012/10/23_18:07  -=> 自定义右键菜单                                        *
*【实现方式, 重新实现QTextEdit的上下菜单事件】                                   *
*protected:void con*
****************************************************************************
**/

#ifndef MDICHILD_H
#define MDICHILD_H

#include <QTextEdit>
#include <QTextDocument>
#include "mysyntaxhighlighter.h"


// 中心部件类
class MdiChild : public QTextEdit
{
    Q_OBJECT
public:
    explicit MdiChild(QWidget *parent = 0);

    // 新增的部件编辑器操作函数
    void newFile( );            // 新建文件操作

    bool loadFile(const QString &fileNmae);           // 加载文件

    bool save( );               // 保存文件

    bool saveAs( );             // 另存为操作

    bool saveAll( );            // 保存全部文件操作

    bool saveFile(const QString &fileName); // 保存文件

    QString useFriendlyCurrentFile( );      // 提取文件名

    QString currentFile( )
    {
        return curFile;            // 返回当前文件的路径
    }

//signals:
protected :     // 保护成员函数
    void closeEvent(QCloseEvent *event);        // 关闭事件

    void contextMenuEvent(QContextMenuEvent *e);        // 右键菜单事件

private slots:   // 公共接口
    void documentWasModified( );               // 文档被修改时, 窗口显示更改状态标志

private :       // 私有成员
    // 私有函数成员
    bool maybeSave( );              // 是否需要保存

    void setCurrentFile(const QString &fileName);   // 设置当前文件

    // 私有数据成员
    QString curFile;        // 保存当前文件路径
    bool isUntitled;        // 作为当前文件是否被保存到硬盘上的标志

    MySyntaxHighlighter *highlighter;       // 支持C/C++语法高亮

};

#endif
