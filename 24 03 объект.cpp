// 24 03 объект прямовугольник стороны и площадь.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class Rect
{
	double a;
	double b;
	double S;

	double Square(bool P = true) // метод считания площади
	{
		// return a*b делать не надо, так как он не сохранит значение, надо делать так:
		S = a * b;
		return S;
	}

public:

	Rect(double A = 1.0, double B = 1.0)  // конструктор
	{
		if ((A > 0) && (B > 0))
		{
			a = A;
			b = B;
		}
		else
		{
			a = 1.0;
			b = 1.0;
		}

		Square(); // вызываем метод подсчета площади в конструкторе
	}

	double GetA(bool p = true) // метод читания стороны а = запрашивания
	{
		if (p)
		{
			return a;
		}
		return -1;
	}

	double GetB(bool p = true) // метод читания стороны b = запрашивания
	{
		if (p)
		{
			return b;
		}
		return -1;
		
	}

	double GetS(bool p = true) // метод читания площади S = запрашивания
	{
		if (p)
		{
			return S;
		}
		return -1;
	}

	bool ResizeA(double newA)
	{
		if ((newA > 0) && (newA != a))
		{
			a = newA;
			Square();
			return true;
		}
		return false;
	}

	bool ResizeB(double newB)
	{
		if ((newB > 0) && (newB != b))
		{
			b = newB;
			Square();
			return true;
		}
		return false;
	}

	bool Resize(double newA, double newB)
	{
		if ((newA > 0) && (newB > 0))
		{
			if ((newA == a) && (newB != b))
			{
				b = newB;
			}
			if ((newB == b) && (newA != a))
			{
				a = newA;
			}
			else
			{
				a = newA;
				b = newB;
			}
			Square();
			return true;
		}
		return false;
	}
};

bool Compare(Rect& o1, Rect& o2)
{
	if (o1.GetS() > o2.GetS())
	{
		cout << "1ый больше 2го" << endl;
		return true;
	}
	if (o1.GetS() < o2.GetS())
	{
		cout << "2oй больше 1го" << endl;
		return true;
	}
	else
	{
		cout << "они равны" << endl;
		return true;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	Rect o1;
	cout << "площадь объекта: " << o1.GetS() << endl;
	o1.Resize(-2, 6);
	cout << "новая площадь объекта: " << o1.GetS() << endl;

	// предположим, что мы захотим сравнивать 2 объекта - чья площадь больше. 
	// -> нам нужна глобальная функция, которая должна управлять объектами
	Rect o2(2,2);
	Compare(o1, o2);
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
