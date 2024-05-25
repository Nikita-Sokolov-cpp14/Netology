FROM ubuntu:rolling
	LABEL sokolov=""
	RUN apt-get update
	RUN apt-get install -y g++
	WORKDIR ~/Netology/MAP/L5 Docker/Task 2/g++
	COPY main.cpp .
	RUN g++ main.cpp -o async_file
	CMD ["./async_file"]
