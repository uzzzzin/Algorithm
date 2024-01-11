#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) 
{
    int accTime = 0;
    
    if(0 == cacheSize)
        return 5* cities.size();
    
    vector<string> cache;
    
    for(int i = 0; i < cities.size(); ++i)
    {
        for(int j = 0 ; j < cities[i].length(); ++j)
            cities[i][j] = tolower(cities[i][j]);
    }
    
    cache.push_back(cities[0]);
    accTime += 5;
    
    for(int i = 1; i < cities.size(); ++i)
    {
        auto iter = find(cache.begin(), cache.end(), cities[i]);
        
        if(iter != cache.end()) // cache hit !!
        {
            cache.erase(iter);
            cache.push_back(cities[i]);
            accTime += 1;
        }
        else // cache miss ㅠㅠ
        {
            if(cacheSize <= cache.size())
                cache.erase(cache.begin()); 
            
            cache.push_back(cities[i]);
            accTime += 5;
        }
    }
    return accTime;
}