template <typename T>
vector& vector::operator=(const vector<T>& other) {
    if( &other = this ){
        return *this;
    }
    _size = other._size;
    _capacity = other._capacity;
    delete [] _elems;
    _elems = T new[_capacity];
    std::copy(other._elems(),other._elems()+_size,_elems());
    return *this;
// fill in the blanks
// we need to copy other._size, other._capacity, and other._elems  
}

vector& vector::operator=(const vector<T>&& other) {
    if(&other == this){
        return *this;
    }
    _size = other._size;
    _capacity = other._capacity;
    _elems = other._elems;
    other._elems = nullptr;
    other._size = 0;
    other._capacity = 0;
    return *this;

}

template <typename T>
void swap(T& a, T& b) noexcept {
T c(std::move(a)); // move constructor
a = std::move(b);  // move assignment
b = std::move(c);  // move assignment
} //std::move释放原来变量的内存，变为rvalue