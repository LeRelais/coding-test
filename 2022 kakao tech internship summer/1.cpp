#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> m;
    int scores[] = { -1, 3, 2, 1, 0, 1, 2, 3 };

    for (int i = 0; i < survey.size(); i++) {
        if (choices[i] < 4) {
            m[survey[i][0]] += scores[choices[i]];
        }
        else if (choices[i] > 4) {
            m[survey[i][1]] += scores[choices[i]];
        }
    }

    answer += m['R'] >= m['T'] ? "R" : "T";
    answer += m['C'] >= m['F'] ? "C" : "F";
    answer += m['J'] >= m['M'] ? "J" : "M";
    answer += m['A'] >= m['N'] ? "A" : "N";


    return answer;
}