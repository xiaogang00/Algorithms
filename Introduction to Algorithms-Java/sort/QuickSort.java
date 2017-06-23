package sort;

//import java.util.Random;

public class QuickSort {
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
	public void quickSort(int[] a,int p,int r){
		if(p<r){
			int q=Partition(a,p,r);
			output(a);
			System.out.println(q);// 返回枢轴关键字在数组中的位置
			quickSort(a,p,q-1);
			quickSort(a,q+1,r);
		}
	}
	public void output(int[]A){
		for (int t = 0; t < A.length; t++)
			System.out.print(A[t] + " ");
		System.out.println();
	}
	public static void main(String[] args) {
		QuickSort q=new QuickSort();
		/*Random ran=new Random();
		double start,end;
		int a[]=new int[30000];
		for(int i=0;i<30000;i++)
			a[i]=ran.nextInt(30000);
		start=System.currentTimeMillis();
		q.quickSort(a,0,a.length-1);
		end=System.currentTimeMillis();
		//for(int t=0;t<30000;t++)
			//System.out.println(a[t]+" ");
		System.out.println("运行时间:"+(end-start)+"ms");*/
		int a[]={13,19,9,5,12,8,7,4,11,2,6,21};
		q.quickSort(a,0,a.length-1);

	}

}
