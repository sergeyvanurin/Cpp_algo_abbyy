class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // счетчик для миниальной стоймости
        int minimum_price = 100000 + 42;
        // счетчик прибыли
        int profit = 0;

        for (const auto price: prices) {
            // тут обновляем минимум
            minimum_price = min(minimum_price, price);
            // тут смотрим если можем увеличить прибыль. этим мы находим наибольшее расстояние между ценами на данный день. 
            profit = max(profit, price - minimum_price);
        }

        return profit;
    }
};