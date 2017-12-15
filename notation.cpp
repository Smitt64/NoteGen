#include "notation.h"
#include <QPainter>
#include <QFontMetrics>
#include <QObject>

#define FONT_SCALE 4.0
#define DEFAULT_NOTE_SIZE 26.0

Notation::Notation(QQuickItem *parent) :
    QQuickPaintedItem(parent),
    m_NoteScale(1.0)
{
    m_Font = QFont("MetDemo");
    m_Font.setPixelSize(noteHeight() * FONT_SCALE);
    //m_FontMetrics = QFontMetrics(m_Font);

    m_ShowLineNumbers = true;
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

void Notation::setNoteScale(const qreal &scale)
{
    TrebleClef *clef = findChild<TrebleClef*>();
    m_NoteScale = scale;
    //m_Font.setPointSize(noteHeight());
    m_Font.setPixelSize(noteHeight() * FONT_SCALE /** FONT_SCALE * noteScale()*/);
    //m_FontMetrics = QFontMetrics(m_Font);
    update();

    if (clef)
        clef->update();

    emit noteScaleChanged(m_NoteScale);
}

QFont Notation::font() const
{
    return m_Font;
}

/*qreal Notation::FindNoteY(const MusicNote &note)
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
}*/

void Notation::paint(QPainter *painter)
{
    //TrebleClef *clef = findChild<TrebleClef*>();
    qreal line_space = noteHeight();
    QRectF brect = boundingRect();

    qreal startY = line_space;
    qreal y = startY;

    painter->save();
    for (int i = 5; i > 0; i--)
    {
        painter->drawLine(QPointF(brect.x(), y), QPointF(brect.right(), y));

        if (m_ShowLineNumbers)
        {
            QFont tmpF(m_Font.family());
            tmpF.setPointSize((noteHeight()) / 2);
            painter->setFont(tmpF);

            QFontMetrics metrics(tmpF);
            QString number = QString::number(i);
            painter->drawText(QPointF(brect.x(), y /*+ metrics.boundingRect(number).height() / 4*/), number);
        }
        y += line_space;
    }
    painter->restore();

    /*painter->setFont(m_Font);
    painter->drawText(100, line_space + line_space / 2, "Q");*/
}
