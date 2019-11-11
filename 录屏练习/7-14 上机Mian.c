#if 0

#include"7-14ио╩З.h"
#include<stdio.h>


void test()
{
	Node *n1 = createNode(1);
	Node *n2 = createNode(2);
	Node *n3 = createNode(3);
	Node *n4 = createNode(4);
	Node *n5 = createNode(5);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;

	n1->random = n3;
	n2->random = n1;
	n3->random = n4;
	n4->random = n4;
	n5->random = NULL;

	Node *result = copy(n1);

	for (Node *cur = n1; cur != NULL; cur = cur->next)
	{
		printf("%p(%d,%p) ", cur, cur->val, cur->random);
	}
	printf("\n");
	for (Node *cur = result; cur != NULL; cur = cur->next)
	{
		printf("%p(%d,%p) ", cur, cur->val, cur->random);
	}
	printf("\n");
}

int main()
{
	test();
	system("pause");
}
#endif