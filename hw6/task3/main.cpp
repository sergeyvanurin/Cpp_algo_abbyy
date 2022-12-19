class Solution
{
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        // возьмем long чтобы не было UB в корнер кейсах
        long xor_numbers = nums[0];

        // xor-нем все числа. Таким образом все повторы отменятся и мы получим число равное answer_first ^ answer_second
        for (int i = 1; i < nums.size(); i++) {
            xor_numbers ^= nums[i];
        }

        // получим число где проставлен один битик (самый правый вроде) 
        xor_numbers &= -xor_numbers;


        int first = 0;
        int second = 0;

        // таким образом мы поделили все числа на те в которых этот битик проставлен и те в которых не проставлен. в одной группе будет первое число ответа, а во второй второе. Сделаем все то же самое но уже по группам. Так как в каждой группе лишь одно число уникальное, оперцаия xor даст нам эти числа (все остальные отменяться)
        for (int num : nums)
        {
            if ((num & xor_numbers) == 0) 
            {
                first ^= num;
            }
            else
            {
                second ^= num;
            }
        }
        return {first, second};
    }
};