package StrongComponents;

import ReadFileData.ReadFileDateUtility;

public class StrongComponent {
	
	static int getStrongConnectedComponents(Digraph G)
	{
		int[] dFSEndOrder = DFS.GetDFSOrder(G);
		Digraph r = G.Reverse();
		G = null;
		int num = DFS.DFSByOrder(r, dFSEndOrder);
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
		long start = System.currentTimeMillis();
		int num = getStrongConnectedComponents(dg);
		long end = System.currentTimeMillis();
		System.out.println(end-start);
		System.out.println(num);
	}
}
