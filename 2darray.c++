//I wrote a code to show the matrix formation using vectors . I have written  a complete library of different operations on the matrix.

#include <iostream>
#include <vector>

using namespace std;

class td{
    private:
         int ro , col;
         vector<vector<int>> matrix;
         vector<vector<int>> matrixCopy;

    public:
        
        td(const int& r= 2 , const int& c = 2) : ro(r),col(c) ,  matrix(ro, vector<int>(col)) , matrixCopy(ro , vector<int>(col)){}; //The class constructor

        
        vector <vector <int>> in(){         //the array intializer
            int c =0 ;
                cout<<"Please enter the number of rows    : ";
                cin>>ro;
                cout<<"Please enter the number of columns : ";
                cin>>col;
                matrix.resize(ro);
                matrixCopy.resize(ro);
                for(int i = 0 ; i<matrix.size() ; i++){
                    matrix[i].resize(col);
                    matrixCopy[i].resize(col);
                    for(int j =0 ;j<matrix[i].size() ; j++){
                        matrix[i][j]= i*j+i+j;
                    }
                }
             matrixCopy = matrix;
            return matrix;
        }

        //The function to print the matrix .
        void print(){
            cout<<"\nThe array is : "<<endl;
            cout<<""<<endl;
            for(int i = 0 ; i<matrix.size() ; i++){
                cout<<" |";
                    for(int j =0 ;j<matrix[i].size() ; j++){
                        cout<<" "<<matrix[i][j];
                        if(j<matrix[i].size()-1){
                            cout<<" ";
                        }
                        
                    }
                    if(i<matrix.size()-1){
                        cout<<"| ";
                    }else{
                        cout<<"|";
                    }cout<<endl;
                }
                cout<<endl<<" ";
        }

        
        void sinPrint(){            //Prints the matrix columnwise 
            cout<<"\nThe array when printed like a sin wave is : "<<endl;
            cout<<endl;
              for(int i = 0 ; i<col ; i++){
                for(int j = 0 ; j<ro ; j++){
                    cout<<matrix[j][i]<<" ";
                }       
              }
            cout<<endl;
        }

        void spiralPrint(){   //Prints the matrix spirally starting from 1st element and coming back to it but not printing it and switching to second row.
            cout<<"\nThe array when printed like a spiral is : "<<endl;
            int c = 0; 
            int c1 =0 ;
            int c2=col-1;
            int c3 = ro-1;
            int ver = ro;
            int hor = col;
            cout<<endl;
            int l1 , l2 ;
            l1 = 0;
            l2 = 1;
            for(int k = 0 ; k<(ro+1)/2 ; k++){
            
                if(c==0){
                    for(int i = l1 ; i < hor  ; i++){                      
                        cout<<matrix[c1][i]<<" ";                   
                        }
                        c=1;
                        c1++;
                        hor--;
                        l1++;
                }
                

                if(c==1){
                    for(int i = l2 ; i < ver ; i++){
                            cout<<matrix[i][c3]<<" ";
                    }
                    c=0;
                    c2++;
                    ver--;
                    c3--;
                    l2++;
                }
            
                if(c==0){
                    for(int i =hor-1 ; i >=l2-1 ; i--){                      
                        cout<<matrix[ver][i]<<" ";                   
                        }
                        c=1;
                }

                if(c==1){
                    for(int i = ver; i >=l1; i--){
                            cout<<matrix[i][l1-1]<<" ";
                    }
                    c=0;
                }
            }
            cout<<endl;
        }

        void ninetyRotate(){        //this function can rotate the matrix by 90 degrees.
            int r = ro-1;
            int c = col-1;
            vector <vector<int>> ans(ro , vector<int>(col));
            for(int i = 0 ; i< matrix.size() ; i++){
                for(int j = 0 ; j<matrix[i].size() ; j++){
                    ans[j][r-i] = matrix[i][j];
                }
            }
            matrix = ans;
        }


        void refresh(){         //This function/method resets the values of the matrix to the initialized matrix
            matrix = matrixCopy;
        }

        void  search(int num){  //This function is used to search the coordinates of a member from the matrix using brute method
            for(int i =0 ; i<ro ; i++){
                for(int j =0 ; j<col ; j++){
                    if(matrix [i][j] == num){
                        cout<<"( "<<i+1<<" , "<<j+1<<" )";
                    }
                }
            }
        }

        vector <vector <int>> sort(){
            vector<vector<int>> ans(col , vector<int>(ro));
            for(int i = 0 ; i< ro ; i++){
                for(int j = 0 ; j<col-1 ; j++){
                    if(matrix[i][j]>matrix[i][j+1]){
                        swap(matrix[i][j+1] , matrix[i][j]);
                    }
                }
            }
            return matrix;
        }
        
        vector < vector<int>>push(){
            int i , j , n , b ;
            cout<<"\nThe number of enteries : ";
            cin>>b;\
            for(int k = 1 ; k<=b ; k++){
                cout<<endl<<"This is the entry no - "<<k;
                cout<<"\nRow(>1) : ";
                cin>>i;
                cout<<"\nColunmn(>1) : ";
                cin>>j;
                cout<<"\nPlease enter the number : ";
                cin>>n;
                matrix[i-1][j-1]=n;\
            }
            return matrix; 
        }
};
        


int main(){
    td mat;
    mat.in();
    mat.print();
    mat.sinPrint();
    mat.spiralPrint();
    mat.ninetyRotate();
    mat.print();
    mat.refresh();
    mat.print();
    mat.search(5);
    mat.push();
    mat.sort();
    mat.print();
    mat.refresh();
    return 0 ;
}
