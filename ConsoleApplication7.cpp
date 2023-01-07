
#include <iostream>
#include <cctype>
#include <cstring>
#include <list>
#include <iostream>

using namespace std;

list<string> Return_max_words_list(string phrase)
{
	list<string> Max_words;

	int Word_ending_index = 0;
	int Word_start_index = 0;
	int Current_lenght = 0;
	int Max_lenght = 0;

	while (Word_ending_index <= phrase.length())
	{
		if (phrase[Word_ending_index] != char(0) && phrase[Word_ending_index] != char(32) && phrase[Word_ending_index] != char(63) && phrase[Word_ending_index] != char(46) && phrase[Word_ending_index] != char(44))
		{
			Word_ending_index++;
		}
		else
		{
			Current_lenght = Word_ending_index - Word_start_index;

			if (Current_lenght > Max_lenght)
			{
				Max_words.clear();
				Max_words.push_back(phrase.substr(Word_start_index, Current_lenght));

				Max_lenght = Current_lenght;
			}
			else if(Current_lenght == Max_lenght)
			{
				bool repeated = false;

				for(list<string>::iterator i = Max_words.begin(); i != Max_words.end();i++)
				{
					if (*i == phrase.substr(Word_start_index, Current_lenght))
					{
						repeated = true;
						break;
					}
				}
				if(repeated == false)
				{
					Max_words.push_back(phrase.substr(Word_start_index, Current_lenght));
				}
			}
			Word_ending_index++;
			Word_start_index = Word_ending_index;
		}
	}
	return Max_words;
}

void show_list(list<string> My_list)
{
	for (list<string>::iterator i = My_list.begin(); i != My_list.end(); i++)
	{
		cout << *i << "|";
	}
}

int main()
{
	string phrase = "Un dia normal de programacion online, es decir desarrolloss ";

	list<string> Test_list = Return_max_words_list(phrase);

	show_list(Test_list);
}
