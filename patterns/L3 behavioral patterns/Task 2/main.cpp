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

class Observer {
public:
    virtual ~Observer() = default;

    virtual void onWarning(const std::string& message) {}
    virtual void onError(const std::string& message) {}
    virtual void onFatalError(const std::string& message) {}

protected:
    std::unique_ptr<LogCommand> logCommandPtr_;
};

class WarningObserver : public Observer {
public:
    void onWarning(const std::string& message) override {
        logCommandPtr_ = std::make_unique<MesToConsole>();
        logCommandPtr_->print(message);
    }
};

class ErrorObserver : public Observer {
public:
    void onError(const std::string& message) override {
        logCommandPtr_ = std::make_unique<MesToFile>("error_log.txt");
        logCommandPtr_->print(message);
    }
};

class FatalErrorObserver : public Observer {
public:
    void onFatalError(const std::string& message) override {
        logCommandPtr_ = std::make_unique<MesToConsole>();
        logCommandPtr_->print(message);

        logCommandPtr_ = std::make_unique<MesToFile>("fatal_error_log.txt");
        logCommandPtr_->print(message);
    }
};

class Observered {
public:
    void warning(const std::string& message) const {
        for (const auto& observer : observers_) {
            std::shared_ptr<Observer> observerIsAlive = observer.lock();
            observerIsAlive->onWarning(message);
        }
    }
    void error(const std::string& message) const {
        for (const auto& observer : observers_) {
            std::shared_ptr<Observer> observerIsAlive = observer.lock();
            observerIsAlive->onError(message);
        }
    }
    void fatalError(const std::string& message) const {
        for (const auto& observer : observers_) {
            std::shared_ptr<Observer> observerIsAlive = observer.lock();
            observerIsAlive->onFatalError(message);
        }
    }

    void addObserver(std::weak_ptr<Observer> observer) {
        observers_.push_back(observer);
    }

private:
    std::vector<std::weak_ptr<Observer>> observers_;
};

int main() {
    std::shared_ptr<Observer> obs1 = std::make_shared<WarningObserver>();
    std::shared_ptr<Observer> obs2 = std::make_shared<FatalErrorObserver>();

    Observered observered;
    observered.addObserver(obs1);
    observered.addObserver(obs2);

    {
        std::shared_ptr<Observer> obs3 = std::make_shared<ErrorObserver>();
        std::shared_ptr<Observer> obs4 = std::make_shared<WarningObserver>();
        observered.addObserver(obs3);
        observered.addObserver(obs4);
        observered.warning("warning_message");
    }

    observered.error("error_message");
    return 0;
}