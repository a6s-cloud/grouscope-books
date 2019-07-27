FROM kauplan/review2.5
MAINTAINER Tsutomu Nakamura<tsuna.0x00@gmail.com>

RUN apt-get update && \
        DEBIAN_FRONTEND=noninteractive apt-get upgrade -y && \
        DEBIAN_FRONTEND=noninteractive apt-get install -y inotify-tools && \
        apt-get autoclean -y && \
        rm -rf /var/lib/apt/lists/*

COPY entrypoint.sh /opt/entrypoint.sh

RUN chmod 755 /opt/entrypoint.sh

ENTRYPOINT "/opt/entrypoint.sh"

