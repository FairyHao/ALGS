package StrongComponents;

import java.util.ArrayList;
import java.util.Stack;

import ReadFileData.ReadFileDateUtility;

public class TarjanSCC
{
	 private int num = 0;
	 private static Digraph g;
	 private int V;
	 private int[] DFN;
	 private int[] low;
	 private Stack<Integer> s = new Stack<Integer>();
	 private int index = 0;
	 private boolean[] isVisit;
	 
	public TarjanSCC(Digraph g)
	{
		this.g = g;
		this.V = g.getV();
		isVisit = new boolean[V];
		DFN = new int[V];
		low = new int[V];
	}

	public int getSCC()
	{
		for(int i = 0;i < V;i++)
		{
			if(isVisit[i] == false )
			{
				 tarjan(i);
			}
		}
		return num;
	}
	private void tarjan(int u)
	{
		isVisit[u] = true;
		low[u] = DFN[u] = index++;
		s.push(u);
		ArrayList<Integer> adj = g.getVertices()[u];
		for(int i = 0;i < (adj==null?0:adj.size());i++)
		{
			int v = adj.get(i);
			if(!isVisit[v])
			{
				tarjan(v);
				low[u] = (low[v]>low[u]?low[u]:low[v]);
			}else if(s.contains(v))
			{
				low[u] = (low[u] > DFN[v]?DFN[v]:low[u]);
			}
		}
		if(DFN[u]==low[u])
		{
			int x;
			while(s.peek()!= u)
			{
				x = s.pop();
				//System.out.print(x);
			}
			x = s.pop();
			//System.out.print(x);
			//System.out.println();
			num++;
		}
	}
	public int getNum()
	{
		return num;
	}

	public static void main(String[] args)
	{
		int[] graphdata = ReadFileDateUtility.readDataToIntArray("StrongComponent/uniprot22m");
		Digraph dg = new Digraph(graphdata[0]);
		for(int i=1;i<graphdata.length-1;i+=2)
		{
			dg.addEdge(graphdata[i], graphdata[i+1]);
		}
		TarjanSCC scc = new TarjanSCC(dg);
		long start = System.currentTimeMillis();
		int num = scc.getSCC();
		long end = System.currentTimeMillis();
		System.out.println(end-start);
		System.out.println(num); 
	}
}
