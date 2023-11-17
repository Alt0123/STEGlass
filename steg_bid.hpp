#ifndef steg_bid_hpp
#define steg_bid_hpp

#include <iostream>

enum class BidType { Buy, Sell };

using currency = double;
using sVolume = unsigned long int;

// Заявка для биржевого стакана
struct STEG_Bid {
  // Тип заявки
  BidType type;
  // Цена
  currency price;
  // Объем
  sVolume volume;
  bool operator > (const STEG_Bid& bid) const;
  bool operator == (const STEG_Bid& bid) const;
  friend std::ostream& operator << (std::ostream &os, const STEG_Bid & bid);
};

#endif /* steg_bid_hpp */
