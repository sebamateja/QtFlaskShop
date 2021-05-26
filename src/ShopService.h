#ifndef SHOPSERVICE_H
#define SHOPSERVICE_H

#include <QObject>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "productmodel.h"

class ShopService : public QObject
{
    Q_OBJECT

//    Q_PROPERTY(ProductModel* shopOfferModel READ shopOfferModel)
//public:
//    ShopService();

//private:
//    ProductModel m_shopOfferModel;

//    QJsonArray readJsonData(const QString &filename);
//    void populateShopOfferModel();

};

#endif // SHOPSERVICE_H
