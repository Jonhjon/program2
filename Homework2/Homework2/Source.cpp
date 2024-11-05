#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;
typedef struct person {
	string name;
	string phone;
	string part;
	struct person* nextptr;
}person;
typedef struct Project {
	string Project_Name;//任務名稱
	string type[10];//任務類型
	string Project_statement;//任務說明
	string Importance;//重要性
	string Charge_man;//負責人
	string Schedule;//時程
	string current_progress;//進度
	string Mark;//註記;
	int typelenth;
	Project* nextptr;
}project;
typedef person* personptr;
typedef project* projectptr;
bool check_havepeople(string name, personptr startptr) {
	while (startptr)
	{
		if (startptr->name == name) 
			return true;
		else
			startptr = startptr->nextptr;
	}
	return false;
}
projectptr Add_project(projectptr startptr,string name,personptr people_startptr,string type[],int type_num) {
	projectptr New_Project = new project(),cur=startptr,pre=NULL;
	string temp_man;
	int temp_type = 0;
	New_Project->Project_Name = name;//把資料輸入到結構裡面
	New_Project->typelenth = 0;
	for (int i = 0; i < type_num; i++)
	{
		cout << i + 1 << ") " << type[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		while (true)
		{
			cout << "請輸入任務類型 (-1結束，最多十個) 第"<<i+1<<"個 : ";
			cin>> temp_type;
			if (temp_type == -1)
			{
				break;
			}
			if (temp_type < 1 || temp_type > type_num) {
				cout << "輸入錯誤，再輸入一次 : ";
			}
			else
			{
				New_Project->type[i] = type[temp_type - 1];
				break;
			}
		}
		if (temp_type == -1)
		{
			break;
		}
		New_Project->typelenth++;
	}
	getchar();
	cout << "請輸入任務說明 : ";
	getline(cin, New_Project->Project_statement);
	cout << "請輸入任務重要性 : ";
	getline(cin, New_Project->Importance);
	cout << "請輸入任務負責人 : ";
	while (true)
	{
		getline(cin, temp_man);
		if (check_havepeople(temp_man, people_startptr))
		{
			New_Project->Charge_man = temp_man;
			break;
		}
		else
		{
			cout << "沒有這個人，請再輸入一次 : ";
		}
	}
	//getchar();
	cout << "請輸入任務時程 : ";
	getline(cin, New_Project->Schedule);
	cout << "請輸入任務進程 : ";
	getline(cin, New_Project->current_progress);
	cout << "請輸入任務註記 : ";
	getline(cin, New_Project->Mark);

	if (startptr == NULL)//查看一開始有沒有東西，沒有就放在開頭，有就放到最後
	{
		startptr = New_Project;
	}
	else
	{
		cur = startptr;
		while (cur->nextptr)
		{
			cur = cur->nextptr;
		}
		cur->nextptr = New_Project;
	}
	return startptr;//回傳開頭
}
void Revise_project_detail(projectptr startptr,string Project_Name) {//修改任務的資訊
	projectptr cur = startptr, pre = NULL;
	while (cur)
	{
		if (cur->Project_Name == Project_Name)//如果有此任務就進行修改
		{
			cout << "請輸入新的任務說明 : ";
			getline(cin, cur->Project_statement);
			cout << "請輸入新的任務重要性 : ";
			getline(cin, cur->Importance);
			cout << "請輸入新的任務負責人 : ";
			getline(cin, cur->Charge_man);
			cout << "請輸入新的任務時程 : ";
			getline(cin, cur->Schedule);
			cout << "請輸入新的任務進程 : ";
			getline(cin, cur->current_progress);
			cout << "請輸入新的任務註記 : ";
			getline(cin, cur->Mark);
			return;
		}
		cur = cur->nextptr;
	}
	if (cur == NULL)//查到最後都沒有就輸出 查無此人
	{
		cout << "查無此任務!!!!\n";
	}
}
void Revise_project_type(projectptr startptr, string Project_Name)
{
	projectptr cur = startptr, pre = NULL;
	string temp_type;
	while (cur)
	{
		if (cur->Project_Name == Project_Name)//找到此任務就修改此任務的類型
		{
			cur->typelenth = 0;
			for (int i = 0; i < 10; i++)
			{
				cout << "請輸入任務類型 (-1結束): ";
				getline(cin, temp_type);
				if (temp_type == "-1" || i == 9)
				{
					break;
				}
				cur->type[i] = temp_type;
				cur->typelenth++;
			}
			return;
		}
		cur = cur->nextptr;
	}
	if (cur == NULL)//沒有則輸出無
	{
		cout << "查無此任務!!!!\n";
	}
}
projectptr Delete_Project(projectptr startptr ,string Project_Name) {
	projectptr cur = startptr, pre = NULL;
	if (startptr == NULL) {//查看list有沒有東西
		cout << "沒有成員!!!\n";
		return startptr;
	}
	while (cur != NULL && Project_Name != cur->Project_Name) {//找project是否有在list裡面
		pre = cur;
		cur = cur->nextptr;
	}
	if (cur == NULL)//是否找到最後
	{
		cout << "沒有此人!!!\n";
		return startptr;
	}
	else if (pre == NULL)//是否是在開頭
	{
		cur = startptr;
		startptr = startptr->nextptr;
		free(cur);
	}
	else {
		pre->nextptr = cur->nextptr;
		delete cur;
	}
	return startptr;
}

personptr Add_person(personptr startptr,string name, string phone, string part) {
	personptr newperson = new person(),currentptr=NULL;
	newperson->name = name;//存入資料
	newperson->phone = phone;
	newperson->part = part;
	newperson->nextptr = NULL;
	if (startptr==NULL)//list是否存在
	{
		startptr = newperson;
	}
	else
	{
		currentptr = startptr;
		while (currentptr->nextptr)
		{
			currentptr = currentptr->nextptr;
		}
		currentptr->nextptr = newperson;
	}
	return startptr;
}
void Revise_person(personptr startptr,string name) {
	personptr cur = startptr;
	while (cur)
	{
		if (cur->name == name)//名字是否有在list裡面
		{
			cout << "請輸入新的電話 : ";
			cin >> cur->phone;
			cout << "請輸入新的角色 : ";
			cin >> cur->part;
			return;
		}
		cur = cur->nextptr;
	}
	if (cur==NULL)//沒有則輸出無
	{
		cout << "查無此人!!!!\n";
	}
	return;
}
personptr Delete_person(personptr startptr, string name) {
	personptr cur = startptr, pre = NULL;
	if (startptr == NULL) {//是否有list
		cout << "沒有成員!!!\n";
		return startptr;
	}
	while (cur != NULL && name != cur->name) {//是否有要刪除的名字
		pre = cur;
		cur = cur->nextptr;
	}
	if (cur == NULL)//找到最後則輸出無
	{
		cout << "沒有此人!!!\n";
		return startptr;
	}
	if (pre == NULL)//在開頭
	{
		cur = startptr;
		startptr = startptr->nextptr;
		free(cur);
	}
	else {//在list中間或是最後
		pre->nextptr = cur->nextptr;
		delete cur;
	}
	return startptr;
}

void display_person(personptr startptr) {
	if (startptr == NULL) {
		cout << "沒有成員!!!\n";
		return;
	}
	while (startptr)//輸出list的所有資訊
	{
		//printf(" 名字 : %s \n 電話 : %s \n 角色 : %s \n\n", startptr->name, startptr->phone, startptr->part);
		cout << " 名字 : " << startptr->name << "\n" << " 電話 : " << startptr->phone << "\n" << " 角色 : " << startptr->part << endl<<endl;
		startptr = startptr->nextptr;
	}
}
void display_project(projectptr startptr) {
	if (startptr == NULL) {
		cout << "沒有成員!!!\n";
		return;
	}
	while (startptr)//輸出list的所有資訊
	{
		//printf(" 名字 : %s \n 電話 : %s \n 角色 : %s \n\n", startptr->name, startptr->phone, startptr->part);
		cout << " 任務名字 : " << startptr->Project_Name << "\n" << " 任務類型 : ";
		for (size_t i = 0; i < startptr->typelenth; i++)
		{
			cout << startptr->type[i] << " ";
		}
		cout <<endl<< " 任務說明 : " << startptr->Project_statement << "\n";
		cout << " 任務重要性 : " << startptr->Importance << endl << " 任務負責人 : " << startptr->Charge_man << endl;
		cout << " 任務時程 : " << startptr->Schedule << endl << " 任務進度 : " << startptr->current_progress << endl;
		cout << " 任務註記 : " << startptr->Mark << endl << endl;
		startptr = startptr->nextptr;
	}
}
void display_person_one(personptr startptr,string name) {
	if (startptr == NULL) {
		cout << "沒有成員!!!\n";
		return;
	}
	while (startptr)//輸出list的所有資訊
	{
		if (startptr->name==name)
		{
			cout << " 名字 : " << startptr->name << "\n" << " 電話 : " << startptr->phone << "\n" << " 角色 : " << startptr->part << endl << endl;
			return;
		}
		startptr = startptr->nextptr;
	}
	cout << "查無此人!!!!\n";
}
void display_project_one(projectptr startptr,string name) {
	if (startptr == NULL) {
		cout << "沒有成員!!!\n";
		return;
	}
	while (startptr)//輸出list的所有資訊
	{
		if (startptr->Project_Name == name) {
			cout << " 任務名字 : " << startptr->Project_Name << "\n" << " 任務類型 : " << startptr->type << endl;
			cout << " 任務說明 : " << startptr->Project_statement << "\n";
			cout << " 任務重要性 : " << startptr->Importance << endl << " 任務負責人 : " << startptr->Charge_man << endl;
			cout << " 任務時程 : " << startptr->Schedule << endl << " 任務進度 : " << startptr->current_progress << endl;
			cout << " 任務註記 : " << startptr->Mark << endl << endl;
			return;
		}
		startptr = startptr->nextptr;
	}
	cout << "查無此任務!!!!\n";
}
void displayMenu() {
	printf("========項目管理系統========\n");
	printf("1) 新增成員\n");
	printf("2) 刪除成員\n");
	printf("3) 修改成員訊息\n");
	printf("4) 印出所有成員\n");
	printf("5) 新增任務\n");
	printf("6) 更改任務類別(全部重新輸入)\n");
	printf("7) 修改任務資訊\n");
	printf("8) 刪除任務\n");
	printf("9) 印出所有任務\n");
	printf("10) 印出指定的人\n");
	printf("11) 印出指定的任務\n");
	printf("-1) 結束\n");
	printf("請輸入 : ");
}

int type_list_add(string type_list[]) {
	int type_num = 0;
	string temp;
	for (size_t i = 0; i < 20; i++)
	{
		cout << "請輸入你要新增的類型名稱 (-1結束輸入，最多20): ";
		cin >> temp;
		if (temp == "-1")
		{
			break;
		}
		type_list[i] = temp;
		type_num++;
	}
	return type_num;
}
int main() {
	projectptr projectptr_startptr=NULL,temp_project=NULL,cur_project=NULL;
	personptr personptr_startptr=NULL,temp_person=NULL, cur_person = NULL;
	int check_person = 0, check_project = 0,type_num=0, choice=0;
	string name, phone, part,temp;
	string Project_Name;
	string type_list[20];
	type_num = type_list_add(type_list);
	while (choice!=-1)
	{
		displayMenu();
		cin >> choice;//選擇想要的項目
		switch (choice)
		{
		case 1://新增人員
			getchar();//把enter鍵刪除
			cout << "請輸入名字 : ";//輸入資訊
			getline(cin, name);
			cout << "請輸入電話 : ";
			getline(cin, phone);
			cout << "請輸入任務 : ";
			getline(cin, part);
			cur_person = personptr_startptr;
			while (cur_person)//檢查是否有重複
			{
				if (cur_person->name==name)//有重複則再輸入一次
				{
					cout << "名字有重複再輸入一次!!!\n";
					cout << "請輸入名字 : ";
					getline(cin, name);
					cout << "請輸入電話 : ";
					getline(cin, phone);
					cout << "請輸入任務 : ";
					getline(cin, part);
					cur_person = personptr_startptr;
				}
				cur_person = cur_person->nextptr;
			}
			if (check_person == 0)
			{
				personptr_startptr = Add_person(personptr_startptr, name, phone, part);
			}
			check_person = 0;
			break;
		case 2://刪除人員
			getchar();
			name.clear();
			cout << "請輸入要刪除的人的名字 : ";
			getline(cin, name);
			personptr_startptr = Delete_person(personptr_startptr,name);
			break;
		case 3://修改人員
			getchar();
			name.clear();
			cout << "請輸入你要修改的人 : ";
			getline(cin, name);
			Revise_person(personptr_startptr, name);
			break;
		case 4://輸出人員
			display_person(personptr_startptr);
			break;
		case 5://新增任務
			getchar();
			cout << "請輸入任務的名稱 : ";
			getline(cin, Project_Name);			
			cur_project = projectptr_startptr;
			while (cur_project)//檢查是否有重複
			{
				if (cur_project->Project_Name==Project_Name)//有重複則再輸入一次
				{
					cout << "命稱重複了，再輸入一次!!!\n";
					cout << "請輸入任務的名稱 : ";
					getline(cin, Project_Name);
					cur_project = projectptr_startptr;
				}
				cur_project = cur_project->nextptr;
			}
			projectptr_startptr = Add_project(projectptr_startptr, Project_Name,personptr_startptr,type_list, type_num);
			break;
		case 6://更改任務類別
			getchar();
			Project_Name.clear();
			cout << "請輸入你要修改的任務名稱 : ";
			getline(cin, Project_Name);
			Revise_project_type(projectptr_startptr, Project_Name);
			break;
		case 7://修改任務資訊
			getchar();
			Project_Name.clear();
			cout << "請輸入你要修改的任務名稱 : ";
			getline(cin, Project_Name);
			Revise_project_detail(projectptr_startptr, Project_Name);
			break;
		case 8://刪除任務
			getchar();
			Project_Name.clear();
			cout << "請輸入你要刪除的任務名稱 : ";
			getline(cin, Project_Name);
			projectptr_startptr = Delete_Project(projectptr_startptr, Project_Name);
			break;
		case 9://印出所有任務
			display_project(projectptr_startptr);
			break;
		case 10:
			getchar();
			cout << "請輸入人的名稱 : ";
			getline(cin, name);
			display_person_one(personptr_startptr, name);
			break;
		case 11:
			getchar();
			cout << "請輸入任務的名稱 : ";
			getline(cin, Project_Name);
			display_project_one(projectptr_startptr, Project_Name);
			break;
		case -1:
			while (personptr_startptr)
			{
				temp_person = personptr_startptr;
				personptr_startptr = personptr_startptr->nextptr;
				free(temp_person);
			}
			while (projectptr_startptr)
			{
				temp_project = projectptr_startptr;
				projectptr_startptr = projectptr_startptr->nextptr;
				free(temp_project);
			}
			cout << "BYE BYE !!!!\n";
			break;
		default:
			cout << "輸入錯誤!!!!!\n";
			break;
		}
	}
	return 0;
}