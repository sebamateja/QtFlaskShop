import QtQuick 2.0
import QtQuick.Controls 2.12
import shoppingCart 1.0

Item {
    anchors.fill: parent

    Item {
        id: rowLabels

        height: 60
        width: parent.width

        Text {
            id: textName

            anchors{
                left: parent.left
                leftMargin: 50
            }

            text: qsTr("Name")
        }

        Text {
            id: textPrice

            anchors{
                left: parent.left
                leftMargin: 200
            }

            text: qsTr("Price")
        }

        Text {
            id: weightPrice

            anchors{
                left: parent.left
                leftMargin: 300
            }

            text: qsTr("Weight")
        }
    }

    ListView {
        anchors.fill: parent
        anchors.topMargin: rowLabels.height+10


        model: productList
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
                    id: weightPrice

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
}
