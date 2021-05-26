#ifndef SHOP_OFFER_MODEL_H
#define SHOP_OFFER_MODEL_H

#include <QAbstractListModel>
#include <QObject>
#include "Product.h"

class ShopOfferModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ShopOfferModel(QObject *parent = nullptr);
    virtual ~ShopOfferModel() = default;

    enum ShopOfferRoles {
        NameRole = Qt::UserRole,
        PriceRole,
        WeightRole
    };

    QHash<int, QByteArray> roleNames() const override;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;

    Product *get(int index);

    const QList<Product*> &items() const
    {
        return m_data;
    }
private:
    QList<Product *> m_data;

    bool isIndexValid(int index) const;
};

#endif // SHOP_OFFER_MODEL_H
