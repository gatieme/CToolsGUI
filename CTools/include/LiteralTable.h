/**
*********************************************************************************
*   CopyRight  : 2013-2014, HerBinUnversity, GatieMe                            *
*   File Name  : main.c                                                         *
*   Description: CTools                                                         *
*   Author     : Gatie_Me                                                       *
*   Version    : Copyright 2013-2014                                            *
*   Data_Time  : 2013-3-10 21:29:24                                             *
*   Content    : CTools-Lexical                                                 *
*********************************************************************************
**/





#ifndef LITERALTABLE_H_INCLUDED
#define LITERALTABLE_H_INCLUDED



#include "..\Lexical\TokenKind.h"


#define UNKNOWVALUE -1
#define CON_ERROR   -1    // ��������

/// �궨�庯���Ķ��巽ʽ��Ϣ
#ifndef PUBLIC_and_PRIVATE
#define PUBLIC_and_PRIVATE
#
#define PUBLIC  extern          // �������Ա�������
#define PRIVATE static      // ����ֻ�ܱ����ļ��ĺ�������
#
#endif



/*typedef struct Literal
{
    Kind m_kind;          // ��ʶ��ǰ����������Ϣ���ֱ�
//    union               // ��ʶ�������ݵ�������
//    {
//        int m_intValue;             // ����
//        long m_longValue;           // ������
//        long long m_llongValue;     // ��������
//
//        float m_floatValue;         // ����������
//        double m_douValue;          // ˫���ȸ���������
//        long double m_ldouValue;    // ��˫���ȸ���������
//        char m_charValue;           // �ַ�����
//        //wchar_t m_wcharValue;       // ���ַ�����
//        char *m_strValue;              // �ַ�������
//    }m_data;            // ������Ϣ
    char *m_data;         // ������Ϣ
    int m_offset;               // ��Ե�ַ
    struct Literal *m_next;   // ָ����һ����Ϣ�ĵ�ַ��ָ��
}Literal;*/


typedef struct Literal
{
    TokenKind       m_kind;          // ��ʶ��ǰ����������Ϣ���ֱ�
    char*           m_data;         // ������Ϣ
    int             m_offset;               // ��Ե�ַ
    struct Literal* m_next;   // ָ����һ����Ϣ�ĵ�ַ��ָ��
}Literal;


// ������Ϊһ��������Ϣ
/// ���ű����ݽṹ[HashTable]
//typedef struct LiteralTable
//{
//    Literal **m_hashTable;        // ���Ź�ϣ��
//}LiteralTable;       // ���ű�
typedef Literal** LiteralTable;





#ifdef PUBLIC_and_PRIVATE
#
#
// ����ʾtoken��ӽ�����ű�
PUBLIC Literal*
InsertLiteralToken(char *token,
                   LiteralTable literTable);
#define insert_literal_token  InsertLiteralToken
#
#
// ��ѯtoken�Ƿ��ڷ��ű���
PUBLIC Literal*
FindLiteralToken(char *token,
                 LiteralTable literTable);
#define find_literal_token    FindLiteralToken
#
#
#endif


#endif // LITERALTABLE_H_INCLUDED
