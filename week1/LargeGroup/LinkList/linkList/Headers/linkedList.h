/***************************************************************************************
 *	File Name				:	linkedList.h
 *	CopyRight				:	2020 QG Studio
 *	SYSTEM					:   win10
 *	Create Data				:	2020.3.28
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

 /**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/ 
 /**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

/**************************************************************
*	Macro Define Section
**************************************************************/

#define OVERFLOW -1

/**************************************************************
*	Struct Define Section
**************************************************************/

// define element type
typedef int ElemType;

// define struct of linked list
typedef struct LNode {
	ElemType data;
  	struct LNode *next;
} LNode, *LinkedList;
#include<stdlib.h> 
// define Status
typedef enum Status {
	ERROR,
	SUCCESS
} Status;

void visit(ElemType e){
	int i=1;
    printf("%d->",e);
}


/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {				//创建头结点 
	LinkedList leap;
	leap = (LinkedList) malloc (sizeof(LNode));
	if(leap==NULL)
	{
		printf("开辟空间失败");
		return ERROR;
	}
	leap->next = NULL;
	*L = leap;
	return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LinkedList leap;
	leap = *L;
	while (*L != NULL)				//对链表进行遍历，挨个删除 
	{
		leap = *L;
		*L = (*L)->next;
		free(leap);
		
	}
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {		//插入数据 

	q->next = p->next;
    p->next = q;
	return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	 if (!p) 							//如果该节点不存在
    {
        printf("指定节点不存在！");
        return ERROR; 
    }
    if (!(p->next)) 					//如果该节点后无节点
    { 
        printf("该节点后无节点！"); 
        return ERROR; 
    }
    LNode *t ;							//进行删除操作
    t=p->next;
    *e = t->data;
    p->next = t->next;
    free(t);
    return SUCCESS;

}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L,void (*visit)(ElemType e)) {
	LinkedList a;
	a = L; 
	while (a!=NULL)
	{
		(*visit)(a->data); 					//与visit函数结合输出遍历结果 
		a = a->next;
	}
	printf("\NULL"); 						//最终指向NULL 
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	LinkedList a;
	a = L;
	while (a != NULL)
	{
		if (a->data == e)					//若查找到，返回成功 
		{
			return SUCCESS;
		}
		a = a->next;
	
	}
	if (a == NULL)
	{ 
		return ERROR;						//查找失败，返回错误 
	}
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	LNode* pre = NULL;
    											//需要反转指向的结点
    LNode* cur = *L;
    
    while(cur)
    {
        										//保存需要头插结点的下一个节点
        LNode* next = cur->next;
        										//将头插到新链表
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return SUCCESS;


}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	LinkedList p1, p2;
	p1 = L;
	p2 = L;
	if (L == NULL)
	{
		printf("该链表不存在");
		return ERROR;
	}
	while (p1->next != NULL && p1->next->next != NULL && p2->next != NULL)
	{
		p1 = p1->next->next;				//快指针 
		p2 = p2->next;						//慢指针 
		if (p1 == p2)						//当两个指针相遇时 
		{
			return SUCCESS;
		}
	}

}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
	LinkedList p1, p2, p3, p4;
	int n = 0;
	p3 = p1 = *L;
	while (p1->next!=NULL)
	{
		p2 = p1->next;						//交换结点 
		p1->next = p2->next;
		p2->next = p1;
		if (++n == 1) {						//如果从1开始（特殊） 
			p3 = p2;
		}
		else {
			p4->next = p2;					
		}
		p4 = p1;							//交换 
		p1 = p1->next;
		if (p1!=NULL)break;
	}
	return p3;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
	LinkedList p1, p2;
	p1 = p2 = *L;
	while (1)
	{
		p2 = p2->next->next;
		if (p2->next == NULL || p2->next->next == NULL||p2->data==00||p2->next->data==00)
		{
			return p1;
		}else p1 = p1->next;
	}
}
 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/



#endif
