#ifndef PRODUCTMODEL_H
#define PRODUCTMODEL_H

#include <QAbstractItemModel>
#include <QStringList>
#include "productdata.h"

class ProductModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum ProductRoles {
        NameRole = Qt::UserRole + 1,
        PriceRole,
        WeightRole
    };

    ProductModel(QObject *parent = 0);

    void addProduct(const Product &product);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;
private:
    QList<Product> m_products;
};

#endif // PRODUCTMODEL_H
