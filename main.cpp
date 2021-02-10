//
//  main.cpp
//  2
//
//  Created by Stanislav Martynov on 26.12.2020.
//

#include <iostream>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <vector>
#include <string>

auto most_frequent_element(std::vector<int>& vec)
{
    std::unordered_map<int, int> count;
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
        ++count[*it];
    int x = 0;
    int max = -1;
    for (const auto& i : count) {
        if (i.second >= max) {
            if (i.second == max) {
                if (i.first < x) x = i.first;
            }
            else {
                max = i.second;
                x = i.first;
            }
        }
    }
    return x;
}
int main()
{
    std::vector<int> vec1;
    std::vector<int> vec;
    std::string line;
    int current = 0;
    int sign = 1;
    int k = 0;
    int j = 0;
    bool flag = false;
    getline(std::cin, line);
    vec1.resize(line.size());
    for (int i = 0; i < line.size(); i++) {
        if (isdigit(line[i]))
        {
            current = current * 10 + (line[i] - 48);
            flag = true;
        }
        else if (line[i] == '-') {
            if (current == 0) sign = -1;
        }
        if ((!isdigit(line[i]) && (current != 0 || flag)) || line[i + 1] == '\0') {
            k++;
            vec1[j] = current * sign;
            j++;
            current = 0;
            sign = 1;
            flag = false;
        }
    }
    vec.resize(k);
    for (int i = 0; i < k; i++) {
        vec[i] = vec1[i];
    }
    vec1.clear();
    auto x = most_frequent_element(vec);
    std::cout << x;
}
