#pragma once
#include "HeapNode.h"
#define MAX_ELEMENT 200
class MaxHeap {
	HeapNode node[MAX_ELEMENT];//요소의 배열
	int size;
public:
	MaxHeap() :size(0) {}
	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX_ELEMENT - 1; }

	HeapNode& getParent(int i) { return node[i / 2]; }
	HeapNode& getLeft(int i) { return node[i * 2]; }
	HeapNode& getRight(int i) { return node[i * 2 + 1]; }

	void insert(int key) {
		if (isFull())return;
		int i = ++size;

		//트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
		while (i != 1 
			&& key > getParent(i).getKey()) {
			node[i] = getParent(i);
		i /= 2;
		}
		node[i].setKey(key);//최종 위치에 데이터 복사
	}
	HeapNode remove() {
		if (isEmpty())return NULL;
		HeapNode item = node[1];//루트노드(꺼낼 요소)
		HeapNode last = node[size--];
		int parent = 1;
		int child = 2;
		while (child <= size) {
			//현재 노드의 자식 노드 중 더 큰 자식노드를 찾음
			if (child < size
				&&getLeft(parent).getKey() < getRight(parent).getKey())
				child++;//child:더 큰 자식 노드의 인덱스
				//마지막 노드가 더 큰 자식보다 크면 ==> 이동완료
				if (last.getKey() >= node[child].getKey())break;
			//아니면 ==>한단계 아래로 이동
				node[parent] = node[child];
				parent = child;
				child *= 2;
		}
		node[parent] = last;//마지막 노드를 최종 위치에 저장
		return item;//루트 노드 반환
	}
	HeapNode find() { return node[1]; }

	void display() {
		for (int i = 1, level = 1; i <= size; i++) {
			if (i == level) {
				printf("\n");
				level *= 2;
			}
			node[i].display();
		}
		printf("\n---------------------------------");
	}
};