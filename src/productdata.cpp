#include "productdata.h"

Product::Product()
{

}

Product::Product(const QString &name, const double &price, const double &weight)
    : m_name(name), m_price(price), m_weight(weight)
{
}

QString Product::name() const
{
    return m_name;
}

double Product::price() const
{
    return m_price;
}

double Product::weight() const
{
    return m_weight;
}

int Product::amount() const
{
    return m_amount;
}

void Product::setName(QString name)
{
    m_name = name;
}

void Product::setPrice(double price)
{
    m_price = price;
}

void Product::setWeight(double weight)
{
    m_weight = weight;
}

void Product::addAmount()
{
    m_amount++;
}
