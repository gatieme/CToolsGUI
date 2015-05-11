/**
******************************************************************************
*   CopyRight  : 2012-2013, HerBinUnversity, GatieMe                         *
*   File Name  : mainwindow.cpp                                              *
*   Description: 多文档编辑器主窗口类源文件                                     *
*   Author     : Gatie_Me                                                    *
*   Version    : Copyright 2012                                              *
*   Data_Time  : 20112-8-29 10:28:43                                         *
*   Content    : Qt设置の多文档编辑器                                           *
******************************************************************************
**/

/**
*************************************************************************
*2012/10/21_20:35  -=> 更新菜单状态。                                     *
*在MdiWindow构造函数中添加间隔期actionSeparator_的信息.                     *
*完成了updataMenus(_)更新菜单函数实现菜单的动作信息, 是各个动作在正确状态下执行 *
*************************************************************************
**/

/**
****************************************************************************
*2012/10/21_21:00  -=> 充实新建文件操作                                      *
*完成了[private slot:]MdiChild *activeMdiChild( )用于创建中心部件             *
****************************************************************************
**/

/**
****************************************************************************
*2012/10/22_19:54  -=> 实现打开文件操作                                      *
*&_实现查找子窗口函数QMdiSubWindow *findMdiChild(const QString &fileName);       *
*&_实现设置活动子窗口void setActiveSubWindow(QWidget *window);                   *
****************************************************************************
**/

// Question:如何实现没打开一个文件窗口就在窗口菜单中列出其文件名
//          而且可以在这个列表中选择一个子窗口, 将它设置为活动窗口
//          实现方法采用菜单影射类QSignalMapper
/**
****************************************************************************
*2012/10/23_18:43  -=> 添加子窗口的列表                                      *
*&_查找子窗口函数QMdiSubWindow *findMdiChild(const QString &fileName);       *
*&_设置活动子窗口void setActiveSubWindow(QWidget *window);                   *
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
*添加private函数实现                                                        *
*               void readSetting( )读入窗口设置                              *
*               void writeSetting( )写入窗口设置                             *
*添加protected函数声实现                                                      *
*               void closeEvenet(QCloseEvent *event)关闭事件                *
*构造函数中添加readSetting( )初始化窗口时读取窗口设置信息                        *
****************************************************************************
**/


/**
***************************************************************************
*2012/11/21 19:48  -=> 添加查找和替换字符块的函数操作[未完全实现]
*添加两个私有槽private slots声明：
*void textFind( );          // 查找文本
*void findNext( );          // 查找下一个
****************************************************************************
**/


