#ifndef NOTATION_H
#define NOTATION_H

#include <QQuickPaintedItem>
#include <QPixmap>
#include "trebleclef.h"

class Notation : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(qreal noteScale READ noteScale WRITE setNoteScale NOTIFY noteScaleChanged)
public:
    enum MusicNote
    {
        NoteUnknown,
        NoteC,       // до
        NoteD,       // ре
        NoteE,       // ми
        NoteF,       // фа
        NoteG,       // соль
        NoteA,       // ля
        NoteB,       // си
    };
    Q_ENUM(MusicNote)
    Notation(QQuickItem *parent = Q_NULLPTR);
    virtual ~Notation();

    QFont font() const;
    virtual void paint(QPainter *painter);

    qreal noteHeight() const;
    qreal noteDefaultHeight() const;
    qreal noteScale() const;

public slots:
    void setNoteScale(const qreal &scale);

signals:
    void noteScaleChanged(const qreal &scale);

private:
    //QPoint FindNoteY(const MusicNote &note);
    QPixmap m_MusicKey, m_Note;
    qreal m_NoteScale;
    QFont m_Font;
};

#endif // NOTATION_H
