FROM ubuntu:latest

RUN apt update -y && \
  apt install -y git cmake gcc g++ && \
  apt clean

WORKDIR /workspace
COPY . /workspace
ENTRYPOINT [ "./test.sh" ]