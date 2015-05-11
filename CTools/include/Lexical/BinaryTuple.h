/**
*********************************************************************************
*   CopyRight  : 2013-2014, HerBinUnversity, GatieMe                            *
*   File Name  : BinaryTuple.h                                                  *
*   Description: CTools                                                         *
*   Author     : Gatie_Me                                                       *
*   Version    : Copyright 2013-2014                                            *
*   Data_Time  : 2013-3-10 21:29:24                                             *
*   Content    : CTools-Lexical                                                 *
*********************************************************************************
**/
/*
������
    BinaryTuple��������ķ�ʽ�洢��ǰ�ļ��Ĵʷ���Ϣ
*/




/**[�����޸���Ϣ]0.6
@@   �޸���douTupleͷ���δ����ռ��ʹ������ɵ�BUG[2013/3/21-15:39]
@@   �޸����ж�Ϊ�ֽ��[5]���ɴ�ӡ�ַ��������ɵĳ������isprint()
##   ���ýϵͼ��İ취�����˶�Ԫ��������char *m_valueָ��ĸ�ֵ����, ��ʱ�޸�Ϊchar m_value[20];
**/

/**[�����޸���Ϣ]0.7
@@   ������������εĴ�����Ϣ
@@   ������TupleNode��������m_fileInfo, �滻��ԭ����[int]m_keycode, ��ΪHEAD����������
     [int] m_keycount�����洢��ǰ�ļ��Ĵʷ���Ϣ��Ŀ
     [char*] m_file�����洢��ǰ������ļ����ļ���
**/



/**[�����޸���Ϣ]0.8
@@  ���˫������������, ���ļ��е���Ϣ��ȡ�������������Ч��[δ���]
**/


/**[�����޸���Ϣ]0.9
@@  �޸�˫������������, ���ļ��е���Ϣ��ȡ�������������Ч��[δ���]
@@  ��ӷ��ű�SymbolTable����Ϣ, ����ʶ�����뵽���ű��еĹ�ϣ����
**/

/**[�����޸���Ϣ]0.95
@@  �޸�˫������������, ���ļ��е���Ϣ��ȡ�������������Ч��[δ���]
@@  �޸ķ��ű�SymbolTable����Ϣ, ����ʶ�����뵽���ű��еĹ�ϣ����
@@  ���ĺ���BufferLexical������100�еĺ���ȫ���ֳɼ����ֱ���ĺ���
    �ֱ���[�ؼ��ֻ��߱�ʶ��], �Լ����������, �ֽ������
**/


/**[�����޸���Ϣ]0.96
@@  �޸ķ��ű�SymbolTable����Ϣ, ����ʶ�����뵽���ű��еĹ�ϣ����
@@  ���ĺ���BufferLexical������100�еĺ���ȫ���ֳɼ����ֱ���ĺ���
    �ֱ���[�ؼ��ֻ��߱�ʶ��], �Լ����������, �ֽ������
@@  �����еĲ�������Ϊָ������, ���Ļ�����������, ��������Ϊ�ѿռ����뿪��
**/


/**[�����޸���Ϣ]0.97
@@  �������еĳ���ṹ���������еľ�����Ϣ
    ��PUBLIC���������ƶ���.h�ļ�, ��PRIVATE���������ƶ���.c�ļ���
    �ṹ�������ĸ��£� ����ָ��ת�͵ľ�����Ϣ

**/


#ifndef BINARYTUPLE_H_INCLUDED
#define BINARYTUPLE_H_INCLUDED


#include "Config.h"     //  #include "..\Config\Config.h"


#include "TokenKind.h"    //  #include "..\Lexical\TokenKind.h"           // �ֱ���Ϣ
#include "..\Tools\Files.h"          // �ļ�����ӿ�
#include "..\Tools\Errors.h"


/// �궨�庯���Ķ��巽ʽ��Ϣ
#ifndef PUBLIC_and_PRIVATE
#define PUBLIC_and_PRIVATE
#
#define PUBLIC  extern          // �������Ա�������
#define PRIVATE static      // ����ֻ�ܱ����ļ��ĺ�������
#
#endif

/// 0.1.6֮ǰԭ���Ľṹ�嶨��
///// ���C���Դʷ���Ϣ�Ķ�Ԫ����
//typedef struct TupleNode
//{
//    Kind  m_kind;       /*�ֱ���*/
//    union Data
//    {
//        char *m_identifier;        // [��ʶ��]ָ����ű��б�ʶ����ַ��ָ��
//        char *m_constNum;               // ��������
//        char *m_fileName;           // �ļ���
//        int m_keyCode;              // [�ؼ���]�ؼ��ֵı���
//    }m_data;
//    struct TupleNode *m_next;      /*ָ����һ������ָ����*/
//}TupleNode;

