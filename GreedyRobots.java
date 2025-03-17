// Author: David Gusmao
// Course: CS2
// Semester: Spring 2025

import java.io.*;
import java.util.*;


public class GreedyRobots 
{
    
    // Arrays to store travel and building distances
    private Integer[] robots;
    private Integer[] buildings;
    // Counters for successful and unserved deliveries
    private int deliveries;
    private int unserved;

    // Constructor initializes arrays and calls readfile method
    public GreedyRobots(int numRobots, int numBuildings, String robotsFile, String buildingsFile) throws IOException 
    {
        robots = new Integer[numRobots];
        buildings = new Integer[numBuildings];
        deliveries = 0;
        unserved = 0;
        // Readfile method call
        readFiles(robotsFile, buildingsFile);
    }

    // Reads robot and building data from files and stores them in arrays
    public void readFiles(String robotsFile, String buildingsFile) throws IOException 
    {
        // Robot Reader
        try (BufferedReader br = new BufferedReader(new FileReader(robotsFile))) 
        {
            for (int i = 0; i < robots.length; i++) 
            {
                robots[i] = Integer.parseInt(br.readLine().trim());
            }
        }

        // Building Reader
        try (BufferedReader br = new BufferedReader(new FileReader(buildingsFile))) 
        {
            for (int i = 0; i < buildings.length; i++) 
            {
                buildings[i] = Integer.parseInt(br.readLine().trim());
            }
        }
    }

    // Assigns deliveries using a greedy approach and only changes the values of the robots
    public void assignDeliveries() 
    {
        // Sort both arrays from largest to smallest ranges
        Arrays.sort(robots, Collections.reverseOrder()); 
        Arrays.sort(buildings, Collections.reverseOrder()); 
        
        // For every building
        for (int buildingIndex = 0; buildingIndex < buildings.length; buildingIndex++) 
        {
            // For every Robot
            for (int robotIndex = 0; robotIndex < robots.length; robotIndex++) 
            {
                // If a robot can reach a building
                if (robots[robotIndex] >= buildings[buildingIndex]) 
                { 
                    // Subtract used energy
                    robots[robotIndex] -= buildings[buildingIndex]; 
                    //Increase deliveries
                    deliveries++; 
                    // Move to next building.
                    break; 
                }
            }
        }
        
        // Calculate unserved buildings
        unserved = buildings.length - deliveries;
    }
    

    // Displays the results of the delivery assignments
    public void displayResults() 
    {
        System.out.println("Successful Deliveries: " + deliveries);
        System.out.println("Unserved Buildings: " + unserved);
    }
}
