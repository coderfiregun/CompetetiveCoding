class Solution {
    boolean isValid(String s){
        //checking digits present or not
        if(s.matches(".*\\d.*")) return false;
        
        //cheking hyphens
        int hs = s.indexOf('-');
        int hl = s.lastIndexOf('-');
            
        if(hs!=-1){
            if(hs!=hl || hs==0 || hl==s.length()-1 || !(s.charAt(hs-1)>='a' && s.charAt(hs-1)<='z') || !(s.charAt(hs+1)>='a' && s.charAt(hs+1)<='z') )
                return false;
        }
        
        
        int cnt = 0;
        char[] punctuation = {'!','.',','};
        int lastidx = -1;
        for(char ch:punctuation){
            if(s.indexOf(ch)!=-1){
                 ++cnt;
                int l = s.indexOf(ch);
                int r = s.lastIndexOf(ch);
                if(l!=r) return false;
                lastidx = l;
            } 
        }
        
        if(cnt>1 || (cnt==1 && lastidx!=s.length()-1 )  ) return false;
        
        return true;
    }
    public int countValidWords(String sentence) {
        //splitting a string around space and then checking its validity
        String[] newStr = sentence.split("\\s+");
        int cnt = 0;
        for(String s:newStr){
            if(s.length()==0) continue;
            if( isValid(s) ){
                 ++cnt;  
                // System.out.println(s);
            }
        }
        return cnt;
    }
}