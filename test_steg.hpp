#ifndef test_steg_hpp
#define test_steg_hpp

#include <iostream>
#include "steg_stock_glass.hpp"

class STEG_TestSteg {
private:
  STEG_StockGlass& stockGlass;
  void TestAddBid();
  void TestChangeBid();
  void TestDeleteBid();
  
public:
  STEG_TestSteg(STEG_StockGlass& sg);
  void RunAllTest();
};

template <typename T>
void EQTest(T t1, T t2) {
  if(t1 == t2){
    std::cout << "Test - OK" << std::endl << std::endl;
  }
  else {
    std::cout << "Test - Failed" << std::endl << std::endl;
  }
}

#endif /* test_steg_hpp */
