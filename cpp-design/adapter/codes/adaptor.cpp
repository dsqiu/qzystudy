
/// class Adaptee -
class Adaptee {
  // Operations
public:
  Adaptee ();
  ~Adaptee ();
  void SpecificRequest ();
};

/// class Adapter -
class Adapter : public Adaptee, public Target {
  // Operations
public:
  Adapter ();
  ~Adapter ();
  void Request ();
};
/// class Target -
class Target {
  // Operations
public:
  Target ();
  ~Target ();
  void Request ();
};

/// class Client -
class Client {
};
