FROM gcc:4.9
RUN mkdir /usr/src/app
COPY app.cpp /usr/src/app
WORKDIR /usr/src/app
RUN gcc app.cpp -O3 -std=c11 -lm -ffast-math -o app
ENTRYPOINT ["./app"]