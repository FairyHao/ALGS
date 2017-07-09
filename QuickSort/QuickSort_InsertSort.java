package QuickSort;

public class QuickSort_InsertSort
{
    final static int k = 7;
    public static void sort(int[] a,int low,int high)
    {
        //divide and conquer 1.divide 根据某个pivot分成两部分 2.Conquer  3.Combine
        if(low >= high)
        {
            return;
        }
        if(low + k >= high)
        {
        	/*
        	 for (int i=low; i<=high; i++)
         		for (int j=i; j>low && a[j-1]>a[j]; j--)
         		    exch(a, a[j-1], a[j]);
             return;*/  
        	for(int i =low;i<=high;i++)
            {
                int j;
                for( j = i-1;j>=0&&a[j] > a[i];j--)
                {
                   a[j+1] = a[j];
                }
                a[j+1] = a[i];
            }
             return;
        }
        	int x = partition(a,low,high);
            sort(a,low,x-1);
            sort(a,x+1,high);
    }
    
    public static void InsertSort(int[] a,int low,int high)
    {
        for(int i =low;i <= high;i++)
        {
            int j;
            for( j = i-1;j>=0&&a[j] > a[i];j--)
            {
               a[j+1] = a[j];
            }
            a[j+1] = a[i];
        }
    }
    //partition method 1; 
    public static int partition(int[] a,int low,int high)
    {
        int pivot = a[low];
        int j = high+1;
        int i = low;
        while(true)
        {
            while(a[--j] > pivot) if(j<=low) break;
            while(a[++i] < pivot) if(i>=high) break;
            if(i>=j)
            {
                break;
            }
            exch(a,j,i);//交换数组两个位置的元素。
        }
        exch(a,j,low);
        return j;
    }
    //partition method 2;   
    public static int partition1(int[] a,int low,int high)
    {
        int pivot = a[low];
        int i = low;
        for(int j = low + 1;j < a.length;j++)
        {
            if(a[j] < pivot)
            {
                exch(a,j,++i);
            }
        }
        exch(a,i,low);
        return i;
    }
    private static void exch(int[] a,int x,int y)
    {
        int temp = a[x];
        a[x] = a[y];
        a[y] = temp;
    }
}