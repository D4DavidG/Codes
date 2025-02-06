package assignment3;

public class Node {
	private int item;//item to be stored in node
	private Node next;//next node
	
	//Default constructor
	private Node()
	{
		next = null;
		item = 0;
	}
	
	public Node(int amount){//constructor with parameter
		item = amount;//declares amount stored in item
		next = null;
	}//end of method
	
	public int getItem(){//Gets the value of Node
		return item;
	}//end of method
	
	public Node getNext(){//Gets next Node
		return next;
	}//end of method
	
	public void setNext(Node next) {//Sets next node as next
        this.next = next;
    }//end of method

}//end of Node class
