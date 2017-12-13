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
    Notation *notation = qobject_cast<Notation*>(parent());
    qreal line_space = notation->noteHeight();

    QFont font("MetDemo");
    QFontMetrics fm(font);
    font.setPixelSize(line_space * 5 * notation->noteScale());

    QRect rc = fm.boundingRect(":");
    return QRect(0, 0, rc.width(), rc.height() + line_space * 3);
}

void TrebleClef::paint(QPainter *painter)
{
    Notation *notation = qobject_cast<Notation*>(parent());
    qreal line_space = notation->noteHeight();

    QFont font("MetDemo");
    QFontMetrics fm(font);
    font.setPixelSize(line_space * 7 * notation->noteScale());
    painter->setFont(font);
    painter->drawText(10, fm.boundingRect(":").height() + line_space * 2, ":");
}
