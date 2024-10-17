/*I wrote a whole class related to replacing whitespaces from the text with _ .The purpose was to learn about the text 
transformations and the different ways they can be used along with the standard library algorithms of c++*/

/*I have tested two different methods here and I tried testing the time efficiency of the methods . You should yourself run and 
test the two methods .*/


#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

class MyString{
    private:
            string str;
    public:

            MyString( const string& initialstr =""): str(initialstr){

            }

            void in(){
                
                cout<<"\nPlease enter the string you want to transform : ";
                getline(cin , str );
            }
            

            //Using the brute force method to transform the line.
            string replaceSpacesBrute() {
                string Sr; 
                for (char i : str) {
                    if (i == ' ') {
                        Sr += '_'; 
                    } else {
                        Sr += i;
                    }
                 }
                str = Sr; // Update the member variable with the modified string
                return str; // Return the modified string
            }

            //Using the replace algorithm to transform the line.
            string replaceSpaces(){
                    replace(str.begin() , str.end() , ' ','_');
                    return str;
            }

            void arrayPrinter(){
                cout<<endl;
                for(auto i : str){
                    cout<<i;
                }
                cout<<endl;
            }

};

int main(){
    clock_t start , end;

    MyString mystr;
    mystr.in();
    cout <<"Please choose the method you want to use for the transfer : 1 for brute 2 for normal ";
    int sw;
    cin>>sw;
    start = clock();
    if(sw==1){
    mystr.replaceSpacesBrute();
    mystr.arrayPrinter();
    }
    if(sw==2){
    mystr.replaceSpaces();
    mystr.arrayPrinter();
    }
    end = clock();
    cout<<"\nThe time taken to run the program is : "<<end - start <<" ms.\n\n";
    return 0;
}