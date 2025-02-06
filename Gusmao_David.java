package assignment2;

public class Gusmao_David {
	public static void main(String[] args) {
		//Declare variables
		int[] occr = new int[11];// number of occurrences
		Dice dice = new Dice();
		
		for(int i = 0; i < 1000; i++) {
			dice.roll();//roll dice
			int value = dice.getFaceValue();//retrieve value
			//Stores occurrence values to array
			if(value == 2) {
				occr[0]++;
			}else if(value == 3) {
				occr[1]++;;
			}else if(value == 4) {
				occr[2]++;;
			}else if(value == 5) {
				occr[3]++;
			}else if(value == 6) {
				occr[4]++;
			}else if(value == 7) {
				occr[5]++;
			}else if(value == 8) {
				occr[6]++;
			}else if(value == 9) {
				occr[7]++;
			}else if(value == 10) {
				occr[8]++;
			}else if(value == 11) {
				occr[9]++;
			}else if(value == 12) {
				occr[10]++;
			}
		}//end of for loop
		
		//Print all occurrences of each number
		System.out.println("Number of 2s are " + occr[0]);
		System.out.println("Number of 3s are " + occr[1]);
		System.out.println("Number of 4s are " + occr[2]);
		System.out.println("Number of 5s are " + occr[3]);
		System.out.println("Number of 6s are " + occr[4]);
		System.out.println("Number of 7s are " + occr[5]);
		System.out.println("Number of 8s are " + occr[6]);
		System.out.println("Number of 9s are " + occr[7]);
		System.out.println("Number of 10s are " + occr[8]);
		System.out.println("Number of 11s are " + occr[9]);
		System.out.println("Number of 12s are " + occr[10]);
		System.out.println("Graph");
		
		int y = 150;//Y axis starting point
		for(int i = 0; i < 6; i++) {//Loops through y axis
			if(y < 100) {//When y is 2 digits add space
				System.out.print(" ");
			}
			System.out.print(y + "|");
			for(int x = 0; x < 11; x++) {//Loops though all numbers
				if(occr[x] >= y) {
					System.out.print("*  ");
				}
				else {
					System.out.print("   ");
				}
			}//End of for
			y -= 25;//Decrements y value
			System.out.println("");//Next Line
		}//End of for
		
		System.out.println("  0|*  *  *  *  *  *  *  *  *  *  *   ");
		System.out.println("    --------------------------------");
		System.out.println("    2  3  4  5  6  7  8  9 10 11 12 ");	
		
	}//End of Main
}//End of class

