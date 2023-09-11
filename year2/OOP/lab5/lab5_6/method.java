package year2.OOP.lab5.lab5_6;

public class method {
    int count = 1, x, y;

    public boolean isConsecutiveFour(int[][] values) {
        for (int i = 0; i < values.length; i++) {
            for (int j = 0; j < values[i].length; j++) {
                count = 1;
                x = 0;
                y = 0;
                if (i + 3 < values.length && j < values[i].length) {
                    if (values[i][j] == values[i + 1][j]) {
                        x = i + 1;
                        while (values[i][j] == values[x][j] && x < values[i].length) {
                            count++;
                            x++;
                            if (count == 4) {
                                return true;
                            }
                        }
                    }
                }
                count = 1;
                x = 0;
                y = 0;
                if (i < values.length && j + 3 < values[i].length) {
                    if (values[i][j] == values[i][j + 1]) {
                        x = j + 1;
                        while (values[i][j] == values[i][x] && x < values[i].length) {
                            count++;
                            x++;
                            if (count == 4) {
                                return true;
                            }
                        }
                    }
                }
                count = 1;
                x = 0;
                y = 0;
                if (i + 3 < values.length && j + 3 < values[i].length) {
                    if (values[i][j] == values[i + 1][j + 1]) {
                        x = i + 1;
                        y = j + 1;
                        while (values[i][j] == values[x][y] && x < values[i].length) {
                            count++;
                            x++;
                            y++;
                            if (count == 4) {
                                return true;
                            }
                        }
                    }
                }
                count = 1;
                x = 0;
                y = 0;
                if (i + 3 < values.length && j - 3 >= 0) {
                    if (values[i][j] == values[i + 1][j - 1]) {
                        x = i + 1;
                        y = j - 1;
                        while (values[i][j] == values[x][y] && x < values[i].length) {
                            count++;
                            x++;
                            y--;
                            if (count == 4) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
}