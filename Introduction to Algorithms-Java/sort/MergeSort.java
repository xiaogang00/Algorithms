package sort;

import java.util.Random;

public class MergeSort{
	public static void mergeSort(int[] a,int p, int r)
	{
		if(p<r)
		{
			int q = (r+p)/2;
			mergeSort(a,p, q);
			mergeSort(a,q+1, r);
			merge(a,p, q, r);
		}
	}
	
	private static void merge(int[] a,int p, int q, int r)
	{
		int n1, n2;
		n1 = q-p+1;
		n2 = r-q;
		int L[], R[];
		L = new int[n1+1];
		R = new int[n2+1];
		for(int i=0; i<n1; i++)
			L[i] = a[p+i];
		for(int i=0; i<n2; i++)
			R[i] = a[q+i+1];
		L[n1] = R[n2] = 60000;
		n1 = n2 = 0;
		for(int i=p; i<=r; i++)
		{
			if(L[n1]>R[n2])
			{
				a[i] = R[n2];
				n2++;
			}
			else
			{
				a[i] = L[n1];
				n1++;
			}
		}
	}
	
	
	public static void main(String[] args) 
	{
		Random ran=new Random();
		double start,end;
		int a[]=new int[30000];
		for(int i=0;i<30000;i++)
			a[i]=ran.nextInt(10000);
		start=System.currentTimeMillis();
		mergeSort(a,0,29999);
		end=System.currentTimeMillis();
		for(int t=0;t<30000;t++)
			System.out.println(a[t]+" ");
		System.out.println("运行时间:"+(end-start)+"ms");

	}
		

}