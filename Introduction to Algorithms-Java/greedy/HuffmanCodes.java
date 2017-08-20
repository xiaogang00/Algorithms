package greedy;

public class HuffmanCodes {
	public Nodes huffman(Nodes[] C){
		
		int n=C.length;
		Nodes Q[]=C;
		Min_priorityQueue mpq= new Min_priorityQueue(Q);
		mpq.BuildMaxHeap();
		
		for(int i=1;i<=n-1;i++){
			Nodes z=new Nodes(null,0,null,null);
			Nodes x=mpq.Heap_Extract_Min();
			Nodes y=mpq.Heap_Extract_Min();
			z.setLchild(x);
			z.setRchild(y);
			int weight=x.getWeight()+y.getWeight();
			z.setWeight(weight);
			mpq.Min_Heap_Insert(z);
			
		}
		return mpq.Heap_Extract_Min();
	}
	
	public static void main(String args[]){
		Nodes[] c=new Nodes[6];
		c[0]=new Nodes("f",5,null,null);
		c[1]=new Nodes("e",9,null,null);
		c[2]=new Nodes("c",12,null,null);
		c[3]=new Nodes("b",13,null,null);
		c[4]=new Nodes("d",16,null,null);
		c[5]=new Nodes("a",45,null,null);
		HuffmanCodes hc=new HuffmanCodes();
		Nodes nodes=hc.huffman(c);
		System.out.println(nodes.getWeight());
		
	}
	
}