/// 0.5.2֮ǰԭ���Ľṹ��Ķ���
/// �ʷ�������������Ϣ
typedef union TupleInfo
{
    char*               m_identifier;        // [��ʶ��]ָ����ű��б�ʶ����ַ��ָ��
    char*               m_constNum;               // ��������
    char*               m_fileName;           // �ļ���
    int                 m_keyCode;              // [�ؼ���]�ؼ��ֵı���
}TupleInfo;                          // size -=> 4B

/// ���C���Դʷ���Ϣ�Ķ�Ԫ����
typedef struct TupleData
{
    TokenKind           m_kind;        // �ʷ���Ϣ���ֱ���
    TupleInfo           m_data;        // �ʷ���Ϣ��������
    Coord               m_coord;       // �ʷ���Ԫ����б�ʶ
}TupleData;

/// ���C���Դʷ���Ϣ�Ķ�Ԫ����
typedef struct TupleNode
{
    TupleData           m_tuple;              // �ʷ���Ԫ����Ϣ

    struct TupleNode    *m_next;      // �ʷ���Ϣ��ָ����һ������ָ����
    struct TupleNode    *m_last;       // �ʷ�=��Ϣ��ָ����һ������ָ����
}TupleNode;

///0.5.4֮��Ķ���ʷ����
//typedef struct TupleNode
//{
//    TupleInfo          m_data;        // �ʷ���Ϣ��������
//    TokenKind          m_kind;        // �ʷ���Ϣ���ֱ���
//    Coord              m_coord;       // �ʷ���Ԫ����б�ʶ
//
//    char*               m_identifier;        // [��ʶ��]ָ����ű��б�ʶ����ַ��ָ��
//    char*               m_constNum;               // ��������
//    char*               m_fileName;           // �ļ���
//    int                 m_keyCode;              // [�ؼ���]�ؼ��ֵı���
//
//    struct TupleNode*   m_next;        // �ʷ���Ϣ��ָ����һ������ָ����
//}TupleNode;
////typedef struct TupleData
////{
////    TokenKind           m_kind;        // �ʷ���Ϣ���ֱ���
////    Coord               m_coord;       // �ʷ���Ԫ����б�ʶ
////
////    char*               m_identifier;        // [��ʶ��]ָ����ű��б�ʶ����ַ��ָ��
////    char*               m_constNum;               // ��������
////    char*               m_fileName;           // �ļ���
////    int                 m_keyCode;              // [�ؼ���]�ؼ��ֵı���
////}TupleData;
////
////typedef struct TupleNode
////{
//////    //TupleInfo          m_data;        // �ʷ���Ϣ��������
//////    TokenKind          m_kind;        // �ʷ���Ϣ���ֱ���
//////    Coord              m_coord;       // �ʷ���Ԫ����б�ʶ
//////
//////    char*               m_identifier;        // [��ʶ��]ָ����ű��б�ʶ����ַ��ָ��
//////    char*               m_constNum;               // ��������
//////    char*               m_fileName;           // �ļ���
//////    int                 m_keyCode;              // [�ؼ���]�ؼ��ֵı���
////    struct TupleData    m_data;
////    struct TupleNode    *m_next;        // �ʷ���Ϣ��ָ����һ������ָ����
////}TupleNode;

/// ���C���Դʷ���Ϣ�Ķ�Ԫ��
typedef TupleNode* BinaryTuple;


#define TUPLE_MAGIC_NUM "ctools.tup"    // �洢�ʷ���Ϣ��*.tup���ļ�ħ����Ϣ
#
#
#ifdef PUBLIC_and_PRIVATE
#
#
/// ��ʼ����Ԫ����Ϣ
PUBLIC BinaryTuple
InitTuple(
          const char* sourFile);
#define init_tuple  InitTuple
#
#
/// ��һ���ؼ�����Ϣ���뵽��Ԫ����
PUBLIC TupleNode*
InsertTupleKey(
               TupleNode *pNode,                   // ��ǰ�����ļ��Ķ�Ԫ����Ϣ���
               TokenKind kind,                     // ������ؼ��ֵ�����[�ؼ��֣������]
               int keyCode,                       // ������ؼ��ֵı�����Ϣ
               Coord *coord);                     // �ʷ���Ϣ��Դ�ļ��е�λ�ñ�ʶ
