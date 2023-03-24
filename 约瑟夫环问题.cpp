#include<stdio.h>
#include<stdlib.h> 

#define MaxSize 100

//�ṹ������ 
typedef struct{
	int data[MaxSize];
	int length;
}SqList;

//����˳���
void CreatList(SqList *&L,int a[],int n){
	int i=0;
	L=(SqList*)malloc(sizeof(SqList));
	while(i<n){
		L->data[i]=a[i];
		i++;
	}
	L->length=i;
}

//��ʼ�����Ա�
void InitList(SqList *&L){
	L=(SqList*)malloc(sizeof(SqList));
	L->length=0;
}

//�������Ա� 
void DestroyList(SqList *&L){
	free(L); 
} 

//����Լɪ����⺯��
void  JosephList(SqList*&L){
	int m,i,j;
	int k=0;
	printf("������ڼ����������˳���: ");
	scanf("%d", &m);
	/*
	//��ֹ������� 
	if(m<0||m>L->length){
		printf("û����ô����ѽ��");	
		return ;
	}
	*/
	printf("����˳��Ϊ��");
	printf("\n");
	for (i=L->length;i>0;i--)
 	{
 		k=(k+m-1)%i;
 		printf("%d ",L->data[k]);
		for (j=k;j<i-1;j++)
 		{
 			L->data[j]=L->data[j+1];
 		}
		L->length=L->length-1;
    }
	printf("\n");
} 


//���������� 
int main(){
	SqList *L;
	InitList(L);
	
	int a[MaxSize]; 
	int n=0;
    printf("�����������������");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
       a[i]=i+1;
    }
	CreatList(L,a,n);
	JosephList(L);
	DestroyList(L);
}

