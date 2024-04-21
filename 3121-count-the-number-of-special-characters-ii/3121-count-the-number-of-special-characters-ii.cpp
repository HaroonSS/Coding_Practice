#define FOR(i, a, n) for(int i = a; i < n; i++)
class Solution {
public:
    int numberOfSpecialChars(string S) {
        int lst[26], fst[26];
        FOR(i, 0, 26)
        lst[i] = fst[i] = -1;

        int n = S.size();

        FOR(i, 0, n) {
            if (islower(S[i]))
                lst[S[i] - 'a'] = i;
        }
        for (int i = n - 1; ~i; i--)
            if (isupper(S[i]))
                fst[S[i] - 'A'] = i;

        int ans = 0;

        FOR(i, 0, 26) {
            if (lst[i] != -1 and lst[i] < fst[i])
                ans++;
        }
        return ans;
    }
};