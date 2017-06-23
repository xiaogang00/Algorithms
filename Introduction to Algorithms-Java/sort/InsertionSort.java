package sort;
import java.util.Random;
public class InsertionSort {

	public void insertion(int[] a){
		int i,j;
		int temp;
		for ( i=1; i<a.length; ++i){
			if (a[i] < a[i-1]){
				temp = a[i];       
				for ( j=i-1; j>=0&&temp < a[j];  -- j )
					a[j+1] = a[j];
				a[j+1] = temp;
			}
		}
	}
	public void Insertion_Sort(int[] a){
		for(int j=2;j<=a.length;j++){
			int key=a[j-1];
			int i=j-1;
			while(i>0 && a[i-1]>key){
				a[i]=a[i-1];
				i--;
			}
			a[i]=key;
		}
	}
	public static void main(String[] args) {
		InsertionSort insert=new InsertionSort();
		Random ran=new Random();
		double start,end;
		int a[]=new int[30000];
		for(int i=0;i<30000;i++)
			a[i]=ran.nextInt(30000);
		start=System.currentTimeMillis();
		//insert.Insertion_Sort(a);
		insert.insertion(a);
		end=System.currentTimeMillis();
		for(int t=0;t<30000;t++)
			System.out.println(a[t]+" ");
		System.out.println("运行时间:"+(end-start)+"ms");

	}

}
