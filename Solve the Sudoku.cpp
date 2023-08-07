//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        int row, col;
        if (!FindUnassignedLocation(grid, row, col))
            return true; // All cells are filled, solution found
        
        for (int num = 1; num <= 9; num++) 
        {
            if (IsSafe(grid, row, col, num)) 
            {
                // Make tentative assignment
                grid[row][col] = num;
                
                // Recur to fill the rest of the grid
                if (SolveSudoku(grid))
                    return true;
                
                // If we reached here, the current assignment didn't lead to a solution
                // and we need to backtrack
                grid[row][col] = UNASSIGNED;
            }
        }
        return false; // No valid assignment found
    }
    
    // Function to check if it's safe to assign a number to a particular cell
    bool IsSafe(int grid[N][N], int row, int col, int num) 
    {
        // Check the row and column
        for (int i = 0; i < N; i++) 
        {
            if (grid[row][i] == num || grid[i][col] == num)
                return false;
        }
        
        // Check the 3x3 sub-grid
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        
        for (int i = 0; i < 3; i++) 
        {
            for (int j = 0; j < 3; j++) 
            {
                if (grid[i + startRow][j + startCol] == num)
                    return false;
            }
        }
        
        return true;
    }
    
    // Function to find an unassigned cell in the grid
    bool FindUnassignedLocation(int grid[N][N], int &row, int &col) 
    {
        for (row = 0; row < N; row++) 
        {
            for (col = 0; col < N; col++) 
            {
                if (grid[row][col] == UNASSIGNED)
                    return true;
            }
        }
        return false;
    }
    
    // Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for (int i = 0; i < N; i++) 
        {
            for (int j = 0; j < N; j++) 
            {
                cout << grid[i][j] << " ";
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends