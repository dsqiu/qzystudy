#include "ConcreteBuilder2.h"
#include "ConcreteBuilder1.h"

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
  ~Product ();
  void setPartA (const string& s);
  void setPartB (const string& s);
  void setPartC (const string& s);
};

