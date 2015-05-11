/**
******************************************************************************
*   CopyRight  : 2012-2013, HerBinUnversity, GatieMe                         *
*   File Name  : mainwindow.cpp                                              *
*   Description: 多文档编辑器中心部件类实现文件                                  *
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

#include <QFile>
#include <QMenu>
#include <QTextStream>
#include <QMessageBox>
#include <QFileInfo>
#include <QApplication>
#include <QAbstractAnimation>
#include <QFileDialog>
#include <QCloseEvent>
#include <QPushButton>

#include "mdichild.h"

MdiChild::MdiChild(QWidget *parent) :       // 构造函数
    QTextEdit(parent)
{
    //  设置在子窗口关闭时销毁这个类的对象
    setAttribute(Qt::WA_DeleteOnClose);

    //  版本0.0.8添加，设置文本的字体为编程字体
    setFontFamily("Courier New");

    QPalette pl = this->palette();
    pl.setBrush(QPalette::Base,QBrush(QColor(0, 0, 0, 0)));
    this->setPalette(pl);
    // 初始化isUntitled为true
    isUntitled = true;
}

void MdiChild::newFile( )
{
    // 设置窗口编号, 因为编号一直被保存, 所以需要使用静态变量
    static int sequenceNumber = 1;

    // 新建的文档没有被保存过
    isUntitled = true;

    // 将当前文件命名为未命名文档加编号, 编号先使用再加1
    curFile = tr("未命名文档%1.txt").arg(sequenceNumber++);

    // 设置窗口标题, 使用[*]可以在文档被更改后在文件名称后显示“*”号
    setWindowTitle(curFile + "[*]" + tr(" - 多文档编辑器"));

    connect(document(), SIGNAL(contentsChanged()), this, SLOT(documentWasModified()));
}


void MdiChild::documentWasModified( )
{
    // 根据文档的isModified( )函数返回值, 判断文档内容是否被修改了
    // 如果被修改了, 就要在设置了[*]号的地方显示“*”号, 这里会在窗口标题中信息
    setWindowModified(document()->isModified());
}


bool MdiChild::loadFile(const QString &fileName)    // 加载文件
{
    // 新建QFile对象
    QFile file(fileName);

    // 只读方式打开文件, 出错则提示, 并且返回false
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, tr("多文档编辑器"),
                             tr("无法读取文件%1:\n%2.").arg(fileName).arg(file.errorString()));
        return false;
    }

    // 新建文本流对象
    QTextStream in(&file);
    // 设置鼠标状态为等待状态
    QApplication::setOverrideCursor(Qt::WaitCursor);
    // 读取文件的全部文本内容, 并且添加到编辑器中
    this->setPlainText(in.readAll());
    // 恢复鼠标状态
    QApplication::restoreOverrideCursor( );


    this->setCurrentFile(fileName); // 设置当前文件

    connect(document(), SIGNAL(contentsChanged()),
            this, SLOT(documentWasModified()));

    highlighter = new MySyntaxHighlighter(this->document( ));

    return true;
}



// 将加载文件的巨灵保存在curFile中, 然后进行一些状态的设置
// 在设置标题时使用了useFriendlyCurrentFile( )函数
void MdiChild::setCurrentFile(const QString &fileName)
{
    // canonicalFilePath()可以去除路径中的符号连接'.'和'..'等符号
    curFile = QFileInfo(fileName).canonicalFilePath( );

    // 文件已经被保存过了
    isUntitled = false;

    // 文档没有被更改过了
    document()->setModified(false);

    // 窗口不显示被更改标志
    setWindowModified(false);

    // 设置窗口标题, userFriendCurrentFile()返回文件名
    setWindowTitle(useFriendlyCurrentFile() + "[*]");
}


// 从文件路径中提取出来文件名
QString MdiChild::useFriendlyCurrentFile( )
{
    // 从文件路径中提取文件名
    return QFileInfo(curFile).fileName( );
}

// 保存文件
bool MdiChild::save( )
{
    // 如果文件未被保存过, 则执行另存为操作, 否则直接保存文件
    if(isUntitled)
    {
        return saveAs( );
    }
    else
    {
        return saveFile(curFile);
    }
}

// 另存为文件
bool MdiChild::saveAs( )
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("另存为"), curFile);
    // 获取文件路径, 如果为空, 则返回false, 否则保存文件
    if(fileName.isEmpty())
    {
        return false;
    }
    else
    {
        return saveFile(fileName);
    }
}


// 保存文件
bool MdiChild::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "CToolsGUI", QString("can't write file %1:\n%2.").arg(fileName).arg(file.errorString()));

        return false;
    }

    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    // 以纯文本文件写入
    out <<toPlainText( );
    QApplication::restoreOverrideCursor( );
    setCurrentFile(fileName);

    return true;
}

// 关闭文件操作
void MdiChild::closeEvent(QCloseEvent *event)
{
    // 如果maybeSave()函数返回true, 则关闭事件, 否则忽略该事件
    if(maybeSave() == true)
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }
}


// 自定义右键函数
void MdiChild::contextMenuEvent(QContextMenuEvent *e)
{
    // 创建菜单, 并向其中添加动作
    QMenu *menu = new QMenu;

    // 设置撤销动作
    QAction *undo = menu->addAction("撤销(&U)", this, SLOT(undo()), QKeySequence::Undo);
    undo->setEnabled(document()->isUndoAvailable());

    // 设置恢复动作
    QAction *redo = menu->addAction("恢复(&R)", this, SLOT(redo()), QKeySequence::Redo);
    redo->setEnabled(document()->isRedoAvailable());
    menu->addSeparator( );

    // 设置剪切动作
    QAction *cut = menu->addAction(tr("剪切(&T)"), this, SLOT(redo()), QKeySequence::Cut);
    cut->setEnabled(textCursor().hasSelection());

    // 设置复制动作
    QAction *copy = menu->addAction(tr("复制(&C)"), this, SLOT(copy()), QKeySequence::Copy);
    copy->setEnabled(textCursor().hasSelection());

    // 设置粘贴动作
    menu->addAction(tr("粘贴(&P)"), this, SLOT(paste()), QKeySequence::Paste);


    // 设置清空动作
    QAction *clear = menu->addAction(tr("清空"), this, SLOT(clear()));
    clear->setEnabled(!document()->isEmpty());
    menu->addSeparator( );

    // 设置全选动作
    QAction *select = menu->addAction(tr("全选"), this, SLOT(selectAll()), QKeySequence::SelectAll);
    select->setEnabled(!document()->isEmpty());


    // 获取鼠标的位置, 然后在这个位置上显示菜单
    menu->exec(e->globalPos()); //// This is available in all editors.

    // 最后销毁这个菜单
    delete menu;
}

// 在窗口关闭时, 判断文件是否需要保存
bool MdiChild::maybeSave( )
{
    // 如果文档被更改过
    if(document()->isModified())
    {
        QMessageBox box;
        box.setWindowTitle(tr("多文档编辑器"));
        box.setText(tr("是否保存对“%1”的更改？").arg(useFriendlyCurrentFile()));
        box.setIcon(QMessageBox::Warning);
        // 添加按钮, QMessageBox::YesRole可以表明这个按钮的行为

        QPushButton *yesBtn = box.addButton(tr("是(&Y)"), QMessageBox::YesRole);
        box.addButton(tr("否(&N)"), QMessageBox::NoRole);
        QPushButton *canceBtn = box.addButton(tr("取消"), QMessageBox::RejectRole);
        // 弹出对话框, 让用户选择是否保存修修改, 或者取消关闭操作
        box.exec( );
        // 如果用户选择是, 则返回保存操作的结果, 如果选择取消, 则返回false
        if(box.clickedButton() ==  yesBtn)
        {
            return save( );
        }
        else if(box.clickedButton() == canceBtn)
        {
            return false;
        }
    }

    // 如果文档没有被更改过, 则直接返回true
    return true;
}



