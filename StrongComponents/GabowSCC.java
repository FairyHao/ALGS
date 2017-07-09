package StrongComponents;

import java.util.ArrayList;
import java.util.Stack;

import ReadFileData.ReadFileDateUtility;

public class GabowSCC
{
	 private int num = 0;
	 private static Digraph g;
	 private int V;
	 private Stack<Integer> path = new Stack<Integer>();
	 private Stack<Integer> root = new Stack<Integer>();
	 private boolean[] isVisit;
	 
	public GabowSCC(Digraph g)
	{
		this.g = g;
		this.V = g.getV();
		isVisit = new boolean[V];
	}

	public int getSCC()
	{
		for(int i = 0;i < V;i++)
		{
			if(isVisit[i] == false )
			{
				Gabow(i);
			}
		}
		return num;
	}
	private void Gabow(int u)
	{
		isVisit[u] = true;
		path.push(u);
		root.push(u);
		ArrayList<Integer> adj = g.getVertices()[u];
		for(int i = 0;i < (adj==null?0:adj.size());i++)
		{
			int v = adj.get(i);
			if(!isVisit[v])
			{
				Gabow(v);
			}else if(root.contains(v))
			{
				while(root.peek() != v)
				{
					root.pop();
				}
			}
		}
		//当root栈顶为u时，则代表以u为根的深度优先子树为一个强联通分量
		if(root.peek() == u)
		{
			root.pop();//pop出u
			//pop出path中u之前的元素
			int x = -1;
			/*
			do
			{
				x = path.pop();
			}
			while (x!=u);*/
			while((x = path.pop())!= u)
			{
			}
			num++;
		}
	}
	public static void main(String[] args)
	{
		int[] graphdata = ReadFileDateUtility.readDataToIntArray("StrongComponent/uniprot22m");
		Digraph dg = new Digraph(graphdata[0]);
		for(int i=1;i<graphdata.length-1;i+=2)
		{
			dg.addEdge(graphdata[i], graphdata[i+1]);
		}
		GabowSCC scc = new GabowSCC(dg);
		long start = System.currentTimeMillis();
		int num = scc.getSCC();
		long end = System.currentTimeMillis();
		System.out.println(end-start);
		System.out.println(num); 
	}

}
