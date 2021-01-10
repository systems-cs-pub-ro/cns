#include <iostream>
#include <string>
#include <array>
#include <cstdint>

#include <stdlib.h>

std::array<uint64_t, 4> num_list;

char header[16];

// felt cute, might delete later
void random_func(uint64_t dunno, const char* cmd)
{
    std::cout << "What is this -> " << dunno << "?\n";
    system(cmd);
}

class ListPrinter {
public:
    explicit ListPrinter(std::array<uint64_t, 4>& arr)
        : arr(arr) {}

    virtual void print(const char* header)
    {
        std::cout << header << ":\n";
        for (size_t i = 0; i < arr.size(); i++)
            std::cout << arr[i] << " ";
        std::cout << "\n";
    }

    bool check_zero()
    {
        for (size_t i = 0; i < arr.size(); i++)
            if (arr[i] == 0)
                return true;
        return false;
    }

    virtual ~ListPrinter() {}

private:
    std::array<uint64_t, 4>& arr;
};


void check_data(ListPrinter* lp)
{
    if (lp->check_zero())
        delete lp;
}

int main()
{
    std::cout << "Enter 4 numbers  (pls no 0's):";
    for (uint32_t i = 0; i < 4; i++) {
        std::cin >> num_list[i];
    }
    // skip newline
    std::cin.get();

    std::cout << "Read output header: \n";
    std::cin.getline(header, 16);

    ListPrinter *lp = new ListPrinter(num_list);

    check_data(lp);

    std::cout << "Enter your name (max 16 characteres):";
    char *x = new char[16];
    std::cin.getline(x, 16);

    lp->print(header);

    std::string cmd = "echo '" + std::string(x) + "' >> access_log";
    // append to access_log
    system(cmd.c_str());

    delete[] x;
    delete lp;

    return 0;
}
