#include "test_steg.hpp"
#include <chrono>

STEG_TestSteg::STEG_TestSteg(STEG_StockGlass& sg):stockGlass(sg){};

void STEG_TestSteg::RunAllTest(){
  TestAddBid();
  TestChangeBid();
  TestDeleteBid();
}

void STEG_TestSteg::TestAddBid(){
  stockGlass.Clear();
  std::cout << "TestAddBid" << std::endl;
  stockGlass.AddBid(1, {BidType::Buy, 1, 100});
  stockGlass.AddBid(2, {BidType::Sell, 2, 101230});
  const auto start {std::chrono::steady_clock::now()};
  stockGlass.AddBid(3, {BidType::Buy, 3, 100});
  const auto end {std::chrono::steady_clock::now()};
  stockGlass.AddBid(4, {BidType::Buy, 3, 100});
  auto elapsed_seconds {std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()};
  std::cout << "Time - " << elapsed_seconds << std::endl;
  EQTest<size_t>(stockGlass.Size(), 4);
}

void STEG_TestSteg::TestChangeBid(){
  stockGlass.Clear();
  std::cout << "TestChangeBid" << std::endl;
  stockGlass.AddBid(1, {BidType::Buy, 1, 100});
  stockGlass.AddBid(2, {BidType::Sell, 2, 101230});
  stockGlass.AddBid(3, {BidType::Buy, 3, 100});
  STEG_Bid b {BidType::Sell, 2, 101230};
  const auto start {std::chrono::steady_clock::now()};
  stockGlass.ChangeBid(2, b);
  const auto end {std::chrono::steady_clock::now()};
  auto elapsed_seconds {std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()};
  std::cout << "Time - " << elapsed_seconds << std::endl;
  EQTest(b, stockGlass.GetBid(2));
}

void STEG_TestSteg::TestDeleteBid(){
  stockGlass.Clear();
  std::cout << "TestDeleteBid" << std::endl;
  stockGlass.AddBid(1, {BidType::Buy, 1, 100});
  stockGlass.AddBid(2, {BidType::Sell, 2, 101230});
  stockGlass.AddBid(3, {BidType::Buy, 3, 100});
  stockGlass.AddBid(4, {BidType::Buy, 3, 100});
  stockGlass.DeleteBid(2);
  const auto start {std::chrono::steady_clock::now()};
  stockGlass.DeleteBid(1);
  const auto end {std::chrono::steady_clock::now()};
  auto elapsed_seconds {std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()};
  std::cout << "Time - " << elapsed_seconds << std::endl;
  EQTest<size_t>(stockGlass.Size(), 2);
}
