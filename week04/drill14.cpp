#include "std_lib_facilities.h"

class B1
{
public:
	virtual void pvf() = 0;
	virtual void vf() const { cout << "B1::vf()" << "\n"; }
	void f() const { cout << "B1::f()" << "\n"; }
};

class  D1 : public B1
{
public:
	void pvf() override { cout << "D1::pvf()" << "\n"; }
	void vf() const { cout << "D1::vf()" << "\n"; }
	void f() { cout << "D1::f()" << "\n"; }
};

class  D2 : public D1
{
public:
	void pvf() override { cout << "D2::pvf()" << "\n"; }
	void vf() const { cout << "D2::vf()" << "\n"; }
	void f() { cout << "D2::f()" << "\n"; }
};

void call(const B1& b1)
{
	b1.vf();
	b1.f();
}


class B2
{
public:
	virtual void pvf() = 0;


};

class D21 : public B2
{
private:
	string data_string = "szoveg";

public:
	void pvf() override;
};

void D21::pvf() 
{
	cout << data_string << "\n";
}

class D22 : public B2
{
private:
	int const data_int = 123;

public:
	void pvf() override { cout << data_int << "\n"; }
};
 
void f(B2& b2) 
{ 
	b2.pvf(); 
}


int main()
{
	D1 d1;
	D2 d2;
	D21 d21;
	D22 d22;
	d1.vf();
	d1.f();
	d1.pvf();
	d2.vf();
	d2.f();
	d2.pvf();
	call(d1);
	call(d2);
	f(d21);
	f(d22);

	return 0;
}

