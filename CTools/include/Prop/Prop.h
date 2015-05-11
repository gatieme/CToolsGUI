/***********************************************************************************
*   CopyRight  : 2013-2014, HerBinUnversity, GatieMe
*   File Name  : Parser.h
*   Description: CTools-SyntacicParser
*   Version    : Copyright 2013-2014
*   Data_Time  : 2013-3-10 21:29:24
*   Content    : CTools-Lexical
*
*   This file is the CodeProp...
***********************************************************************************/


#ifndef PROP_H_INCLUDED
#define PROP_H_INCLUDED


#include "../Parser/Syntax.h"
#include "../Tools/Files.h"
#include "../Config/Config.h"
#include "../Lexical/BinaryTuple.h"
#include "../Lexical/Lexical.h"



/// �궨�庯���Ķ��巽ʽ��Ϣ
#ifndef PUBLIC_and_PRIVATE
#define PUBLIC_and_PRIVATE
#
#define PUBLIC  extern          // �������Ա�������
#define PRIVATE static      // ����ֻ�ܱ����ļ��ĺ�������
#
#endif



//////////////////////////////////////////////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/// ȫ��ͷ�ļ�������׮�괮 -=> ��λ�ÿ�ʼλ�ò���
#define PROP_FILE_NAME  ".\\OutPut\\out_prop.c"
#
#
#define INCLUDE_DEFINE_PROP_STR                                             \
        "#include <stdio.h>\n#include <stdlib.h>\n\n"
#
#
/// �˺궨�����ڲ����׮�ַ��� -=> ���ļ����ļ���ʼλ�ò���
#define LINE_DEFINE_PROP_STR                                                \
        "#define LINE()        fprintf(__propFP__, \"%d\\n\", __LINE__)\n"
#
#
/// ȫ�ֲ�׮�ļ�ָ������괮    -=> ���ļ���ʼλ�ò���
#define GLOBAL_FILE_POINT_PROP_STR                                          \
        "FILE *__propFP__;\n"
#
#
/// �������ļ���ʼλ�ò���ĺ�ļ���
#define START_DEFINE_PROP_STR                                                 \
        INCLUDE_DEFINE_PROP_STR LINE_DEFINE_PROP_STR GLOBAL_FILE_POINT_PROP_STR
#
#
/// �˺궨�����ļ�����Ϣ -=> ������main����ں�����ʼλ��
/*#define FILE_OPEN_DEFINE_PROP_STR                                                 \
        "//\tFILE *__propFP__ = NULL;\n"                                          \
        "\tif((__propFP__ = fopen(\"prop.txt\", \"w\")) == NULL)\n"               \
        "\t{\n"                                                                   \
        "\t\tfprintf(stderr, \"can\'t open the file prop.txt\\n\");\n"            \
        "\t}\n"*/
#define FILE_OPEN_DEFINE_PROP_STR                                             \
        "if((__propFP__ = fopen(\"prop.txt\", \"w\")) == NULL)"               \
        "{"                                                                   \
        "fprintf(stderr, \"can\'t open the file prop.txt\\n\");"              \
        "}"
#
#
/// �˺궨�����ļ����������� -=>  ����������������֮ǰ
#define PROP_CLOSE_DEFINE_PROP_STR             \
        " fclose(__propFP__); "
#
#
/// �˺궨���˲�׮������Ϣ
#define PROP_STREAM_BASE_PROP_STR(stream)  \
        " LINE(stream) "
#
#
#define PROP_STREAM_SEMICOLON_PROP_STR(stream) \
        " LINE(stream); "
#
#
#define PROP_STREAM_COMMA_PROP_STR(stream)  \
        " LINE(stream), "
#
#
#define PROP_BASE_PROP_STR  \
        " LINE( ) "
#
#
#define PROP_SEMICOLON_PROP_STR \
        " LINE( ); "
#
#
#define PROP_COMMA_PROP_STR  \
        " LINE( ), "
#
#
#define PROP_LBRACE_SEPARATOR_STR   \
        " { "
#
#
#define PROP_RBRACE_SEPARATOR_STR   \
        " } "
#
#
/// �˺������ڲ����ض���
#define ReopenDSefineStr    "freopen("prop.txt", "w", stdout);"
#
#
// ���ļ�������ض����ļ��е���Ϣ
#define WritePropLineStr(fp, fileName, fileLine)                                        \
    do                                                                                  \
    {                                                                                   \
        fprintf(fp, "#line %d \"%s\"\n", fileLine, fileName);                           \
    }while(0);


// ���ļ�������ļ���׮��Ϣ
#define WritePropStr(fp, streamName)                 \
        do                                           \
        {                                            \
            fprintf(fp, "Line(%s);", streamName);    \
        }while(0);

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////////////////////////



/// Literal�ĺ�����������
#ifdef PUBLIC_and_PUBLIC
#
#
// ���ļ��������ʼ��Ϣ[������FileOpenDefineStr��FileOpenDefineStr]
PUBLIC void
WritePropStartStr(
              const char *dest,             // ��׮Ŀ���ļ�
              const char *src);             // ����׮Դ�ļ�
#
#
// ���ļ�fileName���в�׮����
PUBLIC void
PropFile(const char *dest,          // ��׮������Ŀ���ļ�
          const char *src);          // ����׮��Դ�ļ�
#
#
// ��Դ�ļ�src��ƫ��start��end������д��dest�ļ���
PUBLIC void
PropWriteSrcToDest(
                    CToolsFILE destfp,         // ָ���׮��Ŀ���ļ���������ָ��
                    CToolsFILE srcfp,          // ָ�����׮�ļ���������ָ��
                    int start,                  // ��Ҫд��λ�õ���ʼλ��
                    int end);                   // ��Ҫд��λ�õĽ���λ��
#
#
// ���ʷ���Ԫ�������ӵ�Ŀ���ļ���
PUBLIC void
PropWriteTupleNode(
                    CToolsFILE destfp,         // ָ���׮��Ŀ���ļ���������ָ��
                    TupleNode* pNode);         // ָ��ʷ���Ԫ���ָ��
#
#
// �жϵ�ǰ�﷨��������ʾ�ĺ���������Ϣ�ǲ�����main�������
PUBLIC bool
IsMainFunc(
           SyntaxTree parentRoot);
#
#
// ��srcFp�ļ�ָ���е�count���ַ�д��destFpָ����ļ���
PUBLIC void
PropWriteCountSrcToDest(
                        CToolsFILE destFp,          // Ŀ���ļ�ָ��
                        CToolsFILE srcFp,           // Ŀ���ļ�ָ��
                        int count);
#
#
// ��Դ�ļ��дӵ�ǰλ�ÿ�ʼ��ĩβ�������ַ�д��Ŀ���ļ���
PUBLIC void
PropWriteAllSrcToDest(
                      CToolsFILE destFp,            // ָ��Ŀ���ļ���ָ��
                      CToolsFILE srcFp);            // ָ��Դ�ļ���ָ��
#
#
#endif




#endif // PROP_H_INCLUDED
