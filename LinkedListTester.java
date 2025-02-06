package assignment3;

import java.io.File;
import java.io.*; //for IOException

public class LinkedListTester{
	
	public static void main(String[] args) throws Exception {      
		//Declare Linked List
		LinkedList data = new LinkedList();
		//Declare Files to be read
		File dataFile = new File("data.txt");
		File processedFile = new File("processed.txt");
	
		//Declare variables
		int count = -100;
		int listLength = 0;//Number of terms in linked list
		

		BufferedReader theBufReader=null;
		try{
			//
			theBufReader = new BufferedReader(new FileReader(dataFile));
			String newline = null;
			newline = theBufReader.readLine();
			
			String[] tokens = newline.split("\\s+");
			for (String token : tokens) {
				int num = Integer.parseInt(token);
	            
				if(num > 0){
					data.add(num);
					listLength++;
				}//end of if
			}//end of for
		} catch(Exception e){
			e.printStackTrace();
		}//end of try catch
		
		
		//Goes through linked list and updates values
		for(int i = 0; i < listLength; i++){
			if(((data.getNum(i) * 2) + 7) == (data.getNum(i+1))){
				data.update(i, count);
				count++;
			}//end of if
		}//end of for
		data.add(count);//Add final count number. 
		
		
		//Write in new file
		BufferedWriter theBufWriter;
		try{
			theBufWriter = new BufferedWriter(new FileWriter(processedFile,true));
			String toWrite = data.printAll();
			theBufWriter.write(toWrite);
			//System.out.println(toWrite);
			theBufWriter.close();
		}catch(Exception e){
			e.printStackTrace();
		}//end of catch
    }//end of main
}//end of program