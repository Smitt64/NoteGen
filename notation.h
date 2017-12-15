#ifndef NOTATION_H
#define NOTATION_H

#include <QQuickPaintedItem>
#include <QPixmap>
#include <QFontMetrics>
#include "trebleclef.h"

class Notation : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(qreal noteScale READ noteScale WRITE setNoteScale NOTIFY noteScaleChanged)
    Q_PROPERTY(bool LineNumbers READ lineNumbers WRITE setLineNumbers)
public:
    enum MusicNote
    {
        NoteUnknown,
        NoteC,       // до
        NoteD,       // ре
        NoteE,       // ми
        NoteF,       // фа
        NoteG,       // соль
        NoteA,       // ля
        NoteB,       // си
    };

    enum MusicLine
    {
        LineNone = -1,
        LineAddTop3,
        LineAddTop2,
        LineAddTop1,
        LineMain1,
        LineMain2,
        LineMain3,
        LineMain4,
        LineMain5,
        LineBottom1,
        LineBottom2,
        LineBottom3,
    };
    Q_ENUM(MusicNote)
    Q_ENUM(MusicLine)
    Notation(QQuickItem *parent = Q_NULLPTR);
    virtual ~Notation();

    QFont font() const;
    virtual void paint(QPainter *painter);

    qreal noteHeight() const;
    qreal noteDefaultHeight() const;
    qreal noteScale() const;

    bool lineNumbers() const;
    void setLineNumbers(bool value);

public slots:
    void setNoteScale(const qreal &scale);

signals:
    void noteScaleChanged(const qreal &scale);

private:
    //QPoint FindNoteY(const MusicNote &note);
    bool m_ShowLineNumbers;
    QPixmap m_MusicKey, m_Note;
    qreal m_NoteScale;
    QFont m_Font;
    //QFontMetrics m_FontMetrics;
};

#endif // NOTATION_H
