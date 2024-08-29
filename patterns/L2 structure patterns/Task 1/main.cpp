#include <string>
#include <iostream>

class Text {
public:
    virtual void render(const std::string &data) const {
        std::cout << data;
    }
};

class DecoratedText : public Text {
public:
    explicit DecoratedText(Text *text) :
    text_(text) {
    }
    Text *text_;
};

class ItalicText : public DecoratedText {
public:
    explicit ItalicText(Text *text) :
    DecoratedText(text) {
    }
    void render(const std::string &data) const {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText {
public:
    explicit BoldText(Text *text) :
    DecoratedText(text) {
    }
    void render(const std::string &data) const {
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};

class Parargaph : public DecoratedText {
public:
    explicit Parargaph(Text *text) :
    DecoratedText(text) {
    }
    void render(const std::string &data) const {
        std::cout << "<p>";
        text_->render(data);
        std::cout << "</p>";
    }
};

class Reversed : public DecoratedText {
public:
    explicit Reversed(Text *text) :
    DecoratedText(text) {
    }
    void render(const std::string &data) const {
        std::string string_for_reversing;
        string_for_reversing = data;
        std::reverse(string_for_reversing.begin(), string_for_reversing.end());
        text_->render(string_for_reversing);
    }
};

class Link : public DecoratedText {
public:
    explicit Link(Text *text) :
    DecoratedText(text) {
    }
    void render(const std::string& link_data, const std::string &data) const {
        std::cout << "<a href=";
        std::cout << link_data;
        std::cout << ">";
        text_->render(data);
        std::cout << "</a>";
    }
};

int main() {
    // auto text_block = new ItalicText(new BoldText(new Text()));
    // text_block->render("Hello world");

    // auto text_block = new Parargaph(new Text());
    // text_block->render("Hello world");

    // auto text_block = new Reversed(new Text());
    // text_block->render("Hello world");

    auto text_block = new Link(new Text());
    text_block->render("netology.ru", "Hello world");
}