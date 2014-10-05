#ifndef FLYWEIGHTFACTORY__H
#define FLYWEIGHTFACTORY__H

#include "Client.h"

/// class FlyweightFactory - 
class FlyweightFactory {
  // Attributes
public:
  vector<Flyweight*> m_vecFly;
  // Operations
public:
  FlyweightFactory ();
  ~FlyweightFactory ();
  Flyweight* GetFlyweight (string key);
  void GetFlyweightCount ();
};

#endif
