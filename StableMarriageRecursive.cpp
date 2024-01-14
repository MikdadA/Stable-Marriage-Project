/** 
 * Project - Stable Marriage (Recursive)
 * I used the majority of the code from stable marriage and changed the main and move function for the recursive program.
 * */
 
 #include <iostream>
using namespace std;

bool okay(int q[], int man) {

    //mp[i][j] = gives man i ranking of women j
    //mp = man's preference
    //man's preference 2D array
     int mp[3][3] = {{ 0, 2, 1 }, // Man 0 likes women 0 the most and 1 the least
                     { 0, 2, 1 }, // Man 1 likes women 0 the most and 1 the least
                     { 1, 2, 0 }}; // Man 2 likes women 1 the most and 0 the least 
                     
    //wp[j][i] = gives women j ranking of man i
    //wp = women's preference
    //women's preference 2D array
     int wp[3][3] = {{ 2, 1, 0 }, // women 0 likes man 2 the most and 0 the least
                     { 0, 1, 2 }, // Woman 1 likes man 0 the most and 2 the least
                     { 2, 0, 1 }}; // Woman 2 likes man 2 the most and 1 the least

// man = currently assigned man 
// q[man] = currently assigned Woman
// i = new man
// q[i] = new Woman
// i and q[i] are the proposed pair to add to the match 
 
//Test 1: this is similar to row test in 8 queens.
//we are checking the man and women against each existing pair to see if they make the match unstable
//otherwise, we check the q array to see if the new women q[i] has been previously matched up. 
    		for(int i = 0; i < man; i++){ 
    			if( q[i] == q[man]) //this is to check if the current women is already been married to the other men.
    			return false; //if they do then return false
			}
 
//Test 2a:
        //if the current man prefers the new women to his current woman 
        //if the new woman prefers the current man to her current partner 
        //if both things occur then reject this because this will make an unstable marriage
		for(int i = 0; i < man; i++){
		if( mp[man][q[i]] < mp[man][q[man]] && wp[q[i]][man] < wp[q[i]][i] ){ //less means higher ranking 
			return false; //this is introducing an instability 
			}
		  	
		}
		
//Test 2b: 
        //if the new man prefers the current woman to his partner 
        //if the current woman prefers the new man to her partner
        ///if both things occur then reject this because this will make an unstable marriage
        for(int i = 0; i < man; i++){
        	if( wp[q[man]][i] < wp[q[man]][man] && mp[man][q[man]] < mp[i][q[i]] ){ //less means higher ranking 
        		return false; //if both scenarios happen then return false 
			}
		}
    return true; //then return true if the marriage is stable
}
//print the solutions 
void print(int q[], int man) {
    static int solution = 0;
    cout << "Solution #" << ++solution << ":\nMan\tWoman\n"; //increment the solution count 
    for (int i = 0; i < 3; ++i)
        cout << i << "\t" << q[i] << "\n";
    cout << "\n";
}

void move(int q[], int man) 
{ //if we have exceeded the last man that means we have found a solution 
   if (man == 3) //if man is equal to the size of the array 3
      print(q , man); //then we call the print function
   else 
   	for (q[man] = 0; q[man] < 3; ++q[man]) //enter the for loop to test whether or not the values assigned in the move function are valid
      if (okay(q, man)) //call the okay function, if it is okay 
         move(q, man+1); //we pass it to the move function, then we move to the next partner 
}

//main function
int main() {
   int q[3]; //we need 3 indexes in the array because the numbers represent the women that are being paired with the mens.
   move(q, 0); //call the move function with the array and the starting index which is 0 
   return 0; //return when we done
}