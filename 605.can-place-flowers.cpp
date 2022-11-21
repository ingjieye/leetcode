class Solution {
public:
    bool isPlanted(vector<int>& v, int i)
    {
        bool ret = false;
        if (i >= 0 && i < v.size()) {
            ret = v[i] == 1;
        }
        return ret;
    }
    
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i=0; n > 0 && i < flowerbed.size(); i++) {
            if (isPlanted(flowerbed, i) ||
                isPlanted(flowerbed, i-1) ||
                isPlanted(flowerbed, i+1)) {
                continue;
            }
            n--;
            i++;
        }
        return n == 0;
    }
};