/**
****************************************************************************
*2012/11/23 18:34  -=> 添加在状态栏显示编辑器中光标所在的行号和列号, 并设置状元栏   *
*添加私有槽private slots声明：                                                *
*void showTextRowAndCol( );           在状态栏显示行号和列号                   *
*添加私有函数声明                                                             *
*    void initWindow( );              初始化窗口                             *
*最后在createMdiChild( )函数中添加显示光标的函数
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


#include <QMdiSubWindow>
#include <QTextEdit>
#include <QFileInfo>
#include <QFileDialog>
#include <QString>
#include <QFileDialog>
#include <QSignalMapper>    // 信号映射类
#include <QMessageBox>      // 消息对话框
#include <QSettings>
#include <QCloseEvent>
#include <QPoint>
#include <QSize>
#include <QPushButton>
#include <QLineEdit>

// 使用拖放打开文件时添加
#include <QDragEnterEvent>
#include <QUrl>
#include <QFile>
#include <QLabel>
#include <QTextStream>
#include <QMimeData>

// 添加打印函数时增添的头
#include <QPrinter>
#include <QPrintDialog>
#include <QPrintPreviewDialog>

#include "mainwindow.h"
#include "mdichild.h"
#include "ui_mainwindow.h"
#include "aboutctools.h"
#include "mysyntaxhighlighter.h"


#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ///  创建系统托盘
    this->sysTrayIcon = new CToolsSystemTrayIcon(this);    // 创建系统托盘图标

    /// CTools工具包
    this->m_ctools = new CToolsPackage(this);

    /// 启动主界面程序后, 打开一个关于对话框
//   AboutCTools aboutCTools;
//   aboutCTools.setWindowTitle(QStringLiteral("GatieMeEdit Running"));
//   aboutCTools.show( );
//   aboutCTools.exec( );
    /// 在主窗口的构造函数中初始化actionSeparator动作,
// 然后执行更新菜单函数, 并关联多文档区域的活动子窗口信号到更新到菜单槽上
// 每当更换活动子窗口时, 都会更新菜单状态

    // 创建间隔器动作并在其中设置间隔器
    actionSeparator = new QAction(this);
    actionSeparator->setSeparator(true);

    // 更新菜单
    updataMenus();

    // 当有活动窗口更新时更新菜单
    connect(ui->mdiArea,
            SIGNAL(subWindowActivated(QMdiSubWindow*)),
            this,
            SLOT(updataMenus()));

/// [2012/10/23_18:52]添加
// 如何实现没打开一个文件窗口就在窗口菜单中列出其文件名
// 而且可以在这个列表中选择一个子窗口, 将它设置为活动窗口
// 实现方法采用菜单影射类QSignalMapper

    // 创建信号映射器
    windowMapper = new QSignalMapper(this);
    // 映射器重新发射信号, 根据信号设置活动窗口
    connect(windowMapper, SIGNAL(mapped(QWidget*)),
            this, SLOT(setActiveSubWindow(QWidget*)));

    // 更新窗口菜单的信息, 并且设置当窗口菜单将要显示的时候更新窗口菜单
    updataWindowMenu( );
    connect(ui->menuW, SIGNAL(aboutToShow()), this, SLOT(updataWindowMenu()));


    // 关联查找功能信号
    connect(ui->actionFind, SIGNAL(triggered()), this, SLOT(textFind()));


    //[2012/11/31 18:48]添加
    this->readSetting( );         // 初始化窗口时读入窗口的设置信息
/// 添加打印以及打印预览生成PDF文件
    connect(ui->actionPrint, SIGNAL(triggered()), this, SLOT(doPrint()));
    connect(ui->actionPrintPreView, SIGNAL(triggered()), this, SLOT(doPrintPreView()));
    connect(ui->actionPDF, SIGNAL(triggered()), this, SLOT(createPdf()));

///  插桩信号和槽的关联
    connect(this->m_ctools, SIGNAL(SignalCodeProp(QString &, QString &)), this, SLOT(slotCodeProp(QString&,QString&)));

///  词法分析的信号和槽关联以及初始化信息
    this->InitLexicalTableWidget( );        // 初始化QTableWidget
    connect(this->m_ctools, SIGNAL(SignalCodeLexical(QString&,BinaryTuple)), this, SLOT(slotCodeLexical(QString&,BinaryTuple)));

/// 在打开主界面以后自动新建一个空白的文档
    // 创建MdiChild
    MdiChild *child = createMdiChild();
    //MdiChild *child = new MdiChild;
    // 多文档区域添加子窗口
    ui->mdiArea->addSubWindow(child);
    // 新建文件
    child->newFile( );
  //child->maximumWidth( );
    child->showMaximized( );        // 将窗口最大化显示



//    qDebug( ) <<__LINE__ <<endl;
//    qDebug() << activeMdiChild( )->document( ) <<endl;
//    qDebug( ) <<__LINE__ <<endl;
    // 显示子窗口
 //   child->show( );
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 更新菜单函数
void MainWindow::updataMenus( )
{
    // 根据是否有活动窗口来设置各个动作是个否可用
    bool hasMdiChild = (activeMdiChild() != 0);

    ui->actionSave->setEnabled(hasMdiChild);    // 保存文件动作
    ui->actionSaveAs->setEnabled(hasMdiChild);  // 另存为文件动作
    ui->actionPaste->setEnabled(hasMdiChild);   // 取消动作
    ui->actionClose->setEnabled(hasMdiChild);   // 关闭文件动作
    ui->actionCloseAll->setEnabled(hasMdiChild);// 关闭所有文件动作
    ui->actionTile->setEnabled(hasMdiChild);  // 平铺动作
    ui->actionCascade->setEnabled(hasMdiChild); // 层叠动作
    ui->actionNext->setEnabled(hasMdiChild);       // 下一个动作
    ui->actionPrevious->setEnabled(hasMdiChild);    // 前一个动作
    ui->actionPrint->setEnabled(hasMdiChild);       // 打印动作
    ui->actionPrevious->setEnabled(hasMdiChild);        // 打印预览
    ui->actionPDF->setEnabled(hasMdiChild);         // 生成PDF
    // 设置间隔器是否需要显示
    actionSeparator->setVisible(hasMdiChild);

    // 有活动窗口且又被选择的文本片段, 剪切复制才可用
    bool hasSelection = (activeMdiChild()
                      && activeMdiChild()->textCursor().hasSelection());
    ui->actionCut->setEnabled(hasSelection);
    ui->actionCopy->setEnabled(hasSelection);

    // 有活动窗口而且文档有撤销操作是撤销动作才可用
    ui->actionUndo->setEnabled(activeMdiChild()
                            && activeMdiChild()->document()->isUndoAvailable());
    // 有活动窗口而且文档有恢复操作是恢复动作才可用
    ui->actionRedo->setEnabled(activeMdiChild()
                            && activeMdiChild()->document()->isRedoAvailable());
}

// 更新窗口菜单函数[2012/10/23_18:58]
void MainWindow::updataWindowMenu( )
{
    // 先清空菜单,然后添加各个菜单动作
    ui->menuW->clear();
    ui->menuW->addAction(ui->actionClose);
    ui->menuW->addAction(ui->actionCloseAll);
    ui->menuW->addSeparator();
    ui->menuW->addAction(ui->actionTile);
    ui->menuW->addAction(ui->actionCascade);
    ui->menuW->addSeparator( );
//    ui->menuW->addAction(ui->actionPrevious);
    ui->menuW->addAction(ui->actionNext);
    ui->menuW->addAction(ui->actionPrevious);
    ui->menuW->addAction(actionSeparator);


    // 如果有活动窗口, 则显示间隔器
    QList<QMdiSubWindow*> window = ui->mdiArea->subWindowList( );
    actionSeparator->setVisible(!window.isEmpty());

    // 遍历各个子窗口
    for(int i = 0; i < window.size(); i++)
    {
        MdiChild *child = qobject_cast<MdiChild* >(window.at(i)->widget());
        QString text;
        // 如果窗口数小于9, 则设置编号为快捷键
        if(i < 9)
        {
            text = tr("&%1 %2").arg(i + 1).arg(child->useFriendlyCurrentFile());
        }
        else
        {
            text = tr("%1 %2").arg(i + 1).arg(child->useFriendlyCurrentFile());
        }

        // 添加动作到菜单, 设置动作可以选择
        QAction *action = ui->menuW->addAction(text);
        action->setCheckable(true);
        // 设置当前活动窗口动作作为选中状态
        action->setChecked(child == activeMdiChild());

        // 关联动作的触发信号到信号映射器的map槽, 这个槽或发射map信号
        connect(action, SIGNAL(triggered()), windowMapper, SLOT(map()));

        // 将动作与相应的窗口部件进行映射
        // 将映射mapped()信号时就会以这个窗口部件为参数
        windowMapper->setMapping(action, window.at(i));
    }
}

// 更新菜单函数的帮助函数
// 复制剪切&&撤销恢复操作设置需要进行的特殊文本判断
MdiChild* MainWindow::activeMdiChild( )
{
    // 如果有活动窗口, 则将其在内的中心部件转换为MdiChild类型， 没有则直接返回0
    if(QMdiSubWindow *activeSubWindow = ui->mdiArea->activeSubWindow())
    {
        return qobject_cast<MdiChild* >(activeSubWindow->widget());
    }
    else
    {
        return 0;
    }
}


// 创建子窗口的函数[2012/10/21_21:00]
MdiChild* MainWindow::createMdiChild( )
{
    // 创建MdiChild部件
    MdiChild *child = new MdiChild;
    // 向多文档区域添加子窗口, child作为中心部件
    //ui->mdiArea->addSubWindow(child);

    // 根据QTextEdit类是否可以复制信号设置剪切复制动作是否可用
    connect(child, SIGNAL(copyAvailable(bool)), ui->actionCut, SLOT(setEnabled(bool)));
    connect(child, SIGNAL(copyAvailable(bool)), ui->actionCopy, SLOT(setEnabled(bool)));

    // 根据QTextEdit类是否可以复制信号设置剪切复制动作是否可用
    connect(child->document(), SIGNAL(undoAvailable(bool)),
            ui->actionUndo, SLOT(setEnabled(bool)));
    connect(child->document(), SIGNAL(redoAvailable(bool)),
            ui->actionUndo, SLOT(setEnabled(bool)));

    // 在状态栏显示光标的位置
    connect(child, SIGNAL(cursorPositionChanged()), this, SLOT(showTextRowAndCol()));

   // connect(child, SIGNAL(selectionChanged()), this, SLOT()
    return child;
}


// 设置活动窗口的函数[将传递过来的窗口部件设置为活动窗口][2012/10/22_19:54]
void MainWindow::setActiveSubWindow(QWidget *window)
{
    if(!window)
    {
        return;
    }
    ui->mdiArea->setActiveSubWindow(qobject_cast<QMdiSubWindow*>(window));
}


// 查找子窗口函数[2012/10/22_19:54]
QMdiSubWindow* MainWindow::findMdiChild(const QString &fileName)
{
    QString canonicalFilePath = QFileInfo(fileName).canonicalFilePath( );
    // 利用foreach语句遍历子窗口列表, 如果其文件路径和要查找的路径相同, 则返回该窗口
    foreach(QMdiSubWindow *window, ui->mdiArea->subWindowList())
    {
        MdiChild *mdiChild = qobject_cast<MdiChild* >(window->widget());
        if(mdiChild->currentFile() == canonicalFilePath)
        {
            return window;
        }
    }

    return 0;
}


// 关闭事件函数[2012/10/31 18:48]
void MainWindow::closeEvent(QCloseEvent *event)
{
    // 先执行多文档区域的关闭文件
    ui->mdiArea->closeAllSubWindows( );
    // 如果还有窗口没有关闭, 则忽略该事件
    if(ui->mdiArea->currentSubWindow())
    {
         event->ignore() ;
    }
    else
    {
        // 在关闭前写入窗口设置
        writeSetting( );
        event->accept( );
    }
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)                 // 拖入进入事件
{
    qDebug( ) <<"拖入进入事件" <<endl;

    if(event->mimeData()->hasUrls())      // 数据中是否包含URL
    {
        event->acceptProposedAction();  // 如果是则接受动作
    }
    else
    {
        event->ignore();        // 否则忽略该事件
    }
}

void MainWindow::dropEvent(QDropEvent *event)           // 放下事件
{
    qDebug( ) <<"放下事件" <<endl;
    const QMimeData *mimeData = event->mimeData( );     // 获取数据
    if(mimeData->hasUrls( ))     // 如果数据中包含URL路径
    {
        QList<QUrl> urlList = mimeData->urls( );    // 获取URL列表

        // 将其中第一个URL表示为本地文件路径
        QString fileName = urlList.at(0).toLocalFile( );
        qDebug() <<fileName <<endl;
        if(fileName.isEmpty( ) != true)        // 如果文件路劲不为空
        {
            QFile file(fileName);      // 建立只读对象并且以只读方式打开该文件
            if(!file.open(QIODevice::ReadOnly))
            {
                return ;
            }
            MdiChild *child = createMdiChild();
            ui->mdiArea->addSubWindow(child);   // 将子窗口添加到多文档编辑区域
            if(child->loadFile(fileName))
            {
                ui->statusBar->showMessage(tr("打开文件成功"), 2000);
                child->show( );
            }
            else
            {
                child->close( );
            }
        }
    }
}

// 写入窗口函数设置
void MainWindow::writeSetting( )
{
    QSettings settings("GatieMe", "myEdit");
    // 写入位置信息和大小信息
    settings.setValue("pos", pos());
    settings.setValue("size", size());
}


// 读取窗口设置
void MainWindow::readSetting( )
{
    QSettings settings("GatieMe", "myEdit");

    //QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint( );
  //  QPoint size = settings.value("size", QSize(400, 400)).toSize( );

   // move(pos);
   //resize(size);
}

void MainWindow::showTextRowAndCol( )          // 在状态栏显示行号和列号
{
     // 如果有活动窗口, 则显示光标所在位置
    if(activeMdiChild())
    {
        // 由于获取的行号列号都是从零开始的, 都需要+1
        int rowNum = activeMdiChild( )->textCursor( ).blockNumber( ) + 1;
        int colNum = activeMdiChild( )->textCursor().columnNumber( ) + 1;


        ui->statusBar->showMessage(tr("%1行 %2列").arg(rowNum).arg(colNum), 2000);
    }
}

void MainWindow::initWindow( )                 // 初始化窗口[2012/11/23 18:34]
{
    setWindowTitle(tr("多文档编辑器"));

    // 在工具栏上右击, 可以关闭工具栏
    ui->mainToolBar->setWindowTitle(tr("显示工具栏"));

    // 当多文档区域的内容超出可是区域后, 出现滚动条
    ui->mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);


    ui->statusBar->showMessage(QStringLiteral("欢迎使用多文档编辑器"));

    QLabel *label = new QLabel(this);
    label->setFrameStyle(QFrame::Box | QFrame::Sunken);
    label->setText(tr("<a href = \"http://www.July.com\">www.July.com</a>"));

    // 标签文本为富文本
    label->setTextFormat(Qt::RichText);
    // 可以打开外部链接
    label->setOpenExternalLinks(true);


    // 显示创建文件的动态
    ui->statusBar->addPermanentWidget(label);
    ui->actionNew->setStatusTip(QStringLiteral("创建一个文件"));

    // 显示打开文件动态
    ui->statusBar->addPermanentWidget(label);
    ui->actionOpen->setStatusTip(QStringLiteral("打开一个文件"));

    // 保存文件动态
    ui->statusBar->addPermanentWidget(label);
    ui->actionSave->setStatusTip(QStringLiteral("保存文件"));

    // 另存为文件动态
    ui->statusBar->addPermanentWidget(label);
    ui->actionSaveAs->setStatusTip(QStringLiteral("另保存文件"));

    // 此处省略20000行代码
    // ......
}


void MainWindow::doPrint( )                    // 打印文档的函数
{
    QPrinter printer;       // 创建打印对象
    QPrintDialog dialog(&printer, this);        // 创建打印对话框
    // 如果编辑器中共有选中区域的话, 则打印选中区域
    if(activeMdiChild()->textCursor().hasSelection())
    {
        dialog.addEnabledOption(QAbstractPrintDialog::PrintSelection);
    }

    if(dialog.exec() == QDialog::Accepted)      // 如果在对话框中按下了打印按钮
    {
        activeMdiChild()->print(&printer);      // 则执行打印操作
    }
}


void MainWindow::doPrintPreView( )             // 打印预览函数
{
    QPrinter printer;           // 创建打印机对象

    QPrintPreviewDialog preview(&printer, this);     // 窗机打印预览对话框
    // 创建生成预览页面时, 发射paintRequested(QPrinter*)
    connect(&preview, SIGNAL(paintRequested(QPrinter*)), this, SLOT(printPreview(QPrinter*)));
    preview.exec( );
}

void MainWindow::printPreview(QPrinter *printer)       // 按照预览打印
{
    activeMdiChild()->print(printer);
}

void MainWindow::createPdf( )           // 生成PDF文件
{
    QString fileName = QFileDialog::getSaveFileName(this, QString("导出PDF文件"), QString(), "*.pdf");
    if(!fileName.isEmpty())     // 文件名不为空
    {
        if(QFileInfo(fileName).suffix().isEmpty())
        {
            fileName.append(".pdf");        // 如果文件后缀为空, 则默认使用.pdf
        }

        QPrinter printer;
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(fileName);
        activeMdiChild()->print(&printer);
    }
}

// 新建文件的槽信息信息函数
void MainWindow::on_actionNew_triggered()
{
    // 创建MdiChild
    MdiChild *child = createMdiChild();
    //MdiChild *child = new MdiChild;
    // 多文档区域添加子窗口
    ui->mdiArea->addSubWindow(child);
    // 新建文件
    child->newFile( );
    // 显示子窗口
    child->showMaximized( );        // 将窗口最大化显示
    //child->show( );
}

// 打开文件的曹信息函数[2012/10/22_19:54]
void MainWindow::on_actionOpen_triggered()
{
    // 获取文件路径
    QString fileName = QFileDialog::getOpenFileName(this);
    // 如果路径不为空, 则查看该文件是否已经打开
    if(fileName.isEmpty() == false)
    {
        QMdiSubWindow *existing = findMdiChild(fileName);
        // 如果文件已经存在, 则将对应的子窗口设置为活动窗口
        if(existing)
        {
            ui->mdiArea->setActiveSubWindow(existing);
            return;
        }
        else    // 如果没有打开, 则新建子窗口
        {
            MdiChild *child = createMdiChild();
            ui->mdiArea->addSubWindow(child);   // 将子窗口添加到多文档编辑区域
            if(child->loadFile(fileName))
            {
                ui->statusBar->showMessage(tr("打开文件成功"), 2000);
                //child->show( );
                child->showMaximized( );        // 将窗口最大化显示
            }
            else
            {
                child->close( );
            }
        }
    }
}


// 保存文件的操作信号槽
void MainWindow::on_actionSave_triggered()
{
    if(activeMdiChild() && activeMdiChild()->save())
    {
        ui->statusBar->showMessage(tr("文件保存成功"));
    }
}

// 另存为文件的操作
void MainWindow::on_actionSaveAs_triggered()
{
    if(activeMdiChild() && activeMdiChild()->save())
    {
        ui->statusBar->showMessage(tr("文件保存成功"));
    }
}

// 撤销操作的信号槽
void MainWindow::on_actionUndo_triggered()
{
    if(activeMdiChild())
    {
        activeMdiChild()->undo( );
    }
}



// 关于Qt的信号
void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, tr("关于GatieMeEdit"),
                       tr("     作者: 哈尔滨学院1031701成坚\n指导老师：王克朝\n版本：v1.0.0_CopyRight2012@Habru.edu\n\n\n旨在学习Qt, 并祝愿Qt越走越好"));
}

void MainWindow::on_actionAboutQt_triggered()
{
    // 关于对话框
    QMessageBox::about(this, tr("关于Qt"),
                       tr("GatieMe祝愿Qt越走越好！"));
}


void MainWindow::on_actionExit_triggered()
{
    // 等价于QApplication::closeAllWindows( );
    qApp->closeAllWindows( );
}

// 关闭文件的信号槽
void MainWindow::on_actionClose_triggered()
{
    ui->mdiArea->closeActiveSubWindow( );
}


void MainWindow::on_actionCloseAll_triggered()
{
    ui->mdiArea->closeAllSubWindows( );
}


void MainWindow::on_actionFind_triggered( )
{

}



void MainWindow::textFind( )//on_actionFind_triggered()  // 查找函数2012/11/21 19:48
{
    QDialog *dialog = new QDialog(this);        // 创建一个对话框
    QLineEdit *lineEdit = new QLineEdit(dialog);       // 创建行编辑器
    QPushButton *button = new QPushButton(dialog);   // 创建按钮

    button->setText("查找下一个");
    connect(button, SIGNAL(clicked()), this, SLOT(findNext()));        // 关联信号和槽

    QVBoxLayout *layout = new QVBoxLayout( );       // 创建垂直布局管理器

    layout->addWidget(lineEdit);
    layout->addWidget(button);
    dialog->setLayout(layout);      // 在对话框中使用布局管理器i

    dialog->show( );
}


void MainWindow::findNext( )    // 查找下一个函数
{
  //  QString string = activeMdiChild( )->;
    // 使用查找函数查找指定的字符串, 查找方式为向后查找
 //  bool isFind = activeMdiChild( )->find(string, QTextDocument::FindBackward);

 //   if(isFind)
    {
       // qDebug() <<tr("行号：%1列号：%2").arg(ui->);
    }
}



// 当单击了插桩菜单按钮时
void MainWindow::on_actionProp_triggered()
{
    if(this->activeMdiChild() == NULL)
    {
        return ;
    }
    // 获取到当前主窗体中活动的文件名
    QString srcFname = this->activeMdiChild( )->currentFile( );
    if(srcFname.isEmpty( ))         // 如果当前没有活动窗口
    {
        return  ;
    }
    // 获取到需要保存到的插桩目标文件的文件名
    QString destFname = QFileDialog::getSaveFileName(this, QString("进行程序插桩"), QString(), "*.c");
    if(!destFname.isEmpty())     // 文件名不为空
    {
        if(QFileInfo(destFname).suffix().isEmpty( ))
        {
            destFname.append(".c");        // 如果文件后缀为空, 则默认使用.pdf
        }

        // 进行程序插桩
        qDebug( ) <<"待插桩的源文件" <<srcFname <<endl;
        qDebug( ) <<"插桩目标文件" <<destFname <<endl;
        this->m_ctools->CodeProp(srcFname, destFname);

    }
    else                        //  文件名为空
    {
        /// NOP
    }


}



void MainWindow::on_actionLexical_triggered()
{
    // 对代码进行词法分析
    if(this->activeMdiChild( ) == NULL)
    {
        return ;
    }

    // 获取到当前主窗体中活动的文件名
    QString srcFname = this->activeMdiChild( )->currentFile( );
    if(srcFname.isEmpty( ))         // 如果当前没有活动窗口
    {
        QMessageBox::about(NULL, "警告", "暂时没有打开任何文件，不能进行词法分析");

    }

    this->m_ctools->CodeLexical(srcFname);              // 对源程序进行词法分析

}

void MainWindow::slotCodeLexical(QString &srcFname, BinaryTuple douTuple)
{
    this->ShowLexicalTable(douTuple);
}



// 撤销菜单被单击
void MainWindow::on_actionRedo_triggered()
{
    if(activeMdiChild())
    {
        this->activeMdiChild()->redo( );
    }
}

//  剪切操作
void MainWindow::on_actionCut_triggered()
{
    if(activeMdiChild())
    {
        this->activeMdiChild()->cut( );
    }
}

//  复制操作
void MainWindow::on_actionCopy_triggered()
{
    if(activeMdiChild())
    {
        this->activeMdiChild()->copy( );
    }
}

//  粘贴操作
void MainWindow::on_actionPaste_triggered()
{
    if(activeMdiChild())
    {
        this->activeMdiChild()->paste( );
    }
}

//  平铺操作
void MainWindow::on_actionTile_triggered()
{
    ui->mdiArea->tileSubWindows( );
}



//  层叠操作
void MainWindow::on_actionCascade_triggered()
{
    ui->mdiArea->cascadeSubWindows( );

}


// 下一个按钮
void MainWindow::on_actionNext_triggered()
{
    ui->mdiArea->activateNextSubWindow( );
}

// 上一个按钮
void MainWindow::on_actionPrevious_triggered()
{
    ui->mdiArea->activatePreviousSubWindow( );
}


void MainWindow::OpenFile(QString &fileName)
{
    // 如果路径不为空, 则查看该文件是否已经打开
    if(fileName.isEmpty() == false)
    {
        QMdiSubWindow *existing = findMdiChild(fileName);
        // 如果文件已经存在, 则将对应的子窗口设置为活动窗口
        if(existing)
        {
            ui->mdiArea->setActiveSubWindow(existing);
            return;
        }
        else    // 如果没有打开, 则新建子窗口
        {
            MdiChild *child = createMdiChild();
            ui->mdiArea->addSubWindow(child);   // 将子窗口添加到多文档编辑区域
            if(child->loadFile(fileName))
            {
                ui->statusBar->showMessage(tr("打开文件成功"), 2000);
                //child->show( );
                child->showMaximized( );        // 将窗口最大化显示
            }
            else
            {
                child->close( );
            }
        }
    }
}

//  插桩的槽函数
//  用户惊醒插桩后，两个文件[插桩源文件和插桩目标文件]平铺在主窗体中
void MainWindow::slotCodeProp(QString &srcFname, QString &destFname)
{
    QMessageBox::StandardButton sBtn = QMessageBox::question(NULL, "警告", "请问您是否希望暂时关闭插桩无关的其他文件", QMessageBox::Yes | QMessageBox::No);

    if(sBtn == QMessageBox::Yes)
    {
        this->on_actionCloseAll_triggered( );       //  暂时关闭其他文件
    }

    this->OpenFile(destFname);         // 打开插桩目标文件
    this->OpenFile(srcFname);          // 打开插装源文件

    this->on_actionTile_triggered( );       // 将两窗口平铺
}



extern const char keyword[MAX_KEYWORD_COUNT][MAX_KEYWORD_SIZE];         // 所有的关键字变量
extern const char procom[MAX_PROCOM_COUNT][MAX_PROCOM_SIZE];           // 预编译指令定义
extern const char operate[MAX_OPERATE_COUNT];             // 简单运算符定义
extern const char allOperator[MAX_OPERATE_COUNT][MAX_OPERATE_SIZE];      // 运算符定义
extern const char separator[MAX_SEPARAROR_COUNT];

//  词法分析显示函数
void MainWindow::ShowLexicalTable(BinaryTuple douTuple)
{
    // 遍历词法链表，同时将词法信息输出到tabWidget
    if(douTuple == NULL)
    {
        return ;
    }

    TupleNode *pNode = (TupleNode *)douTuple->m_next;
   // this->ui->lexicalTableWidget->setRowCount(pNode->m_tuple.m_data.m_keyCode);
    qDebug( ) <<"共计" <<pNode->m_tuple.m_data.m_keyCode <<"个单元" <<endl;
    for(int item = 0; pNode != NULL; item++)
    {

        // 首先取出词法链表中的元素信息
        //ShowCoord(&(pNode->m_tuple.m_coord));
        //ShowTupleData(pNode);
        this->ui->lexicalTableWidget->insertRow(item);

        Coord *coord = &(pNode->m_tuple.m_coord);
        qDebug( ) <<coord->m_fileLine <<"  " <<coord->m_fileBegOffset <<"  " <<coord->m_fileEndOffset <<endl;
        this->ui->lexicalTableWidget->setItem(item, 2, new QTableWidgetItem(QString::number(coord->m_fileLine, 10)));
        this->ui->lexicalTableWidget->setItem(item, 3, new QTableWidgetItem(QString::number(coord->m_fileBegOffset, 10)));
        this->ui->lexicalTableWidget->setItem(item, 4, new QTableWidgetItem(QString::number(coord->m_fileEndOffset, 10)));
        switch((int)pNode->m_tuple.m_kind)          // 依据当前此法结点的编码
        {
            case TOKEN_END               :                  // 标识符号
            {
                this->ui->lexicalTableWidget->setItem(item, 0, new QTableWidgetItem("END"));
                this->ui->lexicalTableWidget->setItem(item, 1, new QTableWidgetItem("终止符"));
                qDebug( ) <<"终止符号" <<pNode->m_tuple.m_data.m_keyCode <<endl;
            // printf("[%d, %d]", TOKEN_END, pNode->m_tuple.m_data.m_keyCode);

                break;
            }
            case TOKEN_NULL              :
            case UNKNOW                  :
            case ARRAY                   :
            case FUNCTION                :
            case PARAMETERS              :
            case POINT                   :
            {
                break;
            }

            case HEAD                    :
            {

                printf("COUNT = %d", pNode->m_tuple.m_coord.m_fileLine);
                printf("COUNT = %d", pNode->m_tuple.m_data.m_keyCode);
                break;
            }

            case IDENTIFIER              :                  // 标识符号
            {
                this->ui->lexicalTableWidget->setItem(item, 0, new QTableWidgetItem(pNode->m_tuple.m_data.m_identifier));
                this->ui->lexicalTableWidget->setItem(item, 1, new QTableWidgetItem("标识符"));
                qDebug( ) <<"标识符号" <<pNode->m_tuple.m_data.m_identifier <<endl;
            //                printf("[%d, %s]", IDENTIFIER, pNode->m_tuple.m_data.m_identifier);
                break;
            }

            case KEYWORD                 :                  /// 关键字信息
            case AUTO_KEYWORD            :
            case BOOL_KEYWORD            :
            case BREAK_KEYWORD           :
            case CASE_KEYWORD            :
            case CHAR_KEYWORD            :
            case CONST_KEYWORD           :
            case CONTINUE_KEYWORD        :
            case DEFAULT_KEYWORD         :
            case DO_KEYWORD              :
            case DOUBLE_KEYWORD          :
            case ELSE_KEYWORD            :
            case ENUM_KEYWORD            :
            case EXTERN_KEYWORD          :
            case FLOAT_KEYWORD           :
            case FOR_KEYWORD             :
            case GOTO_KEYWORD            :
            case IF_KEYWORD              :
            case INLINE_KEYWORD          :
            case INT_KEYWORD             :
            case LONG_KEYWORD            :
            case REGISTER_KEYWORD        :
            case RETURN_KEYWORD          :
            case SHORT_KEYWORD           :
            case SIGNED_KEYWORD          :
            case SIZEOF_OPERATE          :
            case STATIC_KEYWORD          :
            case STRUCT_KEYWORD          :
            case SWITCH_KEYWORD          :
            case TYPEDEF_KEYWORD         :
            case UNION_KEYWORD           :
            case UNSIGNED_KEYWORD        :
            case VOID_KEYWORD            :
            case VOLATILE_KEYWORD        :
            case WHILE_KEYWORD           :
            case _BOOL_KEYWORD           :
            case _COMPLEX_KEYWORD        :
            case _IMAGINARY_KEYWORD      :
            {
                int pos = pNode->m_tuple.m_kind - pNode->m_tuple.m_data.m_keyCode;
                this->ui->lexicalTableWidget->setItem(item, 0, new QTableWidgetItem(keyword[pos]));
                this->ui->lexicalTableWidget->setItem(item, 1, new QTableWidgetItem("关键字"));
                qDebug( ) <<"关键字" <<keyword[pos] <<endl;
                // printf("[%d, %s]", KEYWORD, keyword[pos]);
                // printf("[%d, %d]", pNode->m_tuple.m_data.m_keyCode, pNode->m_tuple.m_kind);
                break;
            }

            case OPERATE                 :                  /// 运算符号
            case COMMA_OPERATE           :                  // ,
            case ASSIGN_OPERATE          :                  // =
            case ADD_ASSIGN_OPERATE      :                  // +=
            case SUB_ASSIGN_OPERATE      :                  // -=
            case MUL_ASSIGN_OPERATE      :                  // *=
            case DIV_ASSIGN_OPERATE      :                  // /=
            case MOD_ASSIGN_OPERATE      :                  // %=
            case BITOR_ASSIGN_OPERATE    :                  // |=
            case BITXOR_ASSIGN_OPERATE   :                  // ^=
            case BITAND_ASSIGN_OPERATE   :                  // &=
            case RSHIFT_ASSIGN_OPERATE   :                  // >>=
            case LSHIFT_ASSIGN_OPERATE   :                  // <<=
            case QUESTION_OPERATE        :                  // ?
            case COLON_OPERATE           :                  // :
            case OR_OPERATE              :                  // ||
            case AND_OPERATE             :                  // &&
            case BITOR_OPERATE           :                  // |
            case BITXOR_OPERATE          :                  // ^
            case BITAND_OPERATE          :                  // &
            case EQUAL_OPERATE           :                  // ==
            case UNEQUAL_OPERATE         :                  // !=
            case GREATER_OPERATE         :                  // >
            case GREATER_EQUAL_OPERATE   :                  // >=
            case LESS_OPERATE            :                  // <
            case LESS_EQUAL_OPERATE      :                  // <=
            case RSHIFT_OPERATE          :                  // >>
            case LSHIFT_OPERATE          :                  // <<
            case ADD_OPERATE             :                  // +
            case SUB_OPERATE             :                  // -
            case MUL_OPERATE             :                  // *
            case DIV_OPERATE             :                  // /
            case MOD_OPERATE             :                  // %
            case NOT_OPERATE             :                  // !
            case COMP_OPERATE            :                  // ~
            case INC_OPERATE             :                  // ++
            case DEC_OPERATE             :                  // --
        //		case RPAREN_OPERATE          :                  // )
        //		case LPAREN_OPERATE          :                  // (
        //    case RBRACKET_OPERATE        :                  // ]
        //		case LBRACKET_OPERATE        :                  // [
            case DOT_OPERATE             :                  // .
            case POINT_TO_OPERATE        :                  // ->
            case ELLIPSE_OPERATE         :                  // ...
            {
                int pos = pNode->m_tuple.m_kind - pNode->m_tuple.m_data.m_keyCode;
                this->ui->lexicalTableWidget->setItem(item, 0, new QTableWidgetItem(allOperator[pos]));
                this->ui->lexicalTableWidget->setItem(item, 1, new QTableWidgetItem("运算符"));
                qDebug( ) <<"运算符" <<allOperator[pos] <<endl;
                //printf("[%d, %s]", OPERATE, allOperator[pos]);
                //printf("[%d, %d]", pNode->m_tuple.m_data.m_keyCode, pNode->m_tuple.m_kind);
                break;
            }

            case SEPARATOR               :
            case SPACE_SEPARATOR         :
            case LBRACE_SEPARATOR        :
            case RBRACE_SEPARATOR        :
            case SEMICOLON_SEPARATOR     :
            case POUND_SEPARATOR         :
            case SINGLE_QUOTE_SEPARATOR  :
            case DOUBLE_QUOTE_SEPARATOR  :
            case NEWLINE_SEPARATOR       :
        //		case ELLIPSE_SEPARATOR       :
            case RPAREN_OPERATE          :                  // )
            case LPAREN_OPERATE          :                  // (
            case RBRACKET_OPERATE        :                  // ]
            case LBRACKET_OPERATE        :                  // [
            {
                int pos = pNode->m_tuple.m_kind - pNode->m_tuple.m_data.m_keyCode;
                this->ui->lexicalTableWidget->setItem(item, 0, new QTableWidgetItem(QString(separator[pos])));
                this->ui->lexicalTableWidget->setItem(item, 1, new QTableWidgetItem("分界符"));
                qDebug( ) <<"分界符" <<separator[pos] <<endl;
                //printf("[%d, %c]", SEPARATOR, separator[pos]);
                //printf("[%d, %d]", pNode->m_tuple.m_data.m_keyCode, pNode->m_tuple.m_kind);
                break;
            }

            case CONST                   :
            case INT_CONST               :
            case UINT_CONST              :
            case LONG_CONST              :
            case ULONG_CONST             :
            case LLONG_CONST             :
            case ULLONG_CONST            :
            case FLOAT_CONST             :
            case DOUBLE_CONST            :
            case LDOUBLE_CONST           :
            case CHAR_CONST              :
            case WCHAR_CONST             :
            case STRING_CONST            :
            {
                this->ui->lexicalTableWidget->setItem(item, 0, new QTableWidgetItem(pNode->m_tuple.m_data.m_constNum));
                this->ui->lexicalTableWidget->setItem(item, 1, new QTableWidgetItem("常量"));
                qDebug( ) <<"常量" <<pNode->m_tuple.m_data.m_constNum <<endl;
                //printf("[%d, %s]", pNode->m_tuple.m_kind, pNode->m_tuple.m_data.m_constNum);
                break;
            }
            case ENUM_CONST              :
            {
                break;
            }
        }


        pNode = (TupleNode *)pNode->m_next;      // 指向下一个指针域
    }
    this->ui->dockWidget->show();
    this->ui->lexicalTableWidget->show( );
}



// 初始化LexicalTableWidget
void MainWindow::InitLexicalTableWidget( )     // 初始化表
{

    this->ui->lexicalTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);   //  禁止用户修改表格
    this->ui->lexicalTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);  //  设置表格选择行为为行选定
    this->ui->lexicalTableWidget->verticalHeader()->setVisible(false);                  //  隐藏表格

    this->ui->lexicalTableWidget->hide( );                                              // 隐藏表格

}

















