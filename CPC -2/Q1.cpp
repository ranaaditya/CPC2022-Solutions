/*
Jack and John are playing a game, they both have one-one words. Let jack words be word1 and John be word2. Jack has to convert his word into John words, He can do it by following these three operations:
By inserting a character
By deleting a character
By replacing a character

Return the minimum number of operations required to convert Jack word into John word.

Word1 and Word2 consist of lowercase English letters.
0 <= word1.length, word2.length <= 500
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
       int v[n+1][m+1];
        
        for(int i=0; i<=m; i++) // base case - if word1 is empty
        {
            v[n][i] = m-i;
        }    
        
        for(int j=0; j<=n; j++) // base case- if word2 is empty
        {
            v[j][m] = n-j;
        }
        
        for(int i=n-1; i>=0; i--)
        {
            for(int j=m-1; j>=0; j--)
            {
                if(word1[i]==word2[j])
                {
                    v[i][j] = v[i+1][j+1];
                }
                else
                    v[i][j] = 1 + min({ v[i+1][j], v[i+1][j+1], v[i][j+1] });
            }
        }
        
        return v[0][0];
        
        
    }
};