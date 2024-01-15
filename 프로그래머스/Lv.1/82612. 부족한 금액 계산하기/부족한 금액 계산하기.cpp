using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = (long long)-money;
    answer += (long long)price * (((long long)count * ((long long)count + 1)) / 2);
    return answer <= 0 ? 0 : answer;
}