public class RegexMatching {

    public static void main(String[] args){
        String p = "mis*is*p*.";
        String s = "mississippi";
        isMatch(s, p);
    }

    public static boolean isMatch(String s, String p) {

        boolean[][] dp = new boolean[s.length() + 1][p.length() + 1];
        dp[0][0] = true;
        for(int i = 1; i < dp[0].length; i++) {
            if(p.charAt(i-1) == '*') {
                dp[0][i] = dp[0][i-2];
            }
        }

        for(int x = 1; x < dp.length; x++) {
            for(int y = 1; y < dp[x].length; y++) {
                if(s.charAt(x -1) == p.charAt(y -1) || p.charAt(y -1 ) == '.') dp[x][y] = dp[x-1][y-1];
                else if(p.charAt(y -1) == '*') {
                    if(p.charAt(y-2) != s.charAt(x -1) && p.charAt(y-2) != '.')
                        dp[x][y] = dp[x][y-2];
                    else
                        dp[x][y] = dp[x][y-2] | dp[x-1][y] | dp[x][y-1];
                }
                else dp[x][y] = false;
            }
        }
        return dp[s.length()][p.length()];

    }

}
