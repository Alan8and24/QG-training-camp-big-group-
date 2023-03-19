//单链表奇偶调换
#include <stdio.h>
#include <stdlib.h>

// 定义单链表节点结构体
typedef struct Node {
	int data;
	struct Node* next;
} Node;

// 在链表尾部插入新节点
void InsertAtTail(Node** headRef, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	
	if (*headRef == NULL) {
		// 如果链表为空，新节点就是头节点
		*headRef = newNode;
	} else {
		// 否则，在尾节点后插入新节点
		Node* currentNode = *headRef;
		while (currentNode->next != NULL) {
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;
	}
}

// 打印链表
void PrintList(Node* head) {
	Node* currentNode = head;
	while (currentNode != NULL) {
		printf("%d ", currentNode->data);
		currentNode = currentNode->next;
	}
	printf("\n");
}

// 单链表奇偶调换
void OddEvenList(Node** headRef) {
	if (*headRef == NULL || (*headRef)->next == NULL) {
		// 如果链表为空或者只有一个节点，不需要调换
		return;
	}
	
	Node* odd = *headRef;
	Node* even = (*headRef)->next;
	Node* evenHead = even;
	
	while (even != NULL && even->next != NULL) {
		// 调换奇数节点和偶数节点
		odd->next = even->next;
		odd = odd->next;
		even->next = odd->next;
		even = even->next;
	}
	
	// 将偶数链表接到奇数链表尾部
	odd->next = evenHead;
}

// 测试代码
int main() {
	Node* head = NULL;
	
	// 在尾部插入新节点
	InsertAtTail(&head, 1);
	InsertAtTail(&head, 2);
	InsertAtTail(&head, 3);
	InsertAtTail(&head, 4);
	InsertAtTail(&head, 5);
	InsertAtTail(&head, 6);
	InsertAtTail(&head, 7);
	InsertAtTail(&head, 8);
	printf("目前链表中的数据有：");
	PrintList(head); // 链表内容：1 2 3 4 5 6 7 8
	
	// 调换奇偶节点
	OddEvenList(&head);
	printf("调换后链表中的数据有：");
	PrintList(head); // 链表内容：1 3 5 7 2 4 6 8
	
	return 0;
}

