
class StockSpanner {
private:
    stack<pair<int, int>> spanDays;  // Pair of price and its span

public:
    StockSpanner() {
    }
    
    int next(int price) {
        int days = 1;

        while (!spanDays.empty() && price >= spanDays.top().first) {
            days += spanDays.top().second;
            spanDays.pop();
        }

        spanDays.push({price, days});
        return days;
    }
};
