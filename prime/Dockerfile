FROM gcc:latest
COPY . /app
WORKDIR /app
RUN g++ app.cpp -oprime -ffast-math -O3 -D_GNU_SOURCE
ENTRYPOINT ["./prime"]
