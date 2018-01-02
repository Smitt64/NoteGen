.import NotationLib 1.0 as NoteLib
.import QtQuick 2.8 as QtQuickLib
.import "common.js" as Script

function stdButtonWidth() {
    return 100;
}

function createButtonObjects(parent, note, handler) {
    var component = Qt.createComponent("NoteButton.qml")

    if (component.status === QtQuickLib.Component.Ready) {
        var btn = component.createObject(parent, {"x": 100, "y": 100, "note": note, "width": stdButtonWidth()})
        btn.activated.connect(rectangle.noteButtonClicked)
    }
}

function createButtons(parent, minor, first, second) {
    var notearr = Script.getNoteArray(minor, first, second)

    for (var i = 0; i < notearr.length; i++) {
        createButtonObjects(parent, notearr[i])
    }
}
