#include"MaxHeap.h"
//���Լ�
void main() {
	MaxHeap heap;

	//���� �׽�Ʈ
	heap.insert(10);	heap.insert( 5);
	heap.insert(30);	heap.insert( 8);
	heap.insert( 9);	heap.insert( 3);
	heap.insert( 7);
	heap.display();//���� ���

	//���� �׽�Ʈ
	heap.remove();	heap.display();
	heap.remove();	heap.display();
	printf("\n");

}