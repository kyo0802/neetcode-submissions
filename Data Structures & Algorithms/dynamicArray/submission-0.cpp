class DynamicArray {
private:
    int capacity; // 目前總容量
    int size;     // 目前元素數量
    int* arr;     // 指向動態陣列的指標
public:

    DynamicArray(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->arr = new int[capacity];
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if (size == capacity) {
            resize();
        }
        arr[size] = n;
        size++;
    }

    int popback() {
        size--;
        return arr[size];
    }

    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];

        // 將舊陣列的資料複製到新陣列
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        // 釋放舊記憶體空間，並將指標指向新陣列
        delete[] arr;
        arr = newArr;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
