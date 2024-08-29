#include <string>
#include <iostream>

class VeryHeavyDatabase {
public:
    std::string GetData(const std::string& key) const noexcept {
        return "Very Big Data String: " + key;
    }
};

class OneShotDB : VeryHeavyDatabase {
public:
    explicit OneShotDB(VeryHeavyDatabase* real_object, const size_t shots = 1) :
        counter_(shots),
        real_db_(real_object) {}

    std::string GetData(const std::string& key) noexcept {
        if (counter_ >= 1) {
            counter_--;
            return real_db_->GetData(key);
        }
        else {
            return "error";
        }
    }
private:
    size_t counter_;
    VeryHeavyDatabase* real_db_;
};

int main() {
    auto real_db = VeryHeavyDatabase();
    auto limit_db = OneShotDB(std::addressof(real_db), 2);

    std::cout << limit_db.GetData("key") << std::endl;
    std::cout << limit_db.GetData("key") << std::endl;
    std::cout << limit_db.GetData("key") << std::endl;

    return 0;
}