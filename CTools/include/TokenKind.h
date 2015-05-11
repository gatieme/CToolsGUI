


#ifndef TOKEN_KIND_H_INCLUDED
#define TOKEN_KIND_H_INCLUDED

#include "Config.h"     //  #include "..\Config\Config.h"         // �����ļ���Ϣ

/// �궨�庯���Ķ��巽ʽ��Ϣ
#ifndef PUBLIC_and_PUBLIC
#define PUBLIC_and_PUBLIC
#
#define PUBLIC  extern          // �������Ա�������
#define PRIVATE static      // ����ֻ�ܱ����ļ��ĺ�������
#
#endif


#define MAX_KEYWORD_COUNT     40      // �ؼ��ָ���
#define MAX_PROCOM_COUNT      15      // Ԥ����ָ��ĸ���
#define MAX_OPERATE_COUNT     50      // ���������
#define MAX_SEPARAROR_COUNT   20      // �ָ�������
#define MAX_STR_SIZE_COUNT    81      // ��������ַ���������С


#define MAX_KEYWORD_SIZE      20      // �����ؼ��ֵĴ�����
#define MAX_PROCOM_SIZE       10      // ����Ԥ����ָ��Ĵ�����
#define MAX_OPERATE_SIZE       4      // ����������Ĵ�����

#define NOT_FIND        -1       // δ�ҵ��˹ؼ�����Ϣ



