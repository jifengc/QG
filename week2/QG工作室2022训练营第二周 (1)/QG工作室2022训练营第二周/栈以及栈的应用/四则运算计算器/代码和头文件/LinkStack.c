#include"LinkStack.h"
#include<stdio.h>
#include <stdlib.h>

Status initLStack(LinkStack *s)//��ʼ��ջ
{
	s->top=(StackNode*)malloc(sizeof(StackNode));
	s->count=0;
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
	s->top->next=NULL;
	return SUCCESS;
	
}

Status destroyLStack(LinkStack *s)//����ջ
{
	free(s->top);
	free(s);
	return SUCCESS;
}

Status LStackLength(LinkStack *s,int *length)//���ջ����
{
	*length=s->count;
	return SUCCESS;
}

Status pushLStack(LinkStack *s,ElemType data)//������ջ
{
	StackNode* sn=(StackNode*)malloc(sizeof(StackNode));
	sn->data=data;
	sn->next=s->top;
	s->top=sn;
	s->count++;
	return SUCCESS;
}

Status pushLStack2(LinkStack *s,ElemType2 data2)//������ջ
{
	StackNode* sn=(StackNode*)malloc(sizeof(StackNode));
	sn->data2=data2;
	sn->next=s->top;
	s->top=sn;
	s->count++;
	return SUCCESS;
}
Status popLStack(LinkStack *s,ElemType *data)//���ֳ�ջ
{
	*data=s->top->data;
	s->top=s->top->next;
	s->count--;
	return SUCCESS;
}

Status popLStack2(LinkStack *s,ElemType2 *data2)//���ų�ջ
{
	*data2=s->top->data2;
	s->top=s->top->next;
	s->count--;
	return SUCCESS;
}
