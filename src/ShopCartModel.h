#ifndef SHOPCARTMODEL_H
#define SHOPCARTMODEL_H

#include <QAbstractListModel>
#include "ShopTypes.h"

#include <QDebug>

class ShopCartModel final : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ShopCartModel(QObject *parent = nullptr);
    virtual ~ShopCartModel() = default;

    enum ShopCartRoles
    {
        Name = Qt::UserRole,
        Price,
        Weight,
        Amount
    };

     QHash<int, QByteArray> roleNames() const override;
     int rowCount(const QModelIndex &parent = QModelIndex()) const override;
     QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

     void add(const ShopTypes::Product &product);

     const QList<ShopTypes::ExtendedProduct> &items() const
     {
         return m_data;
     }

private:
     QList<ShopTypes::ExtendedProduct> m_data;

     std::optional<ShopTypes::ExtendedProduct> getItemById(int id);
     std::optional<int> getIndexById(int id);
     bool isIndexValid(int index) const;
     void notifyDataChanged(int index);
};

#endif // SHOPCARTMODEL_H
