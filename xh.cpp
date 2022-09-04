#include<iostream>
using namespace std;
#include<string>
#define MAX 1000
void showmenu();

struct Person 
{
	string p_name;
	int p_phone;
	string p_address;
};

struct lu
{
	struct Person personArray[MAX];
	int n;
};

void clearperson(lu *l)
{
	l->n = 0;
	cout<<"已清空" << endl;
	system("pause");
	system("cls");
}

void showperson(lu* l)
{
	if (l->n == 0)
	{
		cout<<"空的呢！快来添加吧" << endl;
	}
	int i;

	for (i = 0; i < l->n; i++)
	{
		cout<<i+1<<". " << "姓名:" << l->personArray[i].p_name << " | 电话:" << l->personArray[i].p_phone << " | 住址:" << l->personArray[i].p_address << endl;
	}
	system("pause");
	system("cls");
}

void deleteperson(lu* l)
{
	cout << "请输宁要删除的联系人" << endl;
	string d_name;
	cin >> d_name;
	int i,j;

	for (i = 0; i <= l->n; i++)
	{
		if (d_name == l->personArray[i].p_name)
		{
			for (j = i; j < l->n; j++)
			{
				l->personArray[j] = l->personArray[j + 1];
			}
			l->n--;
			cout<<"删除成功" << endl;
		}
	}
	system("pause");
	system("cls");
}

void modiperson(lu* l)
{
	cout << "请输宁要删除的联系人" << endl;
	string m_name;
	cin >> m_name;
	int i, j;

	for (i = 0; i <= l->n; i++)
	{
		if (m_name == l->personArray[i].p_name)
		{
			cout << "请输入姓名" << endl;
			string name;
			cin >> name;
			l->personArray[i].p_name = name;

			cout << "请输入电话" << endl;
			int phone;
			cin >> phone;
			l->personArray[i].p_phone = phone;

			cout << "请输入住址" << endl;
			string adress;
			cin >> adress;
			l->personArray[i].p_address = adress;
			cout << "修改联系人成功" << endl;
			system("pause");
			system("cls");
		}
	}

}

void findperson(lu *l)
{
	cout<<"请输宁要查找的联系人" << endl;
	string find_name;
	cin >> find_name;
	int i;

	for (i = 0; i <= l->n; i++)
	{
		if (find_name == l->personArray[i].p_name)
		{
			cout <<l->n+1<< ". 姓名:" << l->personArray[i].p_name << " | 电话:" << l->personArray[i].p_phone << " | 住址:" << l->personArray[i].p_address << endl;
		}
	}
	system("pause");
	system("cls");
}

void addperson(lu *l)
{
	cout << "请输入姓名" << endl;
	string name;
	cin >> name;
	l->personArray[l->n].p_name = name;

	cout << "请输入电话" << endl;
	int phone;
	cin >> phone;
	l->personArray[l->n].p_phone = phone;

	cout << "请输入住址" << endl;
	string adress;
	cin >> adress;
	l->personArray[l->n].p_address = adress;

	cout << "添加联系人成功" << endl;
	system("pause");
	system("cls");

}

void showmenu()
{
	cout << "*通讯录系统*" << endl;
	cout << "*----------*" << endl;
	cout << "** 1.添加 **" << endl;
	cout << "** 2.显示 **" << endl;
	cout << "** 3.删除 **" << endl;
	cout << "** 4.查找 **" << endl;
	cout << "** 5.修改 **" << endl;
	cout << "** 6.清空 **" << endl;
	cout << "** 7.退出 **" << endl;
	cout << "**--------**" << endl;
	cout << "************" << endl;
};

int main()
{
	int putin;
	lu ll;
	ll.n = 0;   //个数

while (true)        //循环，除了7，都执行相应命令，7退出循环
{
	    showmenu();
        cout << "请输入你需要的执行的指令" << endl;
		cin >> putin;

	switch (putin)
	{
	case 1:
		cout << "** 1.您要添加 **" << endl;
		addperson(&ll);
		ll.n++;
		break;
	case 2:
		cout << "** 2.您要显示 **" << endl;
		showperson(& ll);
		break;
	case 3:
		cout << "** 3.您要删除 **" << endl;
		deleteperson(&ll);
		break;
	case 4:
		cout << "** 4.您要查找 **" << endl;
		findperson(&ll);
		break;
	case 5:
		cout << "** 5.您要修改 **" << endl;
		modiperson(&ll);
		break;
	case 6:
		cout << "** 6.您要清空 **" << endl;
		clearperson(&ll);
		break;
	default:
		cout<<"宁退出了，欢迎下次使用。" << endl;
		system("pause");
		return 0;
	}
	}
	system("pause");
	return 0;
}