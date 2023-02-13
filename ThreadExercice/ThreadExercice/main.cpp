#include <iostream>
#include <thread>

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
	Matrix3 matProduct(Matrix3 mat)
	{
		Matrix3 newMat = Matrix3(this->a * mat.a + this->b * mat.d + this->c * mat.g, this->a * mat.b + this->b * mat.e + this->c * mat.h, this->a * mat.c + this->b * mat.f + this->c * mat.i,
								 this->d * mat.a + this->e * mat.d + this->f * mat.b, this->d * mat.b + this->e * mat.e + this->f * mat.h, this->d * mat.c + this->e * mat.f + this->f * mat.i,
								 this->g * mat.a + this->h * mat.d + this->i * mat.g, this->g * mat.b + this->h * mat.e + this->i * mat.h, this->g * mat.c + this->h * mat.f + this->i * mat.i
								);

		return newMat;
	}
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

	std::thread t2([&productMat, A, B]() {
		productMat.a = product(A.a, B.b, A.b, B.e, A.c, B.h);  //
	}
	);
	std::thread t3([&productMat, A, B]() {
		productMat.a = product(A.a, B.c, A.b, B.f, A.c, B.i);  //
	}
	);
	std::thread t4([&productMat, A, B]() {
		productMat.a = product(A.a, B.a, A.b, B.d, A.c, B.g);  //
	}
	);
	std::thread t5([&productMat, A, B]() {
		productMat.a = product(A.d, B.a, A.e, B.d, A.f, B.g);  //
	}
	);
	std::thread t6([&productMat, A, B]() {
		productMat.a = product(A.a, B.a, A.b, B.d, A.c, B.g);  //
	}
	);
	std::thread t7([&productMat, A, B]() {
		productMat.a = product(A.a, B.a, A.b, B.d, A.c, B.g);  //
	}
	);
	std::thread t8([&productMat, A, B]() {
		productMat.a = product(A.a, B.a, A.b, B.d, A.c, B.g);  //
	}
	);
	std::thread t9([&productMat, A, B]() {
		productMat.a = product(A.a, B.a, A.b, B.d, A.c, B.g);  //
	}
	);

	//displayMat(productMat);


	return 0;

}