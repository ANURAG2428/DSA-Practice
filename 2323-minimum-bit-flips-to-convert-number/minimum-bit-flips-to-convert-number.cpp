class Solution {
public:
    int minBitFlips(int start, int goal) {
         int diff = start ^ goal; // XOR karo, jahan 1s hain, wo positions hain jahan bit flip karni padegi
        int flips = 0;

        // Jab tak diff mein koi bit bachi hai, loop chalao
        while (diff) {
            flips += (diff & 1);  // Agar current bit 1 hai, flips ko increment karo
            diff >>= 1;           // Diff ko right shift karo
        }

        return flips;  // Final number of flips return karo
    }
    
};