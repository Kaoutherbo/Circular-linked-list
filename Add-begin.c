#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node*link;
}Node;
//Add node to creat the list
Node* Add_node(){
   Node*newNode=(Node*)malloc(sizeof(Node));
   if(newNode==NULL){
   	printf("Memory can not be allocated ");
   }else{	
   int val;
   printf("Enter the data : ");
   scanf("%d",&val);
	newNode->data=val;
	newNode->link=newNode;
	return newNode;
	 }
}
//creat the list
Node* creat_list(int n){
	Node *head,*temp,*newNode;
    int val;
		head=Add_node();
	if(head!=NULL){
		temp=head;
		for(int i=2;i<=n;i++){
			newNode=Add_node();		
   			temp->link=newNode;
   			temp=newNode;
		}
		temp->link=head;
	}
	return head;
}
//Display the elements of the list
void display_list(Node*head){
	Node*temp=head;
	if(head==NULL)printf("Empty list ");
	else{
		do{
			printf("%d\t",temp->data);
			temp=temp->link;
		}while(temp!=head);
	}
}
//Add node in the beginning of the list 
Node* Insert_start(Node *head,int num){
	Node *newNode,*temp=head;
	newNode=(Node*)malloc(sizeof(Node));
	newNode->data=num;
	
	while(temp->link!=head){
		temp=temp->link;
	}
	newNode->link=head;
	head=newNode;
	temp->link=head;
	return head;
}

//Driver code
int main(){
	Node *list;
	int num;
	printf("How many nodes you want ? ");
	scanf("%d",&num);
	list=creat_list(num);
	display_list(list);
	printf("\n Enter the number you want to add it in list : \n");
	scanf("%d",&num);
	list=Insert_start(list,num);
	display_list(list);
	
	return 0;
}