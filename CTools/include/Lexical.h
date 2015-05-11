/**
*********************************************************************************
*   CopyRight  : 2013-2014, HerBinUnversity, GatieMe                            *
*   File Name  : Lexical.h                                                      *
*   Description: CTools                                                         *
*   Author     : Gatie_Me                                                       *
*   Version    : Copyright 2013-2014                                            *
*   Data_Time  : 2013-3-10 21:29:24                                             *
*   Content    : CTools-Lexical                                                 *
*********************************************************************************
**/



/**[�����޸���Ϣ]0.6
@@   �޸���douTupleͷ���δ����ռ��ʹ������ɵ�BUG[2013/3/21-15:39]
@@   �޸����ж�Ϊ�ֽ��[5]���ɴ�ӡ�ַ��������ɵĳ������isprint()
##   ���ýϵͼ��İ취�����˶�Ԫ��������char *m_valueָ��ĸ�ֵ����, ��ʱ�޸�Ϊchar m_value[20];
**/

/**[�����޸���Ϣ]0.7
@@   ������������εĴ�����Ϣ
@@   ������TupleNode��������m_fileInfo, �滻��ԭ����[int]m_keycode, ��ΪHEAD����������
     [int] m_keycount�����洢��ǰ�ļ��Ĵʷ���Ϣ��Ŀ
     [char*] m_file�����洢��ǰ������ļ����ļ���
**/



/**[�����޸���Ϣ]0.8
@@  ���˫������������, ���ļ��е���Ϣ��ȡ�������������Ч��[δ���]
**/


/**[�����޸���Ϣ]0.9
@@  �޸�˫������������, ���ļ��е���Ϣ��ȡ�������������Ч��[δ���]
@@  ��ӷ��ű�SymbolTable����Ϣ, ����ʶ�����뵽���ű��еĹ�ϣ����
**/

/**[�����޸���Ϣ]0.95
@@  �޸�˫������������, ���ļ��е���Ϣ��ȡ�������������Ч��[δ���]
@@  �޸ķ��ű�SymbolTable����Ϣ, ����ʶ�����뵽���ű��еĹ�ϣ����
@@  ���ĺ���BufferLexical������100�еĺ���ȫ���ֳɼ����ֱ���ĺ���
    �ֱ���[�ؼ��ֻ��߱�ʶ��], �Լ����������, �ֽ������
**/


/**[�����޸���Ϣ]0.96
@@  �޸ķ��ű�SymbolTable����Ϣ, ����ʶ�����뵽���ű��еĹ�ϣ����
@@  ���ĺ���BufferLexical������100�еĺ���ȫ���ֳɼ����ֱ���ĺ���
    �ֱ���[�ؼ��ֻ��߱�ʶ��], �Լ����������, �ֽ������
@@  �����еĲ�������Ϊָ������, ���Ļ�����������, ��������Ϊ�ѿռ����뿪��
**/

/**[�����޸���Ϣ]0.97
@@  �������еĳ���ṹ���������еľ�����Ϣ
    ��PUBLIC���������ƶ���.h�ļ�, ��PRIVATE���������ƶ���.c�ļ���
    �ṹ�������ĸ��£� ����ָ��ת�͵ľ�����Ϣ

**/



#ifndef LEXICAL_H_INCLUDED
#define LEXICAL_H_INCLUDED


#include "Config.h"     //  #include "..\Config\Config.h"

#include "Files.h"             // �ļ�����ӿ�
#include "Buffer.h"            // ˫�������ӿ�
#include "TokenKind.h"    //  #include "..\Lexical\TokenKind.h"       // �ؼ��������ʶ
#include "BinaryTuple.h"   //  #include "..\Lexical\BinaryTuple.h"     // �ʷ���Ԫ����Ϣ


/// �궨�庯���Ķ��巽ʽ��Ϣ
#ifndef PUBLIC_and_PRIVATE
#define PUBLIC_and_PRIVATE
#
#
    #define PUBLIC  extern          // �������Ա�������
    #define PRIVATE static      // ����ֻ�ܱ����ļ��ĺ�������
#
#
#endif








#ifdef PUBLIC_and_PRIVATE
#
#
/// ������������
/// ��Դ�ļ����дʷ�����
PUBLIC BinaryTuple                          // ���ط��������Ĵʷ���Ԫ��
BufferLexical(
              const char *sourFile);               // ������Դ�ļ�
#define  buffer_lexical   BufferLexical
#
#
// ��Դ�ļ����дʷ�����
PUBLIC void     // �ʷ������Ĳ���������
MainOfLexical(void);    // ������Դ�ļ�
#define main_of_lexical MainOfLexical
#
#
// ��Դ�ļ����дʷ�����
PUBLIC void     // �ʷ������Ĳ���������
TestOfLexical(void);    // ������Դ�ļ�
#
#
/// ��Դ�ļ����дʷ�����
PUBLIC BinaryTuple                          // ���ط��������Ĵʷ���Ԫ��
BufLexSourFile(
              const char *sourFile);               // ������Դ�ļ�
#define  buffer_lexical   BufferLexical
#
#
/// ��Ԥ�����ļ����дʷ�����
PUBLIC BinaryTuple                          // ���ط��������Ĵʷ���Ԫ��
BufLexProFile(
              const char *proFile);               // ������Դ�ļ�
#endif



#endif // LEXICAL_H_INCLUDED
