class Solution {
public:
    void rotate(vector<int>& v, int k) {
        int n = v.size();
        
        if(k >= n)
            k = k % n;
        
        reverse(v.begin(),v.end()-k);
        reverse(v.begin() + n -k,v.end());
        reverse(v.begin(),v.end());
        
        // for(int i=0; i<k;i++){
        //     int temp = nums[n-1];
        //     for(int j=n-1; j>0;j--){
        //         nums[j] = nums[j-1];
        //     }
        //     nums[0]= temp;
        // }
    }
};