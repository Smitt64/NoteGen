#include "note.h"
#include "notation.h"

Note::Note(QQuickItem *parent) :
    QQuickPaintedItem(parent)
{

}

Note::~Note()
{

}

void Note::paint(QPainter *painter)
{
     Notation *notation = qobject_cast<Notation*>(parent());
     QFont font = notation->font();
     //QFontMetrics fm(font);
}
