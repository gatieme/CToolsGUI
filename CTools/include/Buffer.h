/**
*********************************************************************************
*   CopyRight  : 2013-2014, HerBinUnversity, GatieMe                            *
*   File Name  : Buffer.h                                                       *
*   Description: CTools                                                         *
*   Author     : Gatie_Me                                                       *
*   Version    : Copyright 2013-2014                                            *
*   Data_Time  : 2013-3-10 21:29:24                                             *
*   Content    : CTools-Lexical                                                 *
*********************************************************************************
**/




#ifndef BUFFER_H_INCLUDED
#define BUFFER_H_INCLUDED


#include "Files.h"          // �ļ���Ϣ����
#include "Errors.h"


/// �궨�庯���Ķ��巽ʽ��Ϣ
#ifndef PUBLIC_and_PRIVATE
#define PUBLIC_and_PRIVATE
#
#define PUBLIC  extern          // �������Ա�������
#define PRIVATE static      // ����ֻ�ܱ����ļ��ĺ�������
#
#endif

// �궨��ÿ����������С4096B
#define BUFFER_SIZE  (sizeof(char)*4096)
#define BUFFER_COUNT 2


#define LINE_SIZE 1024
#
#
/// ��������ʹ����Ϣ
#define     NOT_USE   -1   // ��ǰ����������ʼ�����, δʹ��
#define     LEFT       0     // ��ǰʹ���󻺳���
#define     RIGHT      1     // ��ǰʹ���һ�����
#
#
/// ״̬�����ĺ궨����Ϣ
// Ϊ����ĺ����ṩ-=>������Ϊint choice
#define     THIS       0       // ��ʾ��������Ϊ��ǰʹ�û�����
#define     OTHER      1       // ��ʾ��������Ϊ����һ��δʹ�õĻ�����
#define     ALL       -1








//enum BufUsing
//{
//    LEFT = -1,          // ��ʾ�������ʹ���󲿻�����
//    ALL = 0,            // ��ʾ��������������
//    RIGHT = 1,          // ��ʾ�������ʹ���ұ߻�����
//}BufUsing;


// ˫�������ṹ��
typedef struct DouBuffer
{
    // ��������Ϣ
    char       *m_leftBuffer;       // ��벿�ֻ�����    // 4097
    char       *m_rightBuffer;      // �Ұ벿�ֻ�����    // 4097
    int         m_using;            // ��ʾ��ǰ��ʹ����Ϣʹ��   // 1
    // size_t m_bufsize;       // �������Ĵ�С

    // ������ָ����Ϣ
    char       *m_forward;          // ��ǰָ��
    char       *m_lexeme;           // ��ʼָ��

    // �ļ�ƫ����Ϣ
    CToolsFILE  m_fp;               // ָ��ǰ�����������ļ���ָ��
    Coord      *m_coord;            // ��ǰ������ָ���λ��ƫ��
}DouBuffer;                 // ˫������Ϣsizeof(DouBuffer) == 8204



#ifdef PUBLIC_and_PRIVATE
#
#
/// ���ص�ǰ�ַ���
/// ���ַ���str���뵽��������
PUBLIC bool                          // ����ֵ: �������������޸��˻�������λ��, ���ط���ֵfalse, ���򷵻�true
WriteStrInBuffer(                        // ����:   ���ַ����뻺����
                 DouBuffer *douBuffer,   // ������  ������Ļ���Ⱥ��Ϣ
                 char *str);       // ������  ��Ҫ���뻺�������ַ���
#define write_str_in_buffer    WriteStrInBuffer  // �ṩC������ʽ�ĺ������ýӿ�
#
#
/// ���������е���Ϣ�����ļ���
PUBLIC int
WriteBufferToFile(                          // ���ܣ�  ������������Ϣд���ļ���
                  DouBuffer *douBuffer,     // ������  ��������������Ϣ
                  CToolsFILE ofp,           // ������  ָ���д���ļ���ָ��
                  int choice);               // ������  0
