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
����
    ParserΪCTools�������ṩ�ʷ�����Ĵ���ӿ�
*/


#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED



#include "Syntax.h"


//#ifdef PROP_REDUCTION_DEFINE
#include "Prop.h"
#include "PropRed.h"
#include "PropTable.h"
//#endif // PROP_REDUCTION_DEFINE


/// �궨�庯���Ķ��巽ʽ��Ϣ
#ifndef PUBLIC_and_PRIVATE
#define PUBLIC_and_PRIVATE
#
#define PUBLIC  extern          // �������Ա�������
#define PRIVATE static      // ����ֻ�ܱ����ļ��ĺ�������
#
#endif



#ifdef PUBLIC
#
#
PUBLIC SyntaxTree                                  // �﷨�����Ƿ�ͨ��
ParseTuple(
           BinaryTuple douTuple);       // �ʷ���Ԫ����Ϣ
#
#
PUBLIC SyntaxTree                                // �﷨�����Ƿ�ͨ��
ParseFile(
          const char *sourFile);          // Դ�ļ�����
#
#
/// ��douTuple�����﷨����, ͬʱ���в�׮������׮���д��destFname
PUBLIC SyntaxTree
ParseTuplePropRed(
                  BinaryTuple douTuple,
                  const char *destFname);       // �ʷ���Ԫ����Ϣ
#
#
/// ���ļ�fileName�����﷨����, ͬʱ���в�׮����
PUBLIC SyntaxTree
ParseFilePropRed(const char *destFileName,
                 const char *srcFileName);          // Դ�ļ�����
#
#
/// 0.6.0����
/// �﷨����ʱ����Ҫ��Ԥ����ָ������
/// ��������Ԥ�����������
PUBLIC TupleNode*
SkipProComTupleNode(
                    TupleNode *tupleNode);
#endif  // PUBLIC



#endif // PARSER_H_INCLUDED





