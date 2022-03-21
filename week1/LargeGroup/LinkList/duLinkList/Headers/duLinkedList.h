/***************************************************************************************
 *	File Name				:	duLinkedList.h
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

#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED

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
typedef struct DuLNode {
	ElemType data;
  	struct DuLNode *prior,  *next;
} DuLNode, *DuLinkedList;

// define status
typedef enum Status {
	ERROR,
	SUCCESS,
} Status;


/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {				//创建头结点 
	LinkedList leap;
	leap = (LinkedList) malloc (sizeof(DuLNode));
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
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList(DuLinkedList *L) {
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
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList(DuLNode *p, DuLNode *q) {		//插入数据 

	q->next = p->next;
    p->next = q;
	return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */


Status InsertAfterList(DuLNode *p, DuLNode *q) {		//插入数据 

	q->next = p->next;
    p->next = q;
	return SUCCESS;
} 


Status DeleteList(DuLNode *p, ElemType *e) {
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
    DuLNode *t ;							//进行删除操作
    t=p->next;
    *e = t->data;
    p->next = t->next;
    free(t);
    return SUCCESS;

}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
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


 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
