class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // Edge case
        if(bills[0] == 10 || bills[0] == 20) return false;
        
        // step 1 : will do variable count (increament/decreament) -> if at any moment req variable is 0 , then will return false , else return true
        int five = 0 , ten = 0 , twenty = 0;

        // iterate bills vector
        for(int i = 0 ; i<bills.size() ; i++){
            if(bills[i] == 5){
                five++;
            }
            else if (bills[i] == 10){
                ten++;
                if(five == 0) return false;
                else five--;
            }
            else{ // means bills[i] == 20
                twenty++;
                if(ten > 0 && five > 0){
                    ten--;
                    five--;
                }
                else if( five >= 3){
                    five = five - 3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};