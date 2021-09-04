#ifndef SHOPOFFERMODEL_H
#define SHOPOFFERMODEL_H

#include <QAbstractListModel>
#include "ShopTypes.h"

class ShopOfferModel final : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ShopOfferModel(QObject *parent = nullptr);
    virtual ~ShopOfferModel() = default;

    enum ShopOfferRoles
    {
        Name = Qt::UserRole,
        Price,
        Weight
    };

     QHash<int, QByteArray> roleNames() const override;
     int rowCount(const QModelIndex &parent = QModelIndex()) const override;
     QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

     void addProduct(const ShopTypes::Product &product);
     std::optional<ShopTypes::Product> getItem(int index) const;

     const QList<ShopTypes::Product> &items() const
     {
         return m_data;
     }

private:
     QList<ShopTypes::Product> m_data;

     bool isIndexValid(int index) const;
};

#endif // SHOPOFFERMODEL_H
