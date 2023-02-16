#include <iostream>
#include <thread>
#include <mutex>

using std::cout;
using std::endl;


void sayHello() {

	cout << "Hello world" << endl;

}

struct Matrix3
{
	float a, b, c,
		  d, e, f,
		  g, h, i;

	Matrix3(float _a, float _b, float _c, float _d, float _e, float _f, float _g, float _h, float _i) : a(_a), b(_b), c(_c), d(_d), e(_e), f(_f), g(_g), h(_h), i(_i) {};
	Matrix3() : a(0), b(0), c(0), d(0), e(0), f(0), g(0), h(0), i(0) {};
	
};

float product(float a1, float a2, float b1, float b2, float c1, float c2)
{
	return a1 * a2 + b1 * b2 + c1 * c2;
}

void displayMat(Matrix3 mat)
{
	cout << "{ " << mat.a << " , " << mat.b << " , " << mat.c << endl
		<< "  " << mat.d << " , " << mat.e << " , " << mat.f << endl
		<< "  " << mat.g << " , " << mat.h << " , " << mat.i << " }" << endl << endl;
}


std::mutex someMutex;
int i = 0;
void displayInt(int sup)
{
	while (i <= sup )
	{
		std::lock_guard<std::mutex> someLock(someMutex);
		cout << i  << endl;
		i++;
	}
}


int main() {

	Matrix3 A = Matrix3(1, 2, 3, 4, 5, 6, 7, 8, 9);
	Matrix3 B = Matrix3(1, 1, 1, 1, 1, 1, 1, 1, 1);

	displayMat(A);
	displayMat(B);
	Matrix3 productMat;

	std::thread t1(
		[&productMat, A, B]() {
			productMat.a = product(A.a, B.a, A.b, B.d, A.c, B.g);  //
		}
	);

	std::thread t2(
		[&productMat, A, B]() {
		productMat.b = product(A.a, B.b, A.b, B.e, A.c, B.h);  //
	}
	);
	std::thread t3(
		[&productMat, A, B]() {
		productMat.c = product(A.a, B.c, A.b, B.f, A.c, B.i);  //
	}
	);
	std::thread t4(
		[&productMat, A, B]() {
		productMat.d = product(A.d, B.a, A.e, B.d, A.f, B.g);  //
	}
	);
	std::thread t5(
		[&productMat, A, B]() {
		productMat.e = product(A.d, B.b, A.e, B.e, A.f, B.h);  //
	}
	);
	std::thread t6(
		[&productMat, A, B]() {
		productMat.f = product(A.d, B.c, A.e, B.f, A.f, B.i);  //
	}
	);
	std::thread t7(
		[&productMat, A, B]() {
		productMat.g = product(A.g, B.a, A.h, B.d, A.i, B.g);  //
	}
	);
	std::thread t8(
		[&productMat, A, B]() {
		productMat.h = product(A.g, B.b, A.h, B.e, A.i, B.h);  //
	}
	);
	std::thread t9(
		[&productMat, A, B]() {
		productMat.i = product(A.g, B.c, A.h, B.f, A.i, B.i);  //
	}
	);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();
	t9.join();

	displayMat(productMat);

	

	std::thread tPair(displayInt, 1000);
	std::thread tImpair(displayInt, 1000);

	tPair.join();
	tImpair.join();

	return 0;

}