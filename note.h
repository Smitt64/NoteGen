#ifndef NOTE_H
#define NOTE_H

#include <QQuickPaintedItem>

class Note : public QQuickPaintedItem
{
    Q_OBJECT
    friend class Notation;
public:
    Note(QQuickItem *parent = Q_NULLPTR);
    virtual ~Note();

    virtual void paint(QPainter *painter);
};

#endif // NOTE_H
