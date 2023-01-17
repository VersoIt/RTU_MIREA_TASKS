
#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

// Структура узла дерева
struct t_node
{
	int field;
	t_node* left;
	t_node* right;

};


// Вывод дерева
void tree_print(t_node* tree)
{
	if (tree != nullptr) // Пока не стретится пустой узел
	{
		tree_print(tree->left);  // Рекурсивная функция вывода левого поддерева
		cout << tree->field << " "; // Отображаем корень дерева
		tree_print(tree->right); // Рекурсивная функция вывода правого дерева
	}
}

// Добавление узлов в дерево
t_node* add_node(int x, t_node* tree)
{
	if (tree == nullptr) // Если нет корня дерева, то формируем его
	{
		tree = new t_node(); // Выделение памяти вод узел
		tree->field = x; // Поле данных
		tree->left = nullptr;
		tree->right = nullptr; // Ветви инициализируем пустотой
	}
	else
	{
		if (x < tree->field) // Если элемент x меньше корневого
			tree->left = add_node(x, tree->left); // Добавляем элемент
		else // Иначе уходим вправо
			tree->right = add_node(x, tree->right);

		return tree;
	}
}

// Освобождение памяти дерева
void free_mem(t_node* node)
{
	if (node != nullptr)
	{
		free_mem(node->left); // Рекурсивное удаление левой ветки
		free_mem(node->right); // Рекурсивное удаление правой ветки
		delete node;
	}
}

// Тестирование работы
int main()
{
	const int NODES_COUNT = 8; // Количество узлов
	t_node* root = nullptr;

	for (int i = 0; i < NODES_COUNT; ++i)
	{
		int number; // Текущее значение узла
		cout << "Введите значение " << i + 1 << ": ";
		cin >> number; // Ввод числа
		root = add_node(number, root); // Добавление текущего значения в дерево
	}

	tree_print(root); // Вывод элементов дерева, получение отсортированного массива
	free_mem(root); // Освобождение памяти

	cin.get();

	return EXIT_SUCCESS;
}