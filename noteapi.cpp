#include "noteapi.h"
#include "note.h"
#include "notation.h"

NoteApi::tagNoteData::tagNoteData(qint16 Line, bool isUnderline, QString LangName, QString Name, QString DisplayName)
{
    m_Line = Line;
    m_isUnderline = isUnderline;
    m_LangName = LangName;
    m_Name = Name;
    m_DisplayName = DisplayName;
}

NoteApi::tagNoteData::tagNoteData()
{
    m_Line = -1;
    m_isUnderline = false;
    m_LangName = "";
    m_Name = "";
    m_DisplayName = "";
}

NoteApi::NoteApi(QObject *parent)
    : QObject(parent)
{
    m_NoteData[Note::NoteUnknown] = tagNoteData();
    m_NoteData[Note::NoteEm] = tagNoteData(Notation::LineBottom3, true, tr("Ми (малая октава)"), "Em", "E<sup>m</sup>");
    m_NoteData[Note::NoteFm] = tagNoteData(Notation::LineBottom3, false, tr("Фа (малая октава)"), "Fm", "F<sup>m</sup>");
    m_NoteData[Note::NoteGm] = tagNoteData(Notation::LineBottom2, true, tr("Соль (малая октава)"), "Gm", "G<sup>m</sup>");
    m_NoteData[Note::NoteAm] = tagNoteData(Notation::LineBottom2, false, tr("Ля (малая октава)"), "Am", "A<sup>m</sup>");
    m_NoteData[Note::NoteBm] = tagNoteData(Notation::LineBottom1, true, tr("Си (малая октава)"), "Bm", "B<sup>m</sup>");
    m_NoteData[Note::NoteCm] = tagNoteData(Notation::LineBottom1, false, tr("До (малая октава)"), "Cm", "C<sup>m</sup>");
    m_NoteData[Note::NoteD1] = tagNoteData(Notation::LineMain1, true, tr("Ре (1 октава)"), "D1", "D<sup>1</sup>");
    m_NoteData[Note::NoteE1] = tagNoteData(Notation::LineMain1, false, tr("Ми (1 октава)"), "E1", "E<sup>1</sup>");
    m_NoteData[Note::NoteF1] = tagNoteData(Notation::LineMain2, true, tr("Фа (1 октава)"), "F1", "F<sup>1</sup>");
    m_NoteData[Note::NoteG1] = tagNoteData(Notation::LineMain2, false, tr("Соль (1 октава)"), "G1", "G<sup>1</sup>");
    m_NoteData[Note::NoteA1] = tagNoteData(Notation::LineMain3, true, tr("Ля (1 октава)"), "A1", "A<sup>1</sup>");
    m_NoteData[Note::NoteB1] = tagNoteData(Notation::LineMain3, false, tr("Си (1 октава)"), "B1", "B<sup>1</sup>");
    m_NoteData[Note::NoteC2] = tagNoteData(Notation::LineMain4, true, tr("До (2 октава)"), "C2", "C<sup>2</sup>");
    m_NoteData[Note::NoteD2] = tagNoteData(Notation::LineMain4, false, tr("Ре (2 октава)"), "D2", "D<sup>2</sup>");
    m_NoteData[Note::NoteE2] = tagNoteData(Notation::LineMain5, true, tr("Ми (2 октава)"), "E2", "E<sup>2</sup>");
    m_NoteData[Note::NoteF2] = tagNoteData(Notation::LineMain5, false, tr("Фа (2 октава)"), "F2", "F<sup>2</sup>");
}

NoteApi::~NoteApi()
{

}

NoteApi::tagNoteData NoteApi::findNote(const qint16 &note) const
{
    NoteApi::tagNoteData value;

    if (m_NoteData.contains(note))
        value = m_NoteData[note];

    return value;
}

qint16 NoteApi::noteLine(const qint16 &note, bool &isUnderLine) const
{
    NoteApi::tagNoteData value = findNote(note);

    isUnderLine = value.m_isUnderline;
    return value.m_Line;
}

bool NoteApi::isUnderLine(const qint16 &note) const
{
    NoteApi::tagNoteData value = findNote(note);
    return value.m_Name.contains("m");
}

bool NoteApi::isSecondOctave(const qint16 &note) const
{
    NoteApi::tagNoteData value = findNote(note);
    return value.m_Name.contains("2");
}

bool NoteApi::isFirstOctave(const qint16 &note) const
{
    NoteApi::tagNoteData value = findNote(note);
    return value.m_Name.contains("1");
}

QString NoteApi::noteLangName(const qint16 &note) const
{
    NoteApi::tagNoteData value = findNote(note);
    return value.m_LangName;
}

QString NoteApi::noteDisplayName(const qint16 &note) const
{
    NoteApi::tagNoteData value = findNote(note);
    return value.m_DisplayName;
}
