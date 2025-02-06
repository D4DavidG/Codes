package assignment2;

public class Die{
	
	private int faceValue;//Instance Variable
	
	public Die(){
		faceValue = 1;//initialize faceValue to 1
	}
	
	public void setFaceValue(int faceValue) {
		this.faceValue = faceValue;//face value setter
	}
	
	public int getFaceValue() {
		return faceValue;//face value getter
	}
	
	public void roll() {
		int face = (int)(Math.random() * 6 + 1);//Rolls Die for random number 1-6
		faceValue = face;//Update Face Value
	}
}//End of class