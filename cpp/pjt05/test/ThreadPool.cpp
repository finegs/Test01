#include <iostream>
#include <vector>
#include <chrono>

#include <ThreadPool.hpp>
#include <my.hpp>

using namespace std::chrono_literals;

int main(int argc, char* argv[]) {

    // std::ios::sync_with_stdio(false);

    ThreadPool pool(4);

    std::vector<std::future<int>> results;

    for (int i = 0; i <8; i++)
    {
        results.emplace_back(
            pool.enqueue([i]{
                std::cout << my::ts() << "[" << i << "]" << "hello \n";
                std::flush(std::cout);
                std::this_thread::sleep_for(1s);
                std::cout << my::ts() << "[" << i << "]" << "world \n";
                std::flush(std::cout);
                return i*i;
            })
        );
    }
    

    for(auto&& result: results)
        std::cout <<  my::ts() << "[" << result.get() << "]" << " \n";

    std::cout<< std::endl;

    std::getc(stdin);

    return 0;
}