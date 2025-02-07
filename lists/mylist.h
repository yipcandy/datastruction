#ifndef MYLIST_H_
#define MYLIST_H_

#include<iostream>
using namespace std;

class SingleList{
private:
	int m_data;
	SingleList* m_next;
public:
	SingleList* Create(int len) {
		SingleList* prev, * head, * tail;
		head = new SingleList;
		head->m_data = len;
		head->m_next = NULL;
		prev = head;
		if (len == 0) {
			return head;	//false
		}
		cout << "����������ڵ����ֵ:" << endl;
		while(len--){
			int data;
			tail = new SingleList;
			cin >> data;
			this->Attach(prev, tail, data);
			prev = tail;
		}
		return head;
	}
	void Attach(SingleList* prev, SingleList* tail, int data) {
		tail->m_next = NULL;
		tail->m_data = data;
		prev->m_next = tail;
	}
	int GetLength(SingleList* list) {
		return list->m_data;
	}
	bool Isempty(SingleList* list) {
		return list->m_data == 0;
	}
	void Print(SingleList* list) {
		if (list->Isempty(list) ) {
			cout << "The List is empty!" << endl;
				return ;
		}
		int len = list->m_data;
		SingleList* ptrl = list->m_next;
		for (int i = 0; i < len; i++) {
			cout << ptrl->m_data << ' ';
			ptrl = ptrl->m_next;
		}
		return ;
	}
	SingleList* Insert(SingleList* list, int index, int data) {
		SingleList* prev = list;
		SingleList* insert;
		insert = new SingleList;
		int len = list->GetLength(list);

		if (this->Isempty(list)) {
			this->Attach(prev, insert, data);
			list->m_data++;
			return list;
		}

		index = (list->m_data <= index) ? list->m_data : index;
		for (int i = 0; i < index; i++) {
			prev = prev->m_next;
		}
		insert->m_data = data;
		insert->m_next = prev->m_next;
		prev->m_next = insert;
		list->m_data++;
		return list;
	}
	//��������,�������Ӧ��ָ��
	SingleList* FindPointer(SingleList* list, int index){
		SingleList* prev;
		prev = list;
		for (int i = 0; i < index; i++) {
			prev = prev->m_next;
		}
		return prev;
	}
	//�������ݣ������һ������
	int FindIndex(SingleList* list, int data) {
		int index = -1;	//not find
		SingleList* prev;
		prev = list;
		int len = this->GetLength(list);
		for (int i = 0; i < len; i++) {
			prev = prev->m_next;
			if (prev->m_data == data) {
				index = i;
				break;
			}
		}
		return index;
	}
	void DeleteByIndex(SingleList* list,int index) {
		int len = this->GetLength(list);
		if (this->Isempty(list)) {
			cout << "������Ϊ���޷�ɾ��" << endl;
			return ;
		}
		SingleList* del_pre;
		del_pre = this->FindPointer(list, index - 1);
		del_pre->m_next = del_pre->m_next->m_next;
		list->m_data--;
	}
	void DeleteByData(SingleList* list,int data) {
		int index = this->FindIndex(list, data);
		if (index == -1) {
			cout << "��������������Ϊ" << data << "�Ľڵ�" << endl;
			return ;
		}
		this->DeleteByIndex(list, index);
		return ;
	}
};

#endif