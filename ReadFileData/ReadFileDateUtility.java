package ReadFileData;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class ReadFileDateUtility {

	public static int[] readDataToIntArray(String fileName)
	{
		ArrayList<Integer> al = new ArrayList<Integer>();
        InputStreamReader fis = null;//读文件类
        try {
			 fis = new FileReader(fileName+".txt");//读取文件
			 int x ;//读一个字符
			 
			 String s = "";
			 while((x= fis.read())!=-1)//如果没有到达文件末尾
			 {
				 //出错1
				if((char)x != ' '&& x!=13 && x!=10)//空格，回车,换行不放入数组13是回车的ascii码10是换行的ascii码
				{
					s += (x-'0');
				}else if(s!="")
				{
					al.add(Integer.parseInt(s));
					s = "";
				}else 
				{
					continue;
				}
			 }
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}finally
		{
			if(fis!=null)
			{
				try {
					fis.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
		//将arraylist转换成int[]数组
        Object[] disOrderDataTemp = al.toArray();
        int digNum = disOrderDataTemp.length;
        int[] disOrderData = new int[digNum];
        for(int i=0;i<disOrderDataTemp.length;i++)
        {
        	disOrderData[i] = ((Integer)disOrderDataTemp[i]).intValue();
        }
		return disOrderData;
	}
	
	public static boolean writeOrderDataToFile(int[] disOrderData,String fileName)
	{
		 File file = new File(fileName);
	     FileWriter fw = null;
	     try 
	     {
	    	 file.createNewFile();
			 fw = new FileWriter(file);
			 for(int i=0;i<disOrderData.length;i++)
		     {
		        fw.write(disOrderData[i]+" ");
		      }
		  } catch (IOException e1) 
		  {
				// TODO Auto-generated catch block
				e1.printStackTrace();
				return false;
			}finally
			{
				try
				{
					fw.close();
				} catch (IOException e) 
				{
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		  return true;
	   }		
}
