class Solution {
public:
    bool Rotate(string s , int len , int k , string goal ){
    int i = 0;
    int m = len-1;
    while(i<m){
        swap(s[i],s[m]);
        i++;
        m--;
    }
    // cout<<"Reversing Whole a : "<<s<<endl<<endl;

    m = len -1;

    // step 3 : swap first k character
    i = 0;
    int j = k-1;
    while(i<j){
        swap(s[i],s[j]);
        i++;
        j--;
    }
    // cout<<"Reversing first k in s : "<<s<<endl<<endl;

    // step 4 : swap pending char from k to len-1
    j = k;
    while(j<m){
        swap(s[j], s[m]);
        j++;
        m--;
    }

    if(s == goal){
        return true;
    }
    
    
    return false;
    // cout<<"Reversing pending char in s : "<<arr<<endl<<endl;

    }

    bool rotateString(string s, string goal) {
        int len = s.length();

        // sbse pehla check to yhi kar le agr s aur goal ki length hi same nhi hai then no need to to check further
        if(s.length() != goal.length()){
            return false;
        }

        for(int i = 0 ; i<len ; i++){
            int k = i;
            if(Rotate(s, len , k , goal)){
                return true;
            }
            
        }

    return false;      
        
    }
};