#include <iostream>

using namespace std;
int k,d;

int main(){
    cin >> k >> d;
    if ( d == 0 ){
        if ( k == 1 )
            cout << 0;
        else
            cout << "No solution";
        return 0;
    }
    cout << d;
    for ( int i = 1; i < k; i++ )
        cout << 0;
    return 0;
}
