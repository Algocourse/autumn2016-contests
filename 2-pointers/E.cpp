#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

stack<int> st;

int main() {
    string s;
    cin >> s;

    for (int i = 1; i <= (int)s.length(); i++)
        if (s[i - 1] == 'r')
            cout << i << endl;
        else
            st.push(i);

    while (st.size() > 0) {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}
