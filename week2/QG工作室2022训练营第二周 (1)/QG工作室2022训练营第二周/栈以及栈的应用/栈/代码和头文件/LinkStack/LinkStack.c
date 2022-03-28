#include "../head/LinkStack.h" 
#include<stdio.h>
#include <stdlib.h>

Status initLStack(LinkStack *s)//��ʼ��ջ
{
	
	s->top=(StackNode*)malloc(sizeof(StackNode));
	s->count=0;
	s->top->next=NULL;
	return SUCCESS;
}

Status isEmptyLStack(LinkStack *s)//�ж�ջ�Ƿ�Ϊ��
{
  if(s->count==0)
  {
  	printf("����һ����ջ");
  	return SUCCESS;
  }
  printf("�ⲻ��һ����ջ");
  return SUCCESS;
}

Status getTopLStack(LinkStack *s,ElemType *e)//�õ�ջ��Ԫ��
{
  if(s->count==0)
  {
  	printf("����һ����ջ");
  	return SUCCESS;
  }
  *e=s->top->data;
  return SUCCESS;
}
  
Status clearLStack(LinkStack *s)//���ջ
{
	if(s->count==0)
  {
  	printf("����һ����ջ");
  	return ERROR;
  }
	s->count=0;
	s->top->next=NULL;			//�ÿ� 
	return SUCCESS;
	
}

Status destroyLStack(LinkStack *s)//����ջ
{
	LinkStackPtr p1,p2;
	//��ջ��ָ��ָ��Ϊ��ʱ 
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

Status LStackLength(LinkStack *s,int *length)//���ջ����
{
	*length=s->count;
	return SUCCESS;
}

Status pushLStack(LinkStack *s,ElemType data)//��ջ
{
	//���ٿռ�������� 
	StackNode* sn=(StackNode*)malloc(sizeof(StackNode));
	sn->data=data;
	sn->next=s->top;
	s->top=sn;
	s->count++;
	return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data)//��ջ
{
	*data=s->top->data;
	free(s->top); 
	s->top=s->top->next;
	s->count--;
	return SUCCESS;
}
