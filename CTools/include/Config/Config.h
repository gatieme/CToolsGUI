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



#ifndef _CONFIG_H_INCLUDED
#define _CONFIG_H_INCLUDED







////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>          // ��׼�������
#include <stdlib.h>         // ��׼�⺯��
#include <stdarg.h>         // �ɱ�����б�
#include <assert.h>         // ���Ժ���
#include <limits.h>         // ����Ϣ��
#include <errno.h>          // ������Ϣ
#include <string.h>         // �ַ�������
#include <ctype.h>          // �ַ�����
#include <stdbool.h>        // BOOL����
#include <malloc.h>         // �ѿռ䴦��
#include <time.h>
/////////////////////////////////////////////////////////////////////////////////////////
//
//
//
//
//////////////////////////////////////////////////////////////////////////////////////////
#define SYS_WINDOWS_DEF

#ifdef SYS_WINDOWS_DEF
#
    #define SYS_WIN32_DEF            // 32λWindows����ϵͳ
    //#define SYS_WIN64_DEFINE            // 64λWindows����ϵͳ

    #if define      SYS_WIN32_DEF
    #
    #
/////////////////////////////////////////////////////////////////////////////////////////////
        #define	WCHAR		 USHORT                                            //���ַ�����//
        #define CHAR_SIZE         1                                            // �ַ����� //
        #define SHORT_SIZE        2                                            // ������   //
        #define INT_SIZE          4                                            //   ����   //
        #define LONG_SIZE         4                                            //  ������  //
        #define LONG_LONG_SIZE    4                                            // �������� //
        #define FLOAT_SIZE        4                                            //  ������  //
        #define DOUBLE_SIZE       8                                            // ˫������ //
        #define LONG_DOUBLE_SIZE  8                                            //��˫������//
/////////////////////////////////////////////////////////////////////////////////////////////
    #
    #
    #
    #
    #elifdef   SYS_WIN64_DEFINE
    #
    #
//////////////////////////////////////////////////////////////////////////////////////////
        #define WCHAR		   ULONG                                            //���ַ�����//
        #define CHAR_SIZE          1                                            // �ַ����� //
        #define SHORT_SIZE         4                                            // ������   //
        #define INT_SIZE           8                                            //   ����   //
        #define LONG_SIZE          8                                            //  ������  //
        #define LONG_LONG_SIZE     8                                            // �������� //
        #define FLOAT_SIZE         8                                            //  ������  //
        #define DOUBLE_SIZE       16                                            // ˫������ //
        #define LONG_DOUBLE_SIZE  16                                            //��˫������//
//////////////////////////////////////////////////////////////////////////////////////////
    #
    #
    #
    #
    #endif
#
#
#
#
#endif

///CTools�꺯����Ϣ
///////////////////////////////////////////////////////////////////////////////////////////
#
#
/// ��ǰ�ַ�������
#define IsDigit(c)         (c >= '0' && c <= '9')
/// ��ǰ�ַ���8��������
#define IsOctDigit(c)      (c >= '0' && c <= '7')
/// ��ǰ�ַ���16��������
#define IsHexDigit(c)      (IsDigit(c) || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))
/// ��ǰ�ַ�����ĸ����_
#define IsLetter(c)        ((c >= 'a' && c <= 'z') || (c == '_') || (c >= 'A' && c <= 'Z'))
/// ��ǰ�Ը��Ƿ�����C�ı�����������
#define IsLetterOrDigit(c) (IsLetter(c) || IsDigit(c))
#define IsIdentifier    IsLetterOrDigit
/// ��ǰ�ַ��ǿհ��ַ�
#define IsSpace(c)  ((c) == ' ' || (c) == '\t' || (c) == '\n' || (c) == '\r')
///
#define ToUpper(c)		   (c & ~0x20)
/// ȡ����ǰ��Ϣ�ĸ�4λ
#define HIGH_4BIT(v)       ((v) >> (8 * sizeof(int) - 4) & 0x0f)
/// ȡ����ǰ��Ϣ�ĸ�3λ
#define HIGH_3BIT(v)       ((v) >> (8 * sizeof(int) - 3) & 0x07)
/// ȡ����ǰ��Ϣ�ĸ�1λ
#define HIGH_1BIT(v)       ((v) >> (8 * sizeof(int) - 1) & 0x01)
#define ALIGN(size, align) ((size + align - 1) & (~(align - 1)))
#
#
///////////////////////////////////////////////////////////////////////////////////////////








/// CTools�꺯����Ϣ
//////////////////////////////////////////////////////////////////////////////////////////////
#define SHOW_FILE_NAME(fileName)     do                                                     \
                                    {   int i = strlen(fileName) - 1;                       \
                                        for( ; fileName[i] != '\\'                          \
                                        && fileName[i] != '/' && i >= 0; i--);              \
                                        char *fname = malloc(strlen(fileName) - i);         \
                                        strcpy(fname, fileName + i + 1);                    \
                                        printf("File: %s  ", fname);                        \
                                        free(fname);                                        \
                                    }while( 0 );
