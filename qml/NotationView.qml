import QtQuick 2.8
import QtQuick.Window 2.2
import NotationLib 1.0

Notation {
    width: 500
    height: 200
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
}
