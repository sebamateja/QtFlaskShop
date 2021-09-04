#ifndef SHOPAPP_H
#define SHOPAPP_H

#include <QGuiApplication>
#include <QQuickView>
#include <QScopedPointer>
#include "ShopService.h"

class ShopApp final : public QGuiApplication
{
public:
    ShopApp(int argc, char *argv[]);
    virtual ~ShopApp() = default;

private:
    QScopedPointer<ShopService, QScopedPointerDeleteLater> m_shopService;
    QQuickView m_view;
};

#endif // SHOPAPP_H
