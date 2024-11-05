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
	string Project_Name;//���ȦW��
	string type[10];//��������
	string Project_statement;//���Ȼ���
	string Importance;//���n��
	string Charge_man;//�t�d�H
	string Schedule;//�ɵ{
	string current_progress;//�i��
	string Mark;//���O;
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
	New_Project->Project_Name = name;//���ƿ�J�쵲�c�̭�
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
			cout << "�п�J�������� (-1�����A�̦h�Q��) ��"<<i+1<<"�� : ";
			cin>> temp_type;
			if (temp_type == -1)
			{
				break;
			}
			if (temp_type < 1 || temp_type > type_num) {
				cout << "��J���~�A�A��J�@�� : ";
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
	cout << "�п�J���Ȼ��� : ";
	getline(cin, New_Project->Project_statement);
	cout << "�п�J���ȭ��n�� : ";
	getline(cin, New_Project->Importance);
	cout << "�п�J���ȭt�d�H : ";
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
			cout << "�S���o�ӤH�A�ЦA��J�@�� : ";
		}
	}
	//getchar();
	cout << "�п�J���Ȯɵ{ : ";
	getline(cin, New_Project->Schedule);
	cout << "�п�J���ȶi�{ : ";
	getline(cin, New_Project->current_progress);
	cout << "�п�J���ȵ��O : ";
	getline(cin, New_Project->Mark);

	if (startptr == NULL)//�d�ݤ@�}�l���S���F��A�S���N��b�}�Y�A���N���̫�
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
	return startptr;//�^�Ƕ}�Y
}
void Revise_project_detail(projectptr startptr,string Project_Name) {//�ק���Ȫ���T
	projectptr cur = startptr, pre = NULL;
	while (cur)
	{
		if (cur->Project_Name == Project_Name)//�p�G�������ȴN�i��ק�
		{
			cout << "�п�J�s�����Ȼ��� : ";
			getline(cin, cur->Project_statement);
			cout << "�п�J�s�����ȭ��n�� : ";
			getline(cin, cur->Importance);
			cout << "�п�J�s�����ȭt�d�H : ";
			getline(cin, cur->Charge_man);
			cout << "�п�J�s�����Ȯɵ{ : ";
			getline(cin, cur->Schedule);
			cout << "�п�J�s�����ȶi�{ : ";
			getline(cin, cur->current_progress);
			cout << "�п�J�s�����ȵ��O : ";
			getline(cin, cur->Mark);
			return;
		}
		cur = cur->nextptr;
	}
	if (cur == NULL)//�d��᳣̫�S���N��X �d�L���H
	{
		cout << "�d�L������!!!!\n";
	}
}
void Revise_project_type(projectptr startptr, string Project_Name)
{
	projectptr cur = startptr, pre = NULL;
	string temp_type;
	while (cur)
	{
		if (cur->Project_Name == Project_Name)//��즹���ȴN�ק惡���Ȫ�����
		{
			cur->typelenth = 0;
			for (int i = 0; i < 10; i++)
			{
				cout << "�п�J�������� (-1����): ";
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
	if (cur == NULL)//�S���h��X�L
	{
		cout << "�d�L������!!!!\n";
	}
}
projectptr Delete_Project(projectptr startptr ,string Project_Name) {
	projectptr cur = startptr, pre = NULL;
	if (startptr == NULL) {//�d��list���S���F��
		cout << "�S������!!!\n";
		return startptr;
	}
	while (cur != NULL && Project_Name != cur->Project_Name) {//��project�O�_���blist�̭�
		pre = cur;
		cur = cur->nextptr;
	}
	if (cur == NULL)//�O�_���̫�
	{
		cout << "�S�����H!!!\n";
		return startptr;
	}
	else if (pre == NULL)//�O�_�O�b�}�Y
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
	newperson->name = name;//�s�J���
	newperson->phone = phone;
	newperson->part = part;
	newperson->nextptr = NULL;
	if (startptr==NULL)//list�O�_�s�b
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
		if (cur->name == name)//�W�r�O�_���blist�̭�
		{
			cout << "�п�J�s���q�� : ";
			cin >> cur->phone;
			cout << "�п�J�s������ : ";
			cin >> cur->part;
			return;
		}
		cur = cur->nextptr;
	}
	if (cur==NULL)//�S���h��X�L
	{
		cout << "�d�L���H!!!!\n";
	}
	return;
}
personptr Delete_person(personptr startptr, string name) {
	personptr cur = startptr, pre = NULL;
	if (startptr == NULL) {//�O�_��list
		cout << "�S������!!!\n";
		return startptr;
	}
	while (cur != NULL && name != cur->name) {//�O�_���n�R�����W�r
		pre = cur;
		cur = cur->nextptr;
	}
	if (cur == NULL)//���̫�h��X�L
	{
		cout << "�S�����H!!!\n";
		return startptr;
	}
	if (pre == NULL)//�b�}�Y
	{
		cur = startptr;
		startptr = startptr->nextptr;
		free(cur);
	}
	else {//�blist�����άO�̫�
		pre->nextptr = cur->nextptr;
		delete cur;
	}
	return startptr;
}

void display_person(personptr startptr) {
	if (startptr == NULL) {
		cout << "�S������!!!\n";
		return;
	}
	while (startptr)//��Xlist���Ҧ���T
	{
		//printf(" �W�r : %s \n �q�� : %s \n ���� : %s \n\n", startptr->name, startptr->phone, startptr->part);
		cout << " �W�r : " << startptr->name << "\n" << " �q�� : " << startptr->phone << "\n" << " ���� : " << startptr->part << endl<<endl;
		startptr = startptr->nextptr;
	}
}
void display_project(projectptr startptr) {
	if (startptr == NULL) {
		cout << "�S������!!!\n";
		return;
	}
	while (startptr)//��Xlist���Ҧ���T
	{
		//printf(" �W�r : %s \n �q�� : %s \n ���� : %s \n\n", startptr->name, startptr->phone, startptr->part);
		cout << " ���ȦW�r : " << startptr->Project_Name << "\n" << " �������� : ";
		for (size_t i = 0; i < startptr->typelenth; i++)
		{
			cout << startptr->type[i] << " ";
		}
		cout <<endl<< " ���Ȼ��� : " << startptr->Project_statement << "\n";
		cout << " ���ȭ��n�� : " << startptr->Importance << endl << " ���ȭt�d�H : " << startptr->Charge_man << endl;
		cout << " ���Ȯɵ{ : " << startptr->Schedule << endl << " ���ȶi�� : " << startptr->current_progress << endl;
		cout << " ���ȵ��O : " << startptr->Mark << endl << endl;
		startptr = startptr->nextptr;
	}
}
void display_person_one(personptr startptr,string name) {
	if (startptr == NULL) {
		cout << "�S������!!!\n";
		return;
	}
	while (startptr)//��Xlist���Ҧ���T
	{
		if (startptr->name==name)
		{
			cout << " �W�r : " << startptr->name << "\n" << " �q�� : " << startptr->phone << "\n" << " ���� : " << startptr->part << endl << endl;
			return;
		}
		startptr = startptr->nextptr;
	}
	cout << "�d�L���H!!!!\n";
}
void display_project_one(projectptr startptr,string name) {
	if (startptr == NULL) {
		cout << "�S������!!!\n";
		return;
	}
	while (startptr)//��Xlist���Ҧ���T
	{
		if (startptr->Project_Name == name) {
			cout << " ���ȦW�r : " << startptr->Project_Name << "\n" << " �������� : " << startptr->type << endl;
			cout << " ���Ȼ��� : " << startptr->Project_statement << "\n";
			cout << " ���ȭ��n�� : " << startptr->Importance << endl << " ���ȭt�d�H : " << startptr->Charge_man << endl;
			cout << " ���Ȯɵ{ : " << startptr->Schedule << endl << " ���ȶi�� : " << startptr->current_progress << endl;
			cout << " ���ȵ��O : " << startptr->Mark << endl << endl;
			return;
		}
		startptr = startptr->nextptr;
	}
	cout << "�d�L������!!!!\n";
}
void displayMenu() {
	printf("========���غ޲z�t��========\n");
	printf("1) �s�W����\n");
	printf("2) �R������\n");
	printf("3) �ק令���T��\n");
	printf("4) �L�X�Ҧ�����\n");
	printf("5) �s�W����\n");
	printf("6) ���������O(�������s��J)\n");
	printf("7) �ק���ȸ�T\n");
	printf("8) �R������\n");
	printf("9) �L�X�Ҧ�����\n");
	printf("10) �L�X���w���H\n");
	printf("11) �L�X���w������\n");
	printf("-1) ����\n");
	printf("�п�J : ");
}

int type_list_add(string type_list[]) {
	int type_num = 0;
	string temp;
	for (size_t i = 0; i < 20; i++)
	{
		cout << "�п�J�A�n�s�W�������W�� (-1������J�A�̦h20): ";
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
		cin >> choice;//��ܷQ�n������
		switch (choice)
		{
		case 1://�s�W�H��
			getchar();//��enter��R��
			cout << "�п�J�W�r : ";//��J��T
			getline(cin, name);
			cout << "�п�J�q�� : ";
			getline(cin, phone);
			cout << "�п�J���� : ";
			getline(cin, part);
			cur_person = personptr_startptr;
			while (cur_person)//�ˬd�O�_������
			{
				if (cur_person->name==name)//�����ƫh�A��J�@��
				{
					cout << "�W�r�����ƦA��J�@��!!!\n";
					cout << "�п�J�W�r : ";
					getline(cin, name);
					cout << "�п�J�q�� : ";
					getline(cin, phone);
					cout << "�п�J���� : ";
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
		case 2://�R���H��
			getchar();
			name.clear();
			cout << "�п�J�n�R�����H���W�r : ";
			getline(cin, name);
			personptr_startptr = Delete_person(personptr_startptr,name);
			break;
		case 3://�ק�H��
			getchar();
			name.clear();
			cout << "�п�J�A�n�ק諸�H : ";
			getline(cin, name);
			Revise_person(personptr_startptr, name);
			break;
		case 4://��X�H��
			display_person(personptr_startptr);
			break;
		case 5://�s�W����
			getchar();
			cout << "�п�J���Ȫ��W�� : ";
			getline(cin, Project_Name);			
			cur_project = projectptr_startptr;
			while (cur_project)//�ˬd�O�_������
			{
				if (cur_project->Project_Name==Project_Name)//�����ƫh�A��J�@��
				{
					cout << "�R�٭��ƤF�A�A��J�@��!!!\n";
					cout << "�п�J���Ȫ��W�� : ";
					getline(cin, Project_Name);
					cur_project = projectptr_startptr;
				}
				cur_project = cur_project->nextptr;
			}
			projectptr_startptr = Add_project(projectptr_startptr, Project_Name,personptr_startptr,type_list, type_num);
			break;
		case 6://���������O
			getchar();
			Project_Name.clear();
			cout << "�п�J�A�n�ק諸���ȦW�� : ";
			getline(cin, Project_Name);
			Revise_project_type(projectptr_startptr, Project_Name);
			break;
		case 7://�ק���ȸ�T
			getchar();
			Project_Name.clear();
			cout << "�п�J�A�n�ק諸���ȦW�� : ";
			getline(cin, Project_Name);
			Revise_project_detail(projectptr_startptr, Project_Name);
			break;
		case 8://�R������
			getchar();
			Project_Name.clear();
			cout << "�п�J�A�n�R�������ȦW�� : ";
			getline(cin, Project_Name);
			projectptr_startptr = Delete_Project(projectptr_startptr, Project_Name);
			break;
		case 9://�L�X�Ҧ�����
			display_project(projectptr_startptr);
			break;
		case 10:
			getchar();
			cout << "�п�J�H���W�� : ";
			getline(cin, name);
			display_person_one(personptr_startptr, name);
			break;
		case 11:
			getchar();
			cout << "�п�J���Ȫ��W�� : ";
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
			cout << "��J���~!!!!!\n";
			break;
		}
	}
	return 0;
}