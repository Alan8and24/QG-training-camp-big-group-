//非递归进行反转链表
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
	ListNode* prev = NULL;   // 当前节点的前一个节点
	ListNode* curr = head;   // 当前节点
	ListNode* next = NULL;   // 当前节点的后一个节点
	while (curr != NULL) {
		next = curr->next;   // 保存当前节点的后一个节点
		curr->next = prev;   // 反转当前节点
		prev = curr;         // 移动指针
		curr = next;
	}
	head = prev;             // 头节点指向新的头节点
	return head;
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

