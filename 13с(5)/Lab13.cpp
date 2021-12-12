
// --------------------------------- file of main program

/* Problem:
 Find all words contain vowels 'y', 'o', 'u' only.
*/

#include <stdio.h>
#include "Set.h"

char Word[20], S[2 * N],                    // S - set for word
    Vowels[] = "AEIOUYaeiouy", Sv[2 * N],   // Sv - set for vowels
    You[] = "YOUyou", Sy[2 * N], S1[2 * N]; // Sy - set for letters y,o,u

int main()
{
  int i, n, m = 0;
  char oldc = ' ', c;
  CreateSet(Vowels, Sv);
  CreateSet(You, Sy);
  DisplaySet(Sv);
  DisplaySet(Sy); // print for test
  while (i != EOF)
  {
    i = getchar();
    c = i;
    if (!Letter(oldc) && Letter(c))
    {
      n = 0;
      Word[0] = c;
    } // begin of word
    if (Letter(oldc) && Letter(c))
      Word[++n] = c;
    if (Letter(oldc) && !Letter(c)) // end of word
    {
      Word[++n] = '\0';
      CreateSet(Word, S);
      IntersSet(S, Sv, S1);                    // intersection of sets
                                               //	DisplaySet(S); DisplaySet(S1);                    // print for test
      if (!EmptySet(S1) && IncludeSet(S1, Sy)) // only our vowels
      {
        printf("%s ", Word);
        if (!(++m % 10))
          printf("\n");
      }
    }
    oldc = c;
  }
  return 0;
}
/* After:
	  lab13.exe <lab13.cpp >>lab13.cpp
   Result:

words y o u only Word for word for You 
YOUyou Sy Sy for y o u oldc You Sy 
Sy for oldc Word of word oldc Word oldc of 
word Word Word of for Sy only our Word oldc 

*/
