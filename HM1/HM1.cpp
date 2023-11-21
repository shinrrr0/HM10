#include <iostream>
#include <vector>

template<typename T>
class DinamicArray {
public:
    explicit DinamicArray(int u_size = 100) {
        size_ = 0;
        capacity = u_size;
        data = new T[capacity];
    }
    void push_back(T elem) {
        data[size_] = elem;
        ++size_;
    }
    void pop_back() {
        --size_;
    }
    int size() {
        return size_;
    }
    T& operator[] (int index) {
        if (index >= size_ || index < 0) {
            throw "index out of range";
        }
        return data[index];
    }
    T* begin() {
        return data;
    }
    T* end() {
        return data + size_;
    }
    T at(const int& index) {
        if (index >= size_ || index < 0) {
            throw "index out of range";
        }
        return data[index];
    }
private:
    int capacity;
    int size_;
    T* data;

    void update_capacity() {
        if (size_ + 1 <= capacity) {
            return;
        }
        T* tmp;
        capacity *= 2;
        tmp = new T[capacity];
        for (int i = 0; i < size_; ++i) {
            tmp[i] = data[i];
        }
        std::swap(tmp, data);
    }
};

float get_medium(DinamicArray<int>& a) {
    float n = a.size();
    float sum = 0;
    for (auto& elem : a) {
        sum += elem;
    }
    return sum / n;
}

int main()
{
    DinamicArray<int> a;
    for (int i = 1; i < 7 + 1; i++) {
        a.push_back(i);
    }
    a.pop_back();
    a.pop_back();
    for (auto& elem : a) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    int b = a.at(8);
    for (auto& elem : a) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    std::cout << get_medium(a);
}
