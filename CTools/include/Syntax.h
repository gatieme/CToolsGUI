#ifndef SYNTAX_H_INCLUDED
#define SYNTAX_H_INCLUDED


#include "Config.h"         //  #include "..\Config\Config.h"

#include "Lexical.h"        //  #include "..\Lexical\Lexical.h"

#include "BinaryTuple.h"    //  #include "..\Lexical\BinaryTuple.h"            // �ʷ���Ԫ��

#include "StateStack.h"     //  #include "..\Parser\StateStack.h"

#include "SyntaxTable.h"    //  #include "..\Parser\SyntaxTable.h"
#include "Grammar.h"        //  #include "..\Parser\Grammar.h"





/// �궨�庯���Ķ��巽ʽ��Ϣ
#ifndef PUBLIC_and_PRIVATE
#define PUBLIC_and_PRIVATE
#
#define PUBLIC  extern          // �������Ա�������
#define PRIVATE static      // ����ֻ�ܱ����ļ��ĺ�������
#
#endif





/// ���ڱ�ʶ��ǰ�ڵ���Ϣ���͵�������
typedef enum SyntaxTreeKind
{
    SYNTAX_TREE_NULL                    =   00,
    SYNTAX_TERR_STARTER                 =   01,               // �ķ���ʼ���� [��ʼ����]
    SYNTAX_TERR_VARIBALE                =   02,               // �﷨����     [���ս����]
    SYNTAX_TERR_TERINAL                 =   03,                // �﷨�ս���� [�ս����]
}SyntaxTreeKind;


typedef union SyntaxTreeInfo
{
    TupleNode*              m_tupleNode;        // �ս�����ָ���
    SyntaxKind              m_syntaxKind;          // ��ǰ�����Ϣ���﷨����
}SyntaxTreeInfo;


typedef struct SyntaxData
{
    SyntaxTreeKind          m_kind;                 // ��ʶ��ǰ����������
    // ���kind == SYN_ANA_TERR_VARIBALE, ��m_data == m_synaAna
    // ���kind == SYN_ANA_TERR_TERINAL,  ��m_data == m_tupleNode
    SyntaxTreeInfo          m_data;                 // �﷨��������������Ϣ
    Coord                   m_startCoord;                // ��ǰ�﷨��Ϣ�Ŀ�ʼλ��
    Coord                   m_endCoord;                  // ��ǰ�﷨��Ϣ�Ľ���λ��
    //Coord                   m_coord;                // �﷨������λ����Ϣ
}SyntaxData;




/// �﷨���
typedef struct SyntaxTreeNode
{
    // �﷨���������
    SyntaxData           m_syntax;           // �﷨�����������������Ϣ

    // �﷨��ָ������Դ
    struct SyntaxTreeNode*  m_parent;           // ָ���׽���ָ����
    struct SyntaxTreeNode*  m_firstChild;       // ָ���ӽ���ָ����
    struct SyntaxTreeNode*  m_rightBrother;     // ָ���ұߵ�һ���ֵ�
    struct SyntaxTreeNode*  m_finalChild;       // ָ�����һ�����ӽ���ָ����
    struct SyntaxTreeNode*  m_leftBrother;      // ָ����ߵ�һ���ֵܽ��

    // �﷨ջ�����﷨����������
    struct SyntaxTreeNode*  m_next;             // ָ����һ������������
}SyntaxTreeNode, SyntaxStackNode, SyntaxQueueNode;


typedef SyntaxTreeNode*           Syntax;                   // �﷨��Ϣ
typedef SyntaxTreeNode*           SyntaxTree;             // �﷨������

/// �﷨����ջ
typedef struct SyntaxStack
{
    SyntaxStackNode*     m_top; // ջ����Ϣ
    int                  m_count;        // Ԫ�ظ�����Ϣ��ʶ
}SyntaxStack;

/// �﷨����������
typedef struct SyntaxQueue
{
    SyntaxQueueNode     *m_front;           // �﷨����ͷ
    SyntaxQueueNode     *m_rear;            // �﷨����β
    int                  m_count;          // �﷨����
}SyntaxQueue;

#ifdef PUBLIC_and_PRIVATE
#
#
/// �﷨����ջ������Ϣ-BEGIN/////////////////////////////////////////////////////////////////////////////////////////////////////
/// ��ʼ��stackջ��Ϣ
PUBLIC SyntaxStack*           // ���ؽ�����ռ�ռ�ĵ�ַ
CreateSyntaxStack( );
#
#
/// Stack����β����
PUBLIC void
FinitSyntaxStack(SyntaxStack *stack);   // ���ͷָ����Ϣ
#
#
/// ����Stackջ��Ϣ
PUBLIC void
DestroySyntaxStack(SyntaxStack *stack); // �����ٵ�ջ��Ϣ
#
#
/// ���ʷ���Ϣ���ѹ��ջ��
PUBLIC bool
PushTupleInSyntaxStack(                      // ���ʷ���Ϣ���ѹ��ջ��
                      SyntaxStack *stack,   // �﷨����ջ
                      TupleNode *pNode);    // �ʷ���Ϣ�Ľ��
#
#
/// ���﷨����ѹ�����ջ��
PUBLIC bool
PushGrammarInSyntaxStack(                     // ���﷨����ѹ�����ջ��
                        SyntaxStack *stack,  // �����ջ����Ϣ
                        SyntaxKind kind);    // �﷨������Ϣ
#
#
/// ��Ԫ��elemѹ��ջ��
PUBLIC bool             // ѹ��ɹ�����ʧ��
PushSyntax(SyntaxStack *stack,  // ջ��Ϣ
     Syntax syntax);    // Ҫѹ���������Ϣ
