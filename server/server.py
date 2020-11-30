from flask import Flask
import json
app = Flask(__name__)

@app.route('/')
def hello_world():
    return 'Hello, World!'

@app.route('/getProducts')
def sendProducts():
    handle = open('data.json')

    data = json.loads(handle.read())

    # for i in data['products']:
    #     print(i)
    # print(data)
    return data
