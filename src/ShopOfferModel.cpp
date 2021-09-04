#include "ShopOfferModel.h"

ShopOfferModel::ShopOfferModel(QObject *parent) : QAbstractListModel(parent)
{

}

QHash<int, QByteArray> ShopOfferModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Name] = "name";
    roles[Price] = "price";
    roles[Weight] = "weight";
    return roles;
}

int ShopOfferModel::rowCount(const QModelIndex &) const
{
    return m_data.size();
}

QVariant ShopOfferModel::data(const QModelIndex &index, int role) const
{
    const int row = index.row();

    if (!isIndexValid(row))
    {
        return QVariant();
    }

    switch (role)
    {
    case static_cast<int>(ShopOfferRoles::Name):
    {
        return m_data.at(row).name;
    }
    case static_cast<int>(ShopOfferRoles::Price):
    {
        return m_data.at(row).price;
    }
    case static_cast<int>(ShopOfferRoles::Weight):
    {
        return m_data.at(row).weight;
    }
    default:
    {
        return QVariant();
    }
    }
}

void ShopOfferModel::addProduct(const ShopTypes::Product &product)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_data.append(product);
    endInsertRows();
}

std::optional<ShopTypes::Product> ShopOfferModel::getItem(int index) const
{
    if (!isIndexValid(index))
    {
        return std::nullopt;
    }

    return m_data.at(index);
}

bool ShopOfferModel::isIndexValid(int index) const
{
    return index >= 0 && index < m_data.size();
}
