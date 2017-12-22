#include "trebleclef.h"
#include "notation.h"
#include <QFontMetrics>
#include <QPainter>

TrebleClef::TrebleClef(QQuickItem *parent) :
    QQuickPaintedItem(parent)
{

}

TrebleClef::~TrebleClef()
{

}

QRectF TrebleClef::boundingRect() const
{
    /*Notation *notation = qobject_cast<Notation*>(parent());
    qreal line_space = notation->noteHeight();

    QFont font = notation->font();
    QFontMetrics fm(font);

    QRect rc = fm.boundingRect(":");
    return QRect(0, 0, rc.width(), rc.height() + line_space * 3);*/
    return QQuickPaintedItem::boundingRect();
}

void TrebleClef::paint(QPainter *painter)
{
    Notation *notation = qobject_cast<Notation*>(parent());
    qreal line_space = notation->noteHeight();

    QFont font = notation->font();
    QFontMetrics fm(font);
    painter->setFont(font);
    painter->drawText(10, fm.boundingRect(":").height() / 2 + line_space, ":");
}
