import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    id: root

    width: 1200
    height: internal.delegateHeight

    color: "gray"

    QtObject {
        id: internal

        readonly property int fontSize: 30
        readonly property int delegateHeight: 200
    }

    Row {
        anchors.fill: parent

        Item {
            width: 600
            height: root.height

            Text {
                anchors {
                    verticalCenter: parent.verticalCenter
                    left: parent.left
                    leftMargin: 50
                }

                width: parent.width - 50
                text: name
                elide: Text.ElideRight
                font.pixelSize: internal.fontSize
            }
        }

        Item {
            width: 200
            height: root.height

            Text {
                anchors.centerIn: parent

                text: price + qsTr(" PLN")
                font.pixelSize: internal.fontSize
            }
        }

        Item {
            width: 200
            height: root.height

            Text {
                anchors.centerIn: parent

                text: weight + qsTr(" kg")
                font.pixelSize: internal.fontSize
            }
        }

        Item {
            width: 200
            height: root.height

            Button {
                anchors.centerIn: parent

                width: 140
                height: 70

                text: qsTr("Add to cart")

                onClicked: {
                    shopService.addProductToCart(index)
                }
            }
        }
    }
}
