class Solution {
public:
    int binaryGap(int n) {
        int maxDis=0;
        int i=31;
        while(i>=0){
            if(n&(1<<i)) break;
            i--;
        }
        int lastOneIdx=i;
        while(i>=0){
            if(n&(1<<i)){
                maxDis=max(maxDis,lastOneIdx-i);
                lastOneIdx=i;
            }
            i--;
        }
        return maxDis;
    }
};