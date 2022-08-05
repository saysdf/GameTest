#ifndef HELPER_HPP
#define HELPER_HPP

#include <utility>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
#include <memory>

typedef std::pair<std::size_t,std::size_t> Point;
typedef std::pair<float,float> PointF;

class Helper {
public:
    static std::string ptostr(Point p){
        return std::to_string(p.first) + " " +std::to_string(p.second);
    };
    static int length(Point p1,Point p2){
        int dx = p1.first-p2.first;
        int dy = p1.second-p2.second;
        return std::ceil(std::sqrt(dx*dx + dy*dy));
    };

    static std::vector<std::string> split(const std::string& str, const std::string& delim)
    {
        std::vector<std::string> tokens;
        size_t prev = 0, pos = 0;
        do
        {
            pos = str.find(delim, prev);
            if (pos == std::string::npos) pos = str.length();
            std::string token = str.substr(prev, pos-prev);
            if (!token.empty()) tokens.push_back(token);
            prev = pos + delim.length();
        }
        while (pos < str.length() && prev < str.length());
        return tokens;
    }
};
#endif // HELPER_HPP
