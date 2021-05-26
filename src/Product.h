#ifndef PRODUCT_H
#define PRODUCT_H

#include <QObject>

class Product : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(double price READ price WRITE setPrice NOTIFY priceChanged)
    Q_PROPERTY(double weight READ weight WRITE setWeight NOTIFY weightChanged)
    Q_PROPERTY(int amount READ amount WRITE setAmount NOTIFY amountChanged)

public:
    Product();
    Product(const QString &name, double price, double weight);
    virtual ~Product() = default;

    QString name() const;
    double price() const;
    double weight() const;
    int amount() const;

    void setName(const QString &name);
    void setPrice(double price);
    void setWeight(double weight);
    void setAmount(int amount);
    void addAmount();

signals:
    void nameChanged(const QString &name);
    void priceChanged(double price);
    void weightChanged(double weight);
    void amountChanged(int amount);

private:
    QString m_name;
    double m_price;
    double m_weight;
    int m_amount = 0;
};

#endif // PRODUCT_H
