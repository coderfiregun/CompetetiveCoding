class Solution {
    boolean isValid(int num){
        int[] cnt = new int[10];
        Arrays.fill(cnt,0);
        
        int n = num;
        while(n>0){
            cnt[n%10]++;
            n/=10;
        }
        
        for(int i=0;i<=9;++i){
            if(cnt[i]==0 || cnt[i]==i) continue;
            return false;
        }
        return true;
    }
    public int nextBeautifulNumber(int n) {
        //we can brute force over
        for(int i=n+1;i<10000000;++i){
            if(isValid(i)) return i;
        }
        return 1224444;
    }
}