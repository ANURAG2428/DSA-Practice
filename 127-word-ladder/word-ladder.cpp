/*

Optimized Approch : Explained in Register with dry run

- will do level Wise traversal (means BFS traversal)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginword, string endword,
                     vector<string>& wordList) {
        // step 1 : is to put all the vector wordlist in unordered<string>set ,
        // to avoid duplicacy and longer path
        unordered_set<string> wordset(wordList.begin(),
                                      wordList.end()); // ye constructor hai

        // step2 : ek baar manually check krle , endWord exist bhi karta hai
        // wordset mai , agr nhi krta to yhi se 0 return krde loop ki jgh mai
        // sidgh unordered_set ke .find() se dekhunga ki endword hai bhi set mai
        // , agr nhi hai then will return 0.
        if (wordset.find(endword) == wordset.end())
            return 0;

        // step 3 : now ab mai BFS traversal karunga and begin word ko queue mai
        // daal ke uske sare characters ko change krke dekhunga and similar
        // logic will be applied until , did'nt get endword
        int level = 1; // intially beginword ka level 1 hoga (as it is a part of
                       // shortes path )
        queue<pair<string, int>> q;
        q.push({beginword, level});

        // IMP NOTE - in this case to nhi hai beginword -> wordset mai , but
        // kisi example mai ho bhi skta hai , so manually push krne ke baad hm
        // usse wordset se remove kr denge manually EDGE CASE:
        wordset.erase(beginword);

        while (!q.empty()) {
            string currword = q.front().first;
            int currlevel = q.front().second;
            q.pop(); // will pop it out now
            if (currword == endword)
                return currlevel;

            for (int i = 0; i < currword.size(); i++) {
                char originalcharacter = currword[i];
                for (int j = 0; j < 26; j++) {
                    currword[i] = j + 'a';

                    if (wordset.find(currword) != wordset.end()) {
                        q.push({currword, currlevel + 1});
                        wordset.erase(currword);
                    }
                }
                // IMP NOTE - now internal each word ke iteration mai original
                // word modify ho jayega , to each time hr char iteration
                // complete hone ke baad mai original word ko restore karunga
                // (by restoring manipulated character)
                currword[i] = originalcharacter;
            }
        }
        return 0;
    }
};