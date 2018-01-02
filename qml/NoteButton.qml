import QtQuick 2.0
import QtQuick.Controls 2.1
import NotationLib 1.0
import QtQuick.Controls.Styles 1.4

Button {
    property int note: Note.NoteUnknown
    signal activated(int btnNote)
    id: button
    //style: NoteButtonStyle {}

    contentItem: Text {
        text: button.text
        font: button.font
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
        textFormat: Text.RichText
    }

    onClicked: activated(button.note)
    onNoteChanged: {
        button.text = ApiNote.noteDisplayName(button.note)
    }
}
