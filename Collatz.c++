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

#ifdef ENABLE_OPTIMIZATION
int lazy_cache[1000000] = {0};
#endif

int collatz_eval (int i, int j) {
   int max = 0;

   if(j < i) {
     int t;
     t = i;
     i = j;
     j = t;
   }

   for(int k = i; k <= j; ++k) {

     int temp = k;
     int count = 1;

     while(temp != 1){

      #ifdef ENABLE_OPTIMIZATION
        if(temp <= 1000000) {
          if(lazy_cache[temp] != 0){
            count = lazy_cache[temp];
            break;
          }
        }
      #endif

      if(temp % 2 == 0)
        temp /= 2;
      else {
        #ifdef ENABLE_OPTIMIZATION
          temp = ((temp*3) + 1)/2;
          ++count;
        #else
          temp = temp*3 + 1;
        #endif
      }
      ++count;
     }
      #ifdef ENABLE_OPTIMIZATION
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
