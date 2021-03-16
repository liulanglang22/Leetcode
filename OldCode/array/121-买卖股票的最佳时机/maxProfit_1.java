public class maxProfit_1 {
    public int maxProfit(int[] prices) {
        int maxnum = 0;
        for (int i = 0; i < prices.length; i++)
            for (int j = i + 1; j < prices.length; j++)
                if ((prices[j] - prices[i]) > maxnum)
                    maxnum = prices[j] - prices[i];
        return maxnum;
    }
}
