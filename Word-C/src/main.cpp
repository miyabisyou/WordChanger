#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <iomanip> 
#include <fstream>
#include <cstring>

#define LENGTH 1000		//入力される文字
#define MAX 7
#define MIN 2
#define SEED 0

using namespace std;

namespace param
{
	unsigned int max = MAX;
	unsigned int min = MIN;
	unsigned int seed = SEED;
}

void setparam(void);
void str_scanf(vector <string> & moji);
void str_erase(vector <string> & moji);
double strtod(const string & moji);
void change(string *moji);
void preset(vector <string> & moji);
int modecc(void);
void allclear(vector <string> & moji);
void input(vector <string> & moji);
void output(vector <string> & moji);
void delete_save();

int main(void)
{
	vector <string> moji;
	string moji_c;
	int yn, p = 0;
	moji.push_back("正解です");
	moji.push_back("間違いです");

	cout << "word_chengerでは言葉を無作為なひらがなの羅列に変換します" << endl << endl;

	int mode;
	while (1)
	{
		mode = modecc();
		switch(mode)
		{
			case 0:		//言葉の追加
				str_scanf(moji);
				break;
			case 1:		//言葉の削除
				str_erase(moji);
				break;
			case 2:		//変換
				for (int i = 0; i < moji.size(); i++)
				{
					srand((unsigned int)strtod(moji[i]));
					change(&moji_c);
					cout << left << setw(15) << moji[i] << "  to  " << moji_c << endl;
				}
				cout << endl;
				break;
			case 3:		//プリセットの使用
				if (p == 0)
				{
					cout << "プリセットを使用します" << endl;
					cout << "追加した言葉は削除されますがよろしいですか？　YES -> 0, NO -> 1 : ";
					scanf("%d", &yn);
					if (yn == 0)
					{
						preset(moji);
						p = 1;
					}	
					cout << endl;
				}
				else
					cout << "プリセットは使用済みです" << endl << endl;
				break;
			case 4:		//読み込み
				input(moji);
				break;
			case 5:		//保存
				output(moji);
				break;
			case 6:		//セーブデータの削除
				delete_save();
				break;
			case 7:		//一括削除
				allclear(moji);
				p = 0;
				break;
			case 8:
				setparam();
				break;
			default:
				cout << "word_chengerを終了します" << endl;
				cout << "よろしいですか？　YES -> 0, NO -> 1 : ";
				scanf("%d", &yn);
				if (yn == 0)
				{
					exit(0);
				}
				cout << endl;
		}
	}
}

void setparam(void)
{
	int f = 0, ff, yn, tmp;
	cout << "パラメータの設定を行います" << endl;
	while (f != 1)
	{
		cout << "現在のパラメータ　：　max = " << param::max << ", min = " << param::min << ", seed = " << param::seed << endl;
		cout << "max(変換後の文字最大数)    -> 0" << endl << "min(変換後の文字最少数)    -> 1" << endl << "seed(ゲームラウンドの変更) -> 2" << endl << "exit(終了) -> 3" << endl;
		cout << "--------------------------------------------------------" << endl;
		cout << "0～3を入力してください : ";
		scanf("%d", &ff);
		if (ff == 0)
		{
			cout << "max(変換後の文字最大数)の変更を行います" << endl;
			cout << "maxの値を入力してください : ";
			scanf("%d", &tmp);
			cout << "変更前 : " << param::max << ", 変更後 : " << tmp << endl;
			cout << "決定しますか？　YES -> 0, NO -> 1 : ";
			scanf("%d", &yn);
			if (yn == 0)
			{
				param::max = tmp;
				cout << "変更されました" << endl << endl;
			}
		}
		else if (ff == 1)
		{
			cout << "min(変換後の文字少数)の変更を行います" << endl;
			cout << "minの値を入力してください : ";
			scanf("%d", &tmp);
			cout << "変更前 : " << param::min << ", 変更後 : " << tmp << endl;
			cout << "決定しますか？　YES -> 0, NO -> 1 : ";
			scanf("%d", &yn);
			if (yn == 0)
			{
				param::min = tmp;
				cout << "変更されました" << endl << endl;
			}
		}
		else if (ff == 2)
		{
			cout << "seed(ゲームラウンドの変更)の変更を行います" << endl;
			cout << "seed値を入力してください : ";
			scanf("%d", &tmp);
			cout << "変更前 : " << param::seed << ", 変更後 : " << tmp << endl;
			cout << "決定しますか？　YES -> 0, NO -> 1 : ";
			scanf("%d", &yn);
			if (yn == 0)
			{
				param::seed = tmp;
				cout << "変更されました" << endl << endl;
			}
		}
		else if (ff == 3)
		{
			if (param::min <= param::max)
			{
				cout << "パラメータ設定を終了します" << endl;
				cout << "よろしいですか？　YES -> 0, NO -> 1 : ";
				scanf("%d", &yn);
				if (yn == 0)
				{
					f = 1;
				}
				cout << endl;
			}
			else
			{
				cout << "minの値がmaxの値を上回っているため終了できません" << endl;
				cout << "minの値もしくはmaxの値を変更してください" << endl << endl;
			}
		}
		else
			cout << "0～3で入力を行ってください" << endl << endl;
		
	}
}

