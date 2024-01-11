#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string dartResult) 
{
    int answer = 0;
    vector<int> answerVec;
    
  
    for(int i = 0; i < dartResult.length(); ++i)
    { 
        if((0 != dartResult[i+1])&& (49 == dartResult[i]) && (48 == dartResult[i+1]))
        {
            answerVec.push_back(10);
            ++i;
        }                          
        else if((dartResult[i] >= 48) && dartResult[i] <= 57 )
            answerVec.push_back(dartResult[i] - 48);
                                     
        else
        { 
            if( (83 == dartResult[i] )) // S
                answerVec.back() = answerVec.back();
            
            else if( (68 == dartResult[i] )) // D
                answerVec.back() = answerVec.back() * answerVec.back();
            
            else if( (84 == dartResult[i] )) // T
                answerVec.back() = answerVec.back() * answerVec.back() * answerVec.back();
            
            else // *, #
            {
                if(42 == dartResult[i]) // * 스타상
                {
                    if(1 == answerVec.size())
                        answerVec[0] *= 2;
                    else
                    {
                        answerVec[answerVec.size()-1] *= 2;
                        answerVec[answerVec.size()-2] *= 2;
                    }
                }
                else if(35 == dartResult[i]) // # 아차상
                    answerVec.back() = answerVec.back() * -1;
            }
        }
    }
    
    for(int i =0; i < answerVec.size(); ++i)
        answer += answerVec[i];
         
    return answer;
}

                    
                    
