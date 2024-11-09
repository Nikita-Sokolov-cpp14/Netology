#include <fstream>
#include <memory>

class Printable
{
public:
    virtual ~Printable() = default;

    virtual std::string print() const = 0;

protected:
    std::string data_;
};

class PrintAsHTML : public Printable {
public:
    PrintAsHTML(std::string data) {
        data_ = std::move(data);
    }

    std::string print() const override {
        return "<html>" + data_ + "<html/>";
    }
};

class PrintAsText : public Printable {
public:
    PrintAsText(std::string data) {
        data_ = std::move(data);
    }

    std::string print() const override {
        return data_;
    }
};

class PrintAsJSON : public Printable {
public:
    PrintAsJSON(std::string data) {
        data_ = std::move(data);
    }

    std::string print() const override {
        return "{ \"data\": \"" + data_ + "\"}";
    }
};

void saveTo(std::ofstream& file, const std::shared_ptr<Printable> printable) {
    file << printable->print();
}