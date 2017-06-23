package sort;

public class ALS {

    public int[][] Fastest_Way(int[] a1,int[] a2,int[] t1,int[] t2,
    		int e1,int e2,int x1,int x2,int n){
    	int f1[]= new int[n];
    	int f2[]= new int[n];
    	int L[][]= new int[2][n];
    	//int F=0;
    	f1[0]=e1+a1[0];
    	f2[0]=e2+a2[0];
    	for(int j=2;j<=n;j++){
    		if((f1[j-2]+a1[j-1]) <= (f2[j-2]+t2[j-2]+a1[j-1])){
    			f1[j-1]=f1[j-2]+a1[j-1];
    			L[0][j-1]=1;
    		}
    		else {
    			f1[j-1]=f2[j-2]+t2[j-2]+a1[j-1];
    			L[0][j-1]=2;
    		}
    		if((f2[j-2]+a2[j-1]) <= (f1[j-2]+t1[j-2]+a2[j-1])){
    			f2[j-1]=f2[j-2]+a2[j-1];
    			L[1][j-1]=2;
    		}
    		else{
    			f2[j-1]=f1[j-2]+t1[j-2]+a2[j-1];
    			L[1][j-1]=1;
    		}
    	}
    	if(f1[n-1]+x1<=f2[n-1]+x2){
    		//F=f1[n-1]+x1;
    		L[0][0]=1;
    	}
    	else{
    		//F=f2[n-1]+x2;
    		L[0][0]=2;
    	}
    	return L;
    }
    public void Print_Station(int[][] L,int n){
    	int i=L[0][0];
    	System.out.println("line "+i+",station "+n);
    	for(int j=n;j>=2;j--){
    		i=L[i-1][j-1];
    		System.out.println("line "+i+",station "+(j-1));
    	}
    	
    }
	public static void main(String[] args) {
		ALS als=new ALS();
		int e1=2,e2=4,x1=3,x2=2;
		int a1[]={7,9,3,4,8,4};
		int a2[]={8,5,6,4,5,7};
		int t1[]={2,3,1,3,4};
		int t2[]={2,1,2,2,1};
		int n=a1.length;
		int L[][]=new int[2][n];
		L=als.Fastest_Way(a1, a2, t1, t2, e1, e2, x1, x2, n);
		als.Print_Station(L, n);
	}

}
