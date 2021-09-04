//#include <QGuiApplication>
//#include <QQmlApplicationEngine>
//#include <QQmlContext>
//#include <QFile>
//#include <QJsonDocument>
//#include <QJsonObject>
//#include <QJsonArray>
//#include <QDebug>
//#include <QQuickView>
//#include "productdata.h"
//#include "productmodel.h"
//#include "shoppingcart.h"
//#include "shopppingcartmodel.h"

#include "ShopService.h"
#include "ShopApp.h"

#include <iostream>

int main(int argc, char *argv[])
{
    try {
        return ShopApp(argc, argv).exec();
    }  catch (std::runtime_error &e) {
        std::cerr << "Exception in ShopApp: " << e.what();
        return -1;
    }
//    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
//    QGuiApplication app(argc, argv);

//    QJsonArray array = readJson(":/resource/data.json");

//    ProductModel productList;

//    foreach (const QJsonValue &value, array) {
//        QJsonObject obj = value.toObject();

//        productList.addProduct(Product(
//            obj.value("name").toString(),
//            obj.value("price").toDouble(),
//            obj.value("name").toDouble()));
//    }

//    qmlRegisterSingletonType<ShoppingCart>("shoppingCart", 1, 0, "ShoppingCart", &ShoppingCart::qmlInstance);

//    ShopppingCartModel cart;

//    QQmlApplicationEngine engine;
//    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
//    engine.rootContext()->setContextProperty("productList", &productList);
//    engine.rootContext()->setContextProperty("cart", &cart);
//    engine.rootContext()->setContextProperty("shopService", &shopService);
//    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
//                     &app, [url](QObject *obj, const QUrl &objUrl) {
//        if (!obj && url == objUrl)
//            QCoreApplication::exit(-1);
//    }, Qt::QueuedConnection);


//    engine.load(url);

//    return app.exec();
}
