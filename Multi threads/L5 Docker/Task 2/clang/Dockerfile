FROM ubuntu:rolling
	LABEL sokolov=""
	RUN apt-get update
	RUN apt-get install -y clang
	WORKDIR ~/Netology/MAP/L5 Docker/Task 2/clang
	COPY main.cpp .
	RUN clang++ -Wall -std=c++17 main.cpp -o my_project
	CMD ["./my_project"]
