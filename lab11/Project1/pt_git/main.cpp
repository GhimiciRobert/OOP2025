#include <iostream>
#include <exception>
using namespace std;
class IdxOutOfRange : public exception
{
    virtual const char* what() const throw()
    {
        return "Index in afara listei!";
    }
};
class CapacityExceeded : public exception
{
    virtual const char* what() const throw()
    {
        return "Size invalid!";
    }
};
template<class T>
int compare(const T& a, const T& b)
{
    if (a < b)
        return 1;
    if (a > b)
        return -1;
    return 0;
}
class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};
template<class T>
class AllCompare :
    public Compare {
public:

    int CompareElements(void* e1, void* e2) override {
        T* a = static_cast<T*>(e1);
        T* b = static_cast<T*>(e2);

        if (*a < *b) return -1;
        if (*a > *b) return 1;
        return 0;
    }
};
template<class T>
class ArrayIterator;
template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista
public:
    Array(); // Lista nu e alocata, Capacity si Size = 0
    ~Array(); // destructor
    Array(int capacity); // Lista e alocata cu 'capacity' elemente
    Array(const Array<T>& otherArray); // constructor de copiere

    T& operator[] (int index); // arunca exceptie daca index este out of range

    const Array<T>& operator+=(const T& newElem); // adauga un element de tipul T la sfarsitul listei si returneaza this
    const Array<T>& Insert(int index, const T& newElem); // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Insert(int index, const Array<T> otherArray); // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Delete(int index); // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

    bool operator=(const Array<T>& otherArray);

    void Sort(); // sorteaza folosind comparatia intre elementele din T
    void Sort(int(*compare)(const T&, const T&)); // sorteaza folosind o functie de comparatie
    void Sort(Compare* comparator); // sorteaza folosind un obiect de comparatie

    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem); // cauta un element folosind binary search in Array
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparatie
    int BinarySearch(const T& elem, Compare* comparator);//  cauta un element folosind binary search si un comparator

    int Find(const T& elem); // cauta un element in Array
    int Find(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind o functie de comparatie
    int Find(const T& elem, Compare* comparator);//  cauta un element folosind un comparator

    int GetSize();
    int GetCapacity();

    ArrayIterator<T> GetBeginIterator();
    ArrayIterator<T> GetEndIterator();
};
template<class T>
class ArrayIterator
{
private:
    int Current; // mai adaugati si alte date si functii necesare pentru iterator
    Array<T>* array;
public:
    ArrayIterator(Array<T>* arr, int start = 0);
    ArrayIterator& operator ++ ();
    ArrayIterator& operator -- ();
    bool operator= (ArrayIterator<T>& other);
    bool operator!=(ArrayIterator<T>& other);
    T* GetElement();
};

template<class T>
ArrayIterator<T>::ArrayIterator(Array<T>* arr, int start)
{
    array = arr;
    Current = start;
}

template<class T>
ArrayIterator<T>& ArrayIterator<T>::operator++()
{
    if (Current < array->GetSize())
        ++Current;
    return *this;
}

template<class T>
ArrayIterator<T>& ArrayIterator<T>::operator--()
{
    if (Current > 0)
        --Current;
    return *this;
}

template<class T>
bool ArrayIterator<T>::operator=(ArrayIterator<T>& other)
{
    return Current == other.Current;
}

template<class T>
bool ArrayIterator<T>::operator!=(ArrayIterator<T>& other)
{
    return Current != other.Current;
}

template<class T>
T* ArrayIterator<T>::GetElement()
{
    if (Current >= 0 && Current < array->GetSize())
        return &((*array)[Current]);
    return nullptr;
}

template<class T>
Array<T>::Array()
{
    Size = 0;
    Capacity = 0;
    List = nullptr;
}

template<class T>
Array<T>::~Array()
{
    for (int i = 0; i < Capacity; i++)
    {
        delete List[i];
    }
    delete[] List;
}

template<class T>
Array<T>::Array(int capacity)
{
    Capacity = capacity;
    Size = 0;
    List = new T * [Capacity];
    for (int i = 0; i < Capacity; i++)
        List[i] = nullptr;
}

