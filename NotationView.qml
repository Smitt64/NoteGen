import QtQuick 2.8
import QtQuick.Window 2.2
import NotationLib 1.0

Notation {
    TrebleClef {
        id: trebleClef
        opacity: 0
        anchors.fill: parent
    }

    states: [
        State {
            name: "clefenter"

            PropertyChanges {
                target: trebleClef
                opacity: 1
            }
        }
    ]

    transitions: [
        Transition {
            from: ""
            to: "clefenter"
            PropertyAnimation { target: trebleClef; easing.type: Easing.InCubic; duration: 500; properties: "opacity"}
        }
    ]
}
