 //使用递归进行反转链表操作
#include <stdio.h>
#include <stdlib.h>

// 链表节点结构体定义
typedef struct ListNode {
	int val;
	struct ListNode* next;
} ListNode;

// 反转链表
ListNode* reverseList(ListNode* head) {
	// 如果链表为空或只有一个节点，直接返回该节点
	if (head == NULL || head->next == NULL) {
		return head;
	}
	// 递归反转子链表
	ListNode* new_head = reverseList(head->next);
	// 将子链表的尾节点连接到原链表的头节点上
	head->next->next = head;
	// 将原链表的头节点的 next 指针设置为 NULL，避免出现环
	head->next = NULL;
	return new_head;
}

// 测试代码
int main() {
	ListNode* head = NULL;
	head = (ListNode*)malloc(sizeof(ListNode));
	head->val = 1;
	head->next = NULL;
	ListNode* p = head;
	for (int i = 2; i <= 5; i++) {
		ListNode* node = (ListNode*)malloc(sizeof(ListNode));
		node->val = i;
		node->next = NULL;
		p->next = node;
		p = node;
	}
	printf("目前链表中的数据有：\n");
	p = head;
	while (p != NULL) {
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");
	head = reverseList(head);  // 反转链表
	printf("调转后链表中的数据有：\n");
	p = head;
	while (p != NULL) {
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");
	return 0;
}

