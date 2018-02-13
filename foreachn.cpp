#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>

template <class T>
class Shape {
private: 
    const int nb_sides;
    const std::string name;
    std::vector<T> v_sides;    
public:
    Shape(const int&& nb_sides_, const std::string&& name_):nb_sides(nb_sides_), name(name_) {
        v_sides.reserve(nb_sides_);
    }    

    const int get_nb_sides() {return nb_sides;}

    template<typename ... Sides>
    void addSizes(const Sides&&... sides) {
        (v_sides.push_back(sides), ...); 
        if (v_sides.size() > nb_sides) {
            v_sides.clear();
            std::stringstream ss;
            ss << "Error: Too many sides are added to this shape (" << name << " has only " << nb_sides << " sides)";
            throw std::runtime_error(ss.str());
        }           
    };    
    
    void print() {
        for (auto it:v_sides) std::cout << it << '\t';
        std::cout << '\n';        
    };

};

template <class T>
class Square : public Shape<T> {

public:
    Square():Shape<T>(4, "Square") {};
};

template <class T>
class Triangle : public Shape<T> {
public:
    Triangle():Shape<T>(3, "Triangle") {};
};

template <>
class Square<int> : public Shape<int> {
public:
    Square():Shape<int>(4, "Trapeze-Int") {};
};

int main()
{
    std::vector<int> ns{1, 2, 3, 4, 5};
    for (auto n: ns) std::cout << n << ", ";
    std::cout << '\n';
    std::for_each(ns.begin(), ns.end(), [](auto& n){ n *= 2; });
    for (auto n: ns) std::cout << n << ", ";
    std::cout << '\n';    

    Square<int> fSquare;
    std::cout << fSquare.get_nb_sides() << '\n';

    fSquare.addSizes(1.2, 3.4, 5.6);
    fSquare.addSizes(7.8);
    fSquare.print();
    
    try {
        fSquare.addSizes(1, 3, 5, 7, 8.9);
    }
    catch (std::runtime_error& e) {
        std::cout << e.what();
    }

    fSquare.print();
    
    Polygon<double> dPol(3,4,5,6,7,8,9);

}