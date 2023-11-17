#include "steg_bid.hpp"

bool STEG_Bid::operator > (const STEG_Bid& bid) const {
  return price > bid.price;
}

bool STEG_Bid::operator == (const STEG_Bid& bid) const {
  return price == bid.price && volume == bid.volume && type == bid.type;
}

std::ostream& operator << (std::ostream &os, const STEG_Bid & bid) {
  std::string t;
  switch (bid.type) {
    case BidType::Buy:
      t = "buy";
      break;
    case BidType::Sell:
      t = "sell";
      break;
    default:
      break;
  }
  os << "Price: " << bid.price << "\tVolume: " << bid.volume << "\tType: " << t;
  return os;
}
