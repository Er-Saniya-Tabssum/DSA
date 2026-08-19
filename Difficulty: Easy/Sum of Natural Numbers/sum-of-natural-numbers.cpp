#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int i=1,sum=0;
    // code here
    while(n>0){
        sum=i+sum;
        i++;
        n--;
    }
    cout<<sum;
    return 0;
}