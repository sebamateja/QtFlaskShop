from flask import Flask
from flask import jsonify
import json
from .product import Product
from .shoppingCart import ShoppingCart
app = Flask(__name__)

offer = []
cart = ShoppingCart()

def create_app():
    handle = open('resources/data.json')
    data  = json.loads(handle.read())
    for prod in data['products']:
        product = Product(prod['productId'], prod['productName'], prod['productPrice'], prod['productWeight'])
        offer.append(product)
    return Flask(__name__)

app = create_app()

@app.route('/')
def index():
    return '1'

@app.route('/getOffer')
def getListOfProducts():
    return json.dumps(offer, default = lambda x: x.__dict__)

@app.route('/addProduct/<productId>')
def addProduct(productId):
    product = next((x for x in offer if x.productId == int(productId)), None)

    if (product):
        existInCart = next((x for x in cart.getList() if x.productId == int(product.productId)), None)
        if (existInCart):
            existInCart.amount += 1
            return '1'
        else:
            setattr(product, 'amount', 1)
            cart.addProductToCart(product)
            return '1'
    else:
        return '0'

@app.route('/getShoppingCart')
def getShoppingCart():
    # for i in cart.getList():
    #     i.printInfo()
    return json.dumps(cart.getList(), default = lambda x: x.__dict__)
