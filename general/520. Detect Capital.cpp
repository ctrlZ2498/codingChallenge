/*
520. Detect Capital

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.

 

Example 1:

Input: word = "USA"
Output: true
Example 2:

Input: word = "FlaG"
Output: false
 

Constraints:

1 <= word.length <= 100
word consists of lowercase and uppercase English letters.
*/
 
//--------- my answer ----------// best performance with runtime 0ms !!
class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        int vec[n];
        vec[0]=isupper(word[0])?1:0;
        for(int i=1;i<n;i++){
            if(isupper(word[i])){
                vec[i]=vec[i-1]+1;
            } 
            else{
                 vec[i]=vec[i-1];
            } 
        }
        if(vec[n-1]==n || (vec[n-1]==1 && vec[0]==1) || vec[n-1]==0){
            return true;
        }
        else{
            return false;
        }
    }
};

//--------- regex ----------//
class Solution {
    public boolean detectCapitalUse(String word) {
        return word.matches("[A-Z]*|.[a-z]*");
    }
}

////--------- best one in discussions ----------//
class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt=0;
        int loc;
        for(int i=0;i<word.length();i++){
            if(word[i]>='A' && word[i]<='Z'){
                cnt++;
                loc = i;
            }
        }
        return cnt == word.length() || cnt == 0 || (cnt == 1 && loc == 0);
    }
};   
