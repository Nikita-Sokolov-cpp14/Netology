#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <exception>

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

enum Type {
    Warning,
    Error,
    FatalError,
    Unknown
};

class LogMessage {
public:
    LogMessage(Type type, std::string message) {
        type_ = type;
        message_ = message;
    }

    Type type() const {
        return type_;
    }

    const std::string& message() const {
        return message_;
    }

private:
    Type type_;
    std::string message_;
};

class Handler {
public:
    virtual ~Handler() = default;

    virtual void handleMessage(const std::string& message) = 0;
    virtual void transmitMessage(const LogMessage& logMessage) = 0;
};

class UnknownHandler : public Handler {
public:
    void handleMessage(const std::string& message) override {
        throw std::exception();
    }
};

class WarningHandler : public UnknownHandler {
public:
    void handleMessage(const std::string& message) override {
        MesToConsole log;
        log.print(message);
    }

    void transmitMessage(const LogMessage& logMessage) override {
        if (logMessage.type() == Warning) {
            WarningHandler::handleMessage(logMessage.message());
            return;
        }

        UnknownHandler::handleMessage(logMessage.message());
    }
};

class ErrorHandler : public WarningHandler {
public:
    
    void handleMessage(const std::string& message) override {
        MesToFile log("error_log.txt");
        log.print(message);
    }

    void transmitMessage(const LogMessage& logMessage) override {
        if (logMessage.type() == Error) {
            ErrorHandler::handleMessage(logMessage.message());
            return;
        }

        WarningHandler::transmitMessage(logMessage);
    }
};

class FatalErrorHandler : public ErrorHandler {
public:
    void handleMessage(const std::string& message) override {
        throw std::exception();
    }

    void transmitMessage(const LogMessage& logMessage) override {
        if (logMessage.type() == FatalError) {
            handleMessage(logMessage.message());
            return;
        }

        ErrorHandler::transmitMessage(logMessage);
    }
};

int main() {
    LogMessage mes1(Warning, "log 1: warning");

    FatalErrorHandler handler;
    try {
        handler.transmitMessage(mes1);
    }
    catch (std::exception& err) {
        std::cout << err.what() << std::endl;
    }

    return 0;
}