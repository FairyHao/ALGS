package QuickSort;

/*
 * ��quickSort�Ļ����Ͻ������¸Ľ�
 * 1. С�����ò��������㷨
 * 2. 3way <v =v >v
 * 3. ����ѡ��Ľ�
 */
public class QuickSortAdvance {
     final static int k = 7;
	 public static void sort(int[] a,int low,int high)
	 {
	        //divide and conquer 1.divide ����ĳ��pivot�ֳ������� 2.Conquer  3.Combine
	       int length = high-low+1;
	       if(length < k)
	       {
	    	   for (int i=low; i<=high; i++)
	         		for (int j=i; j>low && a[j-1]>a[j]; j--)
	         		    exch(a, j-1, j);
	           return;  
	       }
	       int m = (low+high+1)/2;
	       if(length > 40)
	       {
	    	   int s = (length)/8;
	    	   int l = mid3(a, low,low+s,low+2*s);
	   		   m = mid3(a,m-s,m,m+s);
	   		   int n = mid3(a,high-2*s,high-s,high);
	   		   m = mid3(a, l, m, n);
	       }else if(length>7){
	    	   m = mid3(a, low, m, high);
		   }
	       int  pivot = a[m];
	       exch(a,m,low);
	       int lt = low;
	       int gt = high;                                                
	       int i = low + 1;
	       while(i<=gt)
	       {
	          if(a[i]==pivot)
	          {
	              i++;
	          }else if(a[i]<pivot)
	          {
	                exch(a,i,lt);
	                i++;
	                lt++;
	           }else 
	           {
	               exch(a,i,gt);
	               gt--;
	           }
	       }
	       if(lt-1>low)
	       {
		       sort(a,low,lt-1);
	       }
	       if(high>gt+1)
	       {
	    	   sort(a,gt+1,high);
	       }
	 }
	 private static void exch(int[] a,int x,int y)
	 {
	     int temp = a[x];
	     a[x] = a[y];
	     a[y] = temp;
	 }
	 private static int mid3(int[] a,int x,int y, int z)
	 {
		 return a[x]<a[y]?(a[y]<a[z]?y:(a[x]<a[z])?z:x):(a[y]>a[z]?y:(a[x]<a[z]?x:z));
	 }
	 public static void main(String[] args)
	 {
	      int[] a = {1,2,3,4,5,6,7,8,9};
	        sort(a,0,a.length-1);
	        for(int i=0;i<a.length;i++)
	        {
	            System.out.println(a[i]);
	        }
	 }
}
