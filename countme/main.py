from flask import Flask, request

application = Flask(__name__)

global numbers
global sum_number


@application.route('/count')
def count():
    global numbers,sum_number
    return str(sum_number)


@application.route('/', methods=['POST'])
def index():
    global numbers,sum_number
    numbers = int(request.stream.read())
    sum_number += numbers
    return str(sum_number)


if __name__ == '__main__':
    application.run(debug=True)
