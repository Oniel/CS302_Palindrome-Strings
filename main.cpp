/*
	Oniel Toledo
	Assignment 02
	CS 302 Section 1002

    The following program prompts the user for an input file containing
        an indefinite list of words, the program will run through these
        words and determine which are palindrome strings using a stack
        and a queue to do side by side character comparision, after each has
        been compared an output will notify the user whether or not the word
        is a palindrome.
    For detailed documentation refer to comments above specific functions,
        files, and code fragments.
    Because maximum word size was not specified, a linked list will be used
        to implement the queue and stack, this will enable dynamic memory
        allocation of the stack and queue
*/

//libraries and headers
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "linkedStack.h"
#include "linkedQueue.h"
using namespace std;

int main(){

//variables
fstream input;
string filename, word;
bool isPalindrome;
char stackChar, queueChar;

//object declarations
linkedQueue<char> queue;
linkedStack<char> stack;

//prompt user for input file, input file is expected to have no errors
    //possible make a separate function- pass by reference
    cout << "Please enter the name of an input file" << endl;
    cin >> filename;
    input.open(filename.c_str());
    //input.open("input.txt");



//get first line in text file, loop until end of file has been reached
getline(input, word);
while(input){

   //for the entire string, push and enqueue 1 character at a time
   for(int i =0; i < word.length(); i++){
      stack.push(word[i]);
      queue.enqueue(word[i]);
      }

      //do side-by-side comparison, at first mismatch, set isPalindrome to
      //false and break loop
    isPalindrome = true;
    for(int i =0; i < word.length(); i++){
        if(stack.topNpop() != queue.dequeue()){
            isPalindrome = false;
            break;
        }
    }

        //output result- string and palindrome status
        cout << left << setw(20) << setfill(' ') << word;
        if(isPalindrome == false)
            cout << "Is not a palindrome" << endl;
        else
            cout << "Is a palindrome" << endl;

    //empty stack and queue for the next set and fstream input from file if any
    stack.makeEmpty();
    queue.makeEmpty();

    getline(input, word);
    }

    return 0;
}
