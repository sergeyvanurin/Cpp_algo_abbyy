class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Воспользуемся динамическим программированием. В массиве на месте i стоит минимальное количество монеток для суммы i. Построим наш массив на amount + 1 ячеек (потому что отсчитываем с нуля) и заполним их числами которые точно больше чем максимум (все что угодно больше amount ведь номинал монеток это целое число) 
        vector<int> din(amount + 1, amount + 1337);

        // проинициализируем 0 сумму ноликом
        din[0] = 0;
        for (int current_amount = 1; current_amount <= amount; current_amount++) {
            for (const auto value: coins) {
                if (value <= current_amount) {
                    // Пробуем добавить все монетки меньше чем current_amount. если мы можем добавить монетку и это будет меньше чем если бы не добавляли эту монетку, то сохраняем результат. Иначе оставляем какой был. Для этого мы берем число из ячейки current_amount - value так как все прошлые ячейки мы уже оптимизировали. 
                    din[current_amount] = min(din[current_amount], din[current_amount - value] + 1);
                }
            }
        }

        // проверим что ответ меньше или равен amount ведь монетки целочисленные. Если больше то такого расклада не существует
        return din[amount] <= amount ? din[amount] : -1;
    }
};