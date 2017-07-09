package QuickSort;

import java.util.Arrays;

import ReadFileData.ReadFileDateUtility;

/*
 * 锟斤拷锟斤拷锟絩andom锟侥硷拷锟斤拷92ms  standard:37ms 小锟斤拷锟斤拷锟矫诧拷锟斤拷锟斤拷锟斤拷89ms;3way:100ms;锟斤拷锟窖★拷锟斤拷啵�1143ms
 * 		repeat锟侥硷拷锟斤拷31ms     16ms 
 * 		raise锟侥硷拷:543923ms   37ms
 * 
 * result at 2017/5/6 16:57
 *鍗曚綅锛歮s
 * random:quick sort escaped time:128
			quick sort advanced escaped time:107
			standard method escaped time:89 
    repeat:quick sort escaped time:76
	       quick sort advanced escaped time:14
	       standard method escaped time:37
    raise:quick sort escaped time:锟杰达拷 
		  quick sort advanced escaped time:82
		  standard method escaped time:40
 * */
public class TestResultClass {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		//锟斤拷取锟侥硷拷锟斤拷锟斤拷锟斤拷锟街凤拷锟斤拷锟斤拷锟斤拷
    	String pathString = "QuickSortData/repeat";
    	int[] disOrderData = ReadFileDateUtility.readDataToIntArray(pathString);
    	
        long start = System.currentTimeMillis();
        QuickSort.sort(disOrderData,0,disOrderData.length-1);
        long end = System.currentTimeMillis();
        
        System.out.println("quick sort escaped time:"+(end-start));
        
    	disOrderData = ReadFileDateUtility.readDataToIntArray(pathString);
    	
        long start2 = System.currentTimeMillis();
        QuickSortAdvance.sort(disOrderData,0,disOrderData.length-1);
        long end2 = System.currentTimeMillis();
        
        System.out.println("quick sort advanced escaped time:"+(end2-start2));
        
    	disOrderData = ReadFileDateUtility.readDataToIntArray(pathString);
    	
        long start1 = System.currentTimeMillis();
        Arrays.sort(disOrderData);
        long end1 = System.currentTimeMillis();
        
        System.out.println("standard method escaped time:"+(end1-start1));
        
        ReadFileDateUtility.writeOrderDataToFile(disOrderData,pathString+"_order.txt");
	}
}
