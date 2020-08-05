#include <iostream>

using namespace std;

class Node {
int data;
Node * next;

public:
Node(int nodeData){
	data = nodeData;
}

void setNext(Node* nextNode){
	next = nextNode;
}

};

class LinkedList {

Node * firstNode;

LinkedList(){
	firstNode = NULL;
};

void insertNode(Node* node){
	
}
};

int main(){
	//ios::sync_with_stdio(false);


	return 0;
}
