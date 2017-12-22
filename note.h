#ifndef NOTE_H
#define NOTE_H

#include <QQuickPaintedItem>
#include "notation.h"

class Note : public QQuickPaintedItem
{
    Q_OBJECT
    friend class Notation;
    Q_PROPERTY(MusicNote note READ note WRITE setNote)
public:
    enum MusicNote
    {
        NoteUnknown = 1,
        NoteEm,      // ми (малая октава)
        NoteFm,      // фа (малая октава)
        NoteGm,      // соль (малая октава)
        NoteAm,      // ля (малая октава)
        NoteBm,      // си (малая октава)
        NoteCm,      // до
        NoteD1,      // ре (1 октава)
        NoteE1,      // ми (1 октава)
        NoteF1,      // фа (1 октава)
        NoteG1,      // соль (1 октава)
        NoteA1,      // ля (1 октава)
        NoteB1,      // си (1 октава)
        NoteC2,      // до (2 октава)
        NoteD2,      // ре (2 октава)
        NoteE2,      // ми (2 октава)
        NoteF2,      // фа (2 октава)
        NoteG2,      // соль (2 октава)
        NoteA2,      // ля (2 октава)
        NoteB2,      // си (2 октава)
    };
    Q_ENUM(MusicNote)
    Note(QQuickItem *parent = Q_NULLPTR);
    virtual ~Note();

    virtual void paint(QPainter *painter);

    MusicNote note() const;
    void setNote(const MusicNote &n);

    static QString noteName(const MusicNote &v);

public slots:
    Q_INVOKABLE qint16 noteLine(bool &isUnderLine);
    Q_INVOKABLE bool hasAddLine() const;
    Q_INVOKABLE bool isSecondOctave() const;

private:
    MusicNote m_Note;
    qreal m_X;
};

#endif // NOTE_H
