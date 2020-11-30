#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QObject>
#include <QQmlEngine>
#include <QJSEngine>
#include <QDebug>
#include "productdata.h"

struct ShoppingProductPosition {
    Product product;
    int amount = 0;
};

Q_DECLARE_METATYPE(ShoppingProductPosition)

class ShoppingCart : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<ShoppingProductPosition> productList READ productList WRITE setProductList NOTIFY productListChanged)

public:
    ShoppingCart(QObject *parent=0);
    static QObject *qmlInstance(QQmlEngine *, QJSEngine *);

    void setProductList(QList<ShoppingProductPosition>);

    QList<ShoppingProductPosition> productList() const;

public slots:
    void addProduct(QString name, double price, double weight);
    QList<ShoppingProductPosition> getList();
    int length();

signals:
    void productListChanged();

private:
    QList<ShoppingProductPosition> m_shoppingList;
};

#endif // SHOPPINGCART_H
