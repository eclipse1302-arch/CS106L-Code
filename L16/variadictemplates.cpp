/* template<typename T>
T adder(T v) {
  return v;
}
template<typename T, typename... Args>
T adder(T first, Args... args) {
  return first + adder(args...);
} */

template<typename T>
T adder(T v){
    return v;
}

template<typename T, typename ...Args>
T adder(T v,Args... args){
    return v+adder(args...);
}