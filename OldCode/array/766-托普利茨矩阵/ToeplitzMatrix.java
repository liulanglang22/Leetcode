public class ToeplitzMatrix {
    public static void main(String[] args) {
        int[][] ns ={
                {1, 2, 3, 4 },
                {5, 1, 2, 3 },
                {9, 5, 1, 2 }
        };
        boolean a = new ToeplitzMatrix().isToeplitzMatrix(ns);
        System.out.println(a);
    }
    public boolean isToeplitzMatrix(int[][] matrix) {
        //空间复杂度O(m+n)
        if (matrix.length == 0) {
            return false;
        }
        int m = matrix.length;
        int n = matrix[0].length;
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i-1][j-1] != matrix[i][j])
                    return false;
        return true;
    }
    public boolean isToeplitzMatrix_1(int[][] matrix) {
        //也没优化多少
        for (int r = 1; r < matrix.length; ++r)
            for (int c = 1; c < matrix[0].length; ++c)
                if (matrix[r-1][c-1] != matrix[r][c])
                    return false;
        return true;
    }
}
