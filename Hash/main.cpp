#include "hash.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
int main() 
{
	auto hA = hash<uint32_t>(1);
	auto hC = hash<int>(2);
	auto hD = hash<bool>(false);
	auto hE = hash<char>('a');
	auto hF = hash("asdasfa");
	auto hG = hash("asdasaf");
	auto hH = hash("sadasaf");
	auto hI = hash("afa");

	std::cout << "Hash uint32_t 1:" << hash<uint32_t>(1) << "\n";
	std::cout << "Hash int 2:" << hash<int>(2) << "\n\n";
	std::cout << "Hash bool false:" << hash<bool>(false) << "\n";
	std::cout << "Hash bool true:" << hash<bool>(true) << "\n\n";
	std::cout << "Hash char 'a':" << hash<char>('a') << "\n";
	std::cout << "Hash char 'A':" << hash<char>('A') << "\n";
	std::cout << "Hash char 'b':" << hash<char>('b') << "\n\n";
	std::cout << "Hash \"asdasfa\":" << hash("asdasfa") << "\n";
	std::cout << "Hash \"asdasaf\":" << hash("asdasaf") << "\n";
	std::cout << "Hash \"sadasaf\":" << hash("sadasaf") << "\n";
	std::cout << "Hash \"afa\":" << hash("afa") << "\n\n";

	texture testT1 = texture();
	testT1.texID = 1;
	testT1.width = 100;
	testT1.height = 100;
	testT1.channels = 'a';
	texture testT2 = texture();
	testT2.texID = 2;
	testT2.width = 1000;
	testT2.height = 1000;
	testT2.channels = 'b';


	std::cout << "Hash texture 1:" << hash(testT1) << "\n";
	std::cout << "Hash texture 2:" << hash(testT2) << "\n\n";

	return 0;
}