#include <iostream>
#include <string>
using namespace std;
template<class T>
class Stack
{
private:
	T* val;
	int top;
public:
	Stack(int n) { val = new T[n]; top = -1; }
	void push(T data)
	{
		top++;
		val[top] = data;
	}
	T pop()
	{
		top--;
		return val[top + 1];
	}
	long long int power(long long int a, long long int b)
	{
		long long int sum = 1;
		for (int i = 1; i <= b; i++)
		{
			sum *= a;
		}
		return sum;
	}
};
long long int Solution(string s)
{
	Stack<long long int>st(s.size());
	int i = 0;
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			st.push(s[i] - '0');
		}
		else
		{
			if (s[i] == '~')
			{
				long long int c = st.pop();
				st.push(-c);
			}
			else
			{
				long long int b = st.pop(); long long int a = st.pop();
				switch (s[i])
				{
				case '+': st.push(a + b); break;
				case '-': st.push(a - b); break;
				case '*': st.push(a * b); break;
				case '/': st.push(a / b); break;
				case '^': st.push(st.power(a, b)); break;
				}
			}
		}
		i++;
	}
	return st.pop();
}
int icp(char c)
{
	switch (c)
	{
	case '#':return 0; break;
	case '(':return 11; break;
	case '~':return 10; break;
	case '^':return 7; break;
	case '*':return 4; break;
	case '/':return 4; break;
	case '+':return 2; break;
	case '-':return 2; break;
	case ')':return 1; break;
	}
}
int isp(char c)
{
	switch (c)
	{
	case '#':return 0; break;
	case '(':return 1; break;
	case '~':return 10; break;
	case '^':return 8; break;
	case '*':return 5; break;
	case '/':return 5; break;
	case '+':return 3; break;
	case '-':return 3; break;
	case ')':return 11; break;
	}
}
string Change(string s)//改变成后缀表达式
{
	string ans = s;
	int i = 0;
	int cnt = 0;
	Stack<char>st(s.size());
	st.push('#');
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			ans[cnt] = s[i];
			cnt++;
		}
		else
		{
			char op = st.pop();
			if (icp(s[i]) > isp(op))//入栈
			{
				st.push(op);
				st.push(s[i]);
			}
			else if (icp(s[i]) < isp(op))//出栈
			{
				ans[cnt] = op;
				cnt++;
				i--;
			}
			else if (icp(s[i]) == isp(op))
			{
				if (op == '~')//连续两个取反运算
				{
					st.push(op);
					st.push(op);
				}
			}
		}
		i++;
	}
	char op = st.pop();
	while (op != '#')
	{
		ans[cnt] = op;
		op = st.pop();
		cnt++;
	}
	ans[cnt] = '\0';
	return ans;
}
void Cal()
{
	double ans = 1.0;
	double a = 1.0 / 70.0;
	cout << a << endl;
	double b = 69.0 / 70.0;
	for (int i = 1; i <= 3; i++)
	{

		ans *= a;
	}
	for (int i = 1; i <= 7; i++)
	{
		ans *= b;
	}
	ans /= 120.0;
	cout << ans;
}
int main()
{
	Cal();
	return 0;
}



