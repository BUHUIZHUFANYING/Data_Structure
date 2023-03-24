#include<stdio.h>
#include<stdlib.h> 

#define MaxSize 100

//结构体类型 
typedef struct{
	int data[MaxSize];
	int length;
}SqList;

//建立顺序表
void CreatList(SqList *&L,int a[],int n){
	int i=0;
	L=(SqList*)malloc(sizeof(SqList));
	while(i<n){
		L->data[i]=a[i];
		i++;
	}
	L->length=i;
}

//初始化线性表
void InitList(SqList *&L){
	L=(SqList*)malloc(sizeof(SqList));
	L->length=0;
}

//销毁线性表 
void DestroyList(SqList *&L){
	free(L); 
} 

//定义约瑟夫环求解函数
void  JosephList(SqList*&L){
	int m,i,j;
	int k=0;
	printf("请输入第几个报数的人出列: ");
	scanf("%d", &m);
	/*
	//防止报数溢出 
	if(m<0||m>L->length){
		printf("没有这么多人呀！");	
		return ;
	}
	*/
	printf("出列顺序为：");
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


//定义主函数 
int main(){
	SqList *L;
	InitList(L);
	
	int a[MaxSize]; 
	int n=0;
    printf("请输入队列总人数：");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
       a[i]=i+1;
    }
	CreatList(L,a,n);
	JosephList(L);
	DestroyList(L);
}

