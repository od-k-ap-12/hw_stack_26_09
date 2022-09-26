#include <iostream>
#include <time.h>
using namespace std;

class Stack
{
	// ������ � ������� ������� �����
	enum { EMPTY = -1, FULL = 20 };
	// ������ ��� �������� ������
	char st[FULL + 1];
	// ��������� �� ������� �����
	int top;

public:
	// �����������
	Stack();

	// ���������� ��������
	void Push(char c);

	// ���������� ��������
	char Pop();

	// ������� �����
	void Clear();

	// �������� ������������� ��������� � �����
	bool IsEmpty();

	// �������� �� ������������ �����
	bool IsFull();

	// ���������� ��������� � �����
	int GetCount();

	void Output()
	{
		for (int i = 0; i < top + 1; i++)
		{
			cout << st[i] << " ";
		}
		cout << endl;
	}
	char GetTopChar();
};
char Stack::GetTopChar() {
	return st[top];
}

Stack::Stack()
{
	// ���������� ���� ����
	top = EMPTY;
}

void Stack::Clear()
{
	// ����������� "�������" ����� 
	// (������ � ������� ��� ��� ����������, 
	// �� ������� ������, ��������������� �� ������ � �������� �����,
	// ����� �� ������������)
	top = EMPTY;
}

bool Stack::IsEmpty()
{
	// ����?
	return top == EMPTY;
}

bool Stack::IsFull()
{
	// �����?
	return top == FULL;
}
int Stack::GetCount()
{
	// ���������� �������������� � ����� ���������
	return top + 1;
}

void Stack::Push(char c)
{
	// ���� � ����� ���� �����, �� ����������� ���������
	// �� ������� ����� � ��������� ����� �������
	if (!IsFull())
		st[++top] = c;
}

char Stack::Pop()
{
	// ���� � ����� ���� ��������, �� ���������� ������� �
	// ��������� ��������� �� ������� �����
	if (!IsEmpty())
		return st[top--];
	else // ���� � ����� ��������� ���
		return 0;
}
bool BracketCheckout(const char* string) {
	Stack BC;
	char c;
	for (int i = 0; i < strlen(string); i++) {
		if (string[i] == ')' || string[i] == '(' || string[i] == '[' || string[i] == ']' || string[i] == '{' || string[i] == '}') {
			c = string[i];
			if (c == '(' || c == '[' || c == '{') {
				BC.Push(c);
			}
			else if (c == ')') {
				if (BC.IsEmpty() || BC.GetTopChar() != '(') {
					return false;
				}
				else {
					BC.Pop();
				}

			}
			else if (c == ']') {
				if (BC.IsEmpty() || BC.GetTopChar() != '[') {
					return false;
				}
				else {
					BC.Pop();
				}

			}
			else if (c == '}') {
				if (BC.IsEmpty() || BC.GetTopChar() != '{') {
					return false;
				}
				else {
					BC.Pop();
				}
			}

		}
		else {
			continue;
		}
	}
	return true;
}
int main()
{
	const char str1[30] = "({x-y-z}*[x+2y]-(z+4x))";
	cout << BracketCheckout(str1);
	cout << endl << endl;
	const char str2[30] = "([}*[x+2y)-{z+4x)]";
	cout << BracketCheckout(str2);
	cout << endl << endl;
	system("pause");
}