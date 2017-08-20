package sort;

public class Matrix_chain {
	/**
	 Matrix-chain multiplication
	 ¾ØÕóÁ¬³ËÎÊÌâ
	 */
	public int[][] MatrixChainOrder(int[] p){
		int n=p.length-1;
		int s[][]=new int[n][n];
		int m[][]=new int[n][n];
		for(int i=1;i<=n;i++)
			m[i-1][i-1]=0;
		for(int L=2;L<=n;L++){
			for(int i=1;i<=n-L+1;i++){
				int j=i+L-1;
				m[i-1][j-1]=32767;
				for(int k=i;k<=j-1;k++){
					int q=m[i-1][k-1]+m[k][j-1]+p[i-1]*p[k]*p[j];
					if(q<m[i-1][j-1]){
						m[i-1][j-1]=q;
						s[i-1][j-1]=k;
					}
				}
			}
		}
		return s;
	}
	public void PaintOptimalParens(int[][] s,int i,int j){
		if(i==j)
			System.out.print("A"+i);
		else{
			System.out.print("(");
			PaintOptimalParens(s,i,s[i-1][j-1]);
			PaintOptimalParens(s,s[i-1][j-1]+1,j);
			System.out.print(")");
		}
	}
	public static void main(String[] args) {
		int p[]={30,35,15,5,10,20,25};
		Matrix_chain mc= new Matrix_chain();
		int[][] s=mc.MatrixChainOrder(p);
		mc.PaintOptimalParens(s,1,6);

	}

}
