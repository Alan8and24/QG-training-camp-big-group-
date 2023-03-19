//找到单链表中点
#include <stdio.h>
#include <stdlib.h>

// 链表节点结构体定义
typedef struct ListNode {
	int val;
	struct ListNode* next;
} ListNode;

// 找到链表的中点
ListNode* findMiddleNode(ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return head;  // 链表为空或只有一个节点时，中点就是头节点
	}
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

// 测试代码
int main() {
	ListNode* head = NULL;
	head = (ListNode*)malloc(sizeof(ListNode));
	head->val = 1;
	head->next = NULL;
	ListNode* p = head;
	for (int i = 2; i <= 6; i++) {
		ListNode* node = (ListNode*)malloc(sizeof(ListNode));
		node->val = i;
		node->next = NULL;
		p->next = node;
		p = node;
	}
	ListNode* middle = findMiddleNode(head);
	printf("该单链表中点为: %d\n", middle->val);  // 输出链表的中点
	return 0;
}

