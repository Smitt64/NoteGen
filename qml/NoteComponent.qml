import QtQuick 2.0
import NotationLib 1.0

Note {
    property alias noteType: pNote.note
    id: pNote
    note: Note.NoteCm
    anchors.fill: parent
    opacity: 0.0

    Behavior on opacity {
        PropertyAnimation { duration: 250 }
    }

    SequentialAnimation on noteColor {
        id: badAnim
        loops: Animation.Infinite
        running: false
        ColorAnimation { from: "black"; to: "Red"; duration: 1000 }
        ColorAnimation { from: "Red"; to: "black"; duration: 1000 }
    }

    SequentialAnimation on noteColor {
        id: goodAnim
        loops: Animation.Infinite
        running: false
        ColorAnimation { from: "black"; to: "green"; duration: 1000 }
        ColorAnimation { from: "green"; to: "black"; duration: 1000 }
    }

    function startBad() {
        badAnim.start()
    }

    function startGood() {
        goodAnim.start()
    }

    Component.onCompleted: {
        //anim.start()
        opacity = 1
    }

    onOpacityChanged: {
        if (opacity === 0.0) {
            pNote.destroy()
        }
    }
}
