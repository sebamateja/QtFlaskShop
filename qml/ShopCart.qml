import QtQuick 2.15
import QtQuick.Controls 2.15

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
            text: qsTr("CART")
        }

        Image {
            width: 100
            height: 100
            source: "qrc:/resource/Images/basket-cart-icon.png"
        }
    }

    ListView {
        id: listView

        anchors.centerIn: parent

        width: 1200
        height: 700

        spacing: 10

        clip: true
        model: shopService.shopCartModel
        orientation: Qt.Vertical
        delegate: ShopCartDelegate {}
    }

    Text {
        anchors.centerIn: listView

        font.pixelSize: 40
        text: qsTr("No items in shopping cart")
        visible: listView.count === 0
    }
}
