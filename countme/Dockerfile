
FROM tiangolo/uwsgi-nginx:python3.7

RUN pip install flask
ENV UWSGI_CHEAPER 0
ENV UWSGI_PROCESSES 1

COPY . /app
