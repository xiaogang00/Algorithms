package greedy;

public class Nodes {
	private String character;
	private int weight;
	private Nodes lchild;
	private Nodes rchild;
	public Nodes(String character,int weight,Nodes lchild,Nodes rchild){
		this.character = character;
		this.weight = weight;
		this.lchild = lchild;
		this.rchild = rchild;
	}
	public String getCharacter() {
		return character;
	}
	public void setCharacter(String character) {
		this.character = character;
	}
	public Nodes getLchild() {
		return lchild;
	}
	public void setLchild(Nodes lchild) {
		this.lchild = lchild;
	}
	public Nodes getRchild() {
		return rchild;
	}
	public void setRchild(Nodes rchild) {
		this.rchild = rchild;
	}
	public int getWeight() {
		return weight;
	}
	public void setWeight(int weight) {
		this.weight = weight;
	}
    
}
