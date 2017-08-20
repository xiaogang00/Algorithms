package greedy;

public class Min_priorityQueue {
	/**
	 Priority queues
	 优先队列
	 */

	private int Heap_Size;

	private Nodes[] A;

	public int Parent(int i) {
		return i / 2;
	}

	public int Left(int i) {
		return 2 * i;
	}

	public int Right(int i) {
		return 2 * i + 1;
	}

	Min_priorityQueue(Nodes[] a) {
		this.A = a;
		Heap_Size = A.length;
	}

	public void Min_Heapify(int i) {
		int l, r, largest;
		l = Left(i);
		r = Right(i);
		if (l <= Heap_Size && A[l - 1].getWeight() < A[i - 1].getWeight())
			largest = l;
		else
			largest = i;
		if (r <= Heap_Size && A[r - 1].getWeight()< A[largest - 1].getWeight())
			largest = r;
		if (largest != i) {
			Nodes temp = A[i - 1];
			A[i - 1] = A[largest - 1];
			A[largest - 1] = temp;
			Min_Heapify(largest);
		}

	}

	public Nodes Heap_Minimum() {
		return A[0];
	}

	public Nodes Heap_Extract_Min() {
		if (Heap_Size < 1) {
			System.out.println("heap underflow!");
			System.exit(0);
		}
		Nodes min = A[0];
		A[0] = A[Heap_Size-1];
		Heap_Size--;
		Nodes a[] = new Nodes[Heap_Size];
		for(int i = 0; i < Heap_Size; i++) {
			a[i] = new Nodes(A[i].getCharacter(),A[i].getWeight(),A[i].getLchild(),A[i].getRchild());
		}
		A = a;
		Min_Heapify(1);
		return min;
	}

	public void Heap_Increase_key(int i, Nodes key) {
		if (key.getWeight() < A[i - 1].getWeight()) {
			System.out.println("new key is smaller than current key!");
			System.exit(0);
		}
		A[i - 1] = key;
		while (i > 1 && A[Parent(i) - 1].getWeight() > A[i - 1].getWeight()) {
			Nodes temp = A[i - 1];
			A[i - 1] = A[Parent(i) - 1];
			A[Parent(i) - 1] = temp;
			i = Parent(i);
		}
	}

	public void Min_Heap_Insert(Nodes key) {
		Heap_Size++;
		Nodes a[] = new Nodes[Heap_Size];
		for (int i = 0; i < A.length; i++) {
			a[i] = new Nodes(A[i].getCharacter(),A[i].getWeight(),A[i].getLchild(),A[i].getRchild());
		}
		a[Heap_Size-1] = new Nodes("",Integer.MIN_VALUE,null,null);
		//a[Heap_Size - 1].setWeight(-32767);
		A = a;
		Heap_Increase_key(Heap_Size, key);

	}

	public void BuildMaxHeap() {
		for (int i = A.length / 2; i >= 1; i--)
			Min_Heapify(i);
	}

	public void output() {
		for (int t = 0; t < Heap_Size; t++)
			System.out.print(A[t] + " ");
	}

	/*public static void main(String[] args) {
		int[] a = { 15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1 };
		Min_priorityQueue mpq = new Min_priorityQueue(a);
		mpq.BuildMaxHeap();
		mpq.Min_Heap_Insert(200);
		mpq.output();
		System.out.println("\n"+mpq.Heap_Extract_Min());
		mpq.output();
		System.out.println("\n"+mpq.Heap_Minimum());

	}*/


}
