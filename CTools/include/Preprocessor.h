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


/*
������
    PreprocessorΪCTools�ṩ��Ԥ�������Ľӿ���Ϣ
*/


#ifndef PREPROCESSOR_H_INCLUDED
#define PREPROCESSOR_H_INCLUDED

#include "..\Tools\Buffer.h"



// ϵͳͷ�ļ�·���ĺ궨����Ϣ
#define SYS_INCLUDE_PATH_DIR "D:/SoftwareEngineer/MinGW32/include"


/// �궨�庯���Ķ��巽ʽ��Ϣ
#ifndef PUBLIC_and_PRIVATE
#define PUBLIC_and_PRIVATE
#
#define PUBLIC  extern          // �������Ա�������
#define PRIVATE static      // ����ֻ�ܱ����ļ��ĺ�������
#
#endif



/// Preprocessor��������
#ifdef PUBLIC_and_PRIVATE
#
#
/// Ԥ������
PUBLIC bool                            // ����Ԥ�����Ƿ�ɹ�
Processor(
          char *destFile,           // �������Ŀ���ļ�-=>Ԥ����Դ�ļ�
          char *sourFile);          // ������Դ�ļ����ƻ���·��
#
#
#endif          // PUBLIC_and_PRIVATE











#endif // PREPROCESSOR_H_INCLUDED
