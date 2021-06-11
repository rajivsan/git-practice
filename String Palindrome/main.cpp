/* Comment for the file */

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <bitset>

bool check_palindrome(std::string &);

std::string str_tolower(std::string &s);

int main()
{
    std::string ip_string;
    
    std::cout <<"Enter the String : \n";
    std::getline(std::cin, ip_string);

    ip_string.size() > 0 ?  std::cout <<"The entered string is " << (check_palindrome(ip_string) == true ? "" : "not ") << "a permutation of a palindrome\n" 
                         :  std::cout <<"The entered string is invalid\n";

    return 0;
}

bool check_palindrome(std::string &ip_string)
{
    std::bitset<255> c_record;   
    int whitespace_count = 0; 
    
    str_tolower(ip_string);

    for(auto c: ip_string)  c > 'a' && c < 'z' ? c_record.flip(c-'a') : whitespace_count++;

    bool ret;
    (ip_string.size() - whitespace_count) % 2 == 0 ? ( c_record.any() == true ? ret = false : ret = true ) : ( c_record.count() == 1 ? ret = true : ret = false ); 
    
    return ret;
}

std::string str_tolower(std::string &s) {
    std::transform(s.begin(), s.end(), s.begin(), 
                   [](unsigned char c){ return std::tolower(c); } 
                  );
    return s;
}
