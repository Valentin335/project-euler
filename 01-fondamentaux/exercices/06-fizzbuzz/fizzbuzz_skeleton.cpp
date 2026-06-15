#include "fizzbuzz.hpp"

std::string fizzbuzz_term(int n) {
    /* n → "Fizz"/"Buzz"/"FizzBuzz"/texte du nombre */
    if (n % 15 == 0){
        return "FizzBuzz";
    }
    if (n%3 == 0){
        return "Fizz";
    }
    if (n%5 == 0){
        return "Buzz";
    }
    return std::to_string(n);
}

std::vector<std::string> fizzbuzz_range(int from, int to) {
    /* from, to → {termes de from à to inclus} */
    std::vector<std::string> v ;
    v.reserve(to-from);
    for (int i = from; i<= to ; i++){
        v.push_back(fizzbuzz_term(i));
    }
    return v;
}
