#include <iostream>
#include <stdexcept>

class smart_array {
private:
    int* data;        // Указатель на массив
    size_t capacity;  // Максимальная вместимость массива
    size_t size;      // Текущее количество элементов

public:
    // Конструктор с заданной вместимостью
    smart_array(size_t capacity) : capacity(capacity), size(0) {
        if (capacity == 0) {
            throw std::invalid_argument("Array size must be greater than 0.");
        }
        data = new int[capacity]; // Выделение памяти под массив
    }

    // Функция добавления нового элемента
    void add_element(int value) {
        if (size >= capacity) {
            throw std::overflow_error("Cannot add element: array is full.");
        }
        data[size] = value;
        ++size;
    }

    // Функция получения элемента по индексу
    int get_element(size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index is out of range.");
        }
        return data[index];
    }

    // Деструктор
    ~smart_array() {
        delete[] data; // Освобождение выделенной памяти
    }
};

int main() {
    try {
        smart_array arr(5); // Создаем массив с вместимостью 5
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        std::cout << arr.get_element(1) << std::endl; // Должно вывести 4
    }
    catch (const std::exception& ex) {
        std::cout << "Exception: " << ex.what() << std::endl;
    }
    return 0;
    system("pause");
}