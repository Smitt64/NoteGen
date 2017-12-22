import QtQuick 2.0
import QtQuick.Dialogs 1.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.1
import Qt.labs.settings 1.0

Dialog {
    property alias minor: settings.minor
    property alias first: settings.first
    property alias second: settings.second

    title: qsTr("Параметры")
    contentItem: ListView {
        id: listView
        Layout.fillWidth: true
        Layout.fillHeight: true
        implicitWidth: 400
        implicitHeight: 150
        clip: true

        model: ListModel {
            ListElement { checkstate: "minor"; title: qsTr("Малая октава") }
            ListElement { checkstate: "first"; title: qsTr("Первая октава") }
            ListElement { checkstate: "second"; title: qsTr("Вторая октава") }
        }

        delegate: SwitchDelegate {
            text: title
            width: listView.width
            checked: settings[checkstate]

            onCheckedChanged: {
                settings[checkstate] = checked
            }
        }
    }

    Settings {
        id: settings
        category: "NoteGenerator"
        property bool minor: true
        property bool first: true
        property bool second: true
    }
}
