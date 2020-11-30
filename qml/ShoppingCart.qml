import QtQuick 2.0
import QtQuick.Controls 2.12
import shoppingCart 1.0

Item {
    id: root

    anchors.fill: parent

    property var mylist: ShoppingCart.getList()

    Text {
        text: qsTr("Cart") + ShoppingCart.length()

        anchors.centerIn: parent
    }

    ListView {
        id: list
        anchors.fill: parent
        anchors.topMargin: 100


        model: mylist
        orientation: Qt.Vertical

        Component {
            id: productDelegate
            Item {
                height: 100
                width: parent.width
                anchors.topMargin: 20

                Text {
                    id: textName

                    anchors{
                        left: parent.left
                        leftMargin: 50
                    }

                    text: name
                }

                Text {
                    id: textPrice

                    anchors{
                        left: parent.left
                        leftMargin: 200
                    }

                    text: price + qsTr(" PLN")
                }

                Text {
                    id: textWeight

                    anchors{
                        left: parent.left
                        leftMargin: 300
                    }

                    text: weight + qsTr(" kg")
                }

                Button {
                    id: cartButton

                    anchors{
                        right: parent.right
                        rightMargin: 40
                    }

                    text: "Add to cart"

                    onClicked: {
                        ShoppingCart.addProduct(name, price, weight)
                    }
                }

                Rectangle {
                    anchors {
                        top: cartButton.bottom
                        topMargin: 10
                    }

                    height: 4
                    width: parent.width

                    color: "black"
                }
            }
        }
        delegate: productDelegate
    }

    Timer {
        interval: 1000
        repeat: true
        running: true
        onTriggered: {
            console.log("Number of elements(without duplicates)", ShoppingCart.length())
        }
    }
}
