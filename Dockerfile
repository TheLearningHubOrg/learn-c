# Multi-stage Dockerfile for C Systems Application
FROM alpine:3.20 AS builder

RUN apk add --no-cache build-base cmake

WORKDIR /app
COPY . .

RUN cmake -B build -S . && cmake --build build
RUN ./build/test_runner

FROM alpine:3.20 AS runner
WORKDIR /app

COPY --from=builder /app/build/learn_c ./learn_c

ENTRYPOINT ["./learn_c"]
