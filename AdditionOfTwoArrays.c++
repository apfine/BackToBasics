/*We implement summation of two integers using arrays which allows to add largers numbers. Although its less efficient as compared to 
the integer method listed under ./AddTwoArrays which uses direct int addition but it works for very big numbers which the other method doesn't.*/

#include <iostream>
#include <deque>
#include <ctime>

using namespace std ;

void arrayPrinter(deque <int> a){  //Taking an array and printing each element of it .
    cout<<endl;
    cout<<"[";
    for(int i : a){
        cout<<"  "<<i;
    }
    cout<<"  ]";
    cout<<endl;
}

deque <int> add(deque <int> a1 , deque <int> a2){
    deque <int> ans ;
    deque <int> a ,b;
     if(a2.size()<a1.size()){
                a = a1;
                b= a2;
            }
            else{
                a = a2;
                b = a1;
            }
    int c1 = 0;
    int c2 =0;
    int i = b.size()-1;
    int p ;
    //Traversing over the arrays.
        for(int j = a.size()-1 ;j>=0 ; j--){
            int k = b[i] + a[j];
            if(k>9&& c1>0){
                p=((k+1)%10);
                c2++;   
            }
            else if(k>9){
                p=(k%10);
                c1++;
                c2++;   
            }
            else if(k<10 && c1>0){
                if(k+1 >9){
                    p= 0;
                    
                }
                else{
                    p = k+1;
                    c1--;
                }
                c2++;
            }
            else{
                p=(k);
                c2++;
            }
            //Pushing the calculated values.
            ans.push_front(p);
            i--;
        } 
        //Checking for arrays of dissimilar size and pushing the left out elements.
        if(c2<a1.size()||c2<a2.size()){
            
            if(c2<a1.size()){
                a = a1;
            }
            else{
                a = a2;
            }
            for(int i = a.size()-c2-1 ; i>=0 ; i--){
                if(c1>0){
                p=(a[i]+1);
                    if(p>9){
                        p = p%10;
                    }
                    else{
                        c1--;
                    }                 
                }
                else{
                    p=(a[i]);
                }
                ans.push_front(p);
            }
        }
        if(c1!=0){
            ans.push_front(1);
            c1--;
        }
    //Returning the answer array.
    return ans ;
}

int main(){
    clock_t start , end ;
    start = clock();
    deque <int> a1 = {9,2,3,4,5,5,7,8,9,9};
    deque <int> a2 = {9,7,4,9,7,9,1,3,4,6,8,9,5,6};
    deque <int> ans ;
    ans = add(a1,a2);
    cout<<"\nThe array after addition is : ";
    arrayPrinter(ans);
    end = clock();
    cout<<"The time taken to run the program is "<<end - start <<" ms.";    
    return 0;
}