// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int mid, low = 1, high = n;
        while(low <= high){
            
            mid = low + (high - low)/2; 

            if(isBadVersion(mid) && !isBadVersion(mid-1 )){
                return mid;
            }
            else if(isBadVersion(mid) )
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
        
    }
};
/*
    int firstBadVersion(int n) {
        int lo = 1, hi = n, mid;
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            if (isBadVersion(mid)) hi = mid;
            else lo = mid+1;
        }
        return lo;
    }*/