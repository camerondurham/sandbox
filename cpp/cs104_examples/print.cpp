#include<iostream>
#include<string>
#include<set>
#include<sstream>

using namespace std;



template <typename S>
S union_sets(const S& s1, const S& s2){
    S result = s1;

    result.insert(s2.cbegin(), s2.cend());

    return result;
}

std::set<std::string> getLetterPermutations(std::string rack){
        std::set<std::string> possibleHands;
        //possibleHands.insert( rack );
        //   std::string blankUseString;
        //If the tile rack has blank tiles, try all combos of those letters
        if( rack.find('?') != std::string::npos ){
            int pos = rack.find('?');
            for(int i = 0; i < 26 ; i++){
                char letter  = 'A' + i;
                std::stringstream ss;
                ss << letter;
                std::string tmp;
                ss >> tmp;
                rack.replace(pos,1, tmp);
                possibleHands.insert(rack);
                possibleHands = union_sets( possibleHands, getLetterPermutations(rack));
            }
        }

        return possibleHands;
}


int main(){

    string  s("abcdefghijklmnopqrstuvwxyz");

//  cout << s << endl;

//  cout << s.find('l') << endl;
//  cout << s[s.find('l')] <<endl;
//  s.replace(s.find('l'),1,"r");
//  cout << s<<endl;

    for(int i = 0; i < 26; i++){
        if(s.find('a' + i) != string::npos) {int pos = s.find('a'+i); cout << " erasing letter at position " << pos << "    "; s.erase(pos,1);cout<<s<<endl;}
    }

//  }
//  std::string rack("abc?efg?");
//  std::set<std::string> possiblehand = getLetterPermutations(rack);
//  for(auto p = possiblehand.begin(); p != possiblehand.end() ; ++p){
//      std::cout << *p << std::endl;
//  }





    return 0;


}

