/*students please write your program here*/
#include<iostream>
using namespace std;

struct Node{
	int value;
	Node* next;
	Node(){}
	Node(int x) : value(x), next(NULL) {}
};
void init(Node* head){		//链表初始化
	int val;
	cin>>val;
	head->value=val;
	Node* tmpNode = head;
	for (int i=0;i<9;i++){	//链表共有十个节点,head后还有9个
		cin>>val;
		Node* pNode = new Node(val);
		tmpNode->next=pNode;
		tmpNode=pNode;
	}
	tmpNode->next=NULL;
}
void output(Node* head);		//函数原型声明
int main(){
	Node head;
	init(&head);
	output(&head);
	return 0;
}
void output(Node* head){
	int cnt = 0;
	while(head)
	{
		if(head->value % 2 != 0)
			cout << head->value << " ";
		head = head->next;
	}	
  
  
  
}
