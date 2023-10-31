//#include <iostream>
//#include <fstream>
//#include <string>
//#include <map>
//#include <vector>
//#include <sstream>
////#include<cstdlib>
//
//using namespace std;
//
//template <size_t N>
//int splitString(string(&arr)[N], string str)
//{
//	int count = 0;
//	int n = 0;
//	istringstream iss(str);
//	for (auto it = istream_iterator<string>(iss); it != istream_iterator<string>() && n < N; ++it, ++n)
//	{
//		arr[n] = *it;
//		count++;
//	}
//	return count;
//}
//
//void main()
//{
//	map <string, vector<string>> hash;
//	ifstream input("files/markov.txt");
//	string row;
//	string arr[100];
//	int rowSize;
//	string FirstWord, SecondWord;
//
//	//It is hot.
//	//It likes apple!
//	while (input.peek() != -1)
//	{
//		getline(input, row);
//		rowSize = splitString(arr, row);
//		for (int i = 0; i < rowSize; i++)
//		{
//			FirstWord = arr[i];
//			SecondWord = arr[i + 1];
//			if (i == 0)
//			{
//				hash["__$"].push_back(FirstWord);
//			}
//			auto xx = hash.find(FirstWord);
//			if (xx == hash.end())
//			{
//				vector<string> s;
//				s.push_back(SecondWord);
//
//				pair<string, vector<string>> myPair(FirstWord, s);
//				hash.insert(myPair);
//			}
//			else
//			{
//				hash[FirstWord].push_back(SecondWord);
//			}
//			int g;
//			g = SecondWord.find(".") + SecondWord.find("!") + SecondWord.find("?");
//			if (g != -3)
//			{
//				break;
//			}
//		}
//	}
//
//	srand((unsigned)time(NULL));
//	int random1 = rand();
//	int random2 = rand();
//
//	auto it = hash.begin();
//	std::advance(it, rand() % hash.size());
//	string random_key = it->first;
//	//cout << hash.begin();
//	string name = "poptarts";
//	cout << name << "'s grade is " << hash[name, hash.begin()] << endl;
//
//
////}