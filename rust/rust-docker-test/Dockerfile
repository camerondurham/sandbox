FROM rust:1.50
WORKDIR /usr/src/playground
COPY Cargo.toml .
COPY Cargo.lock .
COPY src src
RUN cargo build --release
CMD cargo run --release