template<class T>
Array<T>::Array(const Array<T>& otherArray)
{
    Capacity = otherArray.Capacity;
    Size = otherArray.Size;
    List = new T * [Capacity];
    for (int i = 0; i < Capacity; ++i) {
        if (otherArray.List[i])
            List[i] = new T(*otherArray.List[i]);
        else
            List[i] = nullptr;
    }
}

template<class T>
T& Array<T>::operator[](int index)
{
    if (index < 0 || index >= Size)
        throw IdxOutOfRange();
    else
        return *List[index];
}

template<class T>
const Array<T>& Array<T>::operator+=(const T& newElem)
{
    if (Size >= Capacity)
        throw IdxOutOfRange();
    List[Size] = new T(newElem);
    Size++;
    return *this;

}

template<class T>
const Array<T>& Array<T>::Insert(int index, const T& newElem)
{
    if (index < 0 || index > Size)
        throw IdxOutOfRange();

    if (Size >= Capacity)
        throw CapacityExceeded();


    for (int i = Size; i > index; i--) {
        List[i] = List[i - 1];
    }


    List[index] = new T(newElem);
    Size++;

    return *this;
}

template<class T>
const Array<T>& Array<T>::Insert(int index, const Array<T> otherArray)
{

    if (index < 0 || index > Size)
        throw IdxOutOfRange();

    if (Size + otherArray.Size > Capacity)
        throw CapacityExceeded();

    for (int i = Size - 1; i >= index; --i)
        List[i + otherArray.Size] = List[i];


    for (int i = 0; i < otherArray.Size; ++i)
        List[index + i] = new T(*otherArray.List[i]);


    Size += otherArray.Size;

    return *this;

}

template<class T>
const Array<T>& Array<T>::Delete(int index)
{
    {
        if (index < 0 || index >= Size)
            throw IdxOutOfRange();

        delete List[index];

        for (int i = index; i < Size - 1; ++i)
            List[i] = List[i + 1];

        List[Size - 1] = nullptr;
        Size--;

        return *this;
    }

}

template<class T>
bool Array<T>::operator=(const Array<T>& otherArray)
{
    if (Size != otherArray.Size)
        return false;
    for (int i = 0; i < Size; i++)
    {
        if (*List[i] != *otherArray.List[i])
            return false;
    }
    return true;

}

template<class T>
void Array<T>::Sort()
{
    bool sorted;
    do
    {
        sorted = true;
        for (int i = 0; i < Size - 1; i++)
            if (*List[i] > *List[i + 1])
            {
                T* aux = List[i];
                List[i] = List[i + 1];
                List[i + 1] = aux;
                sorted = false;
            }

    } while (!sorted);
}

template<class T>
void Array<T>::Sort(int(*compare)(const T&, const T&))
{
    bool sorted;
    do
    {
        sorted = true;
        for (int i = 0; i < Size - 1; i++)
            if (compare(*List[i], *List[i + 1]) == -1)
            {
                T* aux = List[i];
                List[i] = List[i + 1];
                List[i + 1] = aux;
                sorted = false;
            }

    } while (!sorted);
}

template<class T>
void Array<T>::Sort(Compare* comparator)
{
    bool sorted;
    do
    {
        sorted = true;
        for (int i = 0; i < Size - 1; i++)
        {
            if (comparator->CompareElements(List[i], List[i + 1]) > 0)
            {
                T* aux = List[i];
                List[i] = List[i + 1];
                List[i + 1] = aux;
                sorted = false;
            }
        }
    } while (!sorted);
}

template<class T>
int Array<T>::BinarySearch(const T& elem)
{

    int left = 0;
    int right = Size - 1;

    while (left <= right)
    {
        int m = left + (right - left) / 2;

        if (*List[m] == elem)
            return m;

        if (*List[m] < elem)
            left = m + 1;
        else
            right = m - 1;
    }

    return -1;

}

