import QtQuick 2.8
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.1
import Qt.labs.settings 1.0

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    header: ToolBar {
        //Material.foreground: "white"

        RowLayout {
            spacing: 20
            anchors.fill: parent

            ToolButton {
                Image {
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
            }

            ToolButton {
                Image {
                    anchors.fill: parent
                    source: "qrc:///img/20x20@3/menu.png"
                }
                onClicked: optionsMenu.open()

                Menu {
                    id: optionsMenu
                    x: parent.width - width
                    transformOrigin: Menu.TopRight

                    MenuItem {
                        text: "Settings"
                        //onTriggered: settingsDialog.open()
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
        Component.onCompleted: view.state = "clefenter"
    }

    Popup {
        id: scalePopup
    }
}
