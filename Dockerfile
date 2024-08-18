FROM ubuntu:latest

WORKDIR /workspace
RUN sed -i "s/archive.ubuntu.com/cn.archive.ubuntu.com/g" /etc/apt/sources.list

RUN apt update -y && \
  apt install -y git cmake gcc g++ && \
  apt autoremove

ENTRYPOINT [ "bash" ]