#
#
#define __file__ __FILE__           ///CTools�ļ����������
#define FILENAME()                  do                                                      \
                                    {   int i = strlen(__FILE__) - 1;                       \
                                        for( ;                                              \
                                             __FILE__[i] != '\\' && __FILE__[i] != '/';     \
                                            i--);                                           \
                                        char *fname = malloc(strlen(__FILE__) - i);         \
                                        strcpy(fname, __FILE__ + i + 1);                    \
                                        printf("FileName: %s", fname);                      \
                                        free(fname);                                        \
                                    }while( 0 );
#
#
#define __line__ __LINE__           /// CTools�к��������
#define LINE( )                     do                                                      \
                                    {                                                       \
                                        printf("Line: %d", __LINE__);                       \
                                    }while( 0 );
#
#
#define __FUNC__ __func__           /// CTools�������������
#define FUNC( )                     do                                                      \
                                    {                                                       \
                                        printf("Function: %s", __FUNC__);                   \
                                    }while( 0 );
#
#
#define FILE_FUNC_LINE( )           do                                                      \
                                    {                                                       \
                                        FILENAME( );                                        \
                                        putchar(' ');                                       \
                                        FUNC( );                                            \
                                        putchar(' ');                                       \
                                        LINE( );                                            \
                                        putchar('\n');                                      \
                                    }while(0);
#
#
///////////////////////////////////////////////////////////////////////////////////////////////



/// ��������������Ϣ
///////////////////////////////////////////////////////////////////////////////////////////////
#
#
// ��ʱ����
#define DELAY( )                    do                                                      \
                                    {                                                       \
                                        int i;                                              \
                                        for(i = 0; i < 1000000; i++);                       \
                                    }while( 0 );
#
#
#define PAUSE( )                    do                                                       \
                                    {                                                        \
                                        printf("Please enter any key to continue...\n");     \
                                        getchar( );                                          \
                                    }while( 0 );
#define STEP( ) PAUSE( )
#
// �汾�������
#define  VERSION( ) do                                                                              \
                    {   printf("\t\t**************************************************\n");         \
                        printf("\t\t**  Wacky Window (c) 2012 Wacky SoftWare. Inc.  **\n");         \
                        printf("\t\t**     Complied on %s at %s      **\n", __DATE__, __TIME__);    \
                        printf("\t\t**************************************************\n");         \
                        PAUSE( );                                                                   \
                    }while( 0 );
#
#
//////////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// ��׮���϶��ѹ��õ��ĺ�����Ϣ
#define Line(stream)        fprintf(stream, "%d\n", __line__);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////




typedef int State;          // �����﷨״̬����




/// ������Ϣ���Լ��꺯����Ϣ����
///////////////////////////////////////////////////////////////////////////////////////////
// �궨�庯���Ķ��巽ʽ��Ϣ///////////////////////////////////////////////
#ifndef PUBLIC_and_PRIVATE
#define PUBLIC_and_PRIVATE
#
#define PUBLIC  extern          // �������Ա�������
#define PRIVATE static      // ����ֻ�ܱ����ļ��ĺ�������
#
#endif
////////////////////////////////////////////////////////////////////////
#
#
// ����������Ϣ//////////////////////////////////////////////////////////
PUBLIC int CToolsPrintf(const char *format, ...);                       // ����CTools�Լ����������
////////////////////////////////////////////////////////////////////////
#
#
/// DEBUG_DEFINE    ��������������Ϣ��
/// SHOWS_DEFINE    �����������й����е����������ÿһ���е����
/// HELPS_DEFINE    �����Ƶ����������߼�����
//////////////////////////////////////////////////////////////////////////
// ȫ�ֵ�����Ϣ��////////////////////////////////////
// �ļ��򿪷�ʽ����
#define CTOOLS_FILE_OPEN_TEXT
#
#
//#define CTOOLS_FILE_OPEN_BINARY
#
#
// ������Ϣ����
//#define CTOOLS_DEBUG_DEFINE         ///CTools���Ժ���Ϣ//
#
//#define CTOOLS_SHOWS_DEFINE         ///CTools��Ϣ�����//
#
//#define CTOOLS_HELPS_DEFINE         /// CTools���������
#
//#define CTOOLS_STEPS_DEFINE           /// CTools�����������
////////////////////////////////////////////////////
#
#
// �ʷ�������������Ϣ��//////////////////////////////
//#define LEXICAL_DEBUG_DEFINE            /// Lexical������Ϣ��
#
//#define LEXICAL_SHOWS_DEFINE            /// Lexical�����Ϣ��
#
//#define LEXICAL_HELPS_DEFINE            /// Lexical������Ϣ��
///////////////////////////////////////////////////
#
#
// �﷨������������Ϣ��/////////////////////////////
#
//#define PARSER_DEBUG_DEFINE            /// Parser������Ϣ��
#
//#define PARSER_SHOWS_DEFINE            /// Parser�����Ϣ��
#
//#define PARSER_HELPS_DEFINE            /// Parser������Ϣ��
///////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
#
#
// ��׮��������Ϣ��/////////////////////////////
#
//#define PROP_DEBUG_DEFINE            /// Prop������Ϣ��
#
//#define PROP_SHOWS_DEFINE            /// Prop�����Ϣ��
#
//#define PROP_HELPS_DEFINE            /// Prop������Ϣ��
#
//#define PROP_REDUCTION_DEFINE        /// ���﷨������ͬʱ����Prop��׮
///////////////////////////////////////////////////
#
#
///////////////////////////////////////////////////////////////////////////









#endif      // ENDIF __CONFIG_H_
