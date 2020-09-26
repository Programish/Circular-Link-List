#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef struct _Node {
	int data;
	struct _Node *next;
} Node;
Node *head, *tail;

static int n=0;
void print();
void reverse();
void beg_del();
void last_del();
void del(int c);
void beg_ntr(Node *);
void last_ntr(Node *);
void ntr(Node *,int c);
void del_key(Node *);
void srch_key(Node *);
void swap(Node *,Node *);
void sort_asc();
void sort_desc();
void del_duplicate();

int main(){
	head=NULL;
	tail=head;
	char ch;
	do{
		Node *new_node,*prev_node;
		prev_node=head;
		new_node = (Node*) malloc(sizeof(Node));
		printf("Enter data in new node: ");
		scanf("%d", &new_node->data);
		getchar();
		new_node->next=NULL;
		++n;
		if(head==NULL)
			head=new_node;
		else
			tail->next=new_node;
		tail=new_node;	
		printf("Enter more node (y/n) :");
		ch = tolower(getchar());
		getchar();
	} while (ch == 'y');
	tail->next=head;
	print();
	
	char vx;
	printf("Want to reverse (y/n): ");
	vx = tolower(getchar());
	getchar();
	if (vx == 'y')
		reverse();
	print();
	
	char h;
	int m;
	printf("Want to delete a node (y/n): ");
	h = tolower(getchar());
	getchar();
	if (h == 'y'){
		printf("Enter index of list element to be deleted: ");
		scanf("%d", &m);
		getchar();
		if(m==1)
			beg_del();	
		else if(m==n)
			last_del();
		else
			del(m);
	}
	print();
	
	char o;
	int l;
	printf("Want to enter a node (y/n): ");
	o = tolower(getchar());
	getchar();
	if (o == 'y'){
		printf("Enter index of list element to be entered: ");
		scanf("%d", &l);
		getchar();
		Node *tp;
		tp=(Node*)malloc(sizeof(Node));
		printf("Enter data in new node: ");
		scanf("%d",&tp->data);
		getchar();
		tp->next=NULL;
		if(l==1)
			beg_ntr(tp);	
		else if(l==n+1)
			last_ntr(tp);
		else
			ntr(tp,l);
	}
	print();
	
	char q;
	printf("Want to delete a node through data (y/n): ");
	q = tolower(getchar());
	getchar();
	if (q == 'y'){
		Node *tp;
		tp=(Node*)malloc(sizeof(Node));
		printf("Enter data in new node: ");
		scanf("%d",&tp->data);
		getchar();
		if(tp->data==head->data)
			beg_del();	
		else{
			tp->next=NULL;
			del_key(tp);
		}
	}
	print();
	
	char t;
	printf("Want to search a node through data (y/n): ");
	t = tolower(getchar());
	getchar();
	if (t == 'y'){
		Node *tp;
		tp=(Node*)malloc(sizeof(Node));
		printf("Enter data in new node: ");
		scanf("%d",&tp->data);
		getchar();
		tp->next=NULL;
		srch_key(tp);
	}
	print();
	
	char a;
	printf("Want to sort the list in ascending (y/n): ");
	a = tolower(getchar());
	getchar();
	if (a == 'y')
		sort_asc();
	print();
	
	char b;
	printf("Want to sort the list in descending (y/n): ");
	b = tolower(getchar());
	getchar();
	if (b == 'y')
		sort_desc();
	print();
	
	char v;
	printf("Want to delete duplicates (y/n): ");
	v = tolower(getchar());
	getchar();
	if (v == 'y')
		del_duplicate();
	print();
	
	return 0;

}
void print(){
	Node *temp=head;
	for(;temp->next!=head;temp=temp->next)
		printf("%d ->",temp->data);
	Node *x=temp;
	printf("%d ",x->data);
	printf("\n");
}
void reverse(){
	Node *krnt,*pre;
	if(head==NULL){
		printf("Can't reverse \n");
		return;	
	}
	tail=head;
	pre=head;
	krnt=head->next;
	head=head->next;
	while(head!=tail){
		head=head->next;
		krnt->next=pre;
		pre=krnt;
		krnt=head;
	}
	krnt->next=pre;
	head=pre;
}
void beg_del(){
	head=head->next;
	tail->next=head;
}
void last_del(){
	Node *temp=head,*t=head;
	for (; temp->next!=head;t=temp,temp=temp->next) {
	}
	tail=t;
	t->next=head;
	free(temp);
}
void del(int m){
	Node *temp=head,*t=temp->next;
	int x=0;
	for(;t!=head;temp=temp->next){
		++x;
		t=temp->next;
		if(x==m-1){
			temp->next=t->next;
			free(t);
			break;
		}
	}
}
void beg_ntr(Node *tp){
	if(head==NULL){
		tp->next=head;
		head->next=tp;
	}
	else{
		tp->next=head;
		tail->next=tp;
		head=tp;
	}
}
void last_ntr(Node *pt){
	pt->next=head;
	if(head==NULL)
		head->next=pt;
	else{
		tail->next=pt;
		tail=tail->next;
	}
}
void ntr(Node *pt,int c){
	Node *temp=head;
	int x=0;
	if(head==NULL){
		pt->next=NULL;
		head->next=pt;
	}
	else
		for(;temp->next!=NULL;temp=temp->next){
			++x;
			if(x==c-1){
				pt->next=temp->next;
				temp->next=pt;
				break;
			}
		}
}
void del_key(Node *dk){
	Node *a=head,*b;
	b=a->next;
	for(;b!=NULL;a=a->next){
		if(b->data==dk->data){
			a->next=b->next;
			return;
		}
		b=b->next;
	}
}
void srch_key(Node *sk){
	Node *a=head;
	int x=0;
	for(;a!=NULL;a=a->next){
		++x;
		if(a->data==sk->data){
			printf("Found at %d\n",x);
			return;
		}
	}
}
void swap(Node *op,Node *ty){
	int i;
	i=op->data;
	op->data=ty->data;
	ty->data=i;
}
void sort_asc(){
	Node *krnt=head,*ndx=NULL;
	if(head==NULL)
		return;
	else
		while(krnt!=tail){
			ndx=krnt->next;
			while(ndx!=tail){
				if(krnt->data > ndx->data)
					swap(krnt,ndx);
				ndx=ndx->next;
			}
			krnt=krnt->next;
		}
}
void sort_desc(){
	Node *krnt=head,*ndx=NULL;
	if(head==NULL)
		return;
	else
		while(krnt!=tail){
			ndx=krnt->next;
			while(ndx!=tail){
				if(krnt->data < ndx->data)
					swap(krnt,ndx);
				ndx=ndx->next;
			}
			krnt=krnt->next;
		}
}
void del_duplicate(){
	Node *krnt=head,*ndx=NULL,*tmp=NULL;
	if(head==NULL){
		printf("List is empty\n");
		return;
	}
	else
		do{
			tmp=krnt;
			ndx=krnt->next;
			while(ndx!=head){
				if(krnt->data==ndx->data)
					tmp->next=ndx->next;		
				else
					tmp=ndx;
				ndx=ndx->next;
			}
			krnt=krnt->next;
		}while(krnt->next!=head);
}
