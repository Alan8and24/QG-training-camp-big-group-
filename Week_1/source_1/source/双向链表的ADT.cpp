//双向链表的ADT
#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
typedef struct Node {
	int data; // 存储节点数据
	struct Node* next; // 指向下一个节点的指针
	struct Node* prev; // 指向前一个节点的指针
} Node;

// 在链表头插入新节点
void InsertAtHead(Node** headRef, int data) {
	// 创建新节点
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = (*headRef);
	newNode->prev = NULL;

	if ((*headRef) != NULL) {
		// 如果链表非空，将头节点的prev指针指向新节点
		(*headRef)->prev = newNode;
	}

	(*headRef) = newNode;
}

// 在链表尾插入新节点
void InsertAtTail(Node** headRef, int data) {
	// 创建新节点
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	if ((*headRef) == NULL) {
		// 如果链表为空，将新节点设置为头节点
		(*headRef) = newNode;
	} else {
		// 否则，找到链表尾部，将尾节点的next指针指向新节点
		Node* tail = (*headRef);
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = newNode;
		newNode->prev = tail;
	}
}

// 删除链表中第一个值为data的节点
void DeleteNode(Node** headRef, int data) {
	Node* currentNode = (*headRef);
	while (currentNode != NULL && currentNode->data != data) {
		currentNode = currentNode->next;
	}

	if (currentNode == NULL) {
		// 如果链表中没有值为data的节点，直接返回
		return;
	}

	if (currentNode->prev == NULL) {
		// 如果要删除的节点是头节点，将头节点指针指向下一个节点
		(*headRef) = currentNode->next;
	} else {
		// 否则，将要删除的节点的前一个节点的next指针指向要删除的节点的下一个节点
		currentNode->prev->next = currentNode->next;
	}

	if (currentNode->next != NULL) {
		// 如果要删除的节点不是尾节点，将要删除的节点的下一个节点的prev指针指向要删除的节点的前一个节点
		currentNode->next->prev = currentNode->prev;
	}

	// 释放要删除的节点的内存
	free(currentNode);
}

// 获取链表中第position个节点
Node* GetNodeAt(Node* head, int position) {
	Node* currentNode = head;
	int currentPosition = 0;
	while (currentNode != NULL && currentPosition != position) {
		currentNode = currentNode->next;
		currentPosition++;
	}
	return currentNode;
}

// 反转链表
void ReverseList(Node** headRef) {
	Node* currentNode = (*headRef);
	Node* tempNode = NULL;
	Node* nextNode = NULL;
	while (currentNode != NULL) {
		// 保存当前节点的下一个节点
		nextNode = currentNode->next;

		// 将当前节点的next指针指向tempNode
		currentNode->next = tempNode;

		// 将tempNode的prev指针指向当前节点
		if (tempNode != NULL) {
			tempNode->prev = currentNode;
		}

		// 将tempNode指向当前节点
		tempNode = currentNode;

		// 将当前节点指向下一个节点
		currentNode = nextNode;
	}

	// 将头节点指针指向原链表的尾节点
	(*headRef) = tempNode;
}

int main() {
	int length;
	printf("请输入链表的长度：");
	while (scanf("%d", &length) != 1 || length <= 0) {
		printf("输入错误，请重新输入：");
		while (getchar() != '\n');
	}
	
	Node* head = NULL;
	int data;
	printf("请输入链表的数据：");
	for (int i = 0; i < length; i++) {
		printf("请输入第%d个数据：", i+1);
		while (scanf("%d", &data) != 1) {
			printf("输入错误，请重新输入：");
			while (getchar() != '\n');
		}
		InsertAtTail(&head, data);
	}
	
	int deleteData;
	printf("请输入要删除的数据：");
	while (scanf("%d", &deleteData) != 1) {
		printf("输入错误，请重新输入：");
		while (getchar() != '\n');
	}
	DeleteNode(&head, deleteData);
	
	int searchData;
	printf("请输入要查找的数据：");
	while (scanf("%d", &searchData) != 1) {
		printf("输入错误，请重新输入：");
		while (getchar() != '\n');
	}
	Node* searchNode = head;
	while (searchNode != NULL && searchNode->data != searchData) {
		searchNode = searchNode->next;
	}
	if (searchNode == NULL) {
		printf("链表中不存在该数据\n");
	} else {
		printf("链表中存在该数据\n");
	}
	
	char reverse;
	printf("是否进行反转？(y/n)");
	while (scanf(" %c", &reverse) != 1 || (reverse != 'y' && reverse != 'n')) {
		printf("输入错误，请重新输入：");
		while (getchar() != '\n');
	}
	if (reverse == 'y') {
		ReverseList(&head);
	}
	
	printf("链表为：");
	Node* currentNode = head;
	while (currentNode != NULL) {
		printf("%d ", currentNode->data);
		currentNode = currentNode->next;
	}
	printf("\n");
	
}

