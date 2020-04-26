from flask import Flask, request

application = Flask(__name__)

global sum_number
sum_number = 0


@application.route('/count')
def count():
    global sum_number
    return str(sum_number)


@application.route('/', methods=['POST'])
def index():
    global sum_number
    number = int(request.stream.read())
    sum_number += number
    return str(sum_number)


if __name__ == '__main__':
    application.run(debug=True)
