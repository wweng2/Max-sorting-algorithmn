#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

/* Wei zhang weng

SR60854

11//22/2022

CMSC 441 Paper 2 

This program finds the max value in the array by doing comapring and halves it until you have the array to 1 value taht is the max

*/

int arrayMax(int array[], int n){

  int check = 0; /* A check value to make it so that the valeu doen't reach byond the half way point */

  int number = n;

  while(number != 1){ /* Until the number whihc is n reach 1 this whoel loop will keep running */

    int i = 0 ;
    for(i = 0 ; i < (check + (number/2)); i++){/*loop until you reach 0 + number/2 -1 whic is the hlafway point, and keep decrease this halfway point utntil one value is left*/

      if(array[i] < array[i + (number/2)]){/* if the value i is less then i +(number/2) then flip it , do ntohing if it is not*/

        array[i] = array[i + (number/2)];
      }
    }

    number = number /2;
    
  }

  return  array[0] ;
}

int VectorMax(vector<int> vect , int n){

  int check = 0;

  int number = n;

  while(number != 1){/*Keep running until the number is 1 and only one value is left*/

    int i = 0 ;
    for(i = 0 ; i < (check + (number/2)); i++){/*loop until you reach 0 + number/2 -1 whic is the hlafway point, and keep decrease this halfway point utntil one value is left*/

      if(vect[i] < vect[i + (number/2)]){

        vect[i] = vect[i + (number/2)];/* if the value i is less then i +(number/2) then flip it , do ntohing if it is not*/
      }
    }

    
    number = number /2; /* decrase the uasble array size by half*/
    
  }

  return  vect[0] ;
}

int MAX_Value(int number){/*Find the max value and display it and time it */

  int n;

  n = number;
  /* make the array and vector and have the array to the size specifeid by the user*/
  int array1[n];
  vector<int> vect;

  int i = 0;
  /* Add the radnome value form the range of 0 to 1000 in to the array */
  for(i = 0 ; i < n; i++){

    array1[i] = (rand() % 1000) + 1;
  }


   /* Add the radnome value form the range of 0 to 1000 in to the vector */
  for(i = 0 ; i < n; i++){

    vect.push_back((rand() % 1000) + 1);
  }

  cout << "This is the array  value for n : " << n <<endl;
  /*Display both value in the array and the vector, as both vlaue are different since it different rand calls*/
  
  for(i = 0 ; i < n; i++){

    cout << array1[i] << "  ";
  }

  
  cout << endl ;

  cout << "This is the vector   value for n : " << n <<endl;

  for(i = 0 ; i < n; i++){

    cout << vect[i] << "  ";
  }

  cout << endl ;

  /* time the time it takes for the array to find max in nanosecodns*/
  auto start_time = high_resolution_clock::now();
  int value = arrayMax(array1,n);
  auto stop_time = high_resolution_clock::now();

  auto duration= duration_cast<nanoseconds>(stop_time - start_time);

  /* Display both the max value in the array and the time it took */
  cout << "This is the max value in this array: " << value << endl;

  cout << "The time taken to find max in an array of "<< n << " is " << duration.count() << " NanoSeconds "<<endl;

  /* Times the time it takes for the vecotr to find it's max */
  start_time = high_resolution_clock::now();
  int max = VectorMax(vect,n);
  stop_time = high_resolution_clock::now();

  duration= duration_cast<nanoseconds>(stop_time - start_time);

  /* Display the max value in the array and the time it took in nanoseconds */
  
  cout << "This is the max value in this vector: " << max << endl;

  cout << "The time taken to find max in an vector of "<< n << " is " <<duration.count() << " NanoSeconds " << endl;

  return 0;
}

int main() {
  /* The vluaes that is the power of 2 that is used to make the array and call it*/
  int n = 4;

  MAX_Value(n);

  n = 8;

  MAX_Value(n);

  n = 16;

  MAX_Value(n);

  n = 32;

  MAX_Value(n);

  
  

  

  
}
