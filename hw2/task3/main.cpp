class Solution {
public:
    void PlaceBrackets(const int closed_left, const int opened_left, string& current_string, vector<string>& answer) {
        // если у нас кончились оба вида скобочек, значит мы получили валидную комбинацию и ее можно сохранить
    if (closed_left == 0 && opened_left == 0) {
        answer.push_back(current_string);
        return;
    }

    // проверим что у нас остались открытые скобки
    if (opened_left != 0) {
        //если да то добавим ее и попробуем вставить новые, но уже с уменьшенным счетчиком открытых скоб. Не забудем добавить 1 к счетчику закрытых скобочек
        current_string.append("(");
        PlaceBrackets(closed_left + 1, opened_left - 1, current_string, answer);
        // удалим эту скобку чтобы теперь попробовать вместо открытия новой пары закрытие старой
        current_string.pop_back();
    } 
    // если счетчик не ноль значит есть открытые скобки которые можно закрыть. Сделаем это
    if (closed_left != 0) { 
        current_string.append(")");
        // уменьшаем только счетчик закрытых скобок
        PlaceBrackets(closed_left - 1, opened_left, current_string, answer);
        // аналогично стираем чтобы попробовать другие комбинации.
        current_string.pop_back();
    }
    return;

}

vector<string> generateParenthesis(int n) {
    vector<string> answer;
    string current_string;
    PlaceBrackets(0, n, current_string, answer);

    return answer;
}
};