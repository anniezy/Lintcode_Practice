class Solution {
public:
    /**
     * @param k: An integer
     * @param n: An integer
     * @return: An integer denote the count of digit k in 1..n
     */
    int digitCounts(int k, int n) {
    
        long long int c = 10, ans = 0, l, r, nd = 0;
        long long int d = n, p[16], cur;
        if(n < 10){
            if(n >= k) return 1;
            else return 0;
        }
        
        //compute the digits of number n.
        while(d>0){
            d = d/10;
            ++ nd;
        }
        //store the number 10^n
        p[0] = 1;
        for(int i = 1; i < nd; ++ i){
            p[i] = p[i-1] * 10;
        }
        
        d = n;
        //get the count of digit k appears in the leftmost place.
        ans += d/10;
        if(d%10 >= k) ++ ans;
        
        
        //compoute the times that k appears on each of the place, from low to high.
        for(int i = 1; i < nd; ++ i){
          //if the digit k is zero, it is impossible to appear in the highest place.
            if(k == 0 && i == nd-1) return ans;
            
            //get the value of right side in r, left side in l, and current place in cur.
            r = d/p[i];
            l = d%p[i];
            cur = r%10;
            r = r/10;
            
            ans += r * p[i];
            if(cur == k){
                ans += l+1;
            }else if(cur > k){
                ans += p[i];
            }
            
            if(k == 0) ans -= p[i];
        }
        
        return ans;
    }
};
