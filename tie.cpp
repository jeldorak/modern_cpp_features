#include <iostream>
#include <string>
#include <set>
#include <tuple>
 
struct S {
    int n;
    std::string s;
    float d;
    bool operator<(const S& rhs) const
    {
        // compares n to rhs.n,
        // then s to rhs.s,
        // then d to rhs.d
        return std::tie(n, s, d) < std::tie(rhs.n, rhs.s, rhs.d);
    }
};
 
int main()
{
    std::set<S> set_of_s; // S is LessThanComparable
 
    S value1{42, "Test1", 3.14};
    S value2{43, "Test2", 3.15};

    std::set<S>::iterator iter;
    bool inserted;
 
    // unpacks the return value of insert into iter and inserted
    std::tie(iter, inserted) = set_of_s.insert(value1);
 
    auto [it, ins] = set_of_s.insert(value2);
    
    if (inserted && ins)
        std::cout << "Values were inserted successfully\n";
}