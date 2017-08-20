package sort;

import java.util.Random;

public class Randomized_Select {
	public int Partition(int[] a,int p, int r){
		int x=a[r];
		int i=p-1;
		for(int j=p;j<=r-1;j++)
			if(a[j]<=x){
				i++;
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		int temp=a[i+1];
		a[i+1]=a[r];
		a[r]=temp;
		return i+1;
	}
	public int Randomized_Partition(int[] a,int p,int r){
		Random ran=new Random();
		int i=ran.nextInt(r-p)+p;
		int temp=a[r];
		a[r]=a[i];
		a[i]=temp;
		return Partition(a,p,r);
	}
	public int RandomizedSelect(int[] a,int p,int r,int i){
		if(p==r)
			return a[p];
		int q=Randomized_Partition(a,p,r);
		int k=q-p+1;
		if(i==k)
			return a[q];
		if(i<k)
			return RandomizedSelect(a,p,q-1,i);
		else
			return RandomizedSelect(a,q+1,r,i-k);
			
	}
	public static void main(String[] args) {
		Randomized_Select rs=new Randomized_Select();
		int a[]={13,19,9,5,12,8,7,4,11,2,6,21};
		
		for (int i =1; i <= a.length; i++)
			System.out.println("第"+i+"小的数是"+rs.RandomizedSelect(a,0,a.length-1,i));

	}

}
