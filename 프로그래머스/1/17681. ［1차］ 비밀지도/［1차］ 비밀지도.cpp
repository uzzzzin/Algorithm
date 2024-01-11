#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) 
{
    vector<string> answer;
    answer.resize(n);
    
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(bool (arr1[i] & (1 << (n-j-1))) || bool(arr2[i] & (1 << (n-j-1))))
                answer[i] += "#";
            else
                answer[i] += " ";
        }
    }
    return answer;
}
