/* 

Optimized Approch : Explained In Register with dry run

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    void DFS(string word ,string beginword , unordered_set<string>&wordset,  vector<string>&currpath , vector<vector<string>>&ans ,unordered_map<string,int>&mpp){
        
        // 1st base case (agr to word == beginword -> measn we get sequence -> will simply add this currpath in ans vector )
        if(word == beginword){
            reverse(currpath.begin() , currpath.end()); // since currpath is storing seq in reverse order -> that's why
            ans.push_back(currpath);
            // since reversing above currpath -> will disturb the backtracking -> so mai yaha re-reverse karunga currpath vector stroing shortest seq inorder to do correct backtracking
            reverse(currpath.begin() , currpath.end());
            return; // Backtrack -> since it is of void type
        }

        // step 1 : now will check for the word -> that can be formed by character manipulation -> same like we done in BFS + lekin vo jo word bne uska level jo ki map mai store hai must be 1 less than the current word level

        int currlevel = mpp[word];

        for(int i = 0 ; i<word.size() ; i++){
            char originalchar = word[i];
            for(int j = 0 ; j<26 ; j++){
                word[i] = j + 'a';
                if(mpp.find(word)!= mpp.end() && mpp[word]+1 == currlevel){ // means word exists in map , now ek aur if check is ki uska level must be 1 less than the currlevel 
                    currpath.push_back(word); // currpath vector mai word daal dunga
                    DFS(word ,beginword ,wordset , currpath ,  ans , mpp );
                    // pop this new word added to get new dfs call for same level
                    currpath.pop_back();
                }

            }
            word[i] = originalchar;
        }

    }
public:
    vector<vector<string>> findLadders(string beginword, string endword, vector<string>& wordList) {
        // step 1 : sbse pehle to wordlist ko unordered_Set mai store kareneg
        unordered_set<string>wordset(wordList.begin() , wordList.end());

        // IMP - check kr worset mai endword exist krta bhi hai , agr nhi krta empty vector return kr de
        if(wordset.find(endword) == wordset.end()) return {};

        // step 2 : create unordered_map of {string , int} type
        unordered_map<string,int>mpp;
        queue<string>q;
        
        // note - manually push begin word with level 0 in  mpp and stirng in queue
        q.push(beginword);
        mpp[beginword] = 1;

        // note - agr to wordset mai begin word exist krta hai usse remove krde
        wordset.erase(beginword);

        // step 3 : now do BFS , till qeueue empty nhi hoti
    
        while(!q.empty()){
            string word = q.front();
            int currlevel = mpp[word]; 
            q.pop();
            if(word == endword) break; // no need to run this loop , stop
            for(int i = 0 ; i<word.size() ; i++){
                char originalchar = word[i]; 
                for(int j = 0 ; j<26 ; j++){
                    word[i] = j + 'a';
                    if(wordset.find(word) != wordset.end()){
                        mpp.insert({word , currlevel+1}); // insert this into mpp ,with its valid level 
                        q.push(word); // push in queue
                        wordset.erase(word);  // erase it from unordered_set to avoid duplicacy
                    }
                }
                word[i] = originalchar;
            }

        }

        // IMP NOTE - DFS call krne se pehle ye dekho ki hme endword mila hai mpp  mai using BFS + queue (Agar endword tak pahuncha hi nahi ja sakta (matlab graph mein connect hi nahi hai), toh tum seedha DFS(endword, ...) call kar doge. Isse mpp mein ek naya entry ban jayegi galat level ke sath.)

        if(mpp.find(endword) != mpp.end()){
            //  Now will call DFS for endword with ans 2d vector which will have all valid shortest path sequence's -> then will simply return ans
            vector<vector<string>>ans;
            vector<string>currpath;
            currpath.push_back(endword);
            unordered_set<string>wordset2(wordList.begin() , wordList.end());
            DFS(endword, beginword ,wordset2 , currpath ,  ans , mpp);
            return ans;
        }
        return {};
    }

};