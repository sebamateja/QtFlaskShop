#include "shoppingcart.h"

ShoppingCart::ShoppingCart(QObject *parent) : QObject(parent)
{

}

QObject *ShoppingCart::qmlInstance(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    return new ShoppingCart;
}

void ShoppingCart::setProductList(QList<ShoppingProductPosition> shoppingList) {
    m_shoppingList = shoppingList;
    productListChanged();
}

QList<ShoppingProductPosition> ShoppingCart::productList() const
{
    return m_shoppingList;
}

void ShoppingCart::addProduct(QString name, double price, double weight)
{

    qDebug() << "Add product!";
    foreach(ShoppingProductPosition value, m_shoppingList) {
        if (value.product.name() == name) {
            value.amount += 1;
            return;
        }
    }

    ShoppingProductPosition productPosition;
    Product prod(name, price, weight);
    productPosition.product = prod;
    productPosition.amount = 0;

    m_shoppingList.push_back(productPosition);

    qDebug() << name;
}

QList<ShoppingProductPosition> ShoppingCart::getList()
{
    return m_shoppingList;
}

int ShoppingCart::length()
{
    return m_shoppingList.length();
}
