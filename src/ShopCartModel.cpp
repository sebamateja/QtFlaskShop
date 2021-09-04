#include "ShopCartModel.h"

ShopCartModel::ShopCartModel(QObject *parent) : QAbstractListModel(parent)
{

}

QHash<int, QByteArray> ShopCartModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Name] = "name";
    roles[Price] = "price";
    roles[Weight] = "weight";
    roles[Amount] = "amount";
    return roles;
}

int ShopCartModel::rowCount(const QModelIndex &) const
{
    return m_data.size();
}

QVariant ShopCartModel::data(const QModelIndex &index, int role) const
{
    const int row = index.row();

    if (!isIndexValid(row))
    {
        return QVariant();
    }

    switch (role)
    {
    case static_cast<int>(ShopCartRoles::Name):
    {
        return m_data.at(row).name;
    }
    case static_cast<int>(ShopCartRoles::Price):
    {
        return m_data.at(row).price;
    }
    case static_cast<int>(ShopCartRoles::Weight):
    {
        return m_data.at(row).weight;
    }
    case static_cast<int>(ShopCartRoles::Amount):
    {
        return m_data.at(row).amount;
    }
    default:
    {
        return QVariant();
    }
    }
}

void ShopCartModel::add(const ShopTypes::Product &product)
{
    const int number = std::count_if(m_data.begin(), m_data.end(), [&product](const ShopTypes::Product & _product){
        return _product.id == product.id;
    });

    if (number == 0)
    {
        beginInsertRows(QModelIndex(), rowCount(), rowCount());
        m_data.append({product, 1});
        endInsertRows();
        return;
    }
    if (number > 0)
    {
        auto index = getIndexById(product.id);
        if (index.has_value())
        {
            auto &item = m_data[index.value()];
            item.amount += 1;
            notifyDataChanged(index.value());
            return;
        }
    }
}

std::optional<ShopTypes::ExtendedProduct> ShopCartModel::getItemById(int id)
{
    for (const auto &item : m_data)
    {
        if (item.id == id)
        {
            return item;
        }
    }
    return std::nullopt;
}

std::optional<int> ShopCartModel::getIndexById(int id)
{
    for (int i=0;i<m_data.size();++i)
    {
        if (m_data.at(i).id == id)
        {
            return i;
        }
    }
    return std::nullopt;
}

bool ShopCartModel::isIndexValid(int index) const
{
    return index >= 0 && index < m_data.size();
}

void ShopCartModel::notifyDataChanged(int index)
{
    const QModelIndex modelIndex = createIndex(index, 0);
    emit dataChanged(modelIndex, modelIndex);
}
