/**
*********************************************************************************
*   CopyRight  : 2013-2014, HerBinUnversity, GatieMe                            *
*   File Name  : SymbolTable.h                                                  *
*   Description: CTools                                                         *
*   Author     : Gatie_Me                                                       *
*   Version    : Copyright 2013-2014                                            *
*   Data_Time  : 2013-3-10 21:29:24                                             *
*   Content    : CTools-Lexical                                                 *
*********************************************************************************
**/

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


#ifndef SYMBOLTABLE_H_INCLUDED
#define SYMBOLTABLE_H_INCLUDED


#include "TokenKind.h"    //  #include "..\Lexical\TokenKind.h"



#define UNKNOWVALUE -1

/// �궨�庯���Ķ��巽ʽ��Ϣ
#ifndef PUBLIC_and_PRIVATE
#define PUBLIC_and_PRIVATE
#
#define PUBLIC  extern          // �������Ա�������
#define PRIVATE static      // ����ֻ�ܱ����ļ��ĺ�������
#
#endif


///  �������ݽṹ
typedef struct Identifier
{
    char                *m_name;               // ָ��NameTable��ָ��[��ŵ�ǰ����������]//1
    TokenKind            m_kind;                // ���ŵ�����[�������������β�]//
    int                  m_offset;               // ��Ե�ַ
    void                *m_expand;             // ��չָ��[]
    struct Identifier   *m_next;   // ָ����һ����Ϣ�ĵ�ַ��ָ��
}Identifier;                    // ����-ʶ����


// �궨����ű�Ŀ��
#define BUCKETS 27      // 27����ȶ�Ӧ26��Ӣ����ĸ + '_'
// Ҳ����˵�˹�ϣ���ǰ���Ӣ����ĸ��ʼ�����Ĳ��ִ�Сд


/// ���ű����ݽṹ[HashTable]
//typedef struct SymbolTable
//{
//    Identifier **m_hashTable;        // ���Ź�ϣ��
//}SymbolTable;       // ���ű�
typedef Identifier**    SymbolTable;       // ���ű���Ϣ



#ifdef PUBLIC_and_PRIVATE
#
#
// ��ʼ����ϣ����Ϣ
PUBLIC SymbolTable
InitSymbolTalbe(
                SymbolTable /*__attribute__((unused))*/ symbolTable);
#
/// ����ʾtoken��ӽ�����ű�
PUBLIC Identifier*                      // ���ز���ı�ʶ����Ϣ�ڷ��ű��е�ָ��
InsertSymbolToken(char *token,                // ����������Ҫ������ַ�����Ϣ
            SymbolTable symbolTable);   //  ���ű���Ϣ
#
/// ��ѯtoken�Ƿ��ڷ��ű���
PUBLIC Identifier*                      // ���token�ڷ��ű���, ����ָ���ʶ����Ϣ��ָ�룬���򷵻�NULL
FindSymbolToken(char *token,                  // ����������Ҫ������ַ�����Ϣ
          SymbolTable symbolTable);     //  ���ű���Ϣ
#
PUBLIC void
ShowSymbolList(Identifier *idenList);   // ���ÿ����ϣ���������Ϣ
#
PUBLIC void
VisitSymbolTable(SymbolTable symbolTable);  // ������ű����Ϣ
#
#endif



#endif // SYMBOLTABLE_H_INCLUDED
