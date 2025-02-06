package assignment3;

public class LinkedList {
	private Node head;//declare head of linked list
	
	public LinkedList(){//Linked list constructor declares head as null
		head = null;
	}//end of method
	
	
	public String printAll(){//Prints all
		String output = "";//Initial Output
		
		if(isEmpty()){
			return null;
		}else{
			Node current = head;
			
			while(current != null){//Traverses through all nodes
				output = output + current.getItem() + " ";// updates output
				current = current.getNext();//moves to next Node
			}//end of while
	
			return output;
		}//end of else
	}//end of method
	
	
	public boolean isEmpty(){//sets the head to null
		return null == head;
	}//end of method
	
	public void add(int newcount)//Adds node to linked list.
	{
		Node nextNode = new Node(newcount);
		
		if(!isEmpty()){//if not empty
			//add new node to list
			Node cur = head;
			while(cur.getNext() != null){//traverse list
				cur = cur.getNext();
			}//end of while
			cur.setNext(nextNode);
		}else{//if empty make next node new head	
			head = nextNode;
		}//end of else
	}//end of method

	
	public int getNum(int index){ //gets location of node
		Node currentNode = head;
		int position = 0;

		while (currentNode != null){ //traverse list
			if (position == index){//if position is at index
				return currentNode.getItem();//return number of items
			}//end of if
			
			//Update position
			currentNode = currentNode.getNext();
			position++;
		}//end of while
		return 0;
	}//end of getNum Function
	
	public void update(int index, int count) //updates the node information
	{
		//Declare variables
		int position = 0;
		Node currentNode = head;
		Node oldNode = null;
		
		while(currentNode.getNext() != null && currentNode != null){//while in list
			if (position == index){//If we are at desired index
				
				Node newNode = new Node(count);//Create New Node
				
				if(oldNode == null){ //if at start of list
					head = newNode; //update head
				}else { //Move down list.
					oldNode.setNext(newNode);
				}//end of else
				
				newNode.setNext(currentNode.getNext().getNext());
				break;
			}else{//move down list
				if(oldNode == null){ //if at start of list update old node
					head = currentNode;//update head
				}else{//move to next node
					oldNode.setNext(currentNode);
				}//end of else
				
				//Update position in list
				oldNode = currentNode;
				currentNode = currentNode.getNext();
				position++;
			}//end of else
		}//end of while
		
		if (position != index){ //If all fails
			if (oldNode != null){
				oldNode.setNext(currentNode);
			}//end of if
		}//end of if
	}//end of method
	
}//end of program