#define write_buffer_to_file    WriteBufferToFile
#
#
/// ���������е���Ϣ�����ļ���
PUBLIC int
WriteLeftBufferToFile(                      // ���ܣ�  ������������Ϣд���ļ���
                     DouBuffer *douBuffer,    // ������  ��������������Ϣ
                     CToolsFILE ofp);           // ������  ָ���д���ļ���ָ��
#define write_left_buffer_to_file    WriteLeftBufferToFile
#
#
/// ���������е���Ϣ�����ļ���
PUBLIC int
WriteRightBufferToFile(                      // ���ܣ�  ������������Ϣд���ļ���
                     DouBuffer *douBuffer,    // ������  ��������������Ϣ
                     CToolsFILE ofp);           // ������  ָ���д���ļ���ָ��
#define write_right_buffer_to_file    WriteRightBufferToFile
#
#
/// ��ʼ������������Ϣ
PUBLIC DouBuffer*                            // �����޷�����Ϣ
InitBuffer(
           const char *fileName);           // ��������ļ���Ϣ
#define init_buffer InitBuffer          // �ṩC������ʽ�ĺ������ýӿ�
#define create_buffer InitBuffer
#define CreateBuffer InitBuffer
#
#
// ��������β����
PUBLIC void
FinitBuffer(
            DouBuffer *douBuffer);
#define finit_buffer FinitBuffer        // �ṩC������ʽ�ĺ������ýӿ�
#define DestroyBuffer FinitBuffer
#define destroy_buffer FinitBuffer
#
#
/// ��������Դ�ļ�ifp�ļ�����Ϣ���뻺����
PUBLIC int
PutBuffer(
          DouBuffer *douBuffer);         // ����������Ϣ
#define put_buffer PutBuffer            // �ṩC������ʽ�ĺ������ýӿ�
#
#
/// ����ʼ�ַ�����ǰָ��֮����ַ�������
PUBLIC char*                            // ������ȡ�������ļ���ָ��
CopyBufToken(
          DouBuffer *douBuffer);               // ��������Ϣ
#define copy_token  CopyToken           // �ṩC������ʽ�ĺ������ýӿ�
#
#
// ����ʼָ��ָ����һλ��, ͬʱ����λ�ñ�ƫ����Ŀ�ʼƫ��
PUBLIC void
AddBufLexeme(
             DouBuffer *douBuffer);
#define sub_buf_lexeme AddBufLexeme
#
#
/// ����ǰָ��ָ����һ��λ��
PUBLIC int
AddBufForward(
           DouBuffer *douBuffer);                // ��������Ϣ
#define add_forward  AddForward           // �ṩC������ʽ�ĺ������ýӿ�
#
#
// ����ǰָ��ָ����һ��λ��, ͬʱ����λ��ָ��Ľ���ƫ��
PUBLIC void
SubBufForward(
              DouBuffer *douBuffer);
#define sub_buf_forward  SubBufForward
#
#
// ����ʼָ��ָ����һλ��, ͬʱ����λ�ñ�ƫ����Ŀ�ʼƫ��
PUBLIC void
SubBufLexeme(DouBuffer *douBuffer);
#define sub_forward  SubForward           // �ṩC������ʽ�ĺ������ýӿ�

/// �жϵ�ǰ����λ��[��ǰָ��]�ǲ��ǻ�������ĩβ
PUBLIC bool                                // ����ǻ�����ĩβ����TRUE, ���򷵻�FALSE
IsBufferEnd(
            DouBuffer *douBuffer);              // ��������Ϣ
#define is_buffer_end IsBufferEnd              // �ṩC������ʽ�ĺ������ýӿ�
#
#
// ��鿪ʼָ���ǲ���λ�ڻ�����ĩβ
PUBLIC bool
IsLexmeAtBufEnd(
                DouBuffer *doubuffer);
