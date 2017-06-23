package sort;

public class HeapSort {
	private static int heapSize;
	public int Parent(int i){
		return i/2;
	} 
	
	public int Left(int i){
		return 2*i;
	}
	
	public int Right(int i){
		return 2*i+1;
	}
	
	public void MaxHeapify(int[] a,int i){
    int l,r,largest,temp;
    l=Left(i);
    r=Right(i);
    if(l<=heapSize && a[l-1]>a[i-1])
     largest=l;
    else largest=i;
    if(r<=heapSize && a[r-1]>a[largest-1])
     largest=r;
    if(largest!=i){
     temp=a[i-1];
     a[i-1]=a[largest-1];
     a[largest-1]=temp;
     MaxHeapify(a,largest);
    }
   }
	
   public void BuildMaxHeap(int[] a){
	heapSize=a.length;  
    for(int i=a.length/2;i>=1;i--)
     MaxHeapify(a,i);
   }
   
   public void heapSort(int[] a){
    BuildMaxHeap(a);
    for(int i=a.length;i>=2;i--){
     int temp;
     temp=a[i-1];
     a[i-1]=a[0];
     a[0]=temp;
     heapSize=heapSize-1;
     MaxHeapify(a,1);
    }
   }
public static void main(String[] args) {
    HeapSort heap=new HeapSort();
	int[] a = { 15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1 };
	System.out.println("¶ÑÅÅÐò½á¹û£º");
	heap.heapSort(a);
	for(int t=0;t<a.length;t++)
		System.out.println(a[t]+" "); 
}
}
