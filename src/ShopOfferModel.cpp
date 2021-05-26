#include "ShopOfferModel.h"


ShopOfferModel::ShopOfferModel(QObject *parent)
    : QAbstractListModel(parent)
{

}

QHash<int, QByteArray> ShopOfferModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[PriceRole] = "price";
    roles[WeightRole] = "weight";
    return roles;
}

QVariant ShopOfferModel::data(const QModelIndex & index, int role) const {
    const int row = index.row();

    if (isIndexValid(row))
    {
        const auto &item = m_data.at(row);
        switch (role)
        {
            case NameRole:
                return item->name();
            case PriceRole:
                return item->price();
            case WeightRole:
                return item->weight();
            default:
                break;
        }
    }
    return QVariant();
}

void ShopOfferModel::add(Product *item)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_data.append(item);
    endInsertRows();
}

Product *ShopOfferModel::get(int index)
{
    return m_data.at(index);
}

bool ShopOfferModel::isIndexValid(int index) const
{
    return index >= 0 && index < m_data.size();
}
