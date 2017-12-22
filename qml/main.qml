import QtQuick 2.8
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.1
import Qt.labs.settings 1.0
import QtQuick.Controls.Material 2.3
import NotationLib 1.0
import "common.js" as Script

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    Material.theme: Material.Dark

    header: ToolBar {
        id: toolBar

        RowLayout {
            spacing: 20
            anchors.fill: parent

            ToolButton {
                Image {
                    anchors.rightMargin: parent.width / 4
                    anchors.leftMargin: parent.width / 4
                    anchors.bottomMargin: parent.width / 4
                    anchors.topMargin: parent.width / 4
                    anchors.fill: parent
                    source: "qrc:///img/20x20@3/drawer.png"
                }

                onClicked: {
                        drawer.open()
                }
            }

            Label {
                id: titleLabel
                text: "Gallery"
                font.pixelSize: 20
                elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
                textFormat: Text.RichText
            }

            ToolButton {
                Image {
                    anchors.fill: parent
                    anchors.rightMargin: parent.width / 4
                    anchors.leftMargin: parent.width / 4
                    anchors.bottomMargin: parent.width / 4
                    anchors.topMargin: parent.width / 4
                    source: "qrc:///img/20x20@3/menu.png"
                }
                onClicked: optionsMenu.open()

                Menu {
                    id: optionsMenu
                    x: parent.width - width
                    transformOrigin: Menu.TopRight

                    MenuItem {
                        text: "Settings"
                        onTriggered: settingsDialog.open()
                    }

                    MenuItem {
                        text: "Default scale"
                        onTriggered: scaleSlide.value = 0.5
                    }

                    MenuItem {
                        Slider {
                            id: scaleSlide
                            anchors.rightMargin: 0
                            anchors.leftMargin: 0
                            anchors.left: parent.left
                            anchors.right: parent.right
                            value: 0.5
                            onValueChanged: view.update()
                        }
                    }
                }
            }
        }
    }

    Drawer {
        id: drawer
        width: Math.min(window.width, window.height) / 3 * 2
        height: window.height
    }

    NotationView {
        id: view
        anchors.fill: parent
        noteScale: scaleSlide.value
        state: ""
        Component.onCompleted: {
            generateNote()
            view.state = "clefenter"
        }
    }

    SettingsDialog {
        id: settingsDialog
        x: (parent.width - width) / 2
        y: (parent.height - height) / 2
    }

    function generateNote() {
        for(var i = view.children.length; i > 0 ; i--)
        {
            if (Script.qmltypeof(view.children[i-1], "NoteComponent"))
                view.children[i-1].opacity = 0.0
        }
        var notetype = Script.generateRandomNote(settingsDialog.minor, settingsDialog.first, settingsDialog.second)
        Script.createNoteObjects(view, notetype)
        titleLabel.text = ApiNote.noteDisplayName(notetype)
    }

    footer: Button {
        id: button
        text: qsTr("Получить ноту")

        onClicked: generateNote()
    }
}
