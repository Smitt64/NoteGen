.import NotationLib 1.0 as NoteLib
.import QtQuick 2.8 as QtQuickLib

function qmltypeof(obj, className) {
    var str = obj.toString();
    return str.indexOf(className + "(") === 0 || str.indexOf(className + "_QML") === 0;
}

function createNoteObjects(noteView, noteType) {
    var component = Qt.createComponent("NoteComponent.qml");
    if (component.status === QtQuickLib.Component.Ready) {
        var sprite = component.createObject(noteView, {"noteType": noteType});
        if (sprite === null) {
            console.log("Error creating object");
        }
    }
}

function getNoteArray(minor, first, secont) {
    var noteArray = [];
    if (minor) {
        noteArray.push(NoteLib.Note.NoteEm); // ми (малая октава)
        noteArray.push(NoteLib.Note.NoteFm); // фа (малая октава)
        noteArray.push(NoteLib.Note.NoteGm); // соль (малая октава)
        noteArray.push(NoteLib.Note.NoteAm); // ля (малая октава)
        noteArray.push(NoteLib.Note.NoteBm); // си (малая октава)
        noteArray.push(NoteLib.Note.NoteCm); // до
    }

    if (first) {
        noteArray.push(NoteLib.Note.NoteD1); // ре (1 октава)
        noteArray.push(NoteLib.Note.NoteE1); // ми (1 октава)
        noteArray.push(NoteLib.Note.NoteF1); // фа (1 октава)
        noteArray.push(NoteLib.Note.NoteG1); // соль (1 октава)
        noteArray.push(NoteLib.Note.NoteA1); // ля (1 октава)
        noteArray.push(NoteLib.Note.NoteB1); // си (1 октава)
    }

    if (secont) {
        noteArray.push(NoteLib.Note.NoteD2); // ре (2 октава)
        noteArray.push(NoteLib.Note.NoteE2); // ми (2 октава)
        noteArray.push(NoteLib.Note.NoteF2); // фа (2 октава)
        /*noteArray.push(Note.NoteG2); // соль (2 октава)
        noteArray.push(Note.NoteA2); // ля (2 октава)
        noteArray.push(Note.NoteB2); // си (2 октава)*/
    }
    return noteArray;
}

function generateRandomNote(minor, first, secont) {
    var noteArray = getNoteArray(minor, first, secont);
    var rndnoteindex = Math.floor(Math.random() * noteArray.length)
    var notetodisplay = Math.ceil(rndnoteindex);

    return noteArray[notetodisplay]
}
