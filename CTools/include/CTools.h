

#ifndef CTOOLS_H_INCLUDED
#define CTOOLS_H_INCLUDED




/// �����ļ���Ϣ
#include "Config.h"     //  #include "..\Config\Config.h"                // ���ù���


/// ȫ�ֽӿ�
#include "Errors.h"               // ������ӿ�
#include "Files.h"                 // �ļ�����ӿ�

/// ������Ϣ
#include "Buffer.h"               // ˫������

/// �ʷ�������
//#include "BinaryTuple.h"   //  #include "..\Lexical\BinaryTuple.h"         // �ʷ���Ԫ��ӿ�
#include "Lexical.h"    //  #include "..\Lexical\Lexical.h"             // �ʷ����������س���

/// �﷨������
#include "Parser.h"    //  #include "..\Parser\Parser.h"               // �﷨�������س���

/// ���ű���Ϣ
#include "SymbolTable.h"

/// ��׮����Ϣ
#include "Prop.h"

/// �궨�庯���Ķ��巽ʽ��Ϣ
#ifndef PUBLIC_and_PRIVATE
#define PUBLIC_and_PRIVATE
#
#define PUBLIC  extern          // �������Ա�������
#define PRIVATE static      // ����ֻ�ܱ����ļ��ĺ�������
#
#endif





#endif // CTOOLS_H_INCLUDED