void str_scanf(vector <string> & moji)
{
	cout <<"入力を終了する場合は0を入力してください" << endl << "---------------------------------------" << endl;
	char temp[LENGTH];
	while(1)
	{
		memset(temp, 0, sizeof(temp));
		cout << "言葉を入力してください : ";
		scanf("%s", temp);
		if (temp[0] == 48)
			break;
		moji.push_back(temp);
	} 
	cout << "---------------------------------------" << endl;
}

void str_erase(vector <string> & moji)
{
	int x, yn;
	cout << "削除を終了する場合は0を入力してください" << endl << "---------------------------------------" << endl;
	while(1)
	{
		cout << "＝＝＝＝＝＝＝現在の言葉登録情報＝＝＝＝＝＝＝" << endl;

		for (unsigned int i = 0; i < moji.size(); i++)
		{
			cout << setw(3) << i + 1 << "番目 : " << moji[i] << endl;
		}
		cout << "削除する番号を入力してください : ";
		scanf("%d", &x);
		if (x == 0)
			break;
		if (x >= 1 && x <= moji.size())
		{
			cout << setw(3) << x << "番目 : " << moji[x - 1] << endl;
			cout<<"本当に削除しますか？  YES -> 0, NO -> 1 : ";
			scanf("%d", &yn);
			if (yn == 0)
			{
				moji.erase(moji.begin() + x -1);
				cout << "削除しました" << endl << endl;
			}
		}
		else
			cout << "正しい値を入力してください" << endl << endl;
	} 
	cout << "---------------------------------------" << endl;
}

double strtod(const string & moji)
{
	double sum = 0;
	for (unsigned int i = 0; i < moji.size(); i++)
	{
		sum += moji[i] * pow(10.0, (double)i);
	}
	return sum + param::seed;
}

void change(string *moji)
{
	int length;		//変換後の文字数を決定
	length = param::min + rand() % (param::max - param::min + 1);

	moji->clear();
	for (int i = 0; i < length * 2; i++)
	{
		moji->push_back(0x82);
		moji->push_back((-97 + rand() % 83));
		i++;
	}
}

void preset(vector <string> & moji)
{
	vector<string> temp;
	temp.resize(21);
	temp[0] = "正解です";
	temp[1] = "間違いです";
	temp[2] = "1つ";
	temp[3] = "木材";
	temp[4] = "鍵";
	temp[5] = "丸い";
	temp[6] = "もうひとつ";
	temp[7] = "なにもない";
	temp[8] = "左の";
	temp[9] = "右の";
	temp[10] = "簡単";
	temp[11] = "上にあげる";
	temp[12] = "両方の";
	temp[13] = "しない";
	temp[14] = "自然の";
	temp[15] = "全部";
	temp[16] = "手";
	temp[17] = "2つ";
	temp[18] = "持つ";
	temp[19] = "やりなおす";
	temp[20] = "金属の";
	moji = temp;
}

int modecc(void)
{
	while (1)
	{
		int tmp;
		cout << "MODEを選択してください" << endl;
		cout << "言葉の追加        -> 0" << endl << "言葉の削除        -> 1" << endl << "変換              -> 2" << endl << "プリセットの使用  -> 3" << endl << "読み込み          -> 4" << endl << "保存              -> 5" << endl << "セーブデータの削除-> 6" << endl << "一括削除          -> 7" << endl << "パラメータ変更    -> 8" << endl << "exit(終了)        -> 0~8以外の数字" << endl;
		cout << "=====================================" << endl;
		cout << "数字を入力してください : ";
		scanf("%d", &tmp);
		cout << endl;
		return tmp;
	}
}

