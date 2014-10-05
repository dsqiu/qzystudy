#ifndef FLYWEIGHT__H
#define FLYWEIGHT__H

/// class Flyweight - 
class Flyweight {
  // Attributes
private:
  string _instrinsicStatic;
  // Operations
public:
  ~Flyweight ();
  virtual void Operation (const string& extrinsicState) = 0;
  string GetInstrinsicState ();
protected:
  Flyweight (string intrinsicState);
};

#endif
