#include "notation.h"
#include <QPainter>
#include <QFontMetrics>
#include <QObject>

//#define LINE_SPACE 10

Notation::Notation(QQuickItem *parent) :
    QQuickPaintedItem(parent),
    m_NoteScale(1.0)
{
    m_pClef = Q_NULLPTR;
    m_MusicKey.load("://img/musical-note.svg");
    m_Note.load("://img/note.png");
}

Notation::~Notation()
{

}

qreal Notation::noteDefaultHeight() const
{
    return (qreal)m_Note.height();
}

qreal Notation::noteHeight() const
{
    return noteDefaultHeight() * m_NoteScale;
}

qreal Notation::noteScale() const
{
    return m_NoteScale;
}

void Notation::setNoteScale(const qreal &scale)
{
    m_NoteScale = scale;
    emit noteScaleChanged(m_NoteScale);
}

TrebleClef *Notation::noteClef() const
{
    return m_pClef;
}

void Notation::setClef(TrebleClef *clef)
{
    m_pClef = clef;
}

QRect Notation::FindNoteRect(const MusicNote &note)
{
    QRect rc;
    qreal line_space = noteHeight();
    qreal height = noteHeight();

    qreal y = 0.0;
    rc.setX(50); // !!!!!!
    switch(note)
    {
    case NoteC:
        y = line_space * 6; // 1-я добавочная линейка
        break;
    }
    rc.setY(y);
    rc.setWidth(height);
    rc.setHeight(height);
    return rc;
}

void Notation::paint(QPainter *painter)
{
    TrebleClef *clef = findChild<TrebleClef*>();
    qreal line_space = noteHeight();
    QRectF brect = boundingRect();

    qreal startY = line_space;
    qreal y = startY;

    painter->save();
    for (int i = 0; i < 5; i++)
    {
        painter->drawLine(QPointF(brect.x(), y), QPointF(brect.right(), y));
        y += line_space;
    }
    painter->restore();

    QFont font("MetDemo");
    font.setPixelSize(line_space * 7 * noteScale());
    painter->setFont(font);
    painter->drawText(100, line_space + line_space / 2, "Q");
}
