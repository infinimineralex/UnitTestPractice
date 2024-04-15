#include "Password.h"
#include <string>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;
  if(phrase.size() <= 0) return 0;
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}

bool Password::has_mixed_case(string word){
  bool upper=false;
  bool lower=false;
  for(char w : word){
    if(isupper(w)){
      upper=true;
    } else if (islower(w)){
      lower=true;
    }
  }
  if (lower && upper){
    return true;
  }
  return false;
}