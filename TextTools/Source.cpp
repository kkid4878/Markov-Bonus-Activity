#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <set>
#include <iomanip>

using namespace std;

class MarkovGeneration
{
public:
	template <size_t N>
	int splitString(string(&arr)[N], string str);

	int randomnumber(int min, int max);
	string MakeSentences(const map<string, vector<string>>& hash);

	void DoTheThing();
};


template <size_t N>
int MarkovGeneration::splitString(string(&arr)[N], string str)
{
	int count = 0;
	int n = 0;
	istringstream iss(str);
	for (auto it = istream_iterator<string>(iss); it != istream_iterator<string>() && n < N; ++it, ++n)
	{
		arr[n] = *it;
		count++;
	}
	return count;
}

int MarkovGeneration::randomnumber(int min, int max)
{
	return rand() % (max - min + 1) + min;
}


string MarkovGeneration::MakeSentences(const map<string, vector<string>>& hash)
{
	srand(time(nullptr));

	string sentence;
	string currentword = hash.at("__$").at(randomnumber(0, hash.at("__$").size() - 1));
	sentence = sentence + currentword;

	while (true)
	{
		auto it = hash.find(currentword);
		if (it == hash.end())
		{
			break;
		}
		const vector<string>& nextGroupOfWords = it->second;
		if (nextGroupOfWords.empty())
		{
			break;
		}
		string nextWord = nextGroupOfWords.at(randomnumber(0, nextGroupOfWords.size() - 1));
		sentence = sentence + " " + nextWord;
		currentword = nextWord;
		if (nextWord.find_first_of(".?!") != string::npos)
		{
			break;
		}
	}

	return sentence;
}

void MarkovGeneration::DoTheThing()
{
	map <string, vector<string>> hash;
	ifstream input("files/markov.txt");
	string row;
	string arr[100];
	int rowSize;
	string FirstWord, SecondWord;
	MarkovGeneration M;


	while (input.peek() != -1)
	{
		getline(input, row);
		rowSize = M.splitString(arr, row);
		for (int i = 0; i < rowSize; i++)
		{
			FirstWord = arr[i];
			SecondWord = arr[i + 1];
			if (i == 0)
			{
				hash["__$"].push_back(FirstWord);
			}
			auto xx = hash.find(FirstWord);
			if (xx == hash.end())
			{
				vector<string> s;
				s.push_back(SecondWord);

				pair<string, vector<string>> myPair(FirstWord, s);
				hash.insert(myPair);
			}
			else
			{
				hash[FirstWord].push_back(SecondWord);
			}
			int g;
			g = SecondWord.find(".") + SecondWord.find("!") + SecondWord.find("?");
			if (g != -3)
				break;
		}
	}
	int count = 0;
	//cout << std::setw(20);
	for (const auto& w : hash)
	{
		count++;
		cout << "Key Number " << setw(3) << count << ":  " << setw(10) << w.first << setw(10) << "  Has Values:  ";
		for (const auto& next : w.second)
		{
			cout << next << ", ";
		}
		cout << endl;
	}

	cout << endl;
	cout << "Here Are 10 Sentences: " << endl;

	int secondcounter = 0;
	set<string> generatedSentences;
	while (generatedSentences.size() < 10)
	{
		string sentence = M.MakeSentences(hash);
		if (generatedSentences.find(sentence) == generatedSentences.end())
		{
			secondcounter++;
			cout << setw(2) << secondcounter << ":  " << sentence << endl;
			generatedSentences.insert(sentence);
		}
	}

	while (1);
	//srand((unsigned)time(NULL));
	//int random1 = rand();
	//int random2 = rand();

	//cout << random1 << endl;
	//cout << random2 << endl;


	//auto it = hash.begin();
	//advance(it, rand() % hash.size());
	//string random_key = it->first;
	////cout << hash.begin();
	//string name = "poptarts";
	////cout << name << "'s grade is " << hash[name, hash.begin()] << endl;
	//

}

void main()
{
	MarkovGeneration M;
	M.DoTheThing();
}