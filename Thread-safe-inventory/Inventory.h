#pragma once

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
            return -1; // Of gooi een exception als dat beter past bij je design
        }
        int item = items.back();
        items.pop_back();
        return item;
    }
};