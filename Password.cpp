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

Password::Password(){
  pass_history.push_back("ChicoCA-95929");
}



bool Password::has_mixed_case(string word){

  bool found = false;
  for(char c : word){
    if( !found && c >= 'A' && c <= 'Z' ){
      found = true;
    }
    else if( found && c >= 'a' && c <= 'z'){
      return true;
    }
  }
  return false;

}

void Password::set(string word){
  if(word.size() >= 8 && word.size() <= 20) {
    if(count_leading_characters(word) <= 3){
      if(has_mixed_case(word)){
        for(auto i : pass_history){
          if(i == word){
            return;
          }
        }
          pass_history.push_back(word);
      }
    }  
  }
  
}

bool Password::authenticate(string word){
  if(pass_history.back() == word){
    return true;
  }
  return false;
}