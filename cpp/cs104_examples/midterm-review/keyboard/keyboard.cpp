#include "keyboard.h"
#include <map>
#include <vector>
#include <functional>
#include <utility>
#include <numeric>


int calculateTime(std::string keyboard, std::string word) { 
	int sum(0); 
	std::vector<int> permutation(26);

	for(size_t i = 0; i < keyboard.size(); ++i)
	{
		permutation[static_cast<int>(keyboard[i] - 'a')] = i;
	}
	for(size_t i = 0; i < word.size(); ++i)
	{
		if(i == 0)
		{
			sum += permutation[static_cast<size_t>(word[i]-'a')];
		}
		else
		{
			int dist =  permutation[static_cast<size_t>(word[i] - 'a')] + permutation[static_cast<size_t>(word[i-1])];
			sum += (dist < 0 ? -dist : dist);
		}
	}

	return sum; 
}
