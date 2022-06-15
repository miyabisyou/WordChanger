#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <vector>
#include <iomanip> 
#include <fstream>
#include <cstring>

#define LENGTH 1000		//���͂���镶��
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
	moji.push_back("�����ł�");
	moji.push_back("�ԈႢ�ł�");

	cout << "word_chenger�ł͌��t�𖳍�ׂȂЂ炪�Ȃ̗���ɕϊ����܂�" << endl << endl;

	int mode;
	while (1)
	{
		mode = modecc();
		switch(mode)
		{
			case 0:		//���t�̒ǉ�
				str_scanf(moji);
				break;
			case 1:		//���t�̍폜
				str_erase(moji);
				break;
			case 2:		//�ϊ�
				for (int i = 0; i < moji.size(); i++)
				{
					srand((unsigned int)strtod(moji[i]));
					change(&moji_c);
					cout << left << setw(15) << moji[i] << "  to  " << moji_c << endl;
				}
				cout << endl;
				break;
			case 3:		//�v���Z�b�g�̎g�p
				if (p == 0)
				{
					cout << "�v���Z�b�g���g�p���܂�" << endl;
					cout << "�ǉ��������t�͍폜����܂�����낵���ł����H�@YES -> 0, NO -> 1 : ";
					scanf("%d", &yn);
					if (yn == 0)
					{
						preset(moji);
						p = 1;
					}	
					cout << endl;
				}
				else
					cout << "�v���Z�b�g�͎g�p�ς݂ł�" << endl << endl;
				break;
			case 4:		//�ǂݍ���
				input(moji);
				break;
			case 5:		//�ۑ�
				output(moji);
				break;
			case 6:		//�Z�[�u�f�[�^�̍폜
				delete_save();
				break;
			case 7:		//�ꊇ�폜
				allclear(moji);
				p = 0;
				break;
			case 8:
				setparam();
				break;
			default:
				cout << "word_chenger���I�����܂�" << endl;
				cout << "��낵���ł����H�@YES -> 0, NO -> 1 : ";
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
	cout << "�p�����[�^�̐ݒ���s���܂�" << endl;
	while (f != 1)
	{
		cout << "���݂̃p�����[�^�@�F�@max = " << param::max << ", min = " << param::min << ", seed = " << param::seed << endl;
		cout << "max(�ϊ���̕����ő吔)    -> 0" << endl << "min(�ϊ���̕����ŏ���)    -> 1" << endl << "seed(�Q�[�����E���h�̕ύX) -> 2" << endl << "exit(�I��) -> 3" << endl;
		cout << "--------------------------------------------------------" << endl;
		cout << "0�`3����͂��Ă������� : ";
		scanf("%d", &ff);
		if (ff == 0)
		{
			cout << "max(�ϊ���̕����ő吔)�̕ύX���s���܂�" << endl;
			cout << "max�̒l����͂��Ă������� : ";
			scanf("%d", &tmp);
			cout << "�ύX�O : " << param::max << ", �ύX�� : " << tmp << endl;
			cout << "���肵�܂����H�@YES -> 0, NO -> 1 : ";
			scanf("%d", &yn);
			if (yn == 0)
			{
				param::max = tmp;
				cout << "�ύX����܂���" << endl << endl;
			}
		}
		else if (ff == 1)
		{
			cout << "min(�ϊ���̕�������)�̕ύX���s���܂�" << endl;
			cout << "min�̒l����͂��Ă������� : ";
			scanf("%d", &tmp);
			cout << "�ύX�O : " << param::min << ", �ύX�� : " << tmp << endl;
			cout << "���肵�܂����H�@YES -> 0, NO -> 1 : ";
			scanf("%d", &yn);
			if (yn == 0)
			{
				param::min = tmp;
				cout << "�ύX����܂���" << endl << endl;
			}
		}
		else if (ff == 2)
		{
			cout << "seed(�Q�[�����E���h�̕ύX)�̕ύX���s���܂�" << endl;
			cout << "seed�l����͂��Ă������� : ";
			scanf("%d", &tmp);
			cout << "�ύX�O : " << param::seed << ", �ύX�� : " << tmp << endl;
			cout << "���肵�܂����H�@YES -> 0, NO -> 1 : ";
			scanf("%d", &yn);
			if (yn == 0)
			{
				param::seed = tmp;
				cout << "�ύX����܂���" << endl << endl;
			}
		}
		else if (ff == 3)
		{
			if (param::min <= param::max)
			{
				cout << "�p�����[�^�ݒ���I�����܂�" << endl;
				cout << "��낵���ł����H�@YES -> 0, NO -> 1 : ";
				scanf("%d", &yn);
				if (yn == 0)
				{
					f = 1;
				}
				cout << endl;
			}
			else
			{
				cout << "min�̒l��max�̒l�������Ă��邽�ߏI���ł��܂���" << endl;
				cout << "min�̒l��������max�̒l��ύX���Ă�������" << endl << endl;
			}
		}
		else
			cout << "0�`3�œ��͂��s���Ă�������" << endl << endl;
		
	}
}

void str_scanf(vector <string> & moji)
{
	cout <<"���͂��I������ꍇ��0����͂��Ă�������" << endl << "---------------------------------------" << endl;
	char temp[LENGTH];
	while(1)
	{
		memset(temp, 0, sizeof(temp));
		cout << "���t����͂��Ă������� : ";
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
	cout << "�폜���I������ꍇ��0����͂��Ă�������" << endl << "---------------------------------------" << endl;
	while(1)
	{
		cout << "�����������������݂̌��t�o�^��񁁁�����������" << endl;

		for (unsigned int i = 0; i < moji.size(); i++)
		{
			cout << setw(3) << i + 1 << "�Ԗ� : " << moji[i] << endl;
		}
		cout << "�폜����ԍ�����͂��Ă������� : ";
		scanf("%d", &x);
		if (x == 0)
			break;
		if (x >= 1 && x <= moji.size())
		{
			cout << setw(3) << x << "�Ԗ� : " << moji[x - 1] << endl;
			cout<<"�{���ɍ폜���܂����H  YES -> 0, NO -> 1 : ";
			scanf("%d", &yn);
			if (yn == 0)
			{
				moji.erase(moji.begin() + x -1);
				cout << "�폜���܂���" << endl << endl;
			}
		}
		else
			cout << "�������l����͂��Ă�������" << endl << endl;
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
	int length;		//�ϊ���̕�����������
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
	temp[0] = "�����ł�";
	temp[1] = "�ԈႢ�ł�";
	temp[2] = "1��";
	temp[3] = "�؍�";
	temp[4] = "��";
	temp[5] = "�ۂ�";
	temp[6] = "�����ЂƂ�";
	temp[7] = "�Ȃɂ��Ȃ�";
	temp[8] = "����";
	temp[9] = "�E��";
	temp[10] = "�ȒP";
	temp[11] = "��ɂ�����";
	temp[12] = "������";
	temp[13] = "���Ȃ�";
	temp[14] = "���R��";
	temp[15] = "�S��";
	temp[16] = "��";
	temp[17] = "2��";
	temp[18] = "����";
	temp[19] = "���Ȃ���";
	temp[20] = "������";
	moji = temp;
}

int modecc(void)
{
	while (1)
	{
		int tmp;
		cout << "MODE��I�����Ă�������" << endl;
		cout << "���t�̒ǉ�        -> 0" << endl << "���t�̍폜        -> 1" << endl << "�ϊ�              -> 2" << endl << "�v���Z�b�g�̎g�p  -> 3" << endl << "�ǂݍ���          -> 4" << endl << "�ۑ�              -> 5" << endl << "�Z�[�u�f�[�^�̍폜-> 6" << endl << "�ꊇ�폜          -> 7" << endl << "�p�����[�^�ύX    -> 8" << endl << "exit(�I��)        -> 0~8�ȊO�̐���" << endl;
		cout << "=====================================" << endl;
		cout << "��������͂��Ă������� : ";
		scanf("%d", &tmp);
		cout << endl;
		return tmp;
	}
}

void allclear(vector <string> & moji)
{
	int yn;
	cout << "1, 2�Ԗڂ̐��ۂ̒P��͎c��܂�" << endl << "�{���Ɉꊇ�폜���܂����H  YES -> 0, NO -> 1 : ";
	scanf("%d", &yn);
	if (yn == 0)
	{
		moji.clear();
		cout << "�폜���܂���" << endl << endl;
	}
	moji.push_back("�����ł�");
	moji.push_back("�ԈႢ�ł�");
}

void input(vector <string> & moji)
{
	ifstream savedata;
	vector<string> filename;
	string name, str, temp;;
	int x, yn;
	savedata.open("./../data/save.data");
	if (savedata.fail()) {
		cerr << "�Z�[�u�f�[�^���J���܂���" << endl;
		cout << "---------------------------------------" << endl;
		return;
	}
	while (getline(savedata, name))
	{
		filename.push_back(name);
	}
	cout << "�Z�[�u�f�[�^����p�����[�^����ь������ǂݍ��݂܂�(���݂̏��͍폜����܂�)" << endl << "�ǂݍ��݂��I������ꍇ��0����͂��Ă�������" << endl;
	cout << "�����������������݂̃Z�[�u�f�[�^��������������" << endl;
	for (unsigned int i = 0; i < filename.size(); i++)
	{
		cout << setw(3) << i + 1 << "�Ԗ� : " << filename[i] << endl;
	}
	cout << "---------------------------------------" << endl << endl;
	
	while(1)
	{
		cout << "�ǂݍ��ރZ�[�u�f�[�^�̔ԍ�����͂��Ă�������(0�ŏI��) : ";
		scanf("%d", &x);
		if (x == 0)
			break;
		else if (x >= 1 && x <= filename.size())
		{
			cout << setw(3) << x << "�Ԗ� : " << filename[x - 1] << "��ǂݍ��݂܂����H  YES -> 0, NO -> 1 : "<< endl;
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
				cout << "�t�@�C����ǂݍ��݂܂���" << endl;
				break;
			}
		}
		else
			cout << "�������l����͂��Ă�������" << endl << endl;
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
		cerr << "�Z�[�u�f�[�^���J���܂���" << endl;
		cout << "---------------------------------------" << endl;
	}
	while (getline(savedata, name))
	{
		filename.push_back(name);
	}
	savedata.close();
	cout << "�Z�[�u�f�[�^�Ɍ��݂̃p�����[�^����ь������ۑ����܂�" << endl << "�ǂݍ��݂��I������ꍇ��0����͂��Ă�������" << endl;
	cout << "�����������������݂̃Z�[�u�f�[�^��������������" << endl;
	for (unsigned int i = 0; i < filename.size(); i++)
	{
		cout << setw(3) << i + 1 << "�Ԗ� : " << filename[i] << endl;
	}
	cout << "---------------------------------------" << endl << endl;
	
	while(1)
	{
		cout << "�㏑������Z�[�u�f�[�^�̔ԍ�����͂��Ă�������(0�ŏI��). �V�K�ۑ��̏ꍇ��" << filename.size() + 1 << "����͂��Ă������� : ";
		scanf("%d", &x);
		if (x == 0)
			break;
		else if (x >= 1 && x <= filename.size())
		{
			cout << setw(3) << x << "�Ԗ� : " << filename[x - 1] << "�ɏ㏑�����܂����H  YES -> 0, NO -> 1 : "<< endl;
			scanf("%d", &yn);
			if (yn == 0)
			{
				ofstream csv_data("./../data/" + filename[x - 1] +".csv");
				if (!csv_data)
				{
					cerr << "dose not open the csv file." << endl;
					break;
				}
				csv_data << "parameter �F max = " << param::max << ", min = " << param::min << ", seed = " << param::seed << endl;
				for (unsigned int i = 0; i < moji.size(); i++)
				{
					srand((unsigned int)strtod(moji[i]));
					change(&str);
					csv_data << right << setw(3) <<i + 1 << "�Ԗ�, " << left << setw(15) << moji[i] << ", " << str << endl;
				}
				cout << "�ۑ����܂���" << endl;
				break;
			}
		}
		else if(x == filename.size() + 1)
		{
			cout << "�V�K�ۑ�����t�@�C���̖��O����͂��Ă������� : ";
			scanf("%s", temp);
			if (temp[0] == 48)
				break;
			cout << temp <<"�ł�낵���ł����H  YES -> 0, NO -> 1 : ";
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
				csv_data << "parameter �F max = " << param::max << ", min = " << param::min << ", seed = " << param::seed << endl;
				for (unsigned int i = 0; i < moji.size(); i++)
				{
					srand((unsigned int)strtod(moji[i]));
					change(&str);
					csv_data << right << setw(3) <<i + 1 << "�Ԗ�, " << left << setw(15) << moji[i] << ", " << str << endl;
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
				cout << "�ۑ����܂���" << endl;
				break;
			}
		}
		else
			cout << "�������l����͂��Ă�������" << endl << endl;
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
		cerr << "�Z�[�u�f�[�^���J���܂���" << endl;
		cout << "---------------------------------------" << endl;
		return;
	}
	while (getline(savedata, name))
	{
		filename.push_back(name);
	}
	savedata.close();
	cout << "�Z�[�u�f�[�^���폜���܂�" << endl << "�I������ꍇ��0����͂��Ă�������" << endl;
	cout << "�����������������݂̃Z�[�u�f�[�^��������������" << endl;
	for (unsigned int i = 0; i < filename.size(); i++)
	{
		cout << setw(3) << i + 1 << "�Ԗ� : " << filename[i] << endl;
	}
	cout << "---------------------------------------" << endl << endl;
	
	while(1)
	{
		cout << "�폜����Z�[�u�f�[�^�̔ԍ�����͂��Ă�������(0�ŏI��) : ";
		scanf("%d", &x);
		if (x == 0)
			break;
		else if (x >= 1 && x <= filename.size())
		{
			cout << setw(3) << x << "�Ԗ� : " << filename[x - 1] << "���폜���܂����H  YES -> 0, NO -> 1 : " << endl;
			scanf("%d", &yn);
			if (yn == 0)
			{
				savedata.open("./../data/save.data", ios::out);
				if (savedata.fail()) {
					cerr << "�Z�[�u�f�[�^���J���܂���" << endl;
					cout << "---------------------------------------" << endl;
					return;
				}
				string tmp = "./../data/" + filename[x -1] + ".csv";
				if(remove(tmp.c_str()))
				{
					cout << filename[x - 1] <<  "�̍폜�Ɏ��s���܂���" << endl << endl;
				}

				filename.erase(filename.begin() + x - 1);
				for(unsigned int i = 0; i < filename.size(); i++)
					savedata << filename[i] << endl;
				cout << "�폜���܂���" << endl << endl;
				break;
			}
		}
		else
			cout << "�������l����͂��Ă�������" << endl << endl;
	} 
	cout << "---------------------------------------" << endl;
}