#include <iostream>
using namespace std;
struct Node
{
	int val;
	int left;
	int right;
	Node* next;
};
class Queqe
{
private:
	Node* element;//具有空的头结点
	Node* tail;//尾结点
public:
	Queqe() { element = new Node; element->next = NULL; tail = element; }
	void push_back(int val)
	{
		Node* newnode = new Node;
		newnode->val = val;
		newnode->left = 2 * val + 1;
		newnode->right = 3 * val + 1;
		newnode->next = NULL;
		tail->next = newnode;
		tail = newnode;
	}
	void pop_front()
	{
		Node* del = element->next;
		element->next = del->next;
		delete del;
	}
	int Solution(int a, int n)
	{
		int cnt = 1;//目前遍历到第几个元素
		push_back(a);
		Node* target = element->next;//target指第一个遇到的left和right都没有用过的元素
		while (cnt != n)
		{
			if (element->next->left != -1)
			{
				push_back(element->next->left);
				element->next->left = -1;
				cnt++;
				target = element->next->next;
			}
			else
			{
				Node* pre = element->next;
				int ans = pre->right;
				Node *cur = pre->next;
				if (ans > target->left)
				{
					push_back(target->left);
					target->left = -1;
					target = target->next;
					cnt++;
				}
				else
				{
					push_back(ans);
					pop_front(); cnt++;
				}
			}
		}
		return tail->val;
	}
};
int main()
{
	int a, n;
	cin >> a >> n;
	Queqe q;
	cout<<q.Solution(a, n);
	return 0;
}