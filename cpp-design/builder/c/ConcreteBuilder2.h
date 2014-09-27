/// class ConcreteBuilder2 - 
class ConcreteBuilder2 {
  // Attributes
private:
  Product* m_pProduct;
  // Operations
public:
  ConcreteBuilder2 ();
  ~ConcreteBuilder2 ();
  void BuildPartA ();
  void BuildPartB ();
  void BuildPartC ();
  Product* GetProduct ();
};

