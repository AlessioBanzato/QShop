#ifndef VETTORE_H
#define VETTORE_H

template<class T>
class Vettore {
private:
    T* info;
    int size, capacity; // size: numero di elementi attualmente contenuti; capacity: numero di elementi che può contenere

    T* copy() const;
    void resizeUp(int);
    void resizeDown(int);
public:
    Vettore();
    Vettore(int);
    Vettore(const Vettore<T>&);
    int getSize() const;
    int getCapacity() const;
    bool isEmpty() const;
    void insert(const T&);
    void erase(const T&);
    void clear();
    int find(const T&) const;
    T& operator[](int);
    const T& operator[](int) const;
    Vettore& operator=(const Vettore&);
    ~Vettore();
};

// metodi privati

template<class T>
T* Vettore<T>::copy() const {
    if(!info) return nullptr;
    T* tmp = new T[size];
    for(int i = 0; i < size; i++) tmp[i] = info[i];
    return tmp;
}

template<class T>
void Vettore<T>::resizeUp(int new_capacity) {
    T* tmp = new T[new_capacity];

    for (int i = 0; i < size; i++)
        tmp[i] = info[i];

    delete[] info;
    info = tmp;
    capacity = new_capacity;
}

template<class T>
void Vettore<T>::resizeDown(int index) {
    T* tmp = new T[capacity];

    for (int i = 0, j = 0; j < size; i++, j++) {
        if (j == index) j += 1;
        tmp[i] = info[j];
    }

    delete[] info;
    info = tmp;
    size--;
}

// metodi pubblici

template<class T>
Vettore<T>::Vettore() : info(nullptr), size(0), capacity(0) {}

template<class T>
Vettore<T>::Vettore(int s) : info(s==0 ? nullptr : new T[s]), size(s), capacity(s) {}

template<class T>
Vettore<T>::Vettore(const Vettore<T>& v) : info(v.copy()), size(v.size), capacity(v.capacity) {}

template<class T>
int Vettore<T>::getSize() const { return size; }

template<class T>
int Vettore<T>::getCapacity() const { return capacity; }

template<class T>
bool Vettore<T>::isEmpty() const { return size == 0; }

template<class T>
void Vettore<T>::insert(const T& t) {
    if (size >= capacity) {
        if (capacity == 0) resizeUp(1);
        else resizeUp(2*capacity);
    }
    info[size] = t;
    size++;
}

template<class T>
void Vettore<T>::erase(const T& i) {
    int index = find(i);
    if (index < 0 || index >= size) return;
    else resizeDown(index);
}

template<class T>
void Vettore<T>::clear() {
    delete[] info;
    info = nullptr;
    size = 0;
    capacity = 0;
}

template<class T>
int Vettore<T>::find(const T& t) const {
    for (int i = 0; i < size; i++) {
        if (info[i] == t)
            return i;
    }
    return -1;
}

template<class T>
T& Vettore<T>::operator[] (int i) { return info[i]; }

template<class T>
const T& Vettore<T>::operator[] (int i) const { return info[i]; }

template<class T>
Vettore<T>& Vettore<T>::operator=(const Vettore<T>& v) {
    if (this != &v) {
        this->~Vettore(); // distruggo this
        size = v.size;
        capacity = v.capacity;
        info = v.copy();
    }
    return *this;
}

template<class T>
Vettore<T>::~Vettore() { delete[] info; }

#endif // VETTORE_H
