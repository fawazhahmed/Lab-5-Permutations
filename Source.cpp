#include<iostream>
#include<string>

//implicit stack app: backtracking to find all permutaion of string


//
void Permutation(const std::string& remaining, const std::string& locked)
{
	//base case: when remaining is empty:
	//just print locked, as it is 1 permutation
	if (remaining.size() == 0)
	{
		std::cout << locked << std::endl;
		return;
	}
	//use loop to iterate over each letter, send rest letters to recrusion
	for (auto i = 0; i < remaining.size(); i++)
	{
		//remaining.at(i)
		
			//string is copy of locked as original locked is const.
		std::string partialSolution = locked;

	//append one new character to copy of string locked
		partialSolution.push_back(remaining[i]);

		//use substr to form rest characters
		std::string rest = remaining.substr(0, i) + remaining.substr(i + 1);
	
		Permutation(rest, partialSolution); //recursively keep looping through 
	}
}

int main()
{
	//initially: full string remaining, empty string locked
	std::string a = "abcd" ;

	Permutation("abcd", ""); //call the function with an empty string 

	//test cases to make sure it works
	////"a: rest: bcd"
	//std::cout << a[0] << ", rest: " << (a.substr(0,0) + a.substr(0 + 1)) << std::endl;

	////"b: rest: acd"
	//std::cout << a[1] << ", rest: " << (a.substr(0,1) + a.substr(1 + 1)) << std::endl;

	////"c: rest: abd"
	//std::cout << a[2] << ", rest: " << (a.substr(0, 2) + a.substr(2 + 1)) << std::endl;

	////"d: rest: abc"
	//std::cout << a[3] << ", rest: " << (a.substr(0, 3) + a.substr(3 + 1)) << std::endl;
}

