/// class ConcreteBuilder1 - 
class ConcreteBuilder1 {
  // Attributes
private:
  Product* m_pProduct;
  // Operations
public:
  ConcreteBuilder1 ();
  ~ConcreteBuilder1 ();
  void BuildPartA ();
  void BuildPartB ();
  void BuildPartC ();
  Product* GetProduct ();
};

