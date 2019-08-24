#include<iostream>
#include<map>
using namespace std;

const int INF=24;

struct info
{
    int start,end;
};

map <string,struct info> lessons;

int find(int lastEnd)
{
    int earliestFinishTime=INF;
    string earliestLessonName="";
    map <string,struct info> end=lessons.end();
    for(map <string,struct info>::i=lessons.begin();i!=end;i++)
    {
         string name=i->first;
         info lessonInfo=i->second;
         if(lessonInfo.start>lastEnd&&lessonInfo.end<earliestFinishTime)
         {
            earliestFinishTime=lessonInfo.end;
            earliestLessonName=name;
        }
    }
    return name;
}          

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string lesson;
        cin>>lesson;
        info lessonInfo;
        cin>>lessonInfo.start>>lessonInfo.end;
        lessons[lesson]=lessonInfo;
    }
}