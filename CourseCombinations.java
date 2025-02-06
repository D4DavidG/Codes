// Author: David Gusmao
// Course: CS2
// Semester: Spring 2025

import java.util.*;

public class CourseCombinations 
{
    // Main funtion
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);

        // input number of students
        int numStudents = scanner.nextInt(); 
        scanner.nextLine();

        // Array list that contains lists of student names and classes 
        List<String[]> students = new ArrayList<>();

        // loop through number of students
        for(int x = 0; x < numStudents; x++)
        {
            // scans for the student information
            String sudtentInput = scanner.nextLine(); 
            // Splits the input by spaces
            String[] studentInfo = sudtentInput.split(" ");
            // Adds the list of student information to the list of students
            students.add(studentInfo);
        }
        scanner.close();

        //prints the output and calls calculation function
        System.out.println(calculateCourseCombo(students));

        
    }

    // Caluclation function
    public static int calculateCourseCombo(List<String[]> students) 
    {
        // Create a hash map with a set string value to avoid duplicate classes
        Map<String, Set<String>> courseHashMap = new HashMap<>();
        // Populate the hash map
        populateMap(students, courseHashMap);

        // Make a new hash set for the student pairs
        Set<Set<String>> studentPairs = new HashSet<>();

        // Loop through each student of the course map
        for (Set<String> student : courseHashMap.values()) 
        {
            // Make a list of students for each class
            List<String> studentList = new ArrayList<>(student);
            // Number of students that share a class
            int numStudent = studentList.size();

            // Loop to calculate the pairs of students
            for (int x = 0; x < numStudent; x++) 
            {
                for (int y = x + 1; y < numStudent; y++) 
                {
                    // LAST hash set to create pairs
                    Set<String> pair = new HashSet<>();
                    pair.add(studentList.get(y));
                    pair.add(studentList.get(x));
                    // WILL NOT add duplicate pairs
                    studentPairs.add(pair);
                    System.out.println(pair);
                }
            }
        }

        // Return the amount of pairs
        return studentPairs.size();
    }

    // Populates the hashmap with class names as keys and student names as values
    public static void populateMap(List<String[]> studentInfo, Map<String, Set<String>> courseHashMap) 
    {
        // loop through each student in the array list
        for (String[] eachStudent : studentInfo)
        {
            // Assign the student name as the 1st index of the list
            String studentName = eachStudent[0];
            // Loop through every course starting after the name
            for (int x = 1; x < eachStudent.length; x++) 
            {
                // Assigns the index as a course
                String course = eachStudent[x];
                // If a course does not exist then add a new one to the hash set
                courseHashMap.putIfAbsent(course, new HashSet<>());
                // if course exists add a student name to the course
                courseHashMap.get(course).add(studentName);
            }
        }
    }
}
