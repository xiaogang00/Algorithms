package sort;

public class Max_priorityQueue {
	/**
	 Priority queues
	 优先队列
	 */

	private int Heap_Size;

	private int[] A;

	public int Parent(int i) {
		return i / 2;
	}

	public int Left(int i) {
		return 2 * i;
	}

	public int Right(int i) {
		return 2 * i + 1;
	}

	Max_priorityQueue(int[] a) {
		this.A = a;
		Heap_Size = A.length;
	}

	public void Max_Heapify(int i) {
		int l, r, largest, temp;
		l = Left(i);
		r = Right(i);
		if (l <= Heap_Size && A[l - 1] > A[i - 1])
			largest = l;
		else
			largest = i;
		if (r <= Heap_Size && A[r - 1] > A[largest - 1])
			largest = r;
		if (largest != i) {
			temp = A[i - 1];
			A[i - 1] = A[largest - 1];
			A[largest - 1] = temp;
			Max_Heapify(largest);
		}

	}

	public int Heap_Maximum() {
		return A[0];
	}

	public int Heap_Extract_Max() {
		if (Heap_Size < 1) {
			System.out.println("heap underflow!");
			System.exit(0);
		}
		int max = A[1];
		A[1] = A[Heap_Size];
		Heap_Size--;
		Max_Heapify(1);
		return max;
	}

	public void Heap_Increase_key(int i, int key) {
		if (key < A[i - 1]) {
			System.out.println("new key is smaller than current key!");
			System.exit(0);
		}
		A[i - 1] = key;
		while (i > 1 && A[Parent(i) - 1] < A[i - 1]) {
			int temp = A[i - 1];
			A[i - 1] = A[Parent(i) - 1];
			A[Parent(i) - 1] = temp;
			i = Parent(i);
		}
	}

	public void Max_Heap_Insert(int key) {
		Heap_Size++;
		int a[] = new int[Heap_Size];
		for (int i = 0; i < A.length; i++)
			a[i] = A[i];
		a[Heap_Size - 1] = -32767;
		A = a;
		Heap_Increase_key(Heap_Size, key);

	}

	public void BuildMaxHeap() {
		for (int i = A.length / 2; i >= 1; i--)
			Max_Heapify(i);
	}

	public void output() {
		for (int t = 0; t < A.length; t++)
			System.out.print(A[t] + " ");
	}

	public static void main(String[] args) {
		int[] a = { 15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1 };
		Max_priorityQueue mpq = new Max_priorityQueue(a);
		mpq.BuildMaxHeap();
		mpq.Max_Heap_Insert(200);
		mpq.output();
		//System.out.print(mpq.Heap_Maximum());

	}

}