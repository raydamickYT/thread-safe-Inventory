#include <vector>
#include <mutex>
#include <thread>
#include <iostream>

#include "Inventory.h"

void addItems(Inventory& inventory, int start, int count) {
    for (int i = 0; i < count; ++i) {
        inventory.put(start + i);
    }
}

int main() {
    Inventory inventory;

    std::thread thread1(addItems, std::ref(inventory), 100, 50);
    std::thread thread2(addItems, std::ref(inventory), 200, 50);

    thread1.join();
    thread2.join();

    // Check resultaten
    for (int i = 0; i < 100; ++i) {
        std::cout << "Item " << i << ": " << inventory.get() << std::endl;
    }

    return 0;
}
