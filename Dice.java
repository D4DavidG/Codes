package assignment2;

public class Dice {
/*
 * For this part you will create a Dice class which holds 2 private Die objects as instance variables.
- Die class will have a no argument constructor which will initialize faceValues of the both dies to 1.
- You will write a method to get the faceValue of the Dice which is the sum of the faceValues of the 2 dice. 
- Die class will have a void roll method. This method will roll both Dice. This method will not print anything.
 */
	private Die d1, d2;
	
	public Dice(){
		//Initialize Die
		d1 = new Die();
		d2 = new Die();
		//Set Die to 1
		d1.setFaceValue(1);	
		d2.setFaceValue(1);
	}
	
	public int getFaceValue() {
		return d1.getFaceValue() + d2.getFaceValue();//face value getter
	}
	
	public void roll() {//Rolls both Die
		d1.roll();
		d2.roll();
	}
}//End of class
