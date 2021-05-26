import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import "ViewModel/"
import "../qml/ViewModel"

ApplicationWindow {
    width: 1920
    height: 1080
    title: qsTr("FlaskShop")

    MainApp {}

//    // Probably better to use StackView here
//    // not different components and visible changes
//    header: ToolBar {
//        RowLayout {
//            anchors.fill: parent
//            ToolButton {
//                text: qsTr("Products")
//                onClicked: {
//                    shoppingCart.visible = false
//                    settings.visible = false
//                    productList.visible = true
//                }
//            }
//            ToolButton {
//                text: qsTr("Cart")
//                onClicked: {
//                    settings.visible = false
//                    productList.visible = false
//                    shoppingCart.visible = true
//                }
//            }
//            ToolButton {
//                text: qsTr("Settings")
//                onClicked: {
//                    productList.visible = false
//                    shoppingCart.visible = false
//                    settings.visible = true
//                }
//            }
//        }
//    }

//    ProductList {
//        id: productList
//        visible: true
//    }

//    ShoppingCart {
//        id: shoppingCart

//        visible: false
//    }

//    Settings {
//        id: settings
//        visible: false
//    }
}
