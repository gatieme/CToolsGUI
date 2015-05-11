#include "ctoolspackage.h"
#include <iostream>

#include <QDebug>

CToolsPackage::CToolsPackage(QObject *parent)
:QObject(parent)
{

}

CToolsPackage::~CToolsPackage()
{

}



// 代码插桩
void CToolsPackage::CodeProp(QString &srcFname, QString &destFname)
{
    // 首先确认执行了插桩编译
    //#ifndef PROP_REDUCTION_DEFINE
    //#error "ErrorPROP: can't find PROP_REDUCTION_DEFINE in elf...\n"
    //#endif // PROP_REDUCTION_DEFINE

    char propDestFname[FILE_NAME_SIZE];
    char propSrcFname[FILE_NAME_SIZE];


    qDebug( ) <<"待插桩的源文件转换为char *" <<srcFname.toStdString( ).c_str( ) <<endl;
    qDebug( ) <<"插桩目标文件转换为char *" <<destFname.toStdString( ).c_str( ) <<endl;
    strcpy(propSrcFname, srcFname.toStdString( ).c_str( ));           // 取出输入文件
    strcpy(propDestFname, destFname.toStdString( ).c_str( ));

    qDebug( ) <<propDestFname <<endl;
    qDebug( ) <<propSrcFname <<endl;

    // 语法分析的同时对源文件进行插桩分析...
    PropFile(propDestFname, propSrcFname);
    qDebug( ) <<"插桩完成..." <<endl;

    // 发送插桩信号
    emit   SignalCodeProp(srcFname, destFname);
}



// 词法分析
void CToolsPackage::CodeLexical(QString &srcFname)
{
    char lexSrcFname[FILE_NAME_SIZE];
    BinaryTuple douTuple;                   // 二元组信息

    qDebug( ) <<"待插桩的源文件转换为char *" <<srcFname.toStdString( ).c_str( ) <<endl;
    strcpy(lexSrcFname, srcFname.toStdString( ).c_str( ));           // 取出输入文件
    qDebug( ) <<lexSrcFname <<endl;

    douTuple = BufferLexical(lexSrcFname);      // 直接处理源文件

    //VisitTuple(douTuple);            // 遍历二元组信息, 查找二元组正确性

    qDebug( ) <<"词法分析完成..." <<endl;

    // 发送插桩信号
    emit   SignalCodeLexical(srcFname, douTuple);
}
