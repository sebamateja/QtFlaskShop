#include "ShopService.h"

//ShopService::ShopService()
//{

//}

//QJsonArray ShopService::readJsonData(const QString &filename)
//{
//    QFile file;

//    file.setFileName(filename);
//    file.open(QIODevice::ReadOnly | QIODevice::Text);
//    QString value = file.readAll();
//    file.close();

//    QJsonDocument doc = QJsonDocument::fromJson(value.toUtf8());

//    QJsonObject jsonObject = doc.object();

//    return jsonObject.value("products").toArray();
//}

//void ShopService::populateShopOfferModel()
//{
//    const auto jsonArray = readJsonData(":/resource/data.json");

//    foreach (const QJsonValue &value, jsonArray) {
//        QJsonObject obj = value.toObject();

//        m_shopOfferModel.addProduct(Product(
//            obj.value("name").toString(),
//            obj.value("price").toDouble(),
//            obj.value("name").toDouble()));
//    }
//}
