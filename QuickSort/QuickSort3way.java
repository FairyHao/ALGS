package QuickSort;
//<k,==k,>k
public class QuickSort3way
{
    public static void sort(int[] a,int low,int high)
    {
        //divide and conquer 1.divide 根据某个pivot分成两部分 2.Conquer  3.Combine
        if(low >= high)
        {
            return;
        }
        
        int  pivot = a[low];
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
        sort(a,low,lt-1);
        sort(a,gt+1,high);
    }
    
    private static void exch(int[] a,int x,int y)
    {
        int temp = a[x];
        a[x] = a[y];
        a[y] = temp;
    }
    
    public static void main(String[] args)
    {
        int[] a = {49,38,65,97,76};
        sort(a,0,a.length-1);
        for(int i=0;i<a.length;i++)
        {
            System.out.println(a[i]);
        }
    }
}