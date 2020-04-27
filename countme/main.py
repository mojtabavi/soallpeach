from flask import Flask, request

application = Flask(__name__)

global numbers
numbers = []


@application.route('/count')
def count():
    global numbers
    return str(sum(numbers))


@application.route('/', methods=['POST'])
def index():
    global numbers
    numbers.append(int(request.stream.read()))
    return str(sum(numbers))


if __name__ == '__main__':
    application.run(debug=True)
