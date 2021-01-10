#include <iostream>

void bad_func(uint64_t thisptr) {
    printf("Your 'this' pointer = 0x%lx\n", thisptr);
}

void (*func_list[3])(uint64_t) = { bad_func };

class A {
public:
    explicit A(int x) : x(x) {}

    virtual int negate() {
        return -x;
    }

    virtual ~A() {}

private:
    int x;
};

int main() {
    int x;
    std::cout << "Enter a number:";
    std::cin >> x;
    // skip newline
    std::cin.get();

    A *a = new A(x);

    if (x < 0)
        delete a;

    std::cout << "Read a header:";
    char *header = new char[16];
    std::cin.getline(header, 16);

    std::cout << header << ":" << a->negate() << "\n";

    return 0;
}
