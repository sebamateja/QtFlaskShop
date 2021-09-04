#ifndef SHOPSERVICE_H
#define SHOPSERVICE_H

#include <QObject>
#include "ShopOfferModel.h"
#include "ShopCartModel.h"

#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class ShopService final : public QObject
{

    Q_OBJECT
    Q_PROPERTY(ShopOfferModel *shopOfferModel READ shopOfferModel  CONSTANT)
    Q_PROPERTY(ShopCartModel *shopCartModel READ shopCartModel  CONSTANT)

public:
    explicit ShopService(QObject *parent = nullptr);
    virtual ~ShopService() = default;

    Q_INVOKABLE void addProductToCart(int index);

    inline ShopOfferModel *shopOfferModel()
    {
        return &m_shopOfferModel;
    }

    inline ShopCartModel *shopCartModel()
    {
        return &m_shopCartModel;
    }

private:
    ShopOfferModel m_shopOfferModel;
    ShopCartModel m_shopCartModel;

    QJsonArray readJson(const QString &filename);
};

#endif // SHOPSERVICE_H
