import QtQuick 2.15

Item {
    width: 1920
    height: 1080

    Row {
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: parent.top
            topMargin: 50
        }

        spacing: 30
        height: 100
        width: 500

        Text {
            anchors.verticalCenter: parent.verticalCenter

            font.pixelSize: 50
            text: qsTr("SETTINGS")
        }

        Image {
            width: 100
            height: 100
            source: "qrc:/resource/Images/settings-icon.png"
        }
    }
}
