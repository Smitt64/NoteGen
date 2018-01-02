import QtQuick 2.0
import QtQuick.Controls 2.3
import NotationLib 1.0
import "NoteTest.js" as NoteT
import "common.js" as Script

Rectangle {
    id: rectangle
    anchors.fill: parent
    NotationView {
        id: view
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        noteScale: 0.5
        state: ""

        Component.onCompleted: {
            generateNote()
            view.state = "clefenter"
        }
    }

    ScrollView {
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.top: view.bottom
        contentHeight: grid.height
        clip: true

        Grid {
            id: grid
            spacing: 6
            anchors.centerIn: parent
            columns: rectangle.width / (NoteT.stdButtonWidth() + grid.spacing)
            add: Transition {
                NumberAnimation { property: "opacity"; from: 0; to: 1.0; duration: 400 }
                NumberAnimation { property: "scale"; from: 0; to: 1.0; duration: 400 }
            }
        }

    }

    Component.onCompleted: createButtons();

    function createButtons() {
        NoteT.createButtons(grid, true, true, true)
    }

    function generateNote() {
        for(var i = view.children.length; i > 0 ; i--)
        {
            if (Script.qmltypeof(view.children[i-1], "NoteComponent"))
                view.children[i-1].opacity = 0.0
        }
        var notetype = Script.generateRandomNote(settingsDialog.minor, settingsDialog.first, settingsDialog.second)
        Script.createNoteObjects(view, notetype, noteButtonClicked)
        titleLabel.text = ApiNote.noteDisplayName(notetype) + "(" + ApiNote.noteLangName(notetype) + ")"
    }

    function noteButtonClicked(note) {
        console.log(ApiNote.noteLangName(note))

        var firstNote = view.findFirstNote()
        if (firstNote.note === note) {
            firstNote.startGood()
        } else {
            firstNote.startBad()
        }
    }
}
