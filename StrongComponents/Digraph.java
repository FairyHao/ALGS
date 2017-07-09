package StrongComponents;

import java.util.ArrayList;

public class Digraph 
{
	private  int V;//顶点数
	private int E;//边的个数
	private ArrayList<Integer>[] vertices ;//邻接链表

	public int getV()
	{
		return this.V;
	}
	public int getE()
	{
		return this.E;
	}
	public ArrayList<Integer>[] getVertices()
	{
		return vertices;
	}
	
	public Digraph(int V) {
		this.V = V;
		vertices = new ArrayList[V];
		this.E = 0;
	}
	void addEdge(int v,int u)
	{
		if(vertices[v] == null)
		{
			vertices[v] = new ArrayList<Integer>();
		}
		vertices[v].add(u);
		this.E++;                                                                                                                                   
	}
	
	Digraph Reverse()
	{
		Digraph reverseG = new Digraph(this.V);
		for(int i=0;i<V;i++)
		{
			for(int j = 0;j < (this.vertices[i]==null?0:this.vertices[i].size()) ;j++)
			{
				reverseG.addEdge(this.vertices[i].get(j),i);
			}
		}
		return reverseG;
	}
	
}
