from debian:bookworm as base

RUN apt update; apt install libcpprest2.10 -y; apt clean cache

from base as builder 

RUN apt update -y; apt install build-essential libcpprest-dev cmake -y; apt clean cache

WORKDIR /home/
COPY ./http_hello_world/ ./http_hello_world/
COPY ./CMakeLists.txt ./CMakeLists.txt
RUN mkdir ./build
WORKDIR /home/build
RUN cmake .. -DCMAKE_BUILD_TYPE=Release
RUN make
RUN make install

from base as runner

COPY --from=builder /usr/local/bin/ /usr/local/bin/ 
CMD [ "hello_world" ]
