import QtQuick 2.0
import QtQuick.Controls 2.1

Drawer {
    id: drawer
    width: 200
    height: 300

    ListView {
        id: listView
        anchors.fill: parent
        model: ListModel {
            ListElement {
                name: "Grey"
                colorCode: "grey"
            }

            ListElement {
                name: "Red"
                colorCode: "red"
            }

            ListElement {
                name: "Blue"
                colorCode: "blue"
            }

            ListElement {
                name: "Green"
                colorCode: "green"
            }
        }
        delegate: ItemDelegate {
            width: parent.width
            id: itemDelegate
            text: name
        }
    }
}
