#include "Product.h"

Product::Product()
{

}

Product::Product(const QString &name, double price, double weight)
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

void Product::setName(const QString &name)
{
    if (m_name != name)
    {
        m_name = name;
        emit nameChanged(m_name);
    }
}

void Product::setPrice(double price)
{
    if (!qFuzzyCompare(m_price, price))
    {
        m_price = price;
        emit priceChanged(m_price);
    }
}

void Product::setWeight(double weight)
{
    if (!qFuzzyCompare(m_weight, weight))
    {
        m_weight = weight;
        emit weightChanged(m_weight);
    }
}

void Product::setAmount(int amount)
{
    if (m_amount != amount)
    {
        m_amount = amount;
        emit amountChanged(m_amount);
    }
}

void Product::addAmount()
{
    m_amount++;
    emit amountChanged(m_amount);
}
