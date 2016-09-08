// --------------------------
// projects/collatz/Collatz.h
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------

#ifndef Collatz_h
#define Collatz_h

// --------
// includes
// --------

#include <iostream> // istream, ostream
#include <string>   // string
#include <utility>  // pair

using namespace std;

// ------------
// collatz_read
// ------------

/**
 * read two ints from r into i an j
 * @param r an istream
 * @param i an int
 * @param j an int
 * @return true if the read is successful, otherwise false
 */
bool collatz_read (istream& r, int& i, int& j);

// ------------
// collatz_eval
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length of the range [i, j]
 */
int collatz_eval (int i, int j);

// -------------
// collatz_print
// -------------

/**
 * print three ints to w
 * @param w an ostream
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @param v the max cycle length
 */
void collatz_print (ostream& w, int i, int j, int v);

// -------------
// collatz_solve
// -------------

/**
 * @param r an istream
 * @param w an ostream
 */
void collatz_solve (istream& r, ostream& w);

#endif // Collatz_h
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
// -------------------------------
// projects/collatz/RunCollatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// -------------------------------

// --------
// includes
// --------

#include <iostream> // cin, cout


// ----
// main
// ----

int main () {
    using namespace std;
    collatz_solve(cin, cout);
    return 0;}
