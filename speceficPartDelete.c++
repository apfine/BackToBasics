//I wrote a code to remove a substring from a string using the standard <algorithm> library and also without the library.

#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

class MyString{
    private:
        string str;
    public:
        
        MyString(const string& ini="" ):str(ini){}     //This is the constructor of the class.

        void print(){
            cout<<endl;
            for(auto i :str ){
                cout<<i;         
            }
            cout<<endl;
        }

        void in(){                                      //We take in the input of the  string.
            cout<<"\nPlease enter the text you want to transform : ";
            cin>>str;
        }


        string rem(){ 
            clock_t start , end ; 
                                                        //We are using the erase() method of standard c++ algorithms.
            cout<<"\nPlease enter the part of the text you want to remove : ";
            string inp;
            cin>>inp;
            start  = clock();
            
            str.erase(str.find(inp) , inp.length());
            
            end = clock();
            cout<<"\nThe total time taken to transform the string is : "<<end - start << " ms.\n\n";
            return str;
        }


        
        string remBrute(){
                                                        //We are writing the implementation of the above algo using the simple methods
            clock_t start , end;
            cout<<"Please enter the substring you want to remove : ";
            string sub;
            cin>>sub;
            start = clock();
            int index,c1 ,c2,co;
            int su = sub.length();
            int sr = str.length();
            c1=0;

            for(int i = 0 ;i<su ; i++ ){
                c2=0;
                for(int j = 0; j<sr ; j++){
                    if(str[j]==sub[i] && c2==0){
                        cout<<"Entered.";
                        co=j;
                        c2++;
                    }
                }

                int co1 =co ;
                for(int i = 0 ; i<su ; i++){
                    if(str[co1]==sub[i]){
                        c1++;
                        co1++;
                    }
                }

                cout<<endl<<c2<<endl<<c1;//<<" "<<c1;
                if(c1 == sub.length()){
                    for(int i = co ; i<su+co ; i++){
                        str[i] = '_';
                    }
                }

            }
            end = clock();
            cout<<"\nThe time taken to run the program is : "<<end - start <<" ms.";
            return str;
        }

        

};

int main(){
    MyString str;
    str.in();
    int sw;
    cout<<"\nPlease enter 1 for standard and 2 for brute method : ";
    cin>>sw;
    
    if(sw==1){
         str.rem();
    }
    else{
         str.remBrute();
    } 

    cout<<"\nThe string after being transformed is :";
    str.print();
    return 0;
}

/*After comparing both the programs we get that the both work the same way and thus we can roughly imagine the
 mechanism of rem() using remBrute() .*/