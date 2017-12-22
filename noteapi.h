#ifndef NOTEAPI_H
#define NOTEAPI_H

#include <QObject>
#include <QMap>

class NoteApi : public QObject
{
    Q_OBJECT

    typedef struct tagNoteData
    {
        qint16 m_Line;
        bool m_isUnderline;
        QString m_LangName;
        QString m_Name;
        QString m_DisplayName;

        tagNoteData(qint16 Line, bool isUnderline, QString LangName, QString Name, QString DisplayName);
        tagNoteData();
    }NoteData;
public:
    explicit NoteApi(QObject *parent = nullptr);
    virtual ~NoteApi();

signals:

public slots:
    Q_INVOKABLE qint16 noteLine(const qint16 &note, bool &isUnderLine) const;
    Q_INVOKABLE bool isUnderLine(const qint16 &note) const;
    Q_INVOKABLE bool isSecondOctave(const qint16 &note) const;
    Q_INVOKABLE bool isFirstOctave(const qint16 &note) const;
    Q_INVOKABLE QString noteLangName(const qint16 &note) const;
    Q_INVOKABLE QString noteDisplayName(const qint16 &note) const;

private:
    tagNoteData findNote(const qint16 &note) const;
    QMap<qint16, NoteData> m_NoteData;
};

Q_GLOBAL_STATIC(NoteApi, pNoteApi)

#endif // NOTEAPI_H
