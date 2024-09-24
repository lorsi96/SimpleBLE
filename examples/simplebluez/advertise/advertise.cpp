#include <simplebluez/Bluez.h>

#include <atomic>
#include <chrono>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <thread>


SimpleBluez::Bluez bluez;

std::atomic_bool async_thread_active = true;
void async_thread_function() {
    while (async_thread_active) {
        bluez.run_async();
        std::this_thread::sleep_for(std::chrono::microseconds(100));
    }
}

void millisecond_delay(int ms) {
    for (int i = 0; i < ms; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

int main(int argc, char* argv[]) {
    int selection = -1;

    bluez.init();
    std::thread* async_thread = new std::thread(async_thread_function);

    auto adapters = bluez.get_adapters();
    auto adapter = adapters[0];

    auto advertisement = bluez.get_advertisement();
    adapter->register_advertisement(advertisement->path());

    std::cout << "Before test configure | After register Advertisement" << std::endl;
    std::cout << "After test configure" << std::endl;

    // millisecond_delay(25000);

    std::cout << "Enter to test configure" << std::endl;
    std::cin.get();
    // advertisement->test_configure();

    async_thread_active = false;
    while (!async_thread->joinable()) {
        millisecond_delay(10);
    }
    async_thread->join();
    delete async_thread;

    std::cin.get();

    return 0;
}