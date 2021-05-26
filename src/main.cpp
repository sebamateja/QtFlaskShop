#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QScopedPointer>
#include <QDebug>
#include <QQuickView>
#include "ShopService.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QScopedPointer<ShopService, QScopedPointerDeleteLater> m_shopService;

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    engine.rootContext()->setContextProperty("shopService", &m_shopService);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
