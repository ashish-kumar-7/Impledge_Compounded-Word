# Impledge_Compounded-Word

# Problem Statement

Write a program that:
1. Reads provided files (Input_01.txt and Input_02.txt) containing alphabetically sorted words list (one
word per line, no spaces, all lower case)
2. Identifies & display below given data in logs/console/output file:

     a- longest compounded word
    
     b- second longest compounded word
    
     c- time taken to process the input file
    
Note:- A compounded word is one that can be constructed by combining (concatenating) shorter words
also found in the same file

# Approach

1.  I have used chrono library for calculating the start time, end time and time taken to execute the program
2.  getFile(data) is used to input the file from the system and load it into data.
3.  load(T, data) is used to build the Trie Data structure. We take the words from the input file and then go on inserting the words in the Trie.
3.  Then, solve(T,data) is called which checks word by word for the largest and second largest word in the given input file.
4.  check(word, len) function is to check whether that word is actually present in the Trie or not.
5.  destructor are implemented to delete the non-used memory(to prevent memory leaks).

Note:- To check if a word is a compound word, the program traverses the string character by character, till it finds a complete word from the trie. It then recursively checks whether the remaining part is also a word OR a compound word.

# Local Machine Implementation:

Download all the necessary files and make sure your system has GCC compiler in it.

Open the folder in which the code and input files are present.

Then, run the code and enter the filename.


![Screenshot (207)](https://user-images.githubusercontent.com/72808868/193642684-6247f766-e738-486d-b271-321ae33c3c12.png)

