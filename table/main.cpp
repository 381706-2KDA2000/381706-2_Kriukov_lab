#include "TArrList.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
  TTree root;
  root.level = 0;
  root.nextLevel = new TTree(0);
  TTree* string = root.nextLevel;
  string->level = 1;
  string->nextLevel = new TTree(0);
  TTree* word = string->nextLevel;
  word->level = 2;
  word->nextLevel = new TTree('p');
  TTree* symbol = word->nextLevel;
  symbol->sameLevel = new TTree('a');
  symbol->sameLevel->sameLevel =
    new TTree('r');
  symbol->sameLevel->sameLevel->sameLevel
    = new TTree('a');
  symbol->sameLevel->sameLevel->sameLevel->sameLevel
    = new TTree(' ');

  word->sameLevel = new TTree(0);
  TTree* word2 = word->sameLevel;
  word2->level = 2;
  word2->nextLevel = new TTree('v');
  //std::cout << root.d << std::endl;
  root.print2();
  return 0;
}