// Approch : here jb mai string s ko traverse kr rha hu , i want ki jese initially 1st element s[i] agr stack mai gya should be opening bracket , means either ( || { || [ , agr ye hai , bcz stack mai hamesha opening wala char jana chahiye , jisko mai string ki iteration ke closing wale se match karunga , if not matches return false 

class Solution {
public:
    bool isValid(string s) {
    stack<char>st; // stack to char type ka banega na 
        for(int i = 0 ; i<s.size() ; i++){

            if(s[i] == '(' || s[i] == '{' || s[i] == '['){ // if during iteration i encounter opening bracket i will store it in stack
                st.push(s[i]);   
            }
            else{ // means agr to iteration krte hue mujhe opening bracket nhi mile , then
                if(st.empty()){  // agr shuruwat mai hi closing bracket mil gya , then also it is not valid parenthesis
                    return false;
                }
                //Now agr to mere stack mai already character pda mila and vo opening bracket hi h , so ab mai usse bahr nikal lunga aur ek variable mai store kara lunga
                char ch = st.top(); // store the top most character in stack
                st.pop();  // removed that top element

                if((s[i] == ')' && ch =='(') || (s[i] == '}' && ch =='{') || (s[i] == ']' && ch =='[')){  // agr to ye match kr rahe hai ,then skip
        // NOTE - stack mai to opening bracket hoga and char mai closing bracket hoga (which is of s[i])

                    continue; // skip
                } 
                else{
                    // means does'nt matches , then return false
                    return false;
                }
            }

        }
        return st.empty(); // agr to empty hoga means sare top matche ho gye string se , then return true , else return false

        
        
    }
};