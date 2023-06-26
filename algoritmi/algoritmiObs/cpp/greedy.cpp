#include <vector>
#include <iostream>

using namespace std;

struct Interval
{
    int begin;
    int end;
};

void printIntervals(vector<Interval> list){
    for(Interval el:list){
        for (int i = 0; i < el.begin; i++)
        {
            cout << " ";
        }
        for (int i = 0; i <= el.end-el.begin; i++)
        {
            cout << "#";
        }
        cout << endl;
    }
}

vector<Interval> solveIntervals(vector<Interval> list){
    vector<Interval> out;

    out.push_back(list[0]);

    int last = 0;

    for (int  i = 1; i < list.size(); i++)
    {
        if(list[i].begin > list[last].end){
            out.push_back(list[i]);
            last = i;
        }
    }
    
    return out;
}

int main(int argc, char const *argv[])
{
    Interval temp[] = {{1,4}, {2,7}, {8,10}, {5,11}, {6,13}, {13,17}};
    vector<Interval> list;

    for (int i = 0; i < 6; i++)
    {
        list.push_back(temp[i]);
    }
    
    printIntervals(list);

    cout << "--------------------------------------------------" << endl;

    printIntervals(solveIntervals(list));
    
    return 0;
}
