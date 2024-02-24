#include <iostream>
#include <vector>
#include <list>

class Big_number {
private:
    std::vector<short> digs;

public:
    Big_number() {}

    Big_number(const Big_number& right) {
        digs = right.digs;
    }

    Big_number(const std::vector<short>& right) {
        digs = right;
    }

    Big_number(Big_number&& right) noexcept {
        digs = right.digs;
    }

    Big_number& operator=(const Big_number& right) {

        if (&right == this) {
            return *this;
        }
        digs = right.digs;
        return *this;
    }

    Big_number& operator=(Big_number&& right) noexcept {

        if (&right == this) {
            return *this;
        }
        digs = right.digs;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& left, Big_number right);

    friend Big_number operator+(Big_number left, Big_number right);

    friend Big_number operator*(Big_number left, Big_number right);
};

std::ostream& operator<<(std::ostream& left, Big_number right) {
    
    for (const auto& val : right.digs) {
        std::cout << val;
    }

    return std::cout << "";
}

Big_number operator+(Big_number left, Big_number right) {

    auto it_right = right.digs.rbegin();
    auto it_left = left.digs.rbegin();
    short over = 0;
    
    std::list<short> sum;

    while (it_right < right.digs.rend() && it_left < left.digs.rend()) {

        sum.push_front( (*it_left + *it_right + over) % 10);
        over = (*it_left + *it_right + over) / 10;

        it_left++;
        it_right++;
    }

    if (it_left == left.digs.rend()) {
        while (it_right < right.digs.rend()) {
            sum.push_front((*it_right + over) % 10);
            over = (*it_right + over) / 10;

            it_right++;
        }
    }
    else {
        while (it_left < left.digs.rend()) {
            sum.push_front((*it_left + over) % 10);
            over = (*it_left + over) / 10;

            it_left++;
        }
    }

    if (over) {
        sum.push_front(over);
    }

    std::vector<short> ansv;
    for (const auto& val : sum) {
        ansv.push_back(val);
    }

    return Big_number(ansv);
}

Big_number operator*(Big_number left, Big_number right) {

    auto it_right = right.digs.rbegin();
    auto it_left = left.digs.rbegin();
    short over = 0;

    int num_of_decads = 0;

    std::list<short> mult;

    while (it_right < right.digs.rend()) {
        over = 0;

        std::list<short> buf;

        it_left = left.digs.rbegin();
        while (it_left < left.digs.rend()) {

            buf.push_front((*it_left * *it_right + over) % 10);
            over = (*it_left * *it_right + over) / 10;

            it_left++;
        }

        if (over) {
            buf.push_front(over);
        }

        for (int i = 0; i < num_of_decads; i++) {
            buf.push_back(0);
        }

        over = 0;
        
        if (num_of_decads == 0) {
            mult = move(buf);
        }
        else {
            auto it_buf = buf.rbegin();
            auto it_mult = mult.rbegin();

            std::list<short> mult_buf;

            while (it_mult != mult.rend()) {

                mult_buf.push_front((*it_buf + *it_mult + over) % 10);
                over = (*it_buf + *it_mult + over) / 10;

                it_buf++;
                it_mult++;
            }

            while (it_buf != buf.rend()) {
                mult_buf.push_front((*it_buf + over) % 10);
                over = (*it_buf + over) / 10;

                it_buf++;
            }

            if (over) {
                mult_buf.push_front(over);
            }

            mult = move(mult_buf);
        }

         num_of_decads++;
         it_right++;
    }

    std::vector<short> ansv;
    for (const auto& val : mult) {
        ansv.push_back(val);
    }

    return Big_number(ansv);
}

std::vector<short> to_vector(std::string str_num) {

    std::vector<short> digs;
    for (const auto val : str_num) {
        digs.push_back(static_cast<short>(val) - static_cast<short>('0'));
    }

    return digs;
}

int main()
{
    std::string str_1 = "999";
    std::string str_2 = "92";

    std::vector<short> digs_1 = to_vector(str_1);
    std::vector<short> digs_2 = to_vector(str_2);

    Big_number num_1(digs_1);
    Big_number num_2(digs_2);
    Big_number num_3(num_1 + num_2);
    Big_number num_4(num_1 * num_2);

    std::cout << "num_1 = " << num_1 << std::endl;
    std::cout << "num_2 = " << num_2 << std::endl;

    std::cout << "num_1 + num_2 = " << num_3 << std::endl;
    std::cout << "num_1 * num_2 = " << num_4 << std::endl;

    Big_number num_5;
    num_5 = std::move(num_1);

    Big_number num_6(std::move(num_2));

    std::cout << "copy move: " << num_5 << std::endl;
    std::cout << "move: " << num_6 << std::endl;

    return 0;
}
