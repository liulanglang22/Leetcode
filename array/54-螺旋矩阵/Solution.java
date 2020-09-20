import java.util.ArrayList;
import java.util.List;

public class Solution {
    public static void main(String[] args) {
        int[][] ns = {
                {1, 2, 3, 4 },
                {5, 6, 7, 8 },
                {9, 10, 11, 12 }
        };
        List<Integer> a = new Solution().sprialOrder_1(ns);
        for (Integer s : a){
            System.out.printf("%d ",s);
        }
    }
    public  List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> list = new ArrayList<>();
        if (matrix.length == 0)
            return list;
        int m = matrix.length;
        int n = matrix[0].length;
        boolean[][] a = new boolean[m][n];
        int[] s = new int[m*n];
        int i = 0;
        int row = 0, col = 0;
        int directionIndex = 0;
        int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0} };
        int total = m * n;
        for (i = 0;i < total; i++ ){
            s[i] = matrix[row][col];
            a[row][col] = true;
            int nextRow = row + directions[directionIndex][0], nextCol = col +directions[directionIndex][1];
            if (nextRow < 0 || nextRow >= m || nextCol < 0 || nextCol >= n || a[nextRow][nextCol]) {
                directionIndex = (directionIndex +1) % 4;
            }
            row += directions[directionIndex][0];
            col += directions[directionIndex][1];
        }
        for (i = 0; i < m*n; i++){
            list.add(s[i]);
        }
        return list;
    }
    public List<Integer> sprialOrder_1(int[][] matrix) {
        List<Integer> list = new ArrayList<>();
        if(matrix.length == 0) {
            return list;
        }
        int up = 0, down = matrix.length - 1, left = 0, right = matrix[0].length - 1;
        while (true) {
            for (int col = left; col <= right; ++col) {
                list.add(matrix[up][col]);
            }
            if (++up > down) {
                break;
            }
            for (int row = up; row <= down; ++row) {
                list.add(matrix[row][right]);
            }
            if (--right < left) {
                break;
            }
            for (int col = right; col >= left; --col) {
                list.add(matrix[down][col]);
            }
            if (--down < up) {
                break;
            }
            for (int row = down; row >= up; --row) {
                list.add(matrix[row][left]);
            }
            if (++left > right) {
                break;
            }
        }
        return list;
    }
}
