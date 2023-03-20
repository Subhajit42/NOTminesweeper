#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int current_table(bool board[3][3]){
    //board
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
           cout << board [i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

bool check_win(bool board[3][3]){
    //board
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (board[i][j] != 0){
                cout << "Continue\n" << endl;
                return 1;
            }
        }
    }
    cout << "\nVICTORY\n";
    return 0;
}


bool check_change_element(bool board[3][3],int row,int col){
    if (board[row][col] ==0){
        cout << "\nNothing detected\n"<< endl;
    }else{
        board[row][col] = 0;
        
        cout << "\nBomb detected\n"<< endl;
    }
    return board;
}


void print(bool array[3][3],int rows, int columns){
    for (int i=0;i<rows;i++){
        for (int j=0;j<columns;j++){
            cout << array[i][j] << " ";
        }
        cout << endl;
        }
}
void print(string array[3][3],int rows, int columns){
    for (int i=0;i<rows;i++){
        for (int j=0;j<columns;j++){
            cout << array[i][j] << " ";
        }
        cout << endl;
        }
}
//For Randomizing board


bool random_(){
    int num1= (rand() % 10) % 2;
    // cout << num1;
    // return (rand() % 10) % 2;
    return num1;
}

int check_1s(bool array[3][3]){
    int count_1=0;
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (array[i][j] == 1){
                count_1++;
            }
        }
    }
    return count_1;
}

//deepcopy
bool deep_copy(bool board[3][3]){
    bool array[3][3];
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            array[i][j] = board[i][j];
        }
    }
    
    // print(array[3][3],3,3)
    return array;
}

// MAIN CODE 

int main() {
    srand(time(0));
    int rows=3;
    int columns=3;
    bool board[3][3];
    
    for (int i=0;i<3;i++){
        // print(board,rows,columns);
        cout << endl;
        
        for (int j=0;j<3;j++){
            if (check_1s(board)==3){
                break;
            }else{
                board[i][j] = random_();
            }    
        }
    }
      
      
    //DEEP COPY
    bool start_board[3][3];
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            start_board[i][j] = board[i][j];
        }
    }
    
    string sample_board[3][3] = {
        {"X","X","X"},
        {"X","X","X"},
        {"X","X","X"}
        };
    
    cout << "Objective is to find all the bombs in least possible attempts.\nThe Board is a 3X3 Board with first row and column being 0.\n" ;
    print(sample_board,3,3);
    
    
    int row;
    int col;
    int attempts=0;
    while (check_win(board)){
        
        cout << "PLEASE ENTER ONLY INTEGERS FROM 0 TO 2\n";

        cout << "Enter Row number==";
        cin >> row;
        
        cout << "Enter Column number==";
        cin >> col;
        attempts++ ;
        // CHECKING AND OVERWRTING IF 1
        check_change_element(board,row,col);
        //To view current status of board
        //current_table(board);
        }
     
    cout << "\nBoard started with was==\n";
    print(start_board,3,3);
    cout << "\nNumber of attempts used == " << attempts ;
    
    return 0;
}