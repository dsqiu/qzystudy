/// class Singleton - 
class Singleton {
  // Attributes
private:
  static Singleton* pinstance;
  // Operations
public:
  static Singleton* Instance ();
  static void Destory ();
private:
  Singleton ();
};

