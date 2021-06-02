#ifndef SHOPSERVICE_H
#define SHOPSERVICE_H

#include <QObject>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "Product.h"
#include "ShopOfferModel.h"

class ShopService : public QObject
{
    Q_OBJECT
    Q_PROPERTY(ShopOfferModel* shopOfferModel READ shopOfferModel CONSTANT)

public:
    ShopService(QObject *parent = nullptr);

    ShopOfferModel *shopOfferModel()
    {
        return &m_shopOfferModel;
    }

    void addItemToShopOffer(Product *item);


private:
    ShopOfferModel m_shopOfferModel;

    QJsonArray readJsonData(const QString &filename);
    void populateShopOfferModel();
};

Q_DECLARE_METATYPE(QList<Product*>*)

#endif // SHOPSERVICE_H
