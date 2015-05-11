/**
******************************************************************************
*   CopyRight  : 2012-2013, HerBinUnversity, GatieMe                         *
*   File Name  : main.h                                                      *
*   Description: 多文档编辑器主函数文件                                         *
*   Author     : Gatie_Me                                                    *
*   Version    : Copyright 2012                                              *
*   Data_Time  : 20112-8-29 10:28:43                                         *
*   Content    : Qt设置の多文档编辑器                                           *
******************************************************************************
**/



//#include <QApplication>
#include <QTextCodec>   // 添加中文支持的头文件
#include <QObject>      // 添加父基类

#include <QtSingleApplication>
#include <QMessageBox>


#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QtSingleApplication app(argc, argv);

    if (app.isRunning())
    {
        QMessageBox::information(NULL, "CToolsGUI", "Your CToolsGUI is already running ...", QMessageBox::Ok);

        return EXIT_SUCCESS;
    }

    MainWindow w;
    w.setWindowTitle("C源程序智能插桩系统");


    w.show( );

    return app.exec();
}
