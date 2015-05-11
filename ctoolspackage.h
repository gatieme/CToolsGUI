#ifndef CTOOLSPACKAGE_H
#define CTOOLSPACKAGE_H

//  添加CTools库的信息
#ifdef   __cplusplus

    extern "C"
    {
        #include "CTools.h"
    }

#endif      //  #ifdef   __cplusplus

#include <QObject>


class CToolsPackage : public QObject
{
    Q_OBJECT
public:
    explicit  CToolsPackage(QObject *parent = 0);

    ~CToolsPackage( );

    // 代码插桩
    void CodeProp(QString &srcFname, QString &destFname);

    // 词法分析
    void CodeLexical(QString &srcFname);

    // 语法分析
    void CodeParer(QString &srcFname);

signals:
    //  代码插桩完成后的信号
    void SignalCodeProp(QString &srcFname, QString &destFname);

    //  代码词法分析完成后的信息
    void SignalCodeLexical(QString &srcFname, BinaryTuple douTuple);

    //  代码语法分析
    void SignalCodeParser(QString &srcFname);


protected:
//    std::string srcFname;               //  源文件名
//    std::string destFname;              //  目标文件名

};

#endif // CTOOLSPACKAGE_H
