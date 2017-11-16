// 16-3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::tolower;

const int NUM = 26;

const string wordlist[NUM] = { "apiary","beetle","cereal","danger","ensign","florid","garage","health",
"insult","jackal","keeper","loaner","manage","nonce","onset","plaid","quilt"
"remote","stolid","train","useful","valid","whence","xenon","yearn","zippy"
};

int main()
{
	srand(std::time(0));
	char play;
	cout << "Will you play a word game? <y/n>";
	cin >> play;
	play = tolower(play);
	while (play == 'y')
	{
		string target = wordlist[rand() % NUM];
		int length = target.length();
		string attempt(length, '-');//用-来填充attemp对象
		string badchars;
		int guesses = 6;
		cout << "Guess my secret word. It has " << length << " letters, and you guess one letter at a time. You get "
			<< guesses << " wrong guesses.\n";
		cout << "Your word: " << attempt << endl;
		while (guesses > 0 && attempt != target)
		{
			char letter;
			cout << "Guess a letter: ";
			cin >> letter;
			if (badchars.find(letter) != string::npos || attempt.find(letter) != string::npos)//如果在badchars或者attempt中找到了该字符，说明该字符已经被猜过了
			{
				cout << "You already guessed that. Try again.\n";
				continue;
			}
			int loc = target.find(letter);//找到letter在target中第一次出现的位置
			if (loc == string::npos)//如果target中不存在该字符，说明猜错了
			{
				cout << "Oh,bad guess!\n";
				--guesses;
				badchars += letter;//把已经猜过的字符放到badchars中
			}
			else
			{
				cout << "Good guess!\n";
				attempt[loc] = letter;
				//检查letter是否又再次出现了
				loc = target.find(letter, loc + 1);//从loc位置之后开始检查
				while (loc != string::npos)
				{
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);//向后边检查
				}
			}
			cout << "Your word: " << attempt << endl;
			if (attempt != target)
			{
				if (badchars.length() > 0)
				{
					cout << "Bad choices: " << badchars << endl;
				}
				cout << guesses << " bad guesses left\n";
			}
		}
		if (guesses > 0)
		{
			cout << "That's right!\n";
		}
		else
		{
			cout << "Sorry, the word is " << target << ".\n";
		}
		cout << "Will you play another? <y/n>";
		cin >> play;
		play = tolower(play);
	}
	cout << "Done！\n";
	return 0;
}