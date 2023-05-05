# 1456. Maximum Number of Vowels in a Substring of Given Length


Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

 
```
Example 1:
Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
```
```
Example 2:
Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
```
```
Example 3:
Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
```



```cpp
class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int l=0,count=0,ans=0;
        for(int r=0;r<s.size();r++) {
            if(isVowel(s[r])){
                count += 1;
            }

            if(r-l+1 > k) {
                if(isVowel(s[l])) {count -= 1;}
                l += 1;
            }
            ans = max(ans,count);
        }

        return ans;
    }
};
```
