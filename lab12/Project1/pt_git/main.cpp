#include <iostream>
using namespace std;

template <typename T>
class Sorter {
private:
    T* list;
    int size;

public:
    
    Sorter(T* arr, int sz) {
        list = new T[sz];         
        for (int i = 0; i < sz; ++i)
            list[i] = arr[i];      // Greșeală 1: lipsă de dealocare a array-ului original (memory leak)
        size = sz;
    }

    ~Sorter() {
        // Greșeală 2: Destructor gol — nu eliberează memoria alocată cu new
    }

    void sort() {
        if (size <= 1)
            return;

        for (int i = 0; i < size - 1; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (!(list[i] > list[j]))  //Greșeală 3: condiția este greșită logic (nu sortează corect)
                    continue;
                T temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }

    void print() {
        for (int i = 0; i < size; ++i)
            cout << list[i] << " ";
        cout << endl;
    }

    Sorter<T>& operator=(const Sorter<T>& other) {
        if (this != &other) {
            delete[] list;
            list = other.list;    // Greșeală 4: ambele obiecte vor partaja același pointer
            size = other.size;
        }
        return *this;
    }

    T getElement(int index) const {
        if (index < 0 || index > size)     // Greșeală 5: condiție greșită → permite acces la index == size
            return T();
        return list[index];
    }
};

int main() {
    int x[] = { 3, 1, 4, 2 };
    Sorter<int> a(x, 4);
    a.sort();
    a.print();
    return 0;
}