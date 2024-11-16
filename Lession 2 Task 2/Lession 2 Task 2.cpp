#include <iostream>
#include <stdexcept>

class smart_array {
private:
    int* data;        
    size_t capacity; 
    size_t size;      

    
    void copy_from(const smart_array& other) {
        capacity = other.capacity;
        size = other.size;
        data = new int[capacity];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

public:
    smart_array(size_t capacity) : capacity(capacity), size(0) {
        if (capacity == 0) {
            throw std::invalid_argument("Array size must be greater than 0.");
        }
        data = new int[capacity];
    }

    smart_array(const smart_array& other) {
        copy_from(other);
    }

    smart_array& operator=(const smart_array& other) {
        if (this != &other) { 
            delete[] data;    
            copy_from(other);
        }
        return *this;
    }

    ~smart_array() {
        delete[] data;
    }

    void add_element(int value) {
        if (size >= capacity) {
            throw std::overflow_error("Cannot add element: array is full.");
        }
        data[size] = value;
        ++size;
    }

    int get_element(size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index is out of range.");
        }
        return data[index];
    }
};

int main() {
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);

        smart_array new_array(2);
        new_array.add_element(44);
        new_array.add_element(34);

        arr = new_array;

        std::cout << arr.get_element(0) << std::endl;
        std::cout << arr.get_element(1) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << "Exception: " << ex.what() << std::endl;
    }

    return 0;
    system("pause");
}