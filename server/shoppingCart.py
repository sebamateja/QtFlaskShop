class ShoppingCart:
  list = []

  def __init__(self):
    self.list = []
  
  def getList(self):
    return self.list

  def addProductToCart(self, product):
    self.list.append(product)