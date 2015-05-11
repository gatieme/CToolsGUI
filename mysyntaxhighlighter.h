/**
******************************************************************************
*   CopyRight  : 2012-2013, HerBinUnversity, GatieMe                         *
*   File Name  : mysyntaxhighlighter.h                                      *                   *
*   Description: 高亮度显示类文件                                               *
*   Author     : Gatie_Me                                                    *
*   Version    : Copyright 2012                                              *
*   Data_Time  : 20112-8-29 10:28:43                                         *
*   Content    : Qt设置の多文档编辑器                                           *
******************************************************************************
**/


#ifndef MYSYNTAXHIGHLIGHTER_H
#define MYSYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>


class MySyntaxHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    explicit MySyntaxHighlighter(QTextDocument *parent = 0);
    ~MySyntaxHighlighter( );
protected:
    void highlightBlock(const QString &text);
signals:

public slots:

private:
    struct HighlightingRule
    {
        QRegExp pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;

    QRegExp commentStartExpression;
    QRegExp commentEndExpression;

    QTextCharFormat keywordFormat;
    QTextCharFormat classFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat functionFormat;

};

#endif // MYSYNTAXHIGHLIGHTER_H
