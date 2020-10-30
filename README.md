# STEPANOV-S-BINARY-COUNTER
Implement Binary counter to find the second biggest in an array of integers.
Data structure used-
    - The data structure I have used is an array of the structure "list" and a singly linked list.Each element of the array of 
      strutures points to a linked list.Each linked list can be considered to be at a different level with respect to the array index it starts at.
      In the find_Second_greatest() function we iterate through the array of numbers. A node is created for each element and it is inserted into its correct position
      and at the correct position. Then the merge_lists() function is called to check whether a list needs to be pushed or if two lists are at the same level,
      the max elements of each list are compared and they are merged accordingly. Any unwanted nodes are freed as to avoid wasting space.
      After we iterate through the whole input array, we call the merge_lists() function again to make sure all remaining lists are compared and accordingly merged.
      The above case occurs when the input size is not a power of 2. 
      Also whwnever a comparison is made, the program prints it in the required format.
      When we have the final list, we know that the head is the max element so we start checking from the head->next element.And we also know that the final list starts at the last index always.
      Using a while loop we find the second largest element and after that display it. 
	
Compiling-
    - I have only included stdio.h and stdlib.h along with the header file.

Key takeaway-
    - I learnt how to design an algorithm based on the given criteria and got a thorough understanding of how an adjacency list works. 
      The assignment also helped me practice working with pointers and making sure that the correct memory locations are accessed everytime.
      I also had to make sure that memory spaces which were not required were properly freed and no dangling pointers were caused. 
