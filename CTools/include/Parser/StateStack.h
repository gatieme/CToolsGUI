/**
*********************************************************************************
*   CopyRight  : 2013-2014, HerBinUnversity, GatieMe                            *
*   File Name  : Buffer.h                                                       *
*   Description: CTools-SyntacicParser                                          *
*   Author     : Gatie_Me                                                       *
*   Version    : Copyright 2013-2014                                            *
*   Data_Time  : 2013-3-10 21:29:24                                             *
*   Content    : CTools-Lexical                                                 *
*********************************************************************************
**/


/*
������
    SatetSatck����ջ������LR�﷨�����׶δ洢�﷨״̬�Ĵʷ���Ϣ
*/


#ifndef STATESTACK_H_INCLUDED
#define STATESTACK_H_INCLUDED





#include "Config.h"     //  #include "..\Config\Config.h"


/// �궨�庯���Ķ��巽ʽ��Ϣ
#ifndef PUBLIC_and_PRIVATE
#define PUBLIC_and_PRIVATE
#
#define PUBLIC  extern          // �������Ա�������
#define PRIVATE static      // ����ֻ�ܱ����ļ��ĺ�������
#
#endif



typedef struct StateNode
{
    State               m_state;            // ջ�е�����
    struct StateNode*    m_next;   // ��һ������ָ��
}StateNode;



typedef struct StateStack
{
    StateNode*          m_top; // ջ����Ϣ
    int                 m_count;        // Ԫ�ظ�����Ϣ��ʶ
}StateStack;



#ifdef PUBLIC_and_PRIVATE
#
#
/// ��ʼ��stackջ��Ϣ
PUBLIC StateStack*           // ���ؽ�����ռ�ռ�ĵ�ַ
CreateStateStack( );
#
/// Stack����β����
PUBLIC void
FinitStateStack(StateStack *stack);   // ���ͷָ����Ϣ
#
/// ����Stackջ��Ϣ
PUBLIC void
DestroyStateStack(StateStack *stack); // �����ٵ�ջ��Ϣ
#
/// ��Ԫ��elemѹ��ջ��
PUBLIC bool             // ѹ��ɹ�����ʧ��
PushState(StateStack *stack,  // ջ��Ϣ
     State elem);    // Ҫѹ���������Ϣ
#
/// ��ջ�����ݵ���
PUBLIC State           // �����ɹ�����ʧ��
PopState(
         StateStack *stack);   // ջ��Ϣ
#
/// ��ջ�����ݵ���
PUBLIC void             // �����ɹ�����ʧ��
PopedState(
           StateStack *stack,   // ջ��Ϣ
           int count);     // Ҫ���������ݵĸ���
#
/// pandaun��ǰջ�ǲ��ǿ�ջ
PUBLIC bool           // �����ɹ�����ʧ��
EmptyStateStack(
                StateStack *stack);   // ջ��Ϣ
#
/// ����ջ����������Ϣ
PUBLIC State
TopState(
         StateStack *stack);  // ����ջ��ջ������
#
PUBLIC State
NextState(
          StateStack *stack); // ����ջ��Ԫ�ص���һ��Ԫ�ص���Ϣ
#
#
/// ��ʾ��ǰ״̬ջ�е�������Ϣ
PUBLIC void
ShowStateStack(
               StateStack *stack);      // ����ʾ��״̬ջ������
#
#
#endif



#endif // STATESTACK_H_INCLUDED
