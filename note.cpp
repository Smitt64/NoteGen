#include "note.h"
#include "notation.h"
#include "noteapi.h"
#include <QPainter>
#include <QTransform>

Note::Note(QQuickItem *parent) :
    QQuickPaintedItem(parent)
{
    m_Note = NoteUnknown;
    m_X = 50.0;
    m_NoteColor = QColor(Qt::black);
}

Note::~Note()
{

}

Note::MusicNote Note::note() const
{
    return m_Note;
}

void Note::setNote(const Note::MusicNote &n)
{
    m_Note = n;
}

qint16 Note::noteLine(bool &isUnderLine)
{
    return pNoteApi->noteLine(m_Note, isUnderLine);
}

bool Note::hasAddLine() const
{
    return pNoteApi->isUnderLine(m_Note);
}

bool Note::isSecondOctave() const
{
    return pNoteApi->isSecondOctave(m_Note);
}

QString Note::noteName(const MusicNote &v)
{
    return pNoteApi->noteLangName((qint16)v);
}

QColor Note::noteColor() const
{
    return m_NoteColor;
}

void Note::setNoteColor(const QColor &color)
{
    m_NoteColor = color;
    update();
}

void Note::paint(QPainter *painter)
{
     painter->setBackgroundMode(Qt::TransparentMode);
     Notation *notation = qobject_cast<Notation*>(parent());
     QFont font = notation->font();
     QFontMetrics fm(font);

     bool isUnderLine = false;
     qint16 lineNum = noteLine(isUnderLine);
     qreal noteY = notation->linePos((Notation::MusicLine)lineNum);
     noteY += notation->noteHeight() / 2;

     if (isUnderLine)
         noteY += notation->noteHeight() / 2;

     painter->setFont(font);
     painter->save();
     painter->setPen(m_NoteColor);
     if (isSecondOctave())
     {
         QImage img(QSize(fm.width("Q"), fm.height()), QImage::Format_ARGB32);
         QPainter p(&img);
         img.fill(Qt::transparent);
         p.setFont(font);
         p.drawText(QPoint(0, fm.height() / 2), "Q");
         painter->drawImage(QPoint(m_X, noteY - fm.height() / 2 - notation->noteHeight()), img.mirrored());
     }
     else
        painter->drawText(QPoint(m_X, noteY), "Q");
     painter->restore();

     if (hasAddLine())
     {
         for (int i = Notation::LineBottom1; i <= lineNum; i++)
         {
             qreal addLineY = notation->linePos((Notation::MusicLine)i);
             painter->setPen(notation->linePen());
             painter->drawLine(QPoint(m_X, addLineY), QPoint(fm.width("Q") + m_X, addLineY));
         }
     }
}