/// ��ʶ������Ϣ����
typedef enum TokenKind
{

    /*����������Ϊ������Ϣ*/
    TOKEN_NULL                  =   -3,         // û��ֵ
    UNKNOW                      =   -2,         // ��ʶ��������δ֪
    TOKEN_END                   =   -1,         // �����ı�־
    HEAD                        =   00,
    ARRAY                       =   01,
    FUNCTION                    =   02,         // ����
    PARAMETERS                  =   03,         // ��������
    POINT                       =   04,         // ָ��

    /// ��ʶ��
    IDENTIFIER                  =   05,         // ��ʶ��

    /*6 7 8 9 ��Ϊ������Ϣ*/

    /// �ؼ���
    KEYWORD                     =   10,         // �ؼ���
    AUTO_KEYWORD                =   11,         // auto
    BOOL_KEYWORD                =   12,         // bool
    BREAK_KEYWORD               =   13,         // break
    CASE_KEYWORD                =   14,         // case
    CHAR_KEYWORD                =   15,         // char
    CONST_KEYWORD               =   16,         // const
    CONTINUE_KEYWORD            =   17,         // continue
    DEFAULT_KEYWORD             =   18,         // default
    DO_KEYWORD                  =   19,         // do
    DOUBLE_KEYWORD              =   20,         // double
    ELSE_KEYWORD                =   21,         // else
    ENUM_KEYWORD                =   22,         // enum
    EXTERN_KEYWORD              =   23,         // extern
    FLOAT_KEYWORD               =   24,         // float
    FOR_KEYWORD                 =   25,         // for
    GOTO_KEYWORD                =   26,         // goto
    IF_KEYWORD                  =   27,         // if
    INLINE_KEYWORD              =   28,         // inline
    INT_KEYWORD                 =   29,         // int
    LONG_KEYWORD                =   30,         // long
    REGISTER_KEYWORD            =   31,         // register
    RESTRICT_KEYWORD            =   32,         // restrict
    RETURN_KEYWORD              =   33,         // return
    SHORT_KEYWORD               =   34,         // short
    SIGNED_KEYWORD              =   35,         // signed
    SIZEOF_OPERATE              =   36,         // sizeof
    STATIC_KEYWORD              =   37,         // static
    STRUCT_KEYWORD              =   38,         // struct
    SWITCH_KEYWORD              =   39,         // switch
    TYPEDEF_KEYWORD             =   40,         // typedef
    UNION_KEYWORD               =   41,         // union
    UNSIGNED_KEYWORD            =   42,         // unsigned
    VOID_KEYWORD                =   43,         // void
    VOLATILE_KEYWORD            =   44,         // volatile
    WHILE_KEYWORD               =   45,         // while
    _BOOL_KEYWORD               =   46,         // _Bool
    _COMPLEX_KEYWORD            =   47,         // _Complex
    _IMAGINARY_KEYWORD          =   48,         // _Imaginary

    /// �������
    OPERATE                     =   50,         // �����
    COMMA_OPERATE               =   51,         // ,    15-level
    ASSIGN_OPERATE              =   52,         // =    14-level
    ADD_ASSIGN_OPERATE          =   53,         // +=
    SUB_ASSIGN_OPERATE          =   54,         // -=
    MUL_ASSIGN_OPERATE          =   55,         // *=
    DIV_ASSIGN_OPERATE          =   56,         // /=                                 // /=
    MOD_ASSIGN_OPERATE          =   57,         // %=
    BITOR_ASSIGN_OPERATE        =   58,         // |=
    BITXOR_ASSIGN_OPERATE       =   59,         // ^=
    BITAND_ASSIGN_OPERATE       =   60,         // &=
    RSHIFT_ASSIGN_OPERATE       =   61,         // >>=
    LSHIFT_ASSIGN_OPERATE       =   62,         // <<=
    QUESTION_OPERATE            =   63,         // ?    13-level
    COLON_OPERATE               =   64,         // :
    OR_OPERATE                  =   65,         // ||   12-level
    AND_OPERATE                 =   66,         // &&   11-level
    BITOR_OPERATE               =   67,         // |    10-level
    BITXOR_OPERATE              =   68,         // ^    09-level
    BITAND_OPERATE              =   69,         // &    08-level
    EQUAL_OPERATE               =   70,         // ==   07-level
    UNEQUAL_OPERATE             =   71,         // !=
    GREATER_OPERATE             =   72,         // >    06-level
    GREATER_EQUAL_OPERATE       =   73,         // >=
    LESS_OPERATE                =   74,         // <
    LESS_EQUAL_OPERATE          =   75,         // <=
    RSHIFT_OPERATE              =   76,         // >>   05-level
    LSHIFT_OPERATE              =   77,         // <<
    ADD_OPERATE                 =   78,         // +    04-level
    SUB_OPERATE                 =   79,         // -
    MUL_OPERATE                 =   80,         // *    03-level
//    DMUL_OPERATE                =   81,         // **
//    TMUL_OPERATE                =   82,         // ***
//    FMUL_OPERATE                =   83,         // ****
                                                // Ϊ����ָ�붨���ʶԤ����λ��
    DIV_OPERATE                 =   81,         // /
    MOD_OPERATE                 =   82,         // %
    NOT_OPERATE                 =   83,         // !    02-level
    COMP_OPERATE                =   84,         // ~
                                                // ����
    INC_OPERATE                 =   85,         // ++
    DEC_OPERATE                 =   86,         // --
                                                // ȡ��ַ&��ȡָ��*����type������ת����sizeof
    DOT_OPERATE                 =   87,         // .
    POINT_TO_OPERATE            =   88,         // ->
    ELLIPSE_OPERATE             =   89,         // ...

    ///  �ֽ��
    SEPARATOR                   =   100,        // �ֽ��
    SPACE_SEPARATOR             =   101,        // _

    LPAREN_OPERATE              =   102,        // (
    RPAREN_OPERATE              =   103,        // )    01-level
    LBRACKET_OPERATE            =   104,        // [
    RBRACKET_OPERATE            =   105,        // ]

    LBRACE_SEPARATOR            =   106,        // {
    RBRACE_SEPARATOR            =   107,        // }
    SEMICOLON_SEPARATOR         =   108,        // ;
    POUND_SEPARATOR             =   109,        // #
    SINGLE_QUOTE_SEPARATOR      =   110,        // '
    DOUBLE_QUOTE_SEPARATOR      =   111,        // "
    BACKSLASH_SEPARATOR         =   112,        // '\'
    NEWLINE_SEPARATOR           =   113,        // \n
//    ELLIPSE_SEPARATOR           =   113,        // ...
//    EOF_SEPARATOR               =   113,        // eof[\0]


    /// ����
    CONST                       =   120,        // ����const
    INT_CONST                   =   121,        // ���γ���
    UINT_CONST                  =   122,        // �޷������ͳ���
    LONG_CONST                  =   123,        // �����ͳ���
    ULONG_CONST                 =   124,        // �޷��ų����ͳ���
    LLONG_CONST                 =   125,        // �������γ���
    ULLONG_CONST                =   126,        // �޷��ų����ͳ���
    FLOAT_CONST                 =   127,         // ����������
    DOUBLE_CONST                =   128,         // ˫���ȸ���������
    LDOUBLE_CONST               =   129,         // ����˫���ȸ���������
    CHAR_CONST                  =   130,         // �ַ�����
    WCHAR_CONST                 =   131,         // ���ַ�������Ϣ
    STRING_CONST                =   132,         // �ַ�������
    ENUM_CONST                  =   133,         // ö�ٳ���


    /// Ԥ����ָ��
    PROCOM                      =   140,        // Ԥ����ָ��
    NULL_PROCOM                 =   141,        // #��Ԥ����ָ��
    INCLUDE_PROCOM              =   142,        // #include
    LINE_PROCOM                 =   143,        // #line
    DEFINE_PROCOM               =   144,        // #define
    UNDEF_PROCOM                =   145,        // #undef
    IF_PROCOM                   =   146,        // #if
    ELIF_PROCOM                 =   147,        // #elif
    ELSE_PROCOM                 =   148,        // #else
    IFDEF_PROCOM                =   149,        // #ifdef
    IFNDEF_PROCOM               =   150,        // #ifndef
    ENDIF_PROCOM                =   151,        // #endif
    ERROR_PROCOM                =   152,        // #error
    PRAGMA_PROCOM               =   153,        // #pragma
    IMPORT_PROCOM               =   154,        // #import

}TokenKind;




#ifdef PUBLIC_and_PUBLIC
///�Ƿ�Ϊ�ָ���
PUBLIC int
IsSeparator(
            const char ch);
#define is_separator   IsSeparator
#
#
///�Ƿ�Ϊ�������
PUBLIC int
IsOperate(
          const char ch);
#define is_operate IsOperate
#
#
///�Ƿ��������
PUBLIC int
IsAllOperate(
             const char *token);
#define is_all_operate  IsAllOperate
#
#
///�Ƿ�Ϊ�ؼ���
PUBLIC int
IsKeyword(
          const char *str);
#define is_keyword IsKeyWord
#
#
///�Ƿ�Ϊ����
PUBLIC TokenKind
IsConstant(
           const char *str);
#define is_constant IsConstant
#
#
/// �Ƿ���Ԥ����ָ��
PUBLIC int
IsProCom(
         const char *token);
///// �жϵ�ǰ��������ǲ�������*********��ָ������
//PUBLIC int
//IsPoint(
//        char *token);           // ��ȡ�������������
#define is_point IsPoint
#
#endif





#endif // KIND_H_INCLUDED
