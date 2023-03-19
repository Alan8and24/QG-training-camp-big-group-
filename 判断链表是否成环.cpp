//判断链表是否成环
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 链表节点结构体定义
typedef struct ListNode {
	int val;
	struct ListNode* next;
} ListNode;

// 判断链表是否成环
bool hasCycle(ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return false;  // 链表为空或只有一个节点时，不成环
	}
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) {
			return true;  // 快指针追上了慢指针，链表成环
		}
	}
	return false;  // 快指针到达链表末尾，链表不成环
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
	printf("是否成环（1为成环，0为不成环）: %d\n", hasCycle(head));  // 输出链表是否成环
	// 创建一个环形链表
	p->next = head;
	printf("是否成环（1为成环，0为不成环）: %d\n", hasCycle(head));  // 输出链表是否成环
	return 0;
}

