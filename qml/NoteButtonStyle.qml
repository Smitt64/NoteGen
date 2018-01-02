import QtQuick 2.0
import QtQuick.Controls.Styles 1.4

ButtonStyle {
    id: buttonStyle
    label: Text {
        text: control.text
        textFormat: Text.RichText
    }
}
