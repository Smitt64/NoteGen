import QtQuick 2.0
import NotationLib 1.0

Note {
    property alias noteType: pNote.note
    id: pNote
    note: Note.NoteCm
    anchors.fill: parent
    opacity: 0.0

    Behavior on opacity {
        PropertyAnimation {
            //to: 1
            duration: 250
        }
    }

    Component.onCompleted: opacity = 1
    onOpacityChanged: {
        if (opacity === 0.0) {
            pNote.destroy()
        }
    }
}
