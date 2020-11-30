#ifndef PRODUCTDATA_H
#define PRODUCTDATA_H

#include <QObject>

class Product {
public:
    Product();
    Product(const QString &name, const double &price, const double &weight);

    QString name() const;
    double price() const;
    double weight() const;
    int amount() const;

    void setName(QString);
    void setPrice(double);
    void setWeight(double);
    void addAmount();

private:
    QString m_name;
    double m_price;
    double m_weight;
    int m_amount = 0;
};

#endif // PRODUCTDATA_H
