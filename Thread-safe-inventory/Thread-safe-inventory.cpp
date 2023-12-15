#include <vector>
#include <mutex>
#include <thread>
#include <iostream>

class Inventory {
private:
    std::vector<int> items;
    std::mutex mtx;

public:
    void put(int item) {
        std::lock_guard<std::mutex> lock(mtx);
        items.push_back(item);
    }

    int get() {
        std::lock_guard<std::mutex> lock(mtx);
        if (items.empty()) {
            return -1; 
        }
        int item = items.back();
        items.pop_back();
        return item;
    }
};

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
