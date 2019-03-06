#ifndef LIBARR_H
#define LIBARR_H

class libArr {
 public:
  libArr(long int);
  libArr();
  libArr(const libArr& lib);
  long int counter();
  ~libArr();

 private:
  long int n{};
  long int* arr;
  long int result{};
};
#endif
