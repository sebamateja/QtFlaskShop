#include "shopppingcartmodel.h"

ShopppingCartModel::ShopppingCartModel(QObject *parent)
    : QAbstractListModel(parent)
{

}

void ShopppingCartModel::addProduct(const Product &product)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_products << product;
    endInsertRows();
}

int ShopppingCartModel::rowCount(const QModelIndex & parent) const {
    Q_UNUSED(parent)
    return m_products.count();
}

QVariant ShopppingCartModel::data(const QModelIndex & index, int role) const {
    if (index.row() < 0 || index.row() >= m_products.count())
        return QVariant();

    const Product &product = m_products[index.row()];
    if (role == NameRole)
        return product.name();
    else if (role == PriceRole)
        return product.price();
    else if (role == WeightRole)
        return product.weight();
    else if (role == AmountRole)
        return product.amount();
    return QVariant();
}

QHash<int, QByteArray> ShopppingCartModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[PriceRole] = "price";
    roles[WeightRole] = "weight";
    roles[AmountRole] = "amount";
    return roles;
}
