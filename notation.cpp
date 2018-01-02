#include "notation.h"
#include <QPainter>
#include <QFontMetrics>
#include <QObject>
#include "note.h"

#define FONT_SCALE 4.0
#define DEFAULT_NOTE_SIZE 26.0

Notation::Notation(QQuickItem *parent) :
    QQuickPaintedItem(parent),
    m_NoteScale(1.0)
{
    m_Font = QFont("MetDemo");
    m_Font.setPixelSize(noteHeight() * FONT_SCALE);

    m_ShowLineNumbers = true;
    m_LinesPen = QPen(QBrush(Qt::black), 2);
}

Notation::~Notation()
{

}

qreal Notation::noteDefaultHeight() const
{
    return DEFAULT_NOTE_SIZE;
}

qreal Notation::noteHeight() const
{
    return noteDefaultHeight() * m_NoteScale;
}

qreal Notation::noteScale() const
{
    return m_NoteScale;
}

bool Notation::lineNumbers() const
{
    return m_ShowLineNumbers;
}

void Notation::setLineNumbers(bool value)
{
    m_ShowLineNumbers = value;
}

qreal Notation::linePos(const MusicLine &line) const
{
    qreal y = 0.0;
    qreal line_space = noteHeight();

    switch(line)
    {
    case LineMain1:
        y = line_space * 5 + line_space / 2;
        break;
    case LineMain2:
        y = line_space * 4 + line_space / 2;
        break;
    case LineMain3:
        y = line_space * 3 + line_space / 2;
        break;
    case LineMain4:
        y = line_space * 2 + line_space / 2;
        break;
    case LineMain5:
        y = line_space * 1 + line_space / 2;
        break;
    case LineBottom1:
        y = line_space * 6 + line_space / 2;
        break;
    case LineBottom2:
        y = line_space * 7 + line_space / 2;
        break;
    case LineBottom3:
        y = line_space * 8 + line_space / 2;
        break;
    }

    return y;
}

void Notation::setNoteScale(const qreal &scale)
{
    TrebleClef *clef = findChild<TrebleClef*>();
    QList<Note*> notes = findChildren<Note*>();
    m_NoteScale = scale;
    m_Font.setPixelSize(noteHeight() * FONT_SCALE /** FONT_SCALE * noteScale()*/);
    update();
    for (QList<Note*>::iterator i = notes.begin(); i != notes.end(); ++i)
        (*i)->update();

    if (clef)
        clef->update();

    emit noteScaleChanged(m_NoteScale);
}

QFont Notation::font() const
{
    return m_Font;
}

QPen Notation::linePen() const
{
    return m_LinesPen;
}

QString Notation::noteName(const qint16 &v) const
{
    return Note::noteName((Note::MusicNote)v);
}

QRectF Notation::boundingRect() const
{
    QRectF old = QQuickItem::boundingRect();
    QRectF rect;
    rect.setX(old.x());
    rect.setY(old.y());
    rect.setWidth(/*old.width()*/2024);
    rect.setHeight(noteHeight() * LineCount);

    return rect;
}

/*int Notation::findFirstNote() const
{
    QList<Note*> notes = findChildren<Note*>();
    if (notes.empty())
        return Note::NoteUnknown;
    return notes[0]->note();
}*/

Note *Notation::findFirstNote() const
{
    QList<Note*> notes = findChildren<Note*>();
    if (notes.empty())
        return Q_NULLPTR;
    return notes[0];
}

void Notation::paint(QPainter *painter)
{
    //TrebleClef *clef = findChild<TrebleClef*>();
    qreal line_space = noteHeight();
    QRectF brect = boundingRect();

    qreal startY = line_space;
    qreal y = startY;

    painter->fillRect(brect, Qt::white);
    painter->save();
    painter->setPen(m_LinesPen);
    for (int i = LineMain1; i <= LineMain5; i++)
    {
        y = linePos((MusicLine)i);
        painter->drawLine(QPointF(brect.x(), y), QPointF(brect.width(), y));
    }
    painter->restore();
}
