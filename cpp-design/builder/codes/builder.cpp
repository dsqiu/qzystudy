#include <iostream>
#include <string>
#include <vector>
using namespace std;
/// class Product -
class Product {
  // Attributes
private:
  string m_partA;
  string m_partB;
  string m_partC;
  // Operations
public:
  Product ();
  virtual ~Product ();
  void setPartA (const string& s);
  void setPartB (const string& s);
  void setPartC (const string& s);
};

/// class Builder -
class Builder {
  // Operations
public:
  Builder ();
  virtual ~Builder ();
  virtual void BuildPartA () = 0;
  virtual void BuildPartB () = 0;
  virtual void BuildPartC () = 0;
  virtual Product* GetProduct () = 0;
};

/// class ConcreteBuilder1 -
class ConcreteBuilder1 :public Builder{
  // Attributes
private:
  Product* m_pProduct;
  // Operations
public:
  ConcreteBuilder1 ();
  virtual ~ConcreteBuilder1 ();
  virtual void BuildPartA ();
  virtual void BuildPartB ();
  virtual void BuildPartC ();
  virtual Product* GetProduct ();
};

/// class ConcreteBuilder2 -
class ConcreteBuilder2  :public Builder{
  // Attributes
private:
  Product* m_pProduct;
  // Operations
public:
  ConcreteBuilder2 ();
  virtual ~ConcreteBuilder2 ();
  virtual void BuildPartA ();
  virtual void BuildPartB ();
  virtual void BuildPartC ();
  virtual Product* GetProduct ();
};

/// class Director -
class Director {
  // Attributes
private:
  Builder* m_pBuilder;
  // Operations
public:
  Director (Builder* pBuilder);
  ~Director ();
  void Construct ();
};
/// class Client -
class Client {
};

Product::Product()
{}
Product::~Product()
{}
void Product::setPartA(const string& s)
{
	m_partA = s;
}
void Product::setPartB(const string& s)
{
	m_partB = s;
}
void Product::setPartC(const string& s)
{
	m_partC = s;
}
Builder::Builder()
{}
Builder::~Builder()
{}
ConcreteBuilder1::ConcreteBuilder1()
{
	m_pProduct = new Product();
	cout << "Create empty product!" << endl;
}
ConcreteBuilder1::~ConcreteBuilder1()
{
	delete m_pProduct;
	m_pProduct = NULL;
}
void ConcreteBuilder1::BuildPartA()
{
	m_pProduct->setPartA("A");
	cout << "BuildPartA" << endl;
}
void ConcreteBuilder1::BuildPartB()
{
	m_pProduct->setPartB("B");
	cout << "BuildPartB" << endl;
}
void ConcreteBuilder1::BuildPartC()
{
	m_pProduct->setPartC("C");
	cout << "BuildPartC" << endl;
}
Product* ConcreteBuilder1::GetProduct()
{
	return m_pProduct;
}

ConcreteBuilder2::ConcreteBuilder2()
{
	m_pProduct = new Product();
	cout << "Create empty product!" << endl;
}
ConcreteBuilder2::~ConcreteBuilder2()
{
	delete m_pProduct;
	m_pProduct = NULL;
}
void ConcreteBuilder2::BuildPartA()
{
	m_pProduct->setPartA("A");
	cout << "BuildPartA" << endl;
}
void ConcreteBuilder2::BuildPartB()
{
	m_pProduct->setPartB("B");
	cout << "BuildPartB" << endl;
}
void ConcreteBuilder2::BuildPartC()
{
	m_pProduct->setPartC("C");
	cout << "BuildPartC" << endl;
}
Product* ConcreteBuilder2::GetProduct()
{
	return m_pProduct;
}
Director::Director(Builder *pBuilder)
{
	m_pBuilder = pBuilder;
}
void Director::Construct()
{
	m_pBuilder->BuildPartA();
	m_pBuilder->BuildPartB();
	m_pBuilder->BuildPartC();
}
Director::~Director()
{
	delete m_pBuilder;
	m_pBuilder = NULL;
}
int main(int argc, char *argv[])
{
	Director* pDirector = new Director(new ConcreteBuilder1());
	pDirector->Construct();

	Director* pDirector1 = new Director(new ConcreteBuilder2());
	pDirector1->Construct();
    return 0;
}
