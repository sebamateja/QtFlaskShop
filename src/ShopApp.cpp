#include <QQmlContext>
#include "ShopApp.h"


ShopApp::ShopApp(int argc, char *argv[]) : QGuiApplication(argc, argv)
{
    m_shopService.reset(new ShopService());
    m_view.rootContext()->setContextProperty("shopService", m_shopService.get());
    m_view.setSource(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    m_view.show();
}
