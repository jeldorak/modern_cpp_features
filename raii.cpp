#include <thread>
#include <mutex>
#include <iostream>
#include <atomic>
#include <exception>
#include <stdexcept>

std::atomic<int> g_a;
int g_i = 0;
std::mutex g_i_mutex;

void safe_increment_atomic() {
    ++g_a;

    std::cout << std::this_thread::get_id() << '\n';        
}

void safe_increment_lock() {
    std::lock_guard<std::mutex> lock(g_i_mutex);
    ++g_i;
    
    std::cout << std::this_thread::get_id() << '\n';    
}

int main() {
    std::cout << "main lock: " << g_i << '\n';

    std::thread t1(safe_increment_lock);
    std::thread t2(safe_increment_lock);
    
    t1.join();
    t2.join();

    std::cout << "main lock: " << g_i << '\n';
    std::cout << "main atomic: " << g_a << '\n';
    
    std::thread t3(safe_increment_atomic);
    std::thread t4(safe_increment_atomic);

    t3.join();
    t4.join();

    std::cout << "main atomic: " << g_a << '\n';

}