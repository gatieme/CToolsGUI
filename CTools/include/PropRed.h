/***********************************************************************************
*   CopyRight  : 2013-2014, HerBinUnversity, GatieMe
*   File Name  : RedProp.h
*   Description: CTools
*   Author     : Gatie_Me
*   Version    : Copyright 2013-2014
*   Data_Time  : 2013-11-27 14:27:30
*   Content    : CTools-Lexical
***********************************************************************************/

#ifndef REDPROP_H_INCLUDED
#define REDPROP_H_INCLUDED


#include "Prop.h"
#include "PropTable.h"


/// �궨�庯���Ķ��巽ʽ��Ϣ
#ifndef PUBLIC_and_PRIVATE
#define PUBLIC_and_PRIVATE
#
#define PUBLIC  extern          // �������Ա�������
#define PRIVATE static      // ����ֻ�ܱ����ļ��ĺ�������
#
#endif


// ���涨�������ÿ������ʽ�Ĳ�׮����
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef PUBLIC_and_PRIVATE
#
#
// ��ʼ����׮��Ϣ
// ����������ļ�, ������ļ�����Ӳ�׮Ԥ����ͷ
PUBLIC void
InitProp(
              CToolsFILE destFp,
              const char *srcFname);
#
#
// ���յ�0������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction0(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�1������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction1(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�2������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction2(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�3������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction3(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�4������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction4(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�5������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction5(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�6������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction6(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�7������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction7(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�8������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction8(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�9������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction9(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�10������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction10(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�11������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction11(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�12������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction12(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�13������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction13(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�14������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction14(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�15������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction15(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�16������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction16(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�17������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction17(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�18������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction18(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�19������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction19(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�20������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction20(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�21������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction21(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�22������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction22(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�23������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction23(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�24������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction24(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�25������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction25(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�26������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction26(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�27������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction27(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�28������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction28(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�29������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction29(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�30������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction30(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�31������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction31(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�32������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction32(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�33������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction33(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�34������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction34(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�35������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction35(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�36������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction36(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�37������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction37(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�38������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction38(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�39������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction39(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�40������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction40(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�41������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction41(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�42������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction42(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�43������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction43(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�44������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction44(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�45������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction45(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�46������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction46(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�47������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction47(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�48������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction48(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�49������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction49(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�50������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction50(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�51������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction51(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�52������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction52(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�53������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction53(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�54������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction54(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�55������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction55(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�56������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction56(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�57������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction57(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�58������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction58(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�59������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction59(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�60������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction60(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�61������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction61(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�62������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction62(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�63������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction63(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�64������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction64(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�65������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction65(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�66������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction66(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�67������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction67(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�68������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction68(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�69������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction69(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�70������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction70(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�71������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction71(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�72������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction72(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�73������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction73(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�74������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction74(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�75������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction75(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�76������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction76(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�77������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction77(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�78������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction78(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�79������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction79(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�80������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction80(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�81������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction81(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�82������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction82(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�83������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction83(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�84������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction84(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�85������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction85(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�86������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction86(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�87������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction87(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�88������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction88(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�89������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction89(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�90������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction90(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�91������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction91(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�92������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction92(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�93������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction93(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�94������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction94(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�95������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction95(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�96������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction96(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�97������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction97(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�98������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction98(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�99������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction99(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�100������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction100(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�101������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction101(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�102������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction102(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�103������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction103(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�104������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction104(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�105������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction105(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�106������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction106(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�107������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction107(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�108������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction108(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�109������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction109(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�110������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction110(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�111������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction111(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�112������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction112(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�113������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction113(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�114������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction114(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�115������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction115(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�116������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction116(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�117������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction117(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�118������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction118(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�119������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction119(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�120������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction120(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�121������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction121(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�122������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction122(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�123������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction123(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�124������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction124(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�125������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction125(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�126������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction126(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�127������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction127(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�128������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction128(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�129������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction129(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�130������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction130(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�131������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction131(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�132������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction132(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�133������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction133(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�134������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction134(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�135������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction135(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�136������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction136(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�137������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction137(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�138������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction138(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�139������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction139(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�140������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction140(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�141������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction141(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�142������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction142(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�143������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction143(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�144������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction144(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�145������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction145(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�146������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction146(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�147������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction147(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�148������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction148(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�149������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction149(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�150������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction150(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�151������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction151(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�152������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction152(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�153������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction153(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�154������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction154(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�155������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction155(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�156������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction156(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�157������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction157(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�158������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction158(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�159������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction159(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�160������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction160(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�161������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction161(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�162������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction162(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�163������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction163(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�164������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction164(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�165������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction165(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�166������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction166(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�167������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction167(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�168������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction168(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�169������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction169(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�170������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction170(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�171������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction171(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�172������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction172(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�173������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction173(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�174������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction174(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�175������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction175(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�176������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction176(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�177������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction177(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�178������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction178(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�179������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction179(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�180������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction180(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�181������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction181(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�182������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction182(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�183������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction183(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�184������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction184(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�185������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction185(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�186������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction186(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�187������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction187(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�188������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction188(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�189������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction189(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�190������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction190(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�191������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction191(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�192������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction192(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�193������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction193(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�194������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction194(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�195������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction195(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�196������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction196(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�197������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction197(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�198������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction198(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�199������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction199(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�200������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction200(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�201������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction201(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�202������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction202(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�203������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction203(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�204������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction204(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�205������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction205(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�206������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction206(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�207������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction207(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�208������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction208(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�209������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction209(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�210������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction210(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�211������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction211(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�212������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction212(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�213������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction213(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�214������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction214(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�215������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction215(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�216������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction216(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�217������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction217(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�218������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction218(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�219������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction219(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�220������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction220(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�221������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction221(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�222������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction222(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�223������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction223(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�224������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction224(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�225������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction225(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�226������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction226(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�227������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction227(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�228������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction228(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�229������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction229(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�230������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction230(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�231������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction231(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
// ���յ�232������ʽ��Լʱ���ݹ�Լ�������﷨����ִ�еĲ�׮����
PUBLIC void
PropReduction232(
                 PropTable propTable,      // ��׮��Ϣ��
                 SyntaxTree parentRoot);  // ����׮���﷨��
#
#
#endif          // PUBLIC_and_PRIVATE



#endif // REDPROP_H_INCLUDED