#
#
/// ��ջ�����ݵ���
PUBLIC bool           // �����ɹ�����ʧ��
PopSyntax(SyntaxStack *stack);   // ջ��Ϣ
#
#
/// ��ջ�����ݵ���
PUBLIC void             // �����ɹ�����ʧ��
PopedSyntax(SyntaxStack *stack,   // ջ��Ϣ
    int count);     // Ҫ���������ݵĸ���
#
#
/// pandaun��ǰջ�ǲ��ǿ�ջ
PUBLIC bool           // �����ɹ�����ʧ��
EmptySyntaxStack(SyntaxStack *stack);   // ջ��Ϣ
#
#
/// ����ջ����������Ϣ
PUBLIC Syntax
TopSyntax(SyntaxStack *stack);  // ����ջ��ջ������
#
#
/// ����ջ������һ��������Ϣ
PUBLIC Syntax
NextSyntax(SyntaxStack *stack);
#
#
/// ��ȡջ��ջ��step��Ԫ�ص�������Ϣ
PUBLIC Syntax
GetSyntax(SyntaxStack *stack,
           int step);           // ����ջ��Ԫ�ص���һ��Ԫ�ص���Ϣ
#
#
/// �﷨����ջ������Ϣ-ENDLS/////////////////////////////////////////////////////////////////////////////////////////////////////
///
///
///
///
/// �﷨������������Ϣ-NEGIN/////////////////////////////////////////////////////////////////////////////////////////////////////
/// ���ݵ�id���ķ���Ϣ�����﷨����
/// ��ʼ���﷨���
PUBLIC SyntaxTree
CreateSyntaxTree( );
#
#
/// �����﷨������
PUBLIC void
DestroySyntaxTree(
                  SyntaxTree root);
#
#
PUBLIC void
DeleteSyntaxTreeNode(
                     SyntaxTreeNode *node);
#
#
PUBLIC SyntaxTree
InsertSyntaxTree(
           SyntaxStack *stack,           // �﷨����ջ
           int id);                     // ��Լ���ķ�����ʽ���
#
#
// ��ȡ��rootΪ�����﷨���ĸ߶�
PUBLIC int
GetSyntaxTreeHeight(
                    SyntaxTree root);       // �﷨���ĸ�
#
#
// ��ȡ��rootΪ�����﷨���Ľ�����
PUBLIC  int
GetSyntaxTreeNodeCount(
                       SyntaxTree root);      // �﷨���ĸ�
#
#
// ���������rootΪ�����﷨��
PUBLIC void
PreOrderSytaxTree(
                  SyntaxTree root);                 // �﷨���ĸ�

#
#
// ���������rootΪ�����﷨��
PUBLIC void
InOrderSyntaxTree(
                  SyntaxTree root);                 // �﷨���ĸ�
#
#
// ���������rootΪ�����﷨��
PUBLIC void
PostOrderSyntaxTree(SyntaxTree root);                   //  �﷨���ĸ�
#
#
// ��ʾ��ǰ�﷨��Ϣ��ֵ
PUBLIC void
ShowSyntaxTreeNode(
                   SyntaxTreeNode *pNode);                        // ��ʾ��ǰ�﷨������ֵ
#
#
// ����������﷨����done����
PUBLIC void
InOrderDoneSyntaxTree(
                        SyntaxTree root,                        // �﷨���ĸ�
                        void (*Done)(void *));                  // ϣ����ȡ�Ĳ���
#
#
// ����parentRootΪ�����﷨�������ҵ��ս��treinal��λ��
PUBLIC TupleNode*
FindFirstSyntaxTreeTreinal(
                           SyntaxTree parentRoot,
                           TokenKind treinal);
#
#
// ����parentRootΪ�����﷨�������ҵ���һ��Ҷ�ӽڵ�Ĵʷ����ָ����
PUBLIC TupleNode*
FindFirstChildTuple(
                    SyntaxTree parentRoot);
#
#
// ����parentRootΪ�����﷨�������ҵ���һ�����ս����Ҷ�ӽڵ�
PUBLIC SyntaxTreeNode*
FindFirstChildTreeNode(
                       SyntaxTree parentRoot);
#
#
// ����parentRootΪ�����﷨�������ҵ����һ�����ս����Ҷ�ӽڵ�
PUBLIC SyntaxTreeNode*
FindFinalChildTreeNode(
                        SyntaxTree parentRoot);
#
#
// ����parentRootΪ�����﷨�������ҵ���һ�����ս����Ҷ�ӽڵ�
PUBLIC TupleNode*
FindFinalChildTupleNode(
                        SyntaxTree parentRoot);
/// �﷨������������Ϣ-ENDLS/////////////////////////////////////////////////////////////////////////////////////////////////////
///
///
///
///
/// �﷨����ջ������Ϣ-BEGIN/////////////////////////////////////////////////////////////////////////////////////////////////////
#
#
// ��ʼ����ǰ�﷨����
PUBLIC SyntaxQueue*
CreateSyntaxQueue( );
#
#
// �жϵ�ǰ�﷨�����Ƿ�Ϊ��
PUBLIC bool
EmptySyntaxQueue(SyntaxQueue *queue);
#
#
// ���﷨����ѹ���﷨����
PUBLIC void
InSyntaxQueue(SyntaxQueue *queue,
              SyntaxTreeNode *node);
#
#
// ���﷨���ݵ����﷨����
PUBLIC SyntaxTreeNode*
OutSyntaxQueue(
               SyntaxQueue *queue);                 // �﷨����
#
#
#endif      // PUBLIC_and_PRIVATE





#endif // SYNTAX_H_INCLUDED