#define insert_tuple_key  InsertTupleKey
#
#
/// ��һ��������Ϣ���뵽��Ԫ����
PUBLIC TupleNode*
InsertTupleLiteral(
                   TupleNode    *pNode,                // ��ǰ�����ļ��Ķ�Ԫ����Ϣ���
                   char         *token,                    // ������ĳ����ַ���
                   Coord        *coord,                 // �ʷ���Ϣ��Դ�ļ��е�λ�ñ�ʶ
                   TokenKind     kind);                // ���ڱ�ʶ��ǰ������Ϣ��������

#define insert_tuple_literal  InsertTupleLiteral
#
#
/// ��һ����ʶ�����뵽��Ԫ����
PUBLIC TupleNode*
InsertTupleId(TupleNode     *pNode,                     // ��ǰ�����ļ��Ķ�Ԫ����Ϣ���
                char          *token,                          // ������ı�ʶ���ַ�����Ϣ
                Coord         *coord);                       // �ʷ���Ϣ��Դ�ļ��е�λ�ñ�ʶ
#define insert_tuple_id   InsertTupleId
#
#
PUBLIC TupleNode*
InsertEndToken(TupleNode *pNode);                       // �ڴʷ���Ԫ����������������ս��ʶ
#
#
/// �����ʷ���Ԫ����
PUBLIC void
VisitTuple(
           BinaryTuple douTuple);                   // ��Ԫ����Ϣ[��Ԫ�����ָ��ͷ]
#define visit_tuple VisitTuple                 // �ṩC������ʽ�ĺ������ýӿ�
#
#
/// ����ʷ���Ԫ����Ϣ
PUBLIC bool
DestroyTuple(
             BinaryTuple douTuple);
#define  destroy_tuple DestroyTuple                 // �ṩC������ʽ�ĺ������ýӿ�
#
#
/// ���ʷ���Ԫ����Ϣ���ȥ�ƶ����ļ���
PUBLIC void
WriteTupleFile(
               BinaryTuple douTuple,
               char *fname);           // ������Ĵʷ��ļ�
#define wrire_tuple_file    WriteTupleFile       // �ṩC������ʽ�ĺ������ýӿ�
#
#
/// ��ָ���ļ��ж�ȡ�ʷ���Ԫ����Ϣ
PUBLIC BinaryTuple
ReadTupleFile(char *fname);           // ������Ĵʷ��ļ�
#define read_tuple_file    WriteTupleFile       // �ṩC������ʽ�ĺ������ýӿ�
#
#
#
#
/// ���ÿ����Ԫ��Node������Ϣ
PUBLIC void
ShowNode(
         TupleNode *pNode);                         // ��Ԫ����Ϣ[��Ԫ����ָ��]
#define  show_node   ShowNode                   // �ṩC������ʽ�ĺ������ýӿ�
#
#
// ���ÿ����Ԫ��Node������������Ϣ
PUBLIC void
ShowTupleData(
                   TupleNode *pNode);
#
#
// ����pNodeΪ��ʼ�Ĵʷ���Ԫ�������У������ҵ�����Ϊ�ս��treinal�Ľ��
PUBLIC TupleNode*
FindFirstTupleTreinal(
                 TupleNode *headTupleNode,          // ��ʼ�Ĵʷ�����ָ��
                 TokenKind treinal);        // �ս����Ϣ
#
#
// ����pNodeΪ��ʼ�Ĵʷ���Ԫ�������У� ������ҵ��ҵ���count������Ϊ�ս��terinal�Ľ��
PUBLIC TupleNode*
FindTupleTreinal(
                 TupleNode *headTupleNode,          // ��ʼ�Ĵʷ�������ָ��
                 TokenKind terinal,         // �����ҵ��ս����Ϣ
                 int count);                 // �����ҵ��ս���������е�count���ս��
#
#
// ��pNode��β�Ĵʷ���Ԫ�鴮�У�������ҵ���һ��������terinal�Ĵʷ���Ԫ����
PUBLIC TupleNode*
ReFindFirstTupleTreinal(TupleNode *finalTupleNode,           // ��β�Ĵʷ����ָ��
                        TokenKind terinal);         // �����ҵ��ս����Ϣ
#
#
// ����pNode��β�Ĵʷ���Ԫ��������, �ҵ���count��������terinal�Ĵʷ���Ԫ��
PUBLIC TupleNode*
ReFindTupleTreinal(TupleNode *finalTupleNode,       // ��β�Ĵʷ����ָ��
                   TokenKind terinal,      // �����ҵ��ս����Ϣ
                   int count);              // �����ҵ��ս���������е�count���ս��
#
#
// �жϵ�ǰ����ǲ���Ԥ����ָ��
PUBLIC bool
IsProComTupleNode(
                        TupleNode *tupleNode);
#endif


#endif // TUPLE_H_INCLUDED




