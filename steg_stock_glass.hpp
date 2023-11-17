#ifndef steg_stock_glass_hpp
#define steg_stock_glass_hpp

#include <string>
#include <unordered_map>
#include <set>
#include "steg_bid.hpp"

using keyType = size_t;

// Биржевой стакан
class STEG_StockGlass {
private:
  // Множество заявок
  std::unordered_map<keyType, STEG_Bid> stockGlass;
  // Множество лучших 10 заявок
  std::set<STEG_Bid, std::greater<STEG_Bid>> bestBid;
  
public:
  // Добавляет новую заявку по ключу
  bool AddBid(keyType key, const STEG_Bid & bid);
  // Изменяет заявку по ключу
  void ChangeBid(keyType key, STEG_Bid newBid);
  // Удаляет заявку по ключу
  bool DeleteBid(keyType key);
  // Печатает лучшие 10 заявок
  void PrintTopTen();
  // Возвращает STEG_Bid по ключу
  STEG_Bid GetBid(keyType key);
  // Очищает stockGlass
  void Clear();
  // Возвращает размер stockGlass
  size_t Size();
};

#endif /* steg_stock_glass_hpp */
