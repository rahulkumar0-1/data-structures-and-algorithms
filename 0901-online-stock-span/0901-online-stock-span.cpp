class StockSpanner {
public:
    vector<int> arr;
    StockSpanner() {}

    int next(int price) {
        arr.push_back(price);
        int i = arr.size() - 1;
        for (; i >= 0; i--) {
            if (price < arr[i]) {
                break;
            }
        }
        return arr.size() - i-1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */