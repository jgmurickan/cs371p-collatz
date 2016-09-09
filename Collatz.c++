// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream

#include "Collatz.h"

using namespace std;

// ------------
// collatz_read
// ------------

bool collatz_read (istream& r, int& i, int& j) {
    if (!(r >> i))
        return false;
    r >> j;
    return true;}

// ------------
// collatz_eval
// ------------
#define ENABLE_OPTIMIZATION

//really lazy cache optimization, just fills in cycle lengths when it finds it
#ifdef ENABLE_OPTIMIZATION
int lazy_cache[1000000] = {0};
#endif

int collatz_eval (int i, int j) {
   int max = 0;

   //switches i and j if i is greater than j 
   if(j < i) {
     int t;
     t = i;
     i = j;
     j = t;
   }

   //loops through the range
   for(int k = i; k <= j; ++k) {

     int temp = k;
     int count = 1;

     //finds the cycle length
     while(temp != 1){

      #ifdef ENABLE_OPTIMIZATION
        //lazy cache that just checks if it's in the cache in the beginning
        if(temp <= 1000000) {
          if(lazy_cache[temp] != 0){
            count = lazy_cache[temp];
            break;
          }
        }
      #endif

      //if even
      if(temp % 2 == 0)
        temp /= 2;
      //if odd
      else {
        #ifdef ENABLE_OPTIMIZATION
          //two steps in one if odd number optimization, not cache related
          temp = ((temp*3) + 1)/2;
          ++count;
        #else
          temp = temp*3 + 1;
        #endif
      }
      ++count;
     }
      #ifdef ENABLE_OPTIMIZATION
       //if not in lazy cache, add it
       if(temp == 1)
        lazy_cache[temp] = count;
      #endif
     if(count > max)
       max = count;
   }

    return max;}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    int i;
    int j;
    while (collatz_read(r, i, j)) {
        const int v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
