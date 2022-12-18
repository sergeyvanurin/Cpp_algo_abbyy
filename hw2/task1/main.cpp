class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, size_t> unique_counter; // возьмем и заполним мапу которая будет считать число вхождений каждого уникального символа
        for (const auto num: nums) {
            unique_counter[num]++;
        }
 
        vector<vector<int>> accumulator{};
        vector<int> current_permutation{}; // нужно чтобы можно было по ссылке передавать перестановку, что значительно ускорит исполнение (мог бы конечно и перегрузку сделать метода dfs, но думаю не критично)
        dfs(accumulator, current_permutation, unique_counter, nums.size()); // запустим dfs чтобы рекурсивно получить все возможные перестановки и положим их в итоге в accumulator
 
        return accumulator;
}
 
    void dfs(vector<vector<int>>& accumulator, vector<int>& current_permutation, unordered_map<int, size_t>& unique_counter, const int max_permutation_size) {
    if (current_permutation.size() == max_permutation_size) { // проверим что перестановка полная и если да, то пушнем ее в результат
        accumulator.push_back(current_permutation);
        return;
    }
 
    // проходимся по каждому уникальному символу выбирая каждый как потенциального кандидата на вход в перестановку. Уникальность перестановки получается из за того что мы выбираем кандидатов только из уникальных символов
    for (auto& entry: unique_counter) { 
        if (entry.second == 0) {
            continue; // если символ уже закончился, то пропускаем его
        }
        entry.second--; // если не закончился, то берем его как следующий элемент нашей перестановки
        current_permutation.push_back(entry.first);
        dfs(accumulator, current_permutation, unique_counter, max_permutation_size);
 
        current_permutation.pop_back(); // после того как ветку полностью прошли можно удалить этот символ и переходить к следующему
        entry.second++; // не забываем вернуть его в наш счетчик
    }
}
};