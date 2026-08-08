class Solution {
public:
    int totalFruit(vector<int>& v) {
        int n = v.size();
        int maxfruit = 0;
        int s = 0, e = 0;
        int k = 2;
        unordered_map<int, int> mpp;

        while (e < n) {
            // step 1 : sbse pehle to e wala element mpp mai daal frequency ke
            // sath
            mpp[v[e]]++;

            // step 2 : now agr mera mpp.size() >k , so mai s pointer ki help se
            // window from start side tb tk reduce karunga , jb tk mpp.size()
            // <=k
            while (mpp.size() > k) {
                // Note - mai directly v[s] ko delete nhi karunga , blki mai
                // window from left side shrink karate hue freq mai decreament
                // karunga and if meri kisi no ki freq ==0 ho jati hai then mai
                // usse map se delete karunga
                mpp[v[s]]--;
                if (mpp[v[s]] == 0)
                    mpp.erase(v[s]);
                s++;
            }

            maxfruit = max(maxfruit, e - s + 1);
            e++;
        }
        return maxfruit;
    }
};