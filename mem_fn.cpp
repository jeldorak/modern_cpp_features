#include <functional>
#include <iostream>
 
struct Foo {
    void display_greeting() {
        std::cout << "Hello, world.\n";
    }
    void display_number(int i) {
        std::cout << "number: " << i << '\n';
    }
    int data = 7;
};
 
struct X {
    int x;
 
    int&       easy()      {return x;}
    int&       get()       {return x;}
    const int& get() const {return x;}
};

int main() {
    Foo f;
 
    auto greet = std::mem_fn(&Foo::display_greeting);
    greet(f);
 
    auto print_num = std::mem_fn(&Foo::display_number);
    print_num(f, 42);
 
    auto access_data = std::mem_fn(&Foo::data);
    std::cout << "data: " << access_data(f) << '\n';

    auto a = std::mem_fn        (&X::easy); // no problem at all
    //  auto b = std::mem_fn<int&  >(&X::get ); // no longer works in C++14
    //  auto c = std::mem_fn<int&()>(&X::get ); // no longer works in C++17
    auto d = [] (X& x) {return x.get();};   // another approach to overload resolution
    
    X x = {33};
    std::cout << "a() = " << a(x) << '\n';
 //   std::cout << "c() = " << c(x) << '\n';
    std::cout << "d() = " << d(x) << '\n';
    
}