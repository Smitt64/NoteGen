var component;
var sprite;

function qmltypeof(obj, className) {
    var str = obj.toString();
    return str.indexOf(className + "(") === 0 || str.indexOf(className + "_QML") === 0;
}

function createNoteObjects(noteView, noteType) {
    component = Qt.createComponent("NoteComponent.qml");
    if (component.status === Component.Ready)
        finishCreation(noteView, noteType)
    else
        component.statusChanged.connect(finishCreation)
}

function finishCreation(noteView, noteType) {
    if (component.status === Component.Ready) {
        sprite = component.createObject(noteView, {"noteType": noteType});
        if (sprite === null) {
            // Error Handling
            console.log("Error creating object");
        }
    } else if (component.status === Component.Error) {
        // Error Handling
        console.log("Error loading component:", component.errorString());
    }
}

function generateRandomNote(minor, first, secont) {
    var noteArray = [];

    if (minor) {
        noteArray.push(Note.NoteEm); // ми (малая октава)
        noteArray.push(Note.NoteFm); // фа (малая октава)
        noteArray.push(Note.NoteGm); // соль (малая октава)
        noteArray.push(Note.NoteAm); // ля (малая октава)
        noteArray.push(Note.NoteBm); // си (малая октава)
        noteArray.push(Note.NoteCm); // до
    }

    if (first) {
        noteArray.push(Note.NoteD1); // ре (1 октава)
        noteArray.push(Note.NoteE1); // ми (1 октава)
        noteArray.push(Note.NoteF1); // фа (1 октава)
        noteArray.push(Note.NoteG1); // соль (1 октава)
        noteArray.push(Note.NoteA1); // ля (1 октава)
        noteArray.push(Note.NoteB1); // си (1 октава)
    }

    if (secont) {
        noteArray.push(Note.NoteD2); // ре (2 октава)
        noteArray.push(Note.NoteE2); // ми (2 октава)
        noteArray.push(Note.NoteF2); // фа (2 октава)
        /*noteArray.push(Note.NoteG2); // соль (2 октава)
        noteArray.push(Note.NoteA2); // ля (2 октава)
        noteArray.push(Note.NoteB2); // си (2 октава)*/
    }

    var rndnoteindex = Math.floor(Math.random() * noteArray.length)
    var notetodisplay = Math.ceil(rndnoteindex);

    return noteArray[notetodisplay]
}
