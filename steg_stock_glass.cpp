#include "steg_stock_glass.hpp"
#include <iostream>

bool STEG_StockGlass::AddBid(keyType key, const STEG_Bid & bid) {
  if (stockGlass.insert({key, bid}).second) {
    if(bestBid.size() > 10){
      bestBid.erase(std::prev(bestBid.end()));
    }
    bestBid.insert(bid);
    return true;
  }
  return false;
}

void STEG_StockGlass::ChangeBid(keyType key, STEG_Bid newBid) {
  stockGlass[key] = newBid;
}

bool STEG_StockGlass::DeleteBid( keyType  key) {
  return stockGlass.erase(key);
}

void STEG_StockGlass::PrintTopTen() {
  const auto begin = bestBid.begin();
  const auto end = bestBid.size() < 10 ? bestBid.end() : std::next(begin, 10);
  for (auto it = begin; it != end; ++it) {
    std::cout << *it << std::endl;
  }
}

size_t STEG_StockGlass::Size() {
  return stockGlass.size();
}

void STEG_StockGlass::Clear() {
  stockGlass.clear();
}

STEG_Bid STEG_StockGlass::GetBid(keyType key) {
  return stockGlass[key];
}
