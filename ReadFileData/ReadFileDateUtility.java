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
        InputStreamReader fis = null;//���ļ���
        try {
			 fis = new FileReader(fileName+".txt");//��ȡ�ļ�
			 int x ;//��һ���ַ�
			 
			 String s = "";
			 while((x= fis.read())!=-1)//���û�е����ļ�ĩβ
			 {
				 //����1
				if((char)x != ' '&& x!=13 && x!=10)//�ո񣬻س�,���в���������13�ǻس���ascii��10�ǻ��е�ascii��
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
		//��arraylistת����int[]����
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
