#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define all(x) x.begin(), x.end()

const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const int MAXN = 1e5 + 1;
const int M = 20;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        set<string> words(wordList.begin(), wordList.end());
        if (words.count(endWord) == 0)
            return 0;

        queue<string> q;
        set<string> visited;

        int ans = 1;
        q.push(beginWord);
        visited.insert(beginWord);

        while (q.size())
        {
            int len = q.size();
            while (len--)
            {
                string str = q.front();
                q.pop();

                if (str == endWord)
                    return ans;

                for (int i = 0; i < str.size(); ++i)
                {
                    for (char k = 'a'; k <= 'z'; ++k)
                    {
                        str[i] = k;
                        if (words.count(str) and !visited.count(str))
                        {
                            q.push(str);
                            visited.insert(str);
                        }
                    }
                }
            }
            ans++;
        }

        return 0;
    }
};