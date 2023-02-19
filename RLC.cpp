#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class Node1
{
	//T data;
	//Node* next;

public:
	int data;
	Node1* next;
	Node1()
	{
		data = 0;
		next = NULL;
	}

	Node1(int d, Node1* n)
	{
		data = d;
		next = n;

	}

	Node1(int d)
	{
		data = d;
	}
	Node1(Node1* n) {
		next = n;
	}

	//void setData(T d)
	//{
	//	data = d;
	//}

	//void setNext(Node* n)
	//{
	//	next = n;
	//}

	//int getData()
	//{
	//	return data;
	//}

	//Node* getNext()
	//{
	//	return next;
	//}

};
class SLinkedList 
{
private:

	

public:
	Node1* head;
	SLinkedList()
	{
		head = NULL;
	}
	void insert(int n) {
		Node1* add = new Node1();

		add->data = n;

		if (head)
		{
			Node1* currnode = head;
			while (currnode->next != NULL)
			{
				currnode = currnode->next;
			}
			currnode->next = add;
		}
		else
		{
			head = add;
		}
	}
	void insertAtHead(int n) {
		Node1* add = new Node1();
		add->data = n;
		add->next = this->head;
		this->head = add;
	}
	void InsertAtIndex(int n, int index)
	{
		Node1* newnode = new Node1();
		newnode->data = n;
		int currIndex = 1;
		Node1* currnode = this->head;

		if (index == 1)
		{

			insertAtHead(n);

		}
		else {
			for (; currIndex < index; currIndex++) {
				if (currnode != NULL) {
					currnode = currnode->next;
				}
			}
		}
		if (currnode != NULL) {
			newnode->next = currnode->next;
			currnode->next = newnode;
		}

	}
	/*void update(int n1, int n2)
	{
		Node* currnode = head;
		int currindex = 1;

		while (currnode && currnode->data != n1)
		{
			currnode = currnode->next;
			currindex++;
		}

		if (currnode)
		{
			currnode->data = n2;
		}
	}*/
	//void remove(int n)
	//{
	//	Node<T>* prevnode = NULL;
	//	Node<T>* currnode = head;
	//	int currindex = 1;

	//	while (currnode && currnode->data != n)
	//	{
	//		prevnode = currnode;
	//		currnode = currnode->next;
	//		currindex++;
	//	}
	//	if (currnode)
	//	{
	//		if (prevnode)
	//		{
	//			prevnode->next = currnode->next;
	//			delete currnode;
	//		}
	//		else
	//		{
	//			head = currnode->next;
	//			delete currnode;
	//		}
	//	}
	//}
	void print()
	{
		int num = 0;

		Node1* currnode = head;
		currnode = currnode->next;
		currnode = currnode->next;
		while (currnode != NULL)
		{
		
			cout << currnode->data << " ";
			if (currnode->data == -1) {
				cout << endl;
			}
			currnode = currnode->next;
			num++;
			
		}

	}
	void print2() {
		int num = 0;

		Node1* currnode = head;
		while (currnode != NULL)
		{

			cout << currnode->data << " ";
			
			currnode = currnode->next;
			num++;

		}
	}
	/*T search(int key)
	{
		Node<T>* temp = head;

		while (temp != NULL)
		{


			if (temp->data == key)
				return temp->data;


			temp = temp->next;
		}
	}*/

};
int main() {
	Mat image = imread("mIMD002.bmp");

	/*imshow("Display Window", image);
	waitKey(0);*/

	float** matrix = new float* [image.rows];

	image.convertTo(image, CV_32F);

	for (int k = 0; k < image.rows; k++) {
		matrix[k] = new float[image.cols];
	}

	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols; j++)
		{
			matrix[i][j] = image.at<float>(i, j);
		}
	}
	SLinkedList obj;
	obj.insertAtHead(image.rows);
	obj.insert(image.cols);
	
	obj.print2();
	cout << endl;
	for (int a = 0; a < image.rows; a++) {
		for (int b = 0; b < image.cols; b++) {
			if (matrix[a][b] == 255) {
				obj.insert(b+1);
				while (matrix[a][b] == 255) {
					b++;
				}
				obj.insert(b);
			}
		}
		obj.insert(-1);
	}
	obj.print();
	
}