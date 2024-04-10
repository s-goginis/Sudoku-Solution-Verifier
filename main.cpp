#include <iostream>
#include <iomanip>
#include <cctype>
#include <fstream>

using namespace std;

//Function Declaration
bool RowChecker (int [][9], int);
bool ColumnChecker (int [][9], int);
bool SubgridChecker (int [][9]);

//Function main()
int main(){
  
  int grid[9][9];

  //Opening file
  ifstream infile;
  infile.open("sudoku.in");

  //Creating Output file
  ofstream outfile;
  outfile.open("sudoku.out");

  //Checking if file is open
  if(!infile){
    cout << "Error opening file. \n";
    return 1;
  }
  //Getting the amount of solutions to test
  while (infile){
    int num_times = 0;
    infile >> num_times;

    //Inputting values from file into array
    for(int m = 0; m < num_times; m++){
      for(int i=0; i<9; ++i){
        for(int j = 0; j<9; ++j){
          infile >> grid[i][j];
        }
      }
      //Calling functions under conditions
      bool status = true;
      for(int i=0; i<9; ++i){
        if(RowChecker(grid, i) == false || ColumnChecker(grid, i) == false
           || SubgridChecker(grid) == false){
          status = false;
        }
      }

      //Print validation to output file
      if(status){
        outfile << "YES \n";
      }
      else{
        outfile << "NO \n";
      }
    }
  }

  //Closing file
  infile.close();
  outfile.close();
  return 0;
}

//Function RowChecker() 
bool RowChecker(int grid[][9], int row){
  bool unique[10] = {false};

  //Going through row
  for(int i = 0; i<9; i++){
    //checking for duplication
    if(unique[grid[row][i]]){
      return false;
    }
    else{
      unique[grid[row][i]] = true;
    }
  }
  
  return true;
}

//Function ColumnChecker()
bool ColumnChecker(int grid[][9], int col){
  bool unique[10] = {false};
  for(int i = 0; i<9; i++){
    if(unique[grid[i][col]]){
      return false;
    }
    else{
      unique[grid[i][col]] = true;
    }
  }
  
  return true;
}

//Function SubgridChecker()
bool SubgridChecker(int grid[][9]){
  //Breaking the array into desired subgrids
  for(int row = 0; row < 9; row += 3){
    for(int col = 0; col < 9; col += 3){
      bool gridCheck[10] = {false};
      for(int k = row; k < row + 3; k++){
        for(int l = col; l < col + 3; l++){
          if(gridCheck[grid[k][l]]){
            return false;
          }
          else{
            gridCheck[grid[k][l]]=true;
          }
        }
      }
    }
  }
  return true;
  
}
