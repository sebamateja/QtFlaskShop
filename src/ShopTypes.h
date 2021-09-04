#ifndef SHOPTYPES_H
#define SHOPTYPES_H

#include <QObject>

namespace ShopTypes
{

void registerCustomMetaTypes();

struct Product
{
    Q_GADGET

public:
    Q_PROPERTY(QString name MEMBER name)
    Q_PROPERTY(double price MEMBER price)
    Q_PROPERTY(double weight MEMBER weight)

    int id;
    QString name;
    double price;
    double weight;
};

struct ExtendedProduct : Product
{
    Q_GADGET

public:
    Q_PROPERTY(int amount MEMBER amount)

    int amount;
};

}

Q_DECLARE_METATYPE(ShopTypes::Product)
Q_DECLARE_METATYPE(ShopTypes::ExtendedProduct)

#endif // SHOPTYPES_H
