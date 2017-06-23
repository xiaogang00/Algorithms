package sort;

public class LCS {

	public int[][] LCS_Length(char[] X,char[] Y){
		int m=X.length;
	    int n=Y.length;
	    int c[][]=new int[m][n];
	    int b[][]=new int[m][n];
	    for(int i=1;i<=m;i++)
	    	c[i-1][0]=0;
	    for(int j=1;j<=n;j++)
	    	c[0][j-1]=0;
	    for(int i = 1;i<=m-1;i++){
	    	 for(int j=1;j<=n-1;j++){
	    		 if(X[i-1]==Y[j-1]){
	    			 c[i][j]=c[i-1][j-1]+1;
	    			 b[i-1][j-1]=0;
	    		 }
	    		 else if(c[i-1][j]>=c[i][j-1]){
	    			 c[i][j]=c[i-1][j];
	    			 b[i-1][j-1]=1;
	    		 }
	    		 else{
	    			 c[i][j]=c[i][j-1];
	    			 b[i-1][j-1]=2;
	    		 }
	    	 }
	    }
	    return b;
	}
	public void Print_LCS(int[][] b,char[] X,int i,int j){
		if(i==0 || j==0)
			return;
		if(b[i-1][j-1]==0){
			 Print_LCS(b,X,i-1,j-1);
			 System.out.print(X[i-1]+" ");
		}
		else if(b[i-1][j-1]==1)
			Print_LCS(b,X,i-1,j);
		else
			Print_LCS(b,X,i,j-1);
	}
	public static void main(String[] args) {
		LCS lcs=new LCS();
		char S1[]={'A','C','C','G','G','T','C','G','A','G','T','G',
				'C','G','C','G','G','A','A','G','C','C','G','G','C','C','G','A','A'};
		char S2[]={'G','T','C','G','T','T','C','G','G','A','A',
				'T','G','C','C','G','T','T','G','C','T','C','T','G','T','A','A','A'};
		int m=S1.length,n=S2.length;
		int b[][]=new int[m][n];
		b=lcs.LCS_Length(S1, S2);
		lcs.Print_LCS(b, S1, m, n);

	}

}
