#ifndef NOTATION_H
#define NOTATION_H

#include <QQuickPaintedItem>
#include <QPixmap>
#include <QFontMetrics>
#include <QPen>
#include "trebleclef.h"
#include "note.h"

class Notation : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(qreal noteScale READ noteScale WRITE setNoteScale NOTIFY noteScaleChanged)
    Q_PROPERTY(bool LineNumbers READ lineNumbers WRITE setLineNumbers)
public:
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

        LineCount,
    };
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
    QPen linePen() const;

    virtual QRectF boundingRect() const;

public slots:
    void setNoteScale(const qreal &scale);
    Q_INVOKABLE qreal linePos(const MusicLine &line) const;
    Q_INVOKABLE QString noteName(const qint16 &v) const;
    ///*Q_INVOKABLE*/ int findFirstNote() const;
    Q_INVOKABLE Note *findFirstNote() const;

signals:
    void noteScaleChanged(const qreal &scale);

private:
    //QPoint FindNoteY(const MusicNote &note);
    bool m_ShowLineNumbers;
    QPixmap m_MusicKey, m_Note;
    qreal m_NoteScale;
    QFont m_Font;
    QPen m_LinesPen;
    //QFontMetrics m_FontMetrics;
};

#endif // NOTATION_H
