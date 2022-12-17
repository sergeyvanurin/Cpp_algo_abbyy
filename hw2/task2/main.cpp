class Solution {
public:
    vector<vector<int>> subset(const vector<int>& nums, int position){
    if (position >= nums.size()){ // Если конец nums то засовываем пустое множество
        return {{}};
    }

    // ищем и считаем сколько одинаковых цифр идут подряд
    int counter = 0;
    while(position + counter < nums.size() && nums[position] == nums[position+counter]){
        counter++;
    }

    // запускаем субсет от следюущего набора одинаковых чисел, доходя до самого конца. Получим пустое множество, от которого дальше будем работать
    auto answer = subset(nums, position+counter);
    // нужен чтобы запоминать во сколько множеств мы уже засунули новое число. До вставок оно 0
    int prev_size = 0;

    // теперь вставляем новые числа к уже найденым подмножествам
    for (int i = 0; i < counter; i++){
        // счетчик нужен чтобы новые вставки не вызвали бесконечный луп 
        const auto answer_size = answer.size();

        // воспользуемся prev_size чтобы понять с какого сета надо начать вставлять число. Таким образом мы избежим повторов
        for (int j = prev_size; j < answer_size; j++){ 
            vector<int> temp;
            temp.push_back(nums[position]);
            for (const auto num: answer[j]) {
                temp.push_back(num);
            }
            answer.push_back(std::move(temp));
        }
        // обновляем стечик чтобы он указывал на новые сеты которые мы только что создали и в которые будет валидно вставлять новые числа
        prev_size = answer_size;
    }
    return answer;

}

vector<vector<int>> subsetsWithDup(vector<int> nums) {
    vector<vector<int>> subsets;
    // так как подмножеств очень много сортировка не станет долгой операцией в сравении с их поиском. В целом можно было вопсользоватья мапой и посчитать количество уникальных символов, но это не сильно скажется на скорости работы, так как элементов не больше 10 и мне лень переписывать то что уже написал. 
    sort(nums.begin(),nums.end());
    subsets = subset(nums, 0);

    return subsets;
}
};