#define is_lexeme_ad_buf_end    IsLexmeAtBufEnd
#
#
/// �жϵ�ǰ����ָ���Ƿ���ͬһ���������ڲ�
PUBLIC bool                                     // �����ǰָ��Ϳ�ʼָ����ͬһ������������TRUE, ���򷵻�FALSE
IsInSameBuffer(
               DouBuffer *douBuffer);           // ��������Ϣ
#define is_in_same_buffer IsInSameBuffer        // �ṩC������ʽ�ĺ������ýӿ�
#
#
/// ���ص�ǰ�󲿻�������ĩβ
PUBLIC char*                                    // ����ָ���󲿻�����ĩβ��ָ����Ϣ
LeftBufferEnd(
              DouBuffer *douBuffer);             // ��������Ϣ
#define left_buffer_end  LeftBufferEnd          // �ṩC������ʽ�ĺ������ýӿ�
#
#
/// ���ص�ǰ�Ҳ���������ĩβ
PUBLIC char*
RightBufferEnd(
              DouBuffer *douBuffer);           // ��������Ϣ
#define right_buffer_end    RightBufferEnd      // �ṩC������ʽ�ĺ������ýӿ�
#
#
/// ���ص�ǰ������ĩβ
PUBLIC char*                            // ָ��ǰʹ�õĻ������ĵ�ַ��ָ��
BufferEnd(
          DouBuffer *douBuffer,         // ��������Ϣ
          int choice);                  // ���� 0, ��ʾ��ǰʹ�õĻ�������ĩβ���� 1, ��ʾ��ǰδʹ�û�������ĩβ
#define buffer_end    BufferEnd      // �ṩC������ʽ�ĺ������ýӿ�
#
#
/// ���ص�ǰ������ĩβ
PUBLIC char*                        // ָ��ǰʹ�õĻ�������ʼλ�õ�ָ��
BufferBegin(DouBuffer *douBuffer,   // ��������Ϣ
                  int choice);       // ���� 0, ��ʾ��ǰʹ�õĻ������Ŀ�ʼ���� 1, ��ʾ��ǰδʹ�û�������ʼ��ĩβ
#define buffer_begin    BufferBegin  // �ṩC������ʽ�ĺ������ýӿ�
#
#
/// ����ʼָ���������ǰָ���λ��
PUBLIC void                         // ����������ʼָ�����ǰָ�����
CheckLexemeToForward(
                    DouBuffer *douBuffer);        // ��������Ϣ
#define check_lexeme_to_forward          // �ṩC������ʽ�ĺ������ýӿ�
#
#
/// ���㻺��������ָ��֮���ַ����ĳ���
PUBLIC int                              // ���ؼ����������ַ����ĳ���
TokenLength(
            DouBuffer *douBuffer);      // ˫��������Ϣ
#define token_length TokenLength        // �ṩC������ʽ�ĺ������ýӿ�
#
#
/// ������Ԥ���봦��ʱ,�����հ��ַ�����Ϣ-=>�ո��Ʊ����
PUBLIC void
DisBufSpace(
            DouBuffer *doubuffer);           // ������Ļ�������Ϣ
#define dis_space DisSpace              // �ṩC������ʽ�ĺ������ýӿ�
#
#
/// ��������ַ�
PUBLIC void
DisBufControl(
           DouBuffer *douBuffer);                // ��������Ϣ
#define dis_buf_control  DisBufControl
#
#
/// ֱ�Ӵ�����˵������ļ��������е���Ϣ
PUBLIC void
DisCurrLine(
            DouBuffer *douBuffer);
#
#
/// ������ͨ��ע����Ϣ
PUBLIC void
DisBufCommentLine(
                  DouBuffer *douBuffer);
#
#
/// ����Ԥ����ָ����Ϣ
PUBLIC void
DisBufProcom(
              DouBuffer *douBuffer);
#
#
#endif                 // #end_of_ifndef PUBLIC_and_PRIVATE






#endif // BUFFER_H_INCLUDED
