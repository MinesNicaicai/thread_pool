#include "thread_pool.h"

#include <iostream>
#include <random>

std::random_device rd;  // random number generator

std::mt19937 mt(rd());

std::uniform_int_distribution<int> dist(-1000, 1000);

auto rnd = std::bind(dist, mt);


void simulate_hard_computation()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(2 + 10 * rnd()));
}


void multiply(const int a, const int b)
{
    simulate_hard_computation();
    const int res = a * b;
    std::cout << a << " * " << b << " = " << res << std::endl;
}


void multiply_output(int& out, const int a, const int b)
{
    simulate_hard_computation();
    out = a * b;
    std::cout << a << " * " << b << " = " << out << std::endl;
}


int multiply_return(const int a, const int b)
{
    simulate_hard_computation();
    const int res = a * b;
    std::cout << a << " * " << b << " = " << res << std::endl;
    return res;
}


void example()
{

    ThreadPool pool(10);


    pool.init();

    for (int i = 1; i < 3; ++i) {
        for (int j = 1; j < 10; ++j) {
            auto future = pool.submit(multiply, i, j);
        }
    }

    pool.shutdown();


    // int output_ref;
    // auto future1 = pool.submit(multiply_output, std::ref(output_ref), 5, 6);


    // future1.get();
    // std::cout << "Last operation result is equals to " << output_ref << std::endl;


    // auto future2 = pool.submit(multiply_return, 5, 3);


    // int res = future2.get();
    // std::cout << "Last operation result is equals to " << res << std::endl;

    // pool.shutdown();
}

int main()
{
    example();

    return 0;
}
