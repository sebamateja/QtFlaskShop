#include "ShopTypes.h"

namespace ShopTypes
{

void registerCustomMetaTypes()
{
    qRegisterMetaType<Product>("Product");
    qRegisterMetaType<ExtendedProduct>("ExtendedProduct");
}

}
