#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<pair<int, int>,int> hashmap;
    bool isPathCrossing(string path) {
        int x = 0, y = 0;
        for (int i = 0; i < path.length(); i++) {
            switch (path.at(i)) {
            case 'N':
                y++;
                break;
            case 'S':
                y--;
                break;
            case 'W':
                x--;
                break;
            case 'E':
                x++;
                break;
            }
            if (hashmap.find({x, y}) != hashmap.end()) {
                hashmap.clear();
                return true;
            }
            hashmap.insert({{x, y},i});
        }
        hashmap.clear();
        return false;
    }
};
