#include<iostream>
using namespace std;

float last;
int n;

struct info
{
    string name;
    float start,end;
};

const float INF=23.59;
/*const*/ info NULLInfo;

info lessons[1000];

bool find(float lastEnd,info &ret)
{
    for (int i = last; i < n; ++i)
    {
        info lessonInfo=lessons[i];
        if (lessonInfo.start>=lastEnd)
        {
            last=i+1;
            ret=lessonInfo;
            return true;
        }
    }
    return false;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        info lessonInfo;
        cin>>lessonInfo.name>>lessonInfo.start>>lessonInfo.end;
        lessons[i]=lessonInfo;
    }
    // for (int i = 0; i < n; ++i)
    // {
    //     cout<<lessons[i].name<<" ";
    // }
    // cout<<endl;
    last=0;
    float lastEnd=0;
    info lessonInfo;
    while(find(lastEnd,lessonInfo))
    {
        lastEnd=lessonInfo.end;
        cout<<lessonInfo.name<<" ";
    }
}