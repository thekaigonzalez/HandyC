#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

const std::string WHITESPACE = " \n\r\t\f\v";
 
std::string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}
 
std::string rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
 
std::string trim(const std::string &s) {
    return rtrim(ltrim(s));
}

template <typename T>
class HandyArray {
    std::string c;
public:
    HandyArray(const std::string &s) {
        c = s;
    }
    std::vector<std::string>Parse() {

        std::vector<std::string>arraycontents{};
        std::stringstream s(c);
        
        std::string OPENING; /*make this to set the Char pointer ahead. */

        getline(s, OPENING, '[');

        std::string contents;

        getline(s, contents, ']');

        std::stringstream contents_stream(contents);

        std::string ctx;

        while (getline(contents_stream, ctx, ',')) {
            arraycontents.push_back(trim(ctx));
        }
        return arraycontents;
    }
};
