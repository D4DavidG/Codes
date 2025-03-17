// Author: David Gusmao
// Course: CS2
// Semester: Spring 2025

import java.util.*;

public class ParenthesesCombinations 
{
    public List<String> generateParentheses(int pairNum) 
    {
        // List of Strings that will hold the final list of strings
        List<String> finalResult = new ArrayList<>();
        // Declare Sting Builder (this will make editing the length of the strings easier)
        StringBuilder startSB = new StringBuilder();
        // Using Stringbuilder to to modify length of string.
        backtrack(pairNum, finalResult, 0, 0, startSB);

        // Return the completed list of strings
        return finalResult;
    }

    // Method keeps track of the number of open and closeing parethisis as well as the total number of pairs
    private void backtrack(int totalPairs, List<String> finalResult, int openParNum, int closeParNum, StringBuilder curResult) 
    {
        // Keep track of the length of the current result
        if ((totalPairs * 2) == curResult.length()) 
        {
            // Adds only when the length is equal to the total amount of parenthesis
            finalResult.add(curResult.toString());
            return;
        }
        
        // Makes sure we dont pass the amount of pairs
        if (totalPairs > openParNum) 
        {
            // Adds and open parenthesis
            curResult.append('(');
            // Adds to the count of open parenthesies and recurses
            backtrack(totalPairs, finalResult, openParNum + 1, closeParNum, curResult);
            // Shortens the current result if nothing can be done.
            curResult.deleteCharAt(curResult.length() - 1);
        }
        
        // Makes sure we dont pass the amount of open parenthsis
        if (openParNum > closeParNum) 
        {
            // Adds a closed parenthisis
            curResult.append(')');
            // Adds to the count of close parenthesies and recurses
            backtrack(totalPairs, finalResult, openParNum, closeParNum + 1, curResult);
            // Shortens the current result if nothing can be done.
            curResult.deleteCharAt(curResult.length() - 1);
        }

        // Saftey return
        return;
    }
}