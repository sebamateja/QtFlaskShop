class Product:

  productId = 0
  productName = ''
  productPrice = 0.0
  productWeight = 0.0

  def __init__(self, id, name, price, weight):
    self.productId = id
    self.productName = name
    self.productPrice = price
    self.productWeight = weight

  def printInfo(self):
    print("Product id: %s. Name: %s. Price: %s. Weight: %s." % (self.productId, self.productName, self.productPrice, self.productWeight))
    if hasattr(self, 'amount'):
      print("Amount: %s" % (self.amount))