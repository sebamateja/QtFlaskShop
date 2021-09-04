#include "ShopService.h"

ShopService::ShopService(QObject *parent) : QObject(parent)
{
    QJsonArray array = readJson(":/resource/data.json");

    foreach (const QJsonValue &value, array) {
        QJsonObject obj = value.toObject();

        m_shopOfferModel.addProduct({
                obj.value("id").toInt(),
                obj.value("name").toString(),
                obj.value("price").toDouble(),
                obj.value("weight").toDouble()
            });
    }
}

void ShopService::addProductToCart(int index)
{
    const auto item = m_shopOfferModel.getItem(index);
    if (!item.has_value())
    {
        return;
    }
    m_shopCartModel.add(item.value());
}

QJsonArray ShopService::readJson(const QString &filename)
{
    QString value;
    QFile file;

    file.setFileName(filename);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    value = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(value.toUtf8());

    QJsonObject jsonObject = doc.object();

    return jsonObject.value("products").toArray();
}
