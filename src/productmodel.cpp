#include "productmodel.h"

ProductModel::ProductModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

void ProductModel::addProduct(const Product &product)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_products << product;
    endInsertRows();
}

int ProductModel::rowCount(const QModelIndex & parent) const {
    Q_UNUSED(parent)
    return m_products.count();
}

QVariant ProductModel::data(const QModelIndex & index, int role) const {
    if (index.row() < 0 || index.row() >= m_products.count())
        return QVariant();

    const Product &product = m_products[index.row()];
    if (role == NameRole)
        return product.name();
    else if (role == PriceRole)
        return product.price();
    else if (role == WeightRole)
        return product.weight();
    return QVariant();
}

QHash<int, QByteArray> ProductModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[PriceRole] = "price";
    roles[WeightRole] = "weight";
    return roles;
}
