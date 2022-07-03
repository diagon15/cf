// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
        // code here.
        // priority_queue<pair<char, int>> q;
        set<pair<int, int>>st1;
        set<pair<int, int>>st2;

        for (int i = 0; i < str.size(); ++i)
            st1.insert(make_pair(str[i], -i)),
            st2.insert(make_pair(str[i], i));


        for (int i = 0; i < str.size() and k > 0; ++i) {
            // while (not q.empty() and -q.top().second < i) q.pop();
            while(not st1.empty() and - (*--st1.end()).second < i){
                st2.erase(*--st1.end());
                st1.erase(--st1.end());
            }

            if(str[i] == (*--st1.end()).first){
                st1.erase(make_pair(str[i], i));
                st2.erase(make_pair(str[i], i));
            }
            else {
                cout << i << " " << (*--st1.end()).first << (*--st1.end()).second << endl;
                int digit, idx;
                if(str[i] < (*--st1.end()).first){
                    digit = (*--st2.end()).first;
                    idx = (*--st2.end()).second;
                }
                else{
                    // break;
                    continue;
                    digit = (*--st1.end()).first;
                    idx = - (*--st1.end()).second;
                }
                --k;

                st1.erase({str[i], i});
                st2.erase({str[idx], idx});

                swap(str[i], str[idx]);
                st2.insert({str[idx], idx});
            }
        }

        return str;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    // cin >> t;
    // while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
// } Driver Code Ends