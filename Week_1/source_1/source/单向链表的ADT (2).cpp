#include <stdio.h>
#include <stdlib.h>

// 链表结构体
typedef struct ListNode {
	int val;  // 节点存储的数据
	struct ListNode *next;  // 指向下一个节点的指针
} ListNode;

// 初始化链表
void initList(ListNode **head) {
	*head = NULL;
}

// 在链表末尾添加元素
void addNode(ListNode **head, int val) {
	ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->val = val;
	newNode->next = NULL;
	
	if (*head == NULL) {
		*head = newNode;
	} else {
		ListNode *p = *head;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = newNode;
	}
}

// 获取链表长度
int getListLength(ListNode *head) {
	int len = 0;
	ListNode *p = head;
	while (p != NULL) {
		len++;
		p = p->next;
	}
	return len;
}

// 删除指定位置的元素
void deleteNode(ListNode **head, int pos) {
	int len = getListLength(*head);
	if (pos <= 0 || pos > len) {
		printf("Error: Invalid position.\n");
		return;
	}
	
	if (pos == 1) {
		ListNode *temp = *head;
		*head = (*head)->next;
		free(temp);
	} else {
		ListNode *p = *head;
		ListNode *q = NULL;
		for (int i = 1; i < pos; i++) {
			q = p;
			p = p->next;
		}
		q->next = p->next;
		free(p);
	}
}

// 查找指定位置的元素
void searchNode(ListNode *head, int pos) {
	int len = getListLength(head);
	if (pos <= 0 || pos > len) {
		printf("Error: Invalid position.\n");
		return;
	}
	
	ListNode *p = head;
	for (int i = 1; i < pos; i++) {
		p = p->next;
	}
	printf("The value at position %d is %d.\n", pos, p->val);
}

// 反转链表
void reverseList(ListNode **head) {
	if (*head == NULL) {
		return;
	}
	ListNode *prev = NULL;
	ListNode *curr = *head;
	ListNode *next;
	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}

// 主函数
int main() {
	ListNode *head;
	initList(&head);
	
	int len;
	do {
		printf("请输入链表长度：");
		if (scanf("%d", &len) != 1 || len <= 0) {  // 输入不合法
			printf("请输入正整数！\n");
			// 清空输入缓冲区
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
		}
	} while (len <= 0);
	
	
	ListNode *tail = NULL;
	for (int i = 0; i < len; i++) {
		int data;
		do {
			printf("请输入第%d个节点的数据(请输入两次确认你的数据)：", i + 1);
			if (scanf("%d", &data) != 1) {  // 输入不合法
				printf("请输入整数！\n");
				// 清空输入缓冲区
				int c;
				while ((c = getchar()) != '\n' && c != EOF);
			}
		} while (scanf("%d", &data) != 1);
		// 创建新节点
		ListNode *new_node = (ListNode *) malloc(sizeof(ListNode));
		new_node->val = data;
		new_node->next = NULL;
		// 将新节点加入链表尾部
		if (tail == NULL) {  // 链表为空
			head = tail = new_node;
		} else {
			tail->next = new_node;
			tail = new_node;
		}
	} 
	
	
	int option;
	do {
		printf("请选择操作：\n");
		printf("1. 删除节点\n");
		printf("2. 查找节点\n");
		printf("3. 反转链表\n");
		printf("4.退出并输出链表\n");
		printf("请输入数字1-4选择操作：");
		if (scanf("%d", &option) != 1 || option < 1 || option > 4) {  // 输入不合法
			printf("请输入数字1-4选择操作！\n");
			// 清空输入缓冲区
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
		}
	} while (option < 1 || option > 4);
	switch (option) {
	case 1:
		int pos;
		do {
			printf("请输入要删除的节点位置：");
			if (scanf("%d", &pos) != 1 || pos <= 0) {  // 输入不合法
				printf("请输入正整数！\n");
				// 清空输入缓冲区
				int c;
				while ((c = getchar()) != '\n' && c != EOF);
			}
		} while (pos <= 0);
		deleteNode(&head, pos);
		break;
	case 2:
		do {
			printf("请输入要查找的节点位置：");
			if (scanf("%d", &pos) != 1 || pos <= 0) {  // 输入不合法
				printf("请输入正整数！\n");
				// 清空输入缓冲区
				int c;
				while ((c = getchar()) != '\n' && c != EOF);
			}
		} while (pos <= 0);
		searchNode(head, pos);
		break;
	case 3:
		reverseList(&head);
		break;
    case 4:
		break;
	default:
		break;
	}
	printf("链表的数据为：\n");
	ListNode *p = head;
	while (p != NULL) {
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");
	return 0;
}