void allclear(vector <string> & moji)
{
	int yn;
	cout << "1, 2番目の正否の単語は残ります" << endl << "本当に一括削除しますか？  YES -> 0, NO -> 1 : ";
	scanf("%d", &yn);
	if (yn == 0)
	{
		moji.clear();
		cout << "削除しました" << endl << endl;
	}
	moji.push_back("正解です");
	moji.push_back("間違いです");
}

void input(vector <string> & moji)
{
	ifstream savedata;
	vector<string> filename;
	string name, str, temp;;
	int x, yn;
	savedata.open("./../data/save.data");
	if (savedata.fail()) {
		cerr << "セーブデータが開けません" << endl;
		cout << "---------------------------------------" << endl;
		return;
	}
	while (getline(savedata, name))
	{
		filename.push_back(name);
	}
	cout << "セーブデータからパラメータおよび言語情報を読み込みます(現在の情報は削除されます)" << endl << "読み込みを終了する場合は0を入力してください" << endl;
	cout << "＝＝＝＝＝＝＝現在のセーブデータ＝＝＝＝＝＝＝" << endl;
	for (unsigned int i = 0; i < filename.size(); i++)
	{
		cout << setw(3) << i + 1 << "番目 : " << filename[i] << endl;
	}
	cout << "---------------------------------------" << endl << endl;
	
	while(1)
	{
		cout << "読み込むセーブデータの番号を入力してください(0で終了) : ";
		scanf("%d", &x);
		if (x == 0)
			break;
		else if (x >= 1 && x <= filename.size())
		{
			cout << setw(3) << x << "番目 : " << filename[x - 1] << "を読み込みますか？  YES -> 0, NO -> 1 : "<< endl;
			scanf("%d", &yn);
			if (yn == 0)
			{
				ifstream csv_data;
				csv_data.open("./../data/" + filename[x - 1] + ".csv");
				if (csv_data.fail()) {
					cerr << "dose not open the csv file." << endl;
					break;
				}

				moji.clear();
				getline(csv_data, str);
				if (str.find("max = ") != std::string::npos)
				{
					temp = str.substr(str.find("max = ") + 6);
					param::max = stoi(temp.substr(0, temp.find(",")));
				}
				if (str.find("min = ") != std::string::npos)
				{
					temp = str.substr(str.find("min = ") + 6);
					param::min = stoi(temp.substr(0, temp.find(",")));
				}
				if (str.find("seed = ") != std::string::npos)
				{
					param::seed = stoi(str.substr(str.find("seed = ") + 7));
				}
				while (getline(csv_data, str))
				{
					temp = str.substr(str.find(", ") + 2);
					moji.push_back(temp.substr(0, temp.find(" ")));
				}
				cout << "ファイルを読み込みました" << endl;
				break;
			}
		}
		else
			cout << "正しい値を入力してください" << endl << endl;
	} 
	cout << "---------------------------------------" << endl;
}

