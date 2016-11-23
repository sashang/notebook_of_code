#include <iostream>
#include <functional>

int foo(std::function<int()> f)
{
    int a = f();
    std::cout << a;
}

std::function<int()> create(void)
{
    int a = 42;
    auto f = [a]{return a;};
    return f;
}

int main(int argc, char* argv[])
{
    int a = 1;
    auto f = create();
    foo(f);
}

