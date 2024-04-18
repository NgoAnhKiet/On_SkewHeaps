#include <iostream>
using namespace std;

struct Node
{
	int info;
	Node* left;
	Node* right;
};
typedef Node* NodePtr;

//hàm HỢP NHẤT
void merge(NodePtr& s, NodePtr s1, NodePtr s2)
{
	if (s1 == NULL)
		s = s2;
	else if (s2 == NULL)
		s = s1;
	else
	{
		//B1:
		if (s1->info > s2->info)
		{
			NodePtr temp = s1;
			s1 = s2;
			s2 = temp;
		}

		//B2:
		s = s1;
		merge(s->right, s1->right, s2);

		//B3:
		NodePtr temp = s->left;
		s->left = s->right;
		s->right = temp;
	}
}

//Chèn
void insert(NodePtr& s, int value) //hàm insert này tựa tựa như hàm makeNode của những cây khác, NHƯNG KHÔNG GIỐNG HOÀN TOÀN 100%
{
	NodePtr newNode = new Node();
	newNode->info = value;
	newNode->left = NULL;
	newNode->right = NULL;
	merge(s, s, newNode);
}

//Xóa
void deleteRoot(NodePtr& s) //chỉ xóa NODE GỐC
{
	if (s == NULL) return;

	//Gán 2 cây con vào 2 nút tạm để lưu dữ liệu
	NodePtr leftRoot = s->left;
	NodePtr rightRoot = s->right;

	//Xóa nút gốc
	delete s;

	//Hợp nhất 2 cây con lại để tạo ra cây mới
	merge(s, leftRoot, rightRoot);
}

void preOrder(NodePtr s)
{
	if(s)
	{
		cout << s->info << " ";
		preOrder(s->left);
		preOrder(s->right);
	}
}

int main()
{
	NodePtr s = NULL;
	const int MAX = 5;
	int array[] = { 9,4,7,2,6 };
	for (int i = 0; i < MAX; i++)
	{
		insert(s, array[i]);
	}

	cout << "\nPreOrder:";
	preOrder(s);

	cout << "\nPreOrder after remove root: ";
	deleteRoot(s);
	preOrder(s);


	return 0;
}