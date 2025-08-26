class Solution {
public:
    int reverse(int x) {
        long rev = 0;  // to hmne pehle rev ko long bna liya , incase int ki range se bahr wala number bnta hai rev krte hue to handle ho jaye 
        while(x!=0){
            // step 1: num % 10 = to store last digit of num 
            int lastdigit = x % 10;
        
            // step 2: to store the digit i reverse order
            rev = (rev*10)+lastdigit;
        
            // step 3: num ko divison operator ki help se chota krte jayenge by removing the last digit , in each iteration of loop ,
            x = x /10; // isley last digit remove hota jayega , kyoki int type ke num mai       decimal wala ht jata hai


            // NOW AB REVERSE KRTE HUE AGR NUM INT KI RANGE SE BAHR CHALAGYA , TO QUESTION MAI DE RAKHA HAI RETURN 0 
            if(rev>INT_MAX || rev<INT_MIN){
                return 0;
            }

        }
        return (int)rev;    // yaha hm rev ko dubara int bna denge 
    }
};