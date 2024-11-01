#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class MesToConsole : public LogCommand {
public:
    void print(const std::string& message) override {
        std::cout << message << std::endl;
    }
};

class MesToFile : public LogCommand {
public:
    std::string pathToFile;

    MesToFile(const std::string& path) {
        pathToFile = path;
    }

    void print(const std::string& message) override {
        std::ofstream file(pathToFile);

        if (!file) {
            std::cout << "Cannot write file" << std::endl;
        }

        file << message << std::endl;

        file.close();
    }
};

int main() {
    std::vector<std::unique_ptr<LogCommand>> commands;
    std::unique_ptr<LogCommand> lc1 = std::make_unique<MesToConsole>();
    std::unique_ptr<LogCommand> lc2 = std::make_unique<MesToConsole>();
    std::unique_ptr<LogCommand> lc3 = std::make_unique<MesToFile>("mes_1.txt");
    std::unique_ptr<LogCommand> lc4 = std::make_unique<MesToFile>("mes_2.txt");

    commands.push_back(std::move(lc1));
    commands.push_back(std::move(lc2));;
    commands.push_back(std::move(lc3));;
    commands.push_back(std::move(lc4));;

    for (auto& val : commands) {
        std::string message = "message";
        val->print(message);
    }

	return 0;
}