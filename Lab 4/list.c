# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include "tree.c"
// struct var_or_const{
//   int nodetype;
//   int v_or_c;          //1 => v 2=> c
//   char *name;
//   int num_val;
//   char * str_val;
// };



lNode * create_node(struct var_or_const * data){
	lNode * temp = (lNode *)malloc(sizeof(lNode));
	temp->prev = NULL;
    temp->next = NULL;
    temp->data = data;
    return temp;
}

list * create_list(){
    list * l = (list *)malloc(sizeof(list));
    l->head = l->tail = NULL;
    return l;
}

void list_pushback(list * l,struct var_or_const * data){
	lNode * temp = create_node(data);

	if(l->head==NULL)
	{
		l->head = temp;
		l->tail = l->head;
	}
	else
	{
		l->tail->next = temp;
		temp->prev = l->tail;
		l->tail = temp;
	}
}

struct var_or_const * list_seekend(list * l)
{
	if(l->tail!=NULL)
	{
		return l->tail->data;
	}
	else{
		printf("Error: list empty\n");
		return NULL;
	}
}

/*for debugging*/
void printList(list * l)
{
	lNode * temp = l->head;
	while(temp !=NULL)
	{
		printf("fdfdfdfdf%d ", temp->data->nodetype);
		temp = temp->next;
	}
	printf("\n");
}


void list_popback(list * l){ //returns last entry, deletes it from list
	if(l->head == NULL)
	{
		printf("Error: list empty\n");
	}
	if(l->head == l->tail)
	{
		free(l->head);
		l->head = l->tail=NULL;;
		printf("Node deleted - List now empty\n");
		return;
	}
	lNode * temp = l->tail;
	l->tail = l->tail->prev;
	l->tail->next = NULL;
	free(temp);
	printf("Node deleted\n");
}

// int main()
// {
// 	struct var_or_const * temp = (struct var_or_const *)malloc(sizeof(struct var_or_const));
// 	list * l = create_list();
// 	temp->nodetype = 1;
// 	list_pushback(l, temp);
// 	struct var_or_const * temp2 = (struct var_or_const *)malloc(sizeof(struct var_or_const));
// 	temp2->nodetype = 2;
// 	list_pushback(l, temp2);
// 	struct var_or_const * temp3 = (struct var_or_const *)malloc(sizeof(struct var_or_const));
// 	temp3->nodetype = 20;
// 	list_pushback(l, temp3);
// 	printList(l);
//
//
// 	struct var_or_const * seek = list_seekend(l);
// 	printf("%d\n", seek->nodetype);
//
// 	list_popback(l);
// 	seek = list_seekend(l);
// 	printf("%d\n", seek->nodetype);
// 	// for(int i = 1; i<=1; i+=2)
// 	// {
// 	// 	temp->nodetype = i;
// 	// 	list_pushback(l, temp);
// 	// }
// 	printList(l);
// 	return 0;
// }
