#ifndef GRAMMAR_H_INCLUDED
#define GRAMMAR_H_INCLUDED

#include "Config.h"     //  #include "..\Config\Config.h"

#include "TokenKind.h"    //  #include "..\Lexical\TokenKind.h"
#include "SyntaxKind.h"    //  #include "SyntaxKind.h"    //  #include "..\Parser\SyntaxKind.h"




/// ����ʽ��
typedef SyntaxKind  LeftGrammar;
///����ʽ�Ҳ�
typedef struct  RightGrammar        // ����ʽ���Ҳ�
{
    union RightGrammarData                   // ����ʽ���Ҳ����������ս�������ķ�����
    {
        SyntaxKind  m_Syntax;           // �ķ����ŵ���Ϣ
        TokenKind   m_token;            // �ս���ŵ���Ϣ
    }m_data;

    enum  RightGrammarFlag                  // ���ڱ�ʶ����ʽ�Ҳ���ǰλ�����ķ����Ż����ս����
    {
        IS_SYNTAX_DATA,                   // ������ǰλ�����ķ�����
        IS_TOKENS_DATA,                   // ������ǰλ�����ս����
        IS_NULL_DATA,
    }m_flag;

}RightGrammar;




///  �ķ��ṹ��
typedef struct Grammar
{
	int				m_grammarId;		// ���ķ�����ʽ�ı��
    int             m_rightLength;      //  ����ʽ�Ҳ��ĳ���
    LeftGrammar     m_left;             //  �ķ��󲿵ķ�����Ϣ
    RightGrammar    m_right[9];            // ����ʽ�Ҳ�����Ϣ
}Grammar;



/// Literal�ĺ�����������
#ifdef PUBLIC_and_PUBLIC
#
#
PUBLIC int                  // ���ص�ǰ��Ų���ʽ�Ҳ��ĳ���
RightGrammarLength(
                   int id);         // �ķ�����ʽ�ı��
#
#
PUBLIC SyntaxKind           // ���ص�ǰid��Ų���ʽ������Ϣ
LeftGrammarData(
            int id);                //  �ķ�����ʽ�ı��
#
#
#endif





//

#endif // GRAMMAR_H_INCLUDED
