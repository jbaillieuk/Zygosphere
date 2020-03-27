#include <iostream>   
#include <fstream>
#include <cmath>
using namespace std;
//Declares Files to read and write to
ifstream fin ("input.txt");
ofstream fout ("output.txt");
int main(){
   //Since 1<=v<=1000000000, we only need Fibonacci numbers up to the 59th
   long fib[58];
   //Fill the list of Fibonacci dynamically
   fib[0]=1;
   fib[1]=1;
   for(int i = 2; i < 59; i++){
      fib[i]=fib[i-1]+fib[i-2];
   }
   //Set up input as long 
   long v;
   //Take in input
   fin>>v;
   //Declarations
   long store[100];
   int counter=0, holder;
   //Given our amended v isn't 0, run loop
   while(v!=0){
      //Find the biggest fibonacci number <v
      for(int i = 0 ; i < 59 ; i++){
         if(fib[i]>v){
            holder=i-1;
            break;
         }
      }
      //If this number is the same as v, we are done. Negate loop
      if(v==fib[holder]){
         store[counter]=v;
         v=0;
      }
      else{
         //Otherwise, its less. Find the difference and repeat process with that difference.
         store[counter]=fib[holder];
         counter++;
         v=(v-fib[holder]);
      }
   }
   //Output solutions in ascending order
   for(int i = counter; i >-1; i--){
      fout<<store[i]<<" ";
   }
   return 0;
}