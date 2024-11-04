#include <iostream>
#include <fstream>
#include <string>
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

    void recieveMessage(const LogMessage& message) {
        if (message.type() == canHandle()) {
            handleMessage(message);
        }
        else if (next_) {
            next_->recieveMessage(message);
        }
        else {
            throw(std::runtime_error("unkown message: " + message.message()));
        }
    }

    virtual const Type canHandle() const = 0;
    virtual void handleMessage(const LogMessage& message) const = 0;

protected:
    std::unique_ptr<Handler> next_;
};

class WarningHandler : public Handler {
public:
    WarningHandler() {
        next_ = nullptr;
    }

    const Type canHandle() const override {
        return Warning;
    }

    void handleMessage(const LogMessage& message) const override {
        MesToConsole log;
        log.print(message.message());
    }
};

class ErrorHandler : public Handler {
public:
    ErrorHandler() {
        next_ = std::make_unique<WarningHandler>();
    }

    const Type canHandle() const override {
        return Error;
    }

    void handleMessage(const LogMessage& message) const override {
        MesToFile log("error_log.txt");
        log.print(message.message());
    }
};

class FatalErrorHandler : public Handler {
public:
    FatalErrorHandler() {
        next_ = std::make_unique<ErrorHandler>();
    }

    const Type canHandle() const override {
        return FatalError;
    }

    void handleMessage(const LogMessage& message) const override {
        throw(std::exception("fatal error"));
    }
};

int main() {
    LogMessage mes1(Unknown, "log 1: Unknown");
    LogMessage mes2(Warning, "log 2: Warning");
    LogMessage mes3(Error, "log 3: Error");
    LogMessage mes4(FatalError, "log 4: FatalError");

    FatalErrorHandler handler;
    try {
        handler.recieveMessage(mes2);
        handler.recieveMessage(mes3);
        handler.recieveMessage(mes4);
    }
    catch (std::exception& err) {
        std::cout << err.what() << std::endl;
    }

    try {
        handler.recieveMessage(mes1);
    }
    catch (std::exception& err) {
        std::cout << err.what() << std::endl;
    }

    return 0;
}