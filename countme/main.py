from flask import Flask, request

application = Flask(__name__)

global sum_of_requests
sum_of_requests = 0


@application.route('/count')
def count():
    global sum_of_requests
    return str(sum_of_requests)


@application.route('/', methods=['POST'])
def index():
    global sum_of_requests
    in_number = int(request.stream.read())
    sum_of_requests += in_number
    return str(sum_of_requests)


if __name__ == '__main__':
    application.run(debug=True)
