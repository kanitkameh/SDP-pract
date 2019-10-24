#include <iostream>
#include <stack>
using namespace std;
int counter = 0;
void moveDiscs(stack<int>& source, stack<int>& help, stack<int>& dest,
               int discCount){
    if(discCount==1 && (dest.empty() || dest.top()>source.top())){
        int element = source.top();
        source.pop();
        dest.push(element);
        counter++;
        return;
    }
    moveDiscs(source,dest,help,discCount-1);
    moveDiscs(source,help,dest,1);
    moveDiscs(help,source,dest,discCount-1);
}

int main()
{
    stack<int> stck1;
    stack<int> stck2;
    stack<int> stck3;
    int n;
    cin >> n;
    for(int i=n;i>0;i--){
        stck1.push(i);
    }
    moveDiscs(stck1,stck2,stck3,n);
    cout << counter << endl;
    return 0;
}
