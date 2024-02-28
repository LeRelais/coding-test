#include <string>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;
    int q1 = 0, q2 = 0;
    long long sum1 = 0, sum2 = 0;
    deque<int> Q1, Q2;

    for (int i = 0; i < queue1.size(); i++) {
        sum1 += queue1[i];
        Q1.push_back(queue1[i]);
    }
    for (int i = 0; i < queue2.size(); i++) {
        sum2 += queue2[i];
        Q2.push_back(queue2[i]);
    }

    int count = 0, flag = 0;

    if ((sum1 + sum2) % 2 == 1)
        return -1;

    int n = queue1.size();

    while (q1 < 2 * n && q2 < 2 * n) {
        if (sum1 > sum2) {
            sum1 -= queue1[q1];
            sum2 += queue1[q1];
            queue2.push_back(queue1[q1]);
            q1++;
        }
        else if (sum2 > sum1) {
            sum2 -= queue2[q2];
            sum1 += queue2[q2];
            queue1.push_back(queue2[q2]);
            q2++;
        }
        else {
            flag = 1;
            break;
        }
        count++;
    }

    if (flag)
        answer = count;
    else
        answer = -1;

    return answer;
    //     int n = queue1.size(), tmp;

    //     for(int i = 0; i < n * 3; i++){
    //         if(sum1 == sum2)
    //             return i;
    //         else if(sum1 > sum2){
    //             tmp = Q1.front();
    //             Q1.pop_front();

    //             sum1 -= tmp;
    //             Q2.push_back(tmp);
    //             sum2 += tmp;
    //         }
    //         else{
    //             tmp = Q2.front();
    //             Q2.pop_front();

    //             sum2 -= tmp;
    //             Q1.push_back(tmp);
    //             sum1 += tmp;
    //         }
    //     }

    //     return -1;
}