void output(vector <string> & moji)
{
	ifstream savedata;
	vector<string> filename;
	string name, str;
	char temp[100];
	int x, yn;
	savedata.open("./../data/save.data");
	if (savedata.fail()) {
		cerr << "セーブデータが開けません" << endl;
		cout << "---------------------------------------" << endl;
	}
	while (getline(savedata, name))
	{
		filename.push_back(name);
	}
	savedata.close();
	cout << "セーブデータに現在のパラメータおよび言語情報を保存します" << endl << "読み込みを終了する場合は0を入力してください" << endl;
	cout << "＝＝＝＝＝＝＝現在のセーブデータ＝＝＝＝＝＝＝" << endl;
	for (unsigned int i = 0; i < filename.size(); i++)
	{
		cout << setw(3) << i + 1 << "番目 : " << filename[i] << endl;
	}
	cout << "---------------------------------------" << endl << endl;
	
	while(1)
	{
		cout << "上書きするセーブデータの番号を入力してください(0で終了). 新規保存の場合は" << filename.size() + 1 << "を入力してください : ";
		scanf("%d", &x);
		if (x == 0)
			break;
		else if (x >= 1 && x <= filename.size())
		{
			cout << setw(3) << x << "番目 : " << filename[x - 1] << "に上書きしますか？  YES -> 0, NO -> 1 : "<< endl;
			scanf("%d", &yn);
			if (yn == 0)
			{
				ofstream csv_data("./../data/" + filename[x - 1] +".csv");
				if (!csv_data)
				{
					cerr << "dose not open the csv file." << endl;
					break;
				}
				csv_data << "parameter ： max = " << param::max << ", min = " << param::min << ", seed = " << param::seed << endl;
				for (unsigned int i = 0; i < moji.size(); i++)
				{
					srand((unsigned int)strtod(moji[i]));
					change(&str);
					csv_data << right << setw(3) <<i + 1 << "番目, " << left << setw(15) << moji[i] << ", " << str << endl;
				}
				cout << "保存しました" << endl;
				break;
			}
		}
		else if(x == filename.size() + 1)
		{
			cout << "新規保存するファイルの名前を入力してください : ";
			scanf("%s", temp);
			if (temp[0] == 48)
				break;
			cout << temp <<"でよろしいですか？  YES -> 0, NO -> 1 : ";
			scanf("%d", &yn);
			if (yn == 0)
			{
				name = temp;
				ofstream csv_data("./../data/" + name +".csv");
				if (!csv_data)
				{
					cerr << "dose not open the csv file." << endl;
					break;
				}
				csv_data << "parameter ： max = " << param::max << ", min = " << param::min << ", seed = " << param::seed << endl;
				for (unsigned int i = 0; i < moji.size(); i++)
				{
					srand((unsigned int)strtod(moji[i]));
					change(&str);
					csv_data << right << setw(3) <<i + 1 << "番目, " << left << setw(15) << moji[i] << ", " << str << endl;
				}
				filename.push_back(name);
				ofstream save;
				save.open("./../data/save.data", ios_base::app);
				if (!save)
				{
					cerr << "dose not open the save file." << endl;
					break;
				}
				save << filename.back() << endl;
				cout << "保存しました" << endl;
				break;
			}
		}
		else
			cout << "正しい値を入力してください" << endl << endl;
	} 
	cout << "---------------------------------------" << endl;
}

void delete_save()
{
	fstream savedata;
	vector<string> filename;
	string name, str;
	char temp[100];
	int x, yn;
	savedata.open("./../data/save.data");
	if (savedata.fail()) {
		cerr << "セーブデータが開けません" << endl;
		cout << "---------------------------------------" << endl;
		return;
	}
	while (getline(savedata, name))
	{
		filename.push_back(name);
	}
	savedata.close();
	cout << "セーブデータを削除します" << endl << "終了する場合は0を入力してください" << endl;
	cout << "＝＝＝＝＝＝＝現在のセーブデータ＝＝＝＝＝＝＝" << endl;
	for (unsigned int i = 0; i < filename.size(); i++)
	{
		cout << setw(3) << i + 1 << "番目 : " << filename[i] << endl;
	}
	cout << "---------------------------------------" << endl << endl;
	
	while(1)
	{
		cout << "削除するセーブデータの番号を入力してください(0で終了) : ";
		scanf("%d", &x);
		if (x == 0)
			break;
		else if (x >= 1 && x <= filename.size())
		{
			cout << setw(3) << x << "番目 : " << filename[x - 1] << "を削除しますか？  YES -> 0, NO -> 1 : " << endl;
			scanf("%d", &yn);
			if (yn == 0)
			{
				savedata.open("./../data/save.data", ios::out);
				if (savedata.fail()) {
					cerr << "セーブデータが開けません" << endl;
					cout << "---------------------------------------" << endl;
					return;
				}
				string tmp = "./../data/" + filename[x -1] + ".csv";
				if(remove(tmp.c_str()))
				{
					cout << filename[x - 1] <<  "の削除に失敗しました" << endl << endl;
				}

				filename.erase(filename.begin() + x - 1);
				for(unsigned int i = 0; i < filename.size(); i++)
					savedata << filename[i] << endl;
				cout << "削除しました" << endl << endl;
				break;
			}
		}
		else
			cout << "正しい値を入力してください" << endl << endl;
	} 
	cout << "---------------------------------------" << endl;
}