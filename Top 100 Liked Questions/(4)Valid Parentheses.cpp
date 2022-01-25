/*
(20)Valid Parenthesis

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.

*/

-------------- my solution -----------------
    
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;        
        for(int i=0;i<s.length();i++) {
            char top = st.empty() ? '#' : st.top();
            
            if(top == '(' && s[i] == ')') {
                st.pop();
            }else if(top == '{' && s[i] == '}') {
                st.pop();
            }else if(top == '[' && s[i] == ']') {
                st.pop();
            }else{
                st.push(s[i]);
            }    
        }
        
        return st.empty();
    }
};
