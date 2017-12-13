#ifndef NOTATION_H
#define NOTATION_H

#include <QQuickPaintedItem>
#include <QPixmap>

class Notation : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(qreal noteScale READ noteScale WRITE setNoteScale NOTIFY noteScaleChanged)
public:
    Notation(QQuickItem *parent = Q_NULLPTR);
    virtual ~Notation();

    virtual void paint(QPainter *painter);

    qreal noteHeight() const;
    qreal noteDefaultHeight() const;
    qreal noteScale() const;

public slots:
    void setNoteScale(const qreal &scale);

signals:
    void noteScaleChanged(const qreal &scale);

private:
    QPixmap m_MusicKey, m_Note;
    qreal m_NoteScale;
};

#endif // NOTATION_H
