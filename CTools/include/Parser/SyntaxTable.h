/***********************************************************************************
*   CopyRight  : 2013-2014, HerBinUnversity, GatieMe
*   File Name  : Buffer.h
*   Description: CTools-SyntacicParser
*   Author     : Gatie_Me
*   Version    : Copyright 2013-2014
*   Data_Time  : 2013-3-10 21:29:24
*   Content    : CTools-Lexical
***********************************************************************************/


/*
������
    SyntaxTable�������﷨�����׶δ洢LR(1)�﷨������
*/


#ifndef SYNTAXTABLE_H_INCLUDED
#define SYNTAXTABLE_H_INCLUDED


#include "Config.h"     //  #include "..\Config\Config.h"

#include "TokenKind.h"    //  #include "..\Lexical\TokenKind.h"
#include "SyntaxKind.h"    //  #include "..\Parser\SyntaxKind.h"
#include "BinaryTuple.h"   //  #include "..\Lexical\BinaryTuple.h"
/// �궨�庯���Ķ��巽ʽ��Ϣ
#ifndef PUBLIC_and_PRIVATE
#define PUBLIC_and_PRIVATE
#
#define PUBLIC  extern          // �������Ա�������
#define PRIVATE static      // ����ֻ�ܱ����ļ��ĺ�������
#
#endif



#define RECEIVE_SIZE





/// ����ָʾ��ʶ
typedef enum ActionFlag
{
    ACTION_NULL =   -2,
    ERRORS      =   -1,         // ������Ϣ
    ACCEPT      =    0,          // �ƽ�
    MOVING      =    1,         // �ƽ�
    REDUCTION   =    2,      // ��Լ
}ActionFlag;




typedef struct ActionNode
{
    //int     state;                    // ��ǰ״̬
    TokenKind       m_received;             // ��ǰ��ȡ�ʷ���Ϣ
    ActionFlag      m_action;               // ת��MOVE״̬
    SyntaxKind      m_nonter;               // ��ȡ�ƽ����ս���Ϣ
    State           m_actState;             //  �ƽ���ת�Ƶ���״̬
}ActionNode;



typedef struct GoToNode
{
    //int             m_state;            // ��ǰ״̬
    SyntaxKind 	    m_receive;          // ��ǰ��ȡ
    State 	        m_gotoState;             // ��ת������״̬
}GoToNode;

/// Literal�ĺ�����������
#ifdef PUBLIC_and_PUBLIC
#
#
// ACTION���������﷨���������Ϣ
PUBLIC ActionNode*                  // ����ָ������Ϣ��ָ��
ACTION(
       State state,                 // ��ǰ״̬
       TupleNode *tupleNode);       // ��ȡ���Ĵʷ���Ϣ
// ACTION���������﷨���������Ϣ
PUBLIC GoToNode*                    // ����ָ��gotoTable��ָ��
GOTO(
     int state,                     // ��ǰ״̬
     SyntaxKind  receive);          // ��ǰ�������ķ�����
#
#

#endif


#endif // SYNTAXTABLE_H_INCLUDED
