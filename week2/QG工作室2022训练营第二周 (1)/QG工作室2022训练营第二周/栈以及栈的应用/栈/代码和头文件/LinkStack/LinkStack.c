#include "../head/LinkStack.h" 
#include<stdio.h>
#include <stdlib.h>

Status initLStack(LinkStack *s)//初始化栈
{
	
	s->top=(StackNode*)malloc(sizeof(StackNode));
	s->count=0;
	s->top->next=NULL;
	return SUCCESS;
}

Status isEmptyLStack(LinkStack *s)//判断栈是否为空
{
  if(s->count==0)
  {
  	printf("这是一个空栈");
  	return SUCCESS;
  }
  printf("这不是一个空栈");
  return SUCCESS;
}

Status getTopLStack(LinkStack *s,ElemType *e)//得到栈顶元素
{
  if(s->count==0)
  {
  	printf("这是一个空栈");
  	return SUCCESS;
  }
  *e=s->top->data;
  return SUCCESS;
}
  
Status clearLStack(LinkStack *s)//清空栈
{
	if(s->count==0)
  {
  	printf("这是一个空栈");
  	return ERROR;
  }
	s->count=0;
	s->top->next=NULL;			//置空 
	return SUCCESS;
	
}

Status destroyLStack(LinkStack *s)//销毁栈
{
	LinkStackPtr p1,p2;
	//当栈顶指针指向不为空时 
	while(s->top->next != NULL){	
	
	p1=p2=s->top->next;
	p1=p2->next;
	free(p2);
	s->top->next=p1; 
	
	}
	free(s->top);
	free(s);
	return SUCCESS;
}

Status LStackLength(LinkStack *s,int *length)//检测栈长度
{
	*length=s->count;
	return SUCCESS;
}

Status pushLStack(LinkStack *s,ElemType data)//入栈
{
	//开辟空间放入数据 
	StackNode* sn=(StackNode*)malloc(sizeof(StackNode));
	sn->data=data;
	sn->next=s->top;
	s->top=sn;
	s->count++;
	return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data)//出栈
{
	*data=s->top->data;
	free(s->top); 
	s->top=s->top->next;
	s->count--;
	return SUCCESS;
}
