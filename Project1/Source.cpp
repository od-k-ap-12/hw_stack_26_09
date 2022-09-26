#include <iostream>
#include <time.h>
using namespace std;

class Stack
{
	// Нижняя и верхняя границы стека
	enum { EMPTY = -1, FULL = 20 };
	// Массив для хранения данных
	char st[FULL + 1];
	// Указатель на вершину стека
	int top;

public:
	// Конструктор
	Stack();

	// Добавление элемента
	void Push(char c);

	// Извлечение элемента
	char Pop();

	// Очистка стека
	void Clear();

	// Проверка существования элементов в стеке
	bool IsEmpty();

	// Проверка на переполнение стека
	bool IsFull();

	// Количество элементов в стеке
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
	// Изначально стек пуст
	top = EMPTY;
}

void Stack::Clear()
{
	// Эффективная "очистка" стека 
	// (данные в массиве все еще существуют, 
	// но функции класса, ориентированные на работу с вершиной стека,
	// будут их игнорировать)
	top = EMPTY;
}

bool Stack::IsEmpty()
{
	// Пуст?
	return top == EMPTY;
}

bool Stack::IsFull()
{
	// Полон?
	return top == FULL;
}
int Stack::GetCount()
{
	// Количество присутствующих в стеке элементов
	return top + 1;
}

void Stack::Push(char c)
{
	// Если в стеке есть место, то увеличиваем указатель
	// на вершину стека и вставляем новый элемент
	if (!IsFull())
		st[++top] = c;
}

char Stack::Pop()
{
	// Если в стеке есть элементы, то возвращаем верхний и
	// уменьшаем указатель на вершину стека
	if (!IsEmpty())
		return st[top--];
	else // Если в стеке элементов нет
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