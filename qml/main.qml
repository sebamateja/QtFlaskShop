import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    height: 1080
    width: 1920

    SwipeView {
        id: swipeView

        anchors.fill: parent

        currentIndex: 0

        ShopOffer {}
        ShopCart {}
        SettingsView {}
    }

    PageIndicator {
        id: indicator

        count: swipeView.count
        currentIndex: swipeView.currentIndex

        anchors.bottom: swipeView.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
