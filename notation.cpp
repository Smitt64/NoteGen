#include "notation.h"
#include <QPainter>

//#define LINE_SPACE 10

Notation::Notation(QQuickItem *parent) :
    QQuickPaintedItem(parent),
    m_NoteScale(1.0)
{
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

void Notation::paint(QPainter *painter)
{
    qreal line_space = noteHeight();
    QRectF brect = boundingRect();

    qreal startY = line_space + 10;
    qreal y = startY;

    for (int i = 0; i < 5; i++)
    {
        painter->drawLine(QPointF(brect.x(), y), QPointF(brect.right(), y));
        y += line_space;
    }

    /*painter->save();
    painter->setPen(QPen(QBrush(Qt::black), 2.0));
    painter->drawLine(QPointF(y, startY + 1), QPointF(y, y));
    painter->restore();

    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawPixmap(brect.x(), LINE_SPACE / 2, y, y, m_MusicKey);*/
}
