#ifndef SHOPPPINGCARTMODEL_H
#define SHOPPPINGCARTMODEL_H

#include <QAbstractListModel>
#include <QStringList>
#include "productdata.h"

class ShopppingCartModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum ProductRoles {
        NameRole = Qt::UserRole + 1,
        PriceRole,
        WeightRole,
        AmountRole
    };

    ShopppingCartModel(QObject *parent = 0);

    void addProduct(const Product &product);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<Product> m_products;
};

#endif // SHOPPPINGCARTMODEL_H
