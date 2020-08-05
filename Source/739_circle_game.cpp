#include <iostream>
using namespace std;

class Student {
private:
int id;
Student *next;
Student *prev;

public:
Student(){id = -1; next = prev = NULL;}


Student(int tag){id = tag; next = prev = NULL;}


void setNext(Student * s){next = s;}


void setPrev(Student * s){prev = s;}


Student *getNext(){return next;}


Student *getPrev(){return prev;}


int getTag(){return id;}
};

class Circle {
private:
Student *refP;
Student *last;
int size;

public:
Circle(){refP = last = NULL; size = 0;}


void add(int tag){
	Student * s;
	s = new Student(tag);

	if (refP == NULL)
		refP = last = s;
	else {
		last->setNext(s);
		s->setPrev(last);
		last = s;
		s->setNext(refP);
		refP->setPrev(last);
	}
	size++;
}


void insert(int pos, int tag){
	Student * s;
	s = new Student(tag);
	Student * temp = position(pos);
	s->setNext(temp->getNext());
	s->setPrev(temp);
	temp->setNext(s);
	refP = s;
	size++;
	
}


void remove(int pos){
	Student * temp = position(pos);
	temp->getPrev()->setNext(temp->getNext());
	temp->getNext()->setPrev(temp->getPrev());
	refP = temp->getNext();
	if (temp == last) last = temp->getPrev();
	delete temp;
	size--;
	
}


void query(int pos){
	Student * temp = position(pos);
	cout << temp->getTag() << endl;
	refP = temp;
}


Student * position(int pos){
	pos %= (size+1);
	Student *temp = refP;
	for (int i = 1; i < pos; i++)
		temp = temp->getNext();
	return temp;
}
};

int main(){
	ios::sync_with_stdio(false);
	Circle circle;
	int N, Q, pos, oprt, tag;
	int i;

	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> pos;
		circle.add(pos);
	}
	cin >> Q;
	for (i = 0; i < Q; i++) {
		cin >> oprt >> pos;
		switch (oprt) {
		case 1:
			cin >> tag;
			circle.insert(pos, tag);
			break;
		case 2:
			circle.remove(pos);
			break;
		case 3:
			circle.query(pos);
			break;
		}
	}

	return 777;
}
