#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string removeDuplicates(string s)
{
    stack<char> st, str;

    string ans = "";
    int n = s.length() - 1;

    int i = 0, j = 0, k = 0;

    while (k <= n)
    {

        str.push(s.at(k));
        k++;
    }

    while (i <= str.size())
    {
        st.push(str.top());            //  st
        str.pop(); // abbaca           str acabba     abba   i=0     stack a        temp=b   else   stack ab
                   // abbaca               

        if (st.top() == str.top())
        {
            st.pop();
            str.pop();
           
        }
        else
        {

            st.push(str.top());
          
        }

        i++;
    }

    while (j < st.size())
    {
        ans += st.top();
        st.pop();
        j++;
    }


    /*reverse(ans.begin(), ans.end());*/

    return ans;
}

int main()
{

    string s = "abbaca";

    string s1 = "azxxzy";

    cout << removeDuplicates(s) << endl;
    cout << removeDuplicates(s1);
}