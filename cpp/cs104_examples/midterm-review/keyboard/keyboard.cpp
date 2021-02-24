#include "keyboard.h"
#include <vector>
#include <map>
int calculateTime(std::string keyboard, std::string word) {
	int sum(0);
	std::vector<int> permutation(keyboard.size());

	for(size_t i = 0; i < keyboard.size(); ++i)
	{
		permutation[static_cast<int>(keyboard[i] - 'a')] = i;
	}

	sum = permutation[static_cast<size_t>(word[0] - 'a')];

	for (size_t i = 1; i < word.size(); ++i)
	{
		sum += std::abs(permutation[static_cast<size_t>(word[i] - 'a')] - permutation[static_cast<size_t>(word[i - 1] - 'a')]);
	}

	return sum;
}



// int calculateTime(std::string keyboard, std::string word) {
// 	int sum = 0;
// 	std::map<char,int> letters;
// 	for(size_t i = 0; i < keyboard.size(); i++) {
// 		letters[keyboard[i]] = i;
// 	}
// 	sum += letters[word[0]];
// 	for(size_t i = 1; i < word.size(); i++) {
// 		sum += abs(letters[word[i]] - letters[word[i-1]]);
// 	}
// 	return sum;
// }