template<class T>
int Array<T>::BinarySearch(const T& elem, int(*compare)(const T&, const T&))
{
    int left = 0;
    int right = Size - 1;

    while (left <= right)
    {
        int m = left + (right - left) / 2;

        if (compare(*List[m], elem) == 0)
            return m;

        if (compare(*List[m], elem) == -1)
            left = m + 1;
        else
            right = m - 1;
    }

    return -1;
}

template<class T>
int Array<T>::BinarySearch(const T& elem, Compare* comparator)
{
    int left = 0;
    int right = Size - 1;

    while (left <= right)
    {
        int m = left + (right - left) / 2;

        if (comparator->CompareElements(List[m], (void*)&elem) == 0)
            return m;

        if (comparator->CompareElements(List[m], (void*)&elem) == 1)
            left = m + 1;
        else
            right = m - 1;
    }
    return -1;
}

template<class T>
int Array<T>::Find(const T& elem)
{
    for (int i = 0; i < Size; i++)
    {
        if (*List[i] == elem)
            return i;
    }
    return -1;
}

template<class T>
int Array<T>::Find(const T& elem, int(*compare)(const T&, const T&))
{
    for (int i = 0; i < Size; i++)
    {
        if (compare(*List[i], elem) == 0)
            return i;
    }
    return -1;
}

template<class T>
int Array<T>::Find(const T& elem, Compare* comparator)
{
    for (int i = 0; i < Size; i++)
    {
        if (comparator->CompareElements(List[i], (void*)&elem) == 0)
            return i;
    }
    return -1;
}

template<class T>
int Array<T>::GetSize()
{
    return Size;
}

template<class T>
int Array<T>::GetCapacity()
{
    return Capacity;
}

template<class T>
ArrayIterator<T> Array<T>::GetBeginIterator()
{
    return ArrayIterator<T>(this, 0);
}

template<class T>
ArrayIterator<T> Array<T>::GetEndIterator()
{
    return ArrayIterator<T>(this, Size);
}

int main() {
    Array<int> arr(5);


    try {
        arr += 5;
        arr += 2;
        arr += 8;
        arr += 3;
        arr += 10;
        arr += 99;
    }
    catch (exception& e) {
        cout << "Eroare la adaugare: " << e.what() << endl;
    }


    cout << "Elemente in array: ";
    for (int i = 0; i < arr.GetSize(); i++) {
        try {
            cout << arr[i] << " ";
        }
        catch (exception& e) {
            cout << "[Eroare: " << e.what() << "]";
        }
    }
    cout << endl;


    int elementCautat = 8;
    int index = arr.Find(elementCautat);
    if (index != -1)
        cout << "Elementul " << elementCautat << " se afla la indexul " << index << endl;
    else
        cout << "Elementul nu a fost gasit." << endl;


    AllCompare<int> cmp;
    arr.Sort(&cmp);

    cout << "Array sortat: ";
    for (int i = 0; i < arr.GetSize(); i++) {
        try {
            cout << arr[i] << " ";
        }
        catch (exception& e) {
            cout << "[Eroare: " << e.what() << "]";
        }
    }
    cout << endl;


    try {
        arr.Insert(10, 123);
    }
    catch (exception& e) {
        cout << "Eroare la insert pe pozitie invalida: " << e.what() << endl;
    }

    try {
        arr.Insert(2, 77);
        cout << "Dupa inserare pe pozitia 2: ";
        for (int i = 0; i < arr.GetSize(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    catch (exception& e) {
        cout << "Eroare la inserare: " << e.what() << endl;
    }


    try {
        arr.Delete(99);
    }
    catch (exception& e) {
        cout << "Eroare la stergere: " << e.what() << endl;
    }


    try {
        arr.Delete(1);
        cout << "Dupa stergerea de la indexul 1: ";
        for (int i = 0; i < arr.GetSize(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    catch (exception& e) {
        cout << "Eroare la stergere: " << e.what() << endl;
    }


    cout << "Iterare cu ArrayIterator: ";
    ArrayIterator<int> it = arr.GetBeginIterator();
    ArrayIterator<int> end = arr.GetEndIterator();
    while (it != end) {
        cout << *(it.GetElement()) << " ";
        ++it;
    }
    cout << endl;

    return 0;
}