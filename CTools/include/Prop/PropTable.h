/***********************************************************************************
*   CopyRight   : 2013-2014, HerBinUnversity, GatieMe
*   File Name   : Buffer.h
*   Description: CTools-SyntacicParser
*   Author     : Gatie_Me
*   Version    : Copyright 2013-2014
*   Data_Time  : 2013-11-18 08:42:24
*   Content    : CTools-Prop
***********************************************************************************/

#ifndef PROPTABLE_H_INCLUDED
#define PROPTABLE_H_INCLUDED

#include "../Config/Config.h"
#include "Prop.h"




/// �궨�庯���Ķ��巽ʽ��Ϣ
#ifndef PUBLIC_and_PRIVATE
#define PUBLIC_and_PRIVATE
#
#define PUBLIC  extern          // �������Ա�������
#define PRIVATE static      // ����ֻ�ܱ����ļ��ĺ�������
#
#endif


// ��׮���ַ�������(���)
// ����������ÿ�޸�һ�����Ҫȥ�ļ�PropTable.c���޸�WritePropDefStr������propDefStrArray������
typedef enum tagPropStrKind
{
    PROP_TABLE_HEAD             =  -1,          // ͷ�����Ϣ��
    START_DEFINE_PROP_KIND      =   0,          // ��ʼ��Ϣ�괮
    INCLUDE_DEFINE_PROP_KIND    =   1,          // �������ļ������꣬������ļ���ͷ
    LINE_DEFINE_PROP_KIND       =   2,          // �����Ĳ�׮���֧�ֺ꣬������ļ���ͷ
    FILE_OPEN_DEFINE_PROP_KIND  =   3,          // ���ļ����׮���������main������ʼ��λ��
    FILE_CLOSE_DEFINE_PROP_KIND =   4,          // �ر��ļ����׮��, ���������������֮ǰ
    PROP_BASE_PROP_KIND         =   5,          // ������Ĳ�׮��Ϣ��" LINE(stream) "
    PROP_COMMA_PROP_KIND        =   6,          // ��","�Ĳ�׮��Ϣ��" LINE(stream), "
    PROP_SEMICOLON_PROP_KIND    =   7,          // ��"��"�Ĳ�׮��Ϣ��" LINE(stream); "
    PROP_LBRACE_SEPARATOR_KIND  =   8,
    PROP_RBRACE_SEPARATOR_KIND  =   9,
}PropStrKind;


// ��׮��Ϣ������
typedef struct tagPropData
{
    long            m_offset;               // ��Ҫ��Ӳ�׮��Ϣ��ƫ��λ��
    PropStrKind     m_kind;                 // ��ǰλ��Ӧ�ò����׮��Ϣ
    SyntaxKind      m_grammar;              // ��ǰ��Լ���ݵĲ���ʽ���� -=> �����ڲ�׮��չʹ��
    int              m_line;                 // ���¶�λ���к�����
}PropData;

// ��׮��Ϣ��(����)���
typedef struct PropTableNode
{
    PropData                m_prop;             // ��׮��Ϣ������
    struct PropTableNode    *m_next;             // ָ����һ������������
}PropTableNode;

// ��׮��Ϣ��
typedef PropTableNode*  PropTable;              // ��׮��Ϣ��
//typedef struct tagPropTable
//{
//    PropTableNode   *m_headNode;
//    int               m_count;
//}PropTable;


#ifdef PUBLIC_and_PRIVATE
#
#
// ������׮��Ϣ��, ���ҳ�ʼ��
PUBLIC PropTable
CreatePropTable(void);
#
#
// ���﷨����parentRoot���յ�id������ʽ����ʽ���в�׮
PUBLIC void
PropRed(
        PropTable propTable,
        SyntaxTree parentRoot,
        int id);
#
#
// ��"��Ҫ��offsetƫ�ƣ� ����kind��ʽ�Ĳ�׮��"�Ĳ�׮������Ϣ������ַ���
PUBLIC void
InsertPropData(PropTable propTable,    // ��ǰ��׮��Ϣ��
               long offset,            // ��Ҫ����Ϊλ�õ�ƫ��
               PropStrKind kind);      // ��Ҫ����Ĳ�׮��������
#
#
// ��ʾ��ǰ��׮��������
PUBLIC void
ShowPropTableNode(
                  PropTableNode *propNode);           // ��ǰ��׮��Ϣ���
#
#
// ��ʾ��ǰ��׮��Ϣ��
PUBLIC void
ShowPropTable(
              PropTable propTable);                 // ����ʾ�Ĳ�׮��Ϣ��
#
#
// ���ٵ�ǰ��׮��Ϣ��
PUBLIC void
DestroyPropTable(
                 PropTable propTable);              // �����ٵĲ�׮��Ϣ��
// ɾ����׮��Ϣ���еĵ�һ������
PUBLIC void
DeleteFirstPropData(
                    PropTable propTable);       // ������Ĳ�׮��Ϣ��ͷָ��
#
#
// ����ƫ��offset�ں������ҵ��ʵ���λ��
PUBLIC PropTableNode*
FindPropInsertPos(
                  PropTable propTable,          // ������Ĳ�׮���ݱ�ͷָ��
                  int offset);                   // ��Ҫ����Ľ���λ��ƫ��
#
#
#define EmptyPropTable(propTable)               \
        (propTable->m_next == NULL)
        // propTable->m_prop.m_offset == 0
#
#
// ����PropTable����Ϣ��Դ�ļ�srcFname������д��destFname�ļ�
void WriteProp(PropTable propTable,
               const char *destFname,
               const char *srcFname);
#endif  // PUBLIC_and_PRIVATE





#endif // PROPTABLE_H_INCLUDED
