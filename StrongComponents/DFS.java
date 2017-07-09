package StrongComponents;

import java.util.ArrayList;

public class DFS {
	static boolean[] isVisit;
	private static int[] dFSEndOrder ;//������������������ʱ��˳��
	static int i = 0;
	public static int[] GetDFSOrder(Digraph G)
	{
		int V = G.getV();
		isVisit = new boolean[G.getV()];
		dFSEndOrder = new int[V];
		for(int i = 0;i<V;i++)
		{
			isVisit[i] = false;
		}
		for(int i=0;i<V;i++)
		{
			if(isVisit[i] == false)
			{
				DFSVisit(G,i);
			}
		}  
		isVisit = null;
		return dFSEndOrder;
	}
	static void DFSVisit(Digraph G,int v)
	{
		//System.out.println("��ʼ����"+v);
		isVisit[v] = true;
		ArrayList<Integer> edges = G.getVertices()[v];
		int temp =(edges==null?0:edges.size());
		for(int i=0;i<temp;i++)
		{
			if(isVisit[edges.get(i)] == false)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
			{
				DFSVisit(G,edges.get(i));
			}
		}
		//System.out.println("��������"+v);
		dFSEndOrder[i++] = v;
	}
	static void DFSVisit1(Digraph G,int v)
	{
		//System.out.println("��ʼ����"+v);
		isVisit[v] = true;
		ArrayList<Integer> edges = G.getVertices()[v];
		int temp =(edges==null?0:edges.size());
		for(int i=0;i<temp;i++)
		{
			if(isVisit[edges.get(i)] == false)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
			{
				DFSVisit1(G,edges.get(i));
			}
		}
		//System.out.println("��������"+v);
	}
	static int DFSByOrder(Digraph G,int[] order)
	{
		int num = 0;
		int V = G.getV();
		i= 0;
		isVisit = new boolean[G.getV()];
		
		for(int i = 0;i<V;i++)
		{
			isVisit[i] = false;
		}
		//System.out.println("����");
		for(int i = order.length-1;i >= 0;i--)
		{
			int x = order[i];
			if(isVisit[x] == false)
			{
				DFSVisit1(G,x);
				num++;
				//System.out.println(num+"�η��ʽ���");
			}
		}
		return num;
	}
}
