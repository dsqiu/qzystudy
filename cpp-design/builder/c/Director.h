#include "Client.h"
#include "Builder.h"

/// class Director - 
class Director {
  // Associations
  Builder* unnamed;
  // Attributes
private:
  Builder* m_pBuilder;
  // Operations
public:
  Director (Builder* pBuilder);
  ~Director ();
  void Construct ();
};

