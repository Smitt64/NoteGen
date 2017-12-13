#ifndef TREBLECLEF_H
#define TREBLECLEF_H

#include <QQuickPaintedItem>

class TrebleClef : public QQuickPaintedItem
{
    Q_OBJECT
    friend class Notation;
public:
    TrebleClef(QQuickItem *parent = Q_NULLPTR);
    virtual ~TrebleClef();

    virtual void paint(QPainter *painter);
    virtual QRectF boundingRect() const;
};

#endif // TREBLECLEF_H
