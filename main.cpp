#include <iostream>
#include "test_steg.hpp"
int main(int argc, const char * argv[]) {
  STEG_StockGlass s;
  STEG_TestSteg st(s);
  st.RunAllTest();
  return